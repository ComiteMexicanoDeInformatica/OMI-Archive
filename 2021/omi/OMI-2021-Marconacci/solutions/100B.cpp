#include <functional>
#include <iostream>
#include <vector>

#define VVLL std::vector<std::vector<long long>>

const long long MOD = 1e9 + 7;
VVLL unty(2, std::vector<long long>(2));

VVLL mult(VVLL A, VVLL B) {
  VVLL m(2, std::vector<long long>(2, 0));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        m[i][j] += (A[i][k] * B[k][j]) % MOD;
        m[i][j] %= MOD;
      }
    }
  }
  return m;
}

int main() {
  int P;
  std::cin >> P;
  while (P--) {
    long long a, b, I;
    std::cin >> a >> b >> I;
    if (I == 1) {
      std::cout << a << "\n";
      continue;
    }
    if (I == 2) {
      std::cout << b << "\n";
      continue;
    }

    unty[1][1] = 0;
    unty[1][0] = 1;
    unty[0][1] = 1;
    unty[0][0] = 1;
    std::function<VVLL(int)> expo = [&](int e) {
      if (e == 1) return unty;
      if (e & 1) {
        return mult(expo(e - 1), unty);
      } else {
        VVLL m = expo(e >> 1);
        return mult(m, m);
      }
    };
    VVLL m = expo(I - 1);

    std::cout << ((m[1][1] * a) % MOD + (m[1][0] * b) % MOD) % MOD << "\n";
  }

  //   O(log I)
}