#include <iostream>

long long int mod = 1000000007;

long long int n, a, b, res, aux, inf, sup;
long long int factorial[5007], invfactorial[5007];

/// Exponenciacion Binaria
long long int potencia(long long int x, long long int p) {
  if (x == 0) return 0;
  if (x == 1) return 1;
  if (p == 0) return 1;
  if (p == 1) return x;
  long long int ret = potencia(x, p / 2);
  ret *= ret;
  ret %= mod;
  if (p % 2 == 1) ret *= x;
  ret %= mod;
  return ret;
}

int main() {
  /// Lectura de las variables
  std::cin >> n >> a >> b;

  /// Calculo de los factoriales de 0 a n modulo 1e9+7
  factorial[0] = 1;
  for (long long int i = 1; i <= n; i++)
    factorial[i] = (factorial[i - 1] * i) % mod;

  /// Calculo de los factoriales inversos usando Fermat Chiquito y
  /// Exponenciacion Binaria
  for (long long int i = 0; i <= n; i++)
    invfactorial[i] = potencia(factorial[i], mod - 2);

  /// Caso a==b
  if (a == b) {
    res = factorial[n] * invfactorial[a];
    res %= mod;
    res *= invfactorial[n - a];
    res %= mod;
    res = ((res * res) + (mod - res)) % mod;
    std::cout << res;
    return 0;
  }

  /// Sin perdida de generalidad a<b
  if (a > b) {
    aux = a;
    a = b;
    b = aux;
  }

  /// Para cada bit en el que puede ocurrir el desempate
  for (long long int i = 1; i <= n; i++) {
    /// Elegir cuantos "1" se empatan a la derecha del desempate
    inf = std::max(0LL, b + 1 - i);
    sup = std::min(a - 1, n - i);
    for (long long int j = inf; j <= sup; j++) {
      /// Elegir donde seran los "j" empates a la derecha del desempate
      aux = factorial[n - i];
      aux *= invfactorial[j];
      aux %= mod;
      aux *= invfactorial[(n - i) - (j)];
      aux %= mod;

      /// Formas de tomar los 1 a la izquierda del desempate de "a"
      aux *= factorial[i - 1];
      aux %= mod;
      aux *= invfactorial[a - (j + 1)];
      aux %= mod;
      aux *= invfactorial[(i - 1) - (a - (j + 1))];
      aux %= mod;

      /// Formas de tomar los 1 a la izquierda del desempate de "b"
      aux *= factorial[i - 1];
      aux %= mod;
      aux *= invfactorial[b - j];
      aux %= mod;
      aux *= invfactorial[(i - 1) - (b - j)];
      aux %= mod;

      res += aux;
      res %= mod;
    }
  }
  std::cout << res;
}
