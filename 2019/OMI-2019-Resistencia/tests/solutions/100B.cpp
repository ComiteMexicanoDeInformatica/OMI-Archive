/*
Esta solución requiere un trabajo manual con la salida, ya que encuentra números de persistencia 10,
pero para conseguir uno de persistencia 11 es cosa de agarrar uno de los de persistencia 10,
factorizarlo (queda 2^19 * 3^4 * 7^ 6) y luego encontrar cómo agrupar los dígitos para que den ese producto,
la mejor manera es 277777788888899
*/
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
const ll NUM_DIGITOS = 30;
const ll BASE = 1000000;

ll ProductoDigitos(ll num) {
    ll prod = 1;
    while (num > 0) {
        prod *= num % 10;
        num /= 10;
    }
    return prod;
}

class BigNum {
public:
    BigNum& operator+= (const BigNum& b) {
        for (int i = 0; i < NUM_DIGITOS; ++i) {
            digito_[i] += b.digito_[i];
        }
        acarrea();
        return *this;
    }
    BigNum operator* (const BigNum& b) {
        BigNum ret;
        for (int i = 0; i < NUM_DIGITOS; ++i) {
            for (int k = 0; i + k < NUM_DIGITOS; ++k) {
                ret.digito_[i + k] += digito_[i] * b.digito_[k];
            }
        }
        ret.acarrea();
        return ret;
    }
    BigNum& operator*= (ll factor) {
        for (ll& num : digito_) {
            num *= factor;
        }
        acarrea();
        return *this;
    }
    BigNum(ll num) {
        for (ll& num : digito_) {
            num = 0;
        }
        digito_[0] = num;
        acarrea();
    }
    BigNum() : BigNum(0) {}
    BigNum(const BigNum& b) = default;
    BigNum(BigNum&& b) = default;
    BigNum& operator= (const BigNum& b) {
        digito_ = b.digito_;
        return *this;
    }
    BigNum& operator= (BigNum&& b) {
        digito_ = b.digito_;
        return *this;
    }
    BigNum& operator*= (const BigNum& b) {
        *this = (*this) * b;
        return *this;
    }
    BigNum operator+ (const BigNum& b) {
        BigNum ret(*this);
        ret += b;
        return std::move(ret);
    }
    BigNum ProductoDigitosBigNum() const {
        BigNum prod(1);
        for (ll d : digito_) {
            prod *= ProductoDigitos(d);
        }
        return std::move(prod);
    }
    bool operator < (ll b) const {
        return *this < BigNum(b);
    }
    bool operator < (const BigNum& b) const {
        for (int i = NUM_DIGITOS - 1; i >= 0; --i) {
            if (digito_[i] != b.digito_[i]) {
                return digito_[i] < b.digito_[i];
            }
        }
        return false;
    }
    private:
    template<int Base_Local>
    void ImprimeConCeros(ll num) const {
        if (Base_Local == 10) {
            cout << num;
            return;
        }
        ImprimeConCeros<Base_Local / 10>(num / 10);
        cout << num % 10;
    }
    void acarrea() {
        for (int i = 0; i + 1 < NUM_DIGITOS; ++i) {
            digito_[i + 1] += digito_[i] / BASE;
            digito_[i] %= BASE;
        }
    }
    std::array<ll, NUM_DIGITOS> digito_;
    template<typename T>
    friend T& operator<<(T& out, const BigNum& bignum);
};

BigNum ProductoDigitos(const BigNum& num) {
    return num.ProductoDigitosBigNum();
}

template<typename T>
T& operator<<(T& out, const BigNum& bignum) {
    ll i = NUM_DIGITOS - 1;
    while (i >= 0 && bignum.digito_[i] == 0) {
        --i;
    }
    if (i < 0) {
        out << 0;
        return out;
    }
    out << bignum.digito_[i];
    --i;
    while (i >= 0) {
        bignum.ImprimeConCeros<BASE>(bignum.digito_[i]);
        --i;
    }
    return out;
}

BigNum pow(const BigNum& base, int exponente) {
    if (exponente > 0) {
        BigNum ret(pow(base, exponente / 2));
        ret *= ret;
        if(exponente % 2 == 1) {
            return ret * base;
        }
        return ret;
    }
    return BigNum(1);
}

template<ll P1, ll P2, ll P3>
vector<BigNum> GeneraNumeros(int suma_de_los_digitos) {
    int sum_rem_1, sum_rem_2;
    sum_rem_1 = suma_de_los_digitos - P1;
    BigNum P3_big(P3);
    vector<BigNum> ret;
    for (BigNum a = P1; sum_rem_1 >= 0; a *= P1, sum_rem_1 -= P1) {
        sum_rem_2 = sum_rem_1;
        for (BigNum b = 1; sum_rem_2 >= 0; b *= P2, sum_rem_2 -= P2) {
            if (sum_rem_2 % P3 == 0) {
                BigNum c = pow(P3_big, sum_rem_2 / P3);
                BigNum ab = a * b;
                BigNum abc = ab * c;
                ret.push_back(abc);
            }
        }
    }
    return ret;
}

template<ll P1, ll P2>
vector<BigNum> GeneraNumeros(int suma_de_los_digitos) {
    int sum_rem = suma_de_los_digitos;
    vector<BigNum> ret;
    BigNum P2_big(P2);
    for (BigNum a = 1; sum_rem >= 0; a *= P1, sum_rem -= P1) {
        if (sum_rem % P2 == 0) {
            BigNum b = pow(P2_big, sum_rem / P2);
            BigNum ab = a * b;
            ret.push_back(ab);
        }
    }
    return ret;
}

template<typename Num>
void ImprimeLista(const std::vector<Num>& lista) {
    for (auto num : lista) {
        cout << num << " ";
    }
    cout << endl;
}

template<typename Num>
int CalculaPersistencia(Num num) {
    if (num < 10) {
        return 0;
    }
    auto prod = ProductoDigitos(num);
    return CalculaPersistencia(prod) + 1;
}

int MayorPersistencia = 0;

template<typename Num>
void BuscaPersistencia(const std::vector<Num>& lista_numeros) {
    for (auto num : lista_numeros) {
        int persistencia = CalculaPersistencia(num);
        if (persistencia >= MayorPersistencia) {
            MayorPersistencia = persistencia;
            cout << persistencia << " " << num << endl;
        }
    }
}

int main()
{
    for (int suma = 0; suma < 1000; suma++) {
        auto lista1 = GeneraNumeros<2, 3, 7>(suma);
        auto lista2 = GeneraNumeros<5, 3, 7>(suma);
        auto lista3 = GeneraNumeros<3, 7>(suma);
        BuscaPersistencia(lista1);
        BuscaPersistencia(lista2);
        BuscaPersistencia(lista3);
    }
    return 0;
}
