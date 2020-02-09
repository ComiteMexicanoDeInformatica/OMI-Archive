#include <inttypes.h>

#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <memory>
#include <random>
#include <vector>

#include "moebius.h"

namespace {

// This allows the transformation of the number in the range [0,
// 2**range_width_bits) to an int64_t with a desired distribution.
// This function must be injective.
using RangeTransform = std::function<int64_t(uint64_t, uint64_t)>;

RangeTransform biased_linear_transform(uint64_t bias,
                                       uint64_t range_width_bits,
                                       int64_t direction) {
  uint64_t range_width_mask = (1ULL << range_width_bits) - 1;

  return [bias, range_width_bits, range_width_mask, direction](
             uint64_t index, uint64_t result) -> int64_t {
    result += bias;
    // Once we have the final result in the unsigned-house-address-space, we
    // need to transform that into the signed-house-address-space, which is
    // the range [-range_width_/2, range_width_/2). That needs to be done
    // with bit twiddling to avoid entering undefined behavior-land.
    uint64_t result_mantissa = result & (range_width_mask >> 1);
    bool result_sign = (result & (1ULL << (range_width_bits - 1))) != 0;
    if (result_sign) {
      // We need to manually perform two's complement of the number to make
      // it overflow within the chosen range without invoking undefined
      // behavior.
      return -static_cast<int64_t>(
                 (~result_mantissa & (range_width_mask >> 1)) + 1) *
             direction;
    } else {
      return static_cast<int64_t>(result_mantissa) * direction;
    }
  };
}

RangeTransform unsigned_linear_transform(uint64_t range_width_bits,
                                         int64_t direction) {
  return [direction](uint64_t index, uint64_t result) -> int64_t {
    return static_cast<int64_t>(result) * direction;
  };
}

RangeTransform exponential_transform(double k,
                                     uint64_t range_width_bits,
                                     int64_t direction) {
  long double max_real_value = std::pow(2, range_width_bits);
  static_assert(sizeof(max_real_value) == 16, "we need moar bits");
  uint64_t max_int_value = 1ULL << range_width_bits;
  return [max_real_value, max_int_value, k, direction](
             uint64_t index, uint64_t result) -> int64_t {
    // Transforms the distribution into a value in the [0, 1) range.
    long double unit_uniform = result / max_real_value;
    static_assert(sizeof(unit_uniform) == 16, "we need moar bits");

    // Now transforms it back to a value in the [0, 2**range_width_bits) range.
    uint64_t transformed_result = static_cast<uint64_t>(
        std::round(std::pow(unit_uniform, k) * max_int_value));
    transformed_result = std::max(transformed_result, index);
    return static_cast<int64_t>(transformed_result) * direction;
  };
}

template <typename Generator>
std::vector<uint64_t> monotonically_increasing_uniform_random_stream(
    Generator& g,
    uint64_t n,
    uint64_t width) {
  // Taken from "Generating Sorted Lists of Random Numbers" by Jon Louis
  // Bentley and James B.Saxe.
  double ln_cur_max = 0.0;

  std::vector<uint64_t> result(n);
  std::uniform_real_distribution<> dist;
  int last_unfilled = 0;
  for (int i = n; i > 0; i--) {
    ln_cur_max += std::log(dist(g)) / i;
    result[i - 1] = static_cast<uint64_t>((std::exp(ln_cur_max)) * width);
    if (result[i - 1] <= i - 1) {
      // If we get here, all further entries will have a collision. So might as
      // well stop now and just fill the first entries by hand.
      last_unfilled = i;
      break;
    }
    // Iron out any collisions due to rounding.
    while (i < n && result[i - 1] >= result[i] && result[i - 1] > 0) {
      result[i - 1]--;
    }
  }
  // If the first few entries had collisions, we stopped that process from
  // underflowing and taking forever. Fill out the rest of the yet-to-be filled
  // entries with a collision-free sequence.
  for (int i = 0; i < last_unfilled; i++) {
    result[i] = i;
  }
  return result;
}

template <typename Generator>
class CalleInfinita {
 public:
  CalleInfinita(Generator& g, uint64_t origen, int num_houses_bits, int bits) {
    assert(1 < bits && bits < 64);
    assert(num_houses_bits <= bits);

    // There are 2**|chunk_houses_bits| houses within each one of the
    // 2**|chunk_num_bits| chunk, and the width of each chunk is
    // 2**|chunk_width_bits|.
    int chunk_houses_bits = std::min(18, num_houses_bits);
    int chunk_num_bits = num_houses_bits - chunk_houses_bits;
    int chunk_width_bits = bits - chunk_num_bits;
    assert(chunk_width_bits + chunk_num_bits == bits);
    assert(chunk_num_bits + chunk_houses_bits == num_houses_bits);

    num_houses_ = 1ULL << num_houses_bits;
    num_houses_bits_ = num_houses_bits;
    num_houses_mask_ = num_houses_ - 1ULL;
    range_width_ = 1ULL << bits;
    range_width_bits_ = bits;
    range_width_mask_ = range_width_ - 1;
    houses_per_chunk_ = 1ULL << chunk_houses_bits;
    houses_per_chunk_bits_ = chunk_houses_bits;
    houses_per_chunk_mask_ = houses_per_chunk_ - 1ULL;
    chunk_width_ = 1ULL << chunk_width_bits;
    chunk_width_bits_ = chunk_width_bits;
    num_chunks_ = 1ULL << chunk_num_bits;
    pos_ = origen % num_houses_;
    random_buffer_ = monotonically_increasing_uniform_random_stream(
        g, houses_per_chunk_, chunk_width_);
    assert(random_buffer_.size() == houses_per_chunk_);
    assert(houses_per_chunk_ * num_chunks_ == num_houses_);
  }

  uint64_t avanza(int64_t n) {
    // Since we are only dealing with powers of two, applying a mask is
    // equivalent to doing a modulo. It also plays nicely with the unsigned
    // overflow/underflow.
    pos_ = (pos_ + n) & num_houses_mask_;

    return pos_;
  }

  uint64_t get_address(uint64_t index) const {
    // The bit twiddling is done since it is conceptually easier to deal with
    // (and faster!) than multiplication and modulo.
    //
    // This transforms |index| from index-space, which is the ranger
    // [0, num_houses_) into unsigned-house-address-space, which is the range
    // [0,  range_width_). |random_buffer_| has |houses_per_chunk_| entries in
    // the range [0, chunk_width_), so the lowest |houses_per_chunk_bits_| bits
    // go into that lookup table, and the remaining bits are just shifted to the
    // correct range in the possitive-house-address-space.
    return (random_buffer_[index & houses_per_chunk_mask_] |
            (((index & num_houses_mask_) >> houses_per_chunk_bits_)
             << chunk_width_bits_));
  }

 private:
  std::vector<uint64_t> random_buffer_;
  uint64_t pos_;
  uint64_t range_width_;
  uint64_t range_width_bits_;
  uint64_t range_width_mask_;
  uint64_t num_houses_;
  uint64_t num_houses_bits_;
  uint64_t num_houses_mask_;
  uint64_t houses_per_chunk_;
  uint64_t houses_per_chunk_bits_;
  uint64_t houses_per_chunk_mask_;
  uint64_t chunk_width_;
  uint64_t chunk_width_bits_;
  uint64_t num_chunks_;
};

RangeTransform range_transform;
std::unique_ptr<CalleInfinita<std::default_random_engine>> calle;
int contador = 0;
int limite = 0;
int64_t destino = 0;

}  // namespace

long long avanza(long long num_casas) {
  contador++;
  if (contador > limite) {
    std::cerr << "Límite de ejecuciones (" << contador << "/" << limite
              << ") excedido.\n";
    std::cout << "0\n";
    exit(0);
  }

  uint64_t index = calle->avanza(num_casas);
  int64_t r = range_transform(index, calle->get_address(index));
  if (r == destino) {
    std::cerr << "Casa encontrada en (" << contador << "/" << limite
              << ") ejecuciones.\n";
    std::cout << "1\n";
    exit(0);
  }
  return r;
}

int main() {
  uint64_t semilla, casa_origen, casa_destino;
  int bits, nbits, direction, level;

  std::cin >> semilla >> bits >> nbits >> casa_origen >> casa_destino >>
      limite >> direction >> level;

  std::default_random_engine g(semilla);

  calle.reset(new CalleInfinita<std::default_random_engine>(g, casa_origen,
                                                            nbits, bits));

  if (level == 0) {
    int64_t bias = calle->get_address(casa_origen);
    range_transform = biased_linear_transform(bias, bits, direction);
  } else if (level == 1) {
    range_transform = unsigned_linear_transform(bits, direction);
  } else if (level == 2) {
    range_transform = exponential_transform(1.5, bits, direction);
  } else if (level == 3) {
    range_transform = exponential_transform(2.0, bits, direction);
  }

#if defined(DEBUG)
  int64_t prev = range_transform(0, calle->get_address(0));
  int overflows = 0;
  for (uint64_t i = 1; i < 1 << std::min(26, nbits); ++i) {
    int64_t curr = range_transform(i, calle->get_address(i));
    if (prev < curr && direction == 1) {
      continue;
    }
    if (prev > curr && direction == -1) {
      continue;
    }
    if (++overflows > 1) {
      char buf[1024];
      snprintf(buf, sizeof(buf),
               "Assertion prev < curr failed: %" PRId64 " >= %" PRId64, prev,
               curr);
      throw std::range_error(buf);
    }
    prev = curr;
  }
#endif

  int64_t origen =
      range_transform(casa_origen, calle->get_address(casa_origen));
  destino = range_transform(casa_destino, calle->get_address(casa_destino));

  encuentraCasa(static_cast<long long>(origen),
                static_cast<long long>(destino));
  std::cerr << "No se encontró la casa en (" << contador << "/" << limite
            << ") ejecuciones.\n";
  std::cout << "0\n";
}
