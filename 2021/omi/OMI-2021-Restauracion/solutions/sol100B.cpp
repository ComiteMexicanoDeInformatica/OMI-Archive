#include <algorithm>
#include <iostream>
#include <vector>

#define lli long long
#define rep(i, a, b) for (lli i = (a); i <= (b); ++i)
#define repa(i, a, b) for (lli i = (a); i >= (b); --i)

#define nl "\n"
#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << nl

#define valor first
#define posicion second
#define MAX_N 100003

lli n, k, a[MAX_N], b[MAX_N], intactas[MAX_N], deja[MAX_N], prev[MAX_N], l, r,
    mitad, mayor, largolis, p;
std::vector<std::pair<lli, lli> > lis;

int main() {
  std::cin >> n >> k;
  rep(i, 1, n) std::cin >> a[i];
  rep(i, 1, k) std::cin >> intactas[i];

  // VERIFICA SI ES POSIBLE
  rep(i, 2, k) {
    if ((intactas[i] - intactas[i - 1]) >
        (a[intactas[i]] - a[intactas[i - 1]])) {
      std::cout << -1 << nl;
      return 0;
    }
  }
  if (a[intactas[1]] < intactas[1] - 1) {
    std::cout << -1 << nl;
    return 0;
  }

  // NORMALIZA LOS NUMEROS QUITANDOLES LA RAMPA
  rep(i, 1, n) b[i] = a[i];
  b[0] = -1;
  rep(i, 1, n) a[i] -= i;

  // PARA CADA PAREJA DE ESCALONES FIJOS, CALCULA EL LIS.
  a[0] = -1;
  intactas[k + 1] = n + 1;
  a[n + 1] = 2e9;
  intactas[0] = 0;

  rep(i, 1, k + 1) {
    // OBTEN EL LIS DE intactas[i - 1] a intactas[i]
    std::vector<std::pair<lli, lli> >().swap(lis);

    rep(j, intactas[i - 1], intactas[i]) {
      if (lis.size() == 0) {
        lis.push_back({a[j], j});
        continue;
      }

      l = 0;
      r = lis.size() - 1;
      mayor = -1;
      while (l <= r) {
        mitad = (l + r) / 2;
        if (lis[mitad].valor > a[j]) {
          mayor = mitad;
          r = mitad - 1;
        } else
          l = mitad + 1;
      }

      if (mayor == -1) {
        prev[j] = lis.back().posicion;
        lis.push_back({a[j], j});  // EL ULTIMO ELEMENTO VA AL FINAL
      } else if (mayor > 0) {
        prev[j] = lis[mayor - 1].posicion;
        lis[mayor] = {a[j],
                      j};  // NO DISMINUYAS EL CERO PORQUE ES EL intactas[i-1]
                           // Y LA LIS TIENE QUE EMPEZAR EN ESE
      }
    }

    if (mayor == -1)
      p = lis.back().posicion;
    else
      p = lis[mayor].posicion;
    while (p != intactas[i - 1]) {
      deja[p] = 1;
      p = prev[p];
    }
  }

  // CONSTRUYE LA ESCALERA
  rep(i, 1, n) if (!deja[i]) b[i] = b[i - 1] + 1;
  rep(i, 1, n) std::cout << b[i] << " ";
  std::cout << nl;

  return 0;
}
