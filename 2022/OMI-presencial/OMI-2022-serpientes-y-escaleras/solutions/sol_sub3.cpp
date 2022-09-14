#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << "\n";

#define MAX 1000000
#define MAXP 2000001

int n, m, l, r, c, d, pos, res, pareja[MAXP + 2], ciclo[MAXP + 2],
    tam[MAXP + 2], vis[MAXP + 2];
std::vector<int> ciclosPorTamano;

int main() {
  std::cin >> n >> m;
  for (int i = 1; i <= n; ++i) std::cin >> l >> r;

  // PASA POR TODOS LOS PORTALES ORIGINALES
  res = n;

  // CON CADA PORTAL NUEVO SE PUEDEN AUMENTAR 3
  // SI HAY UN PORTAL ORIGINAL SIN USAR
  res += 3 * std::min(n, m);

  // CON CADA PAREJA DE PORTALES EXTRA SE PUEDEN
  // HACER 4.
  // CON CADA PORTAL EXTRA SIN PAREJA SE AGREGA 1
  d = m - n;
  if (d > 0) {
    res += 4 * (d / 2);
    res += d % 2;
  }

  std::cout << res << "\n";

  return 0;
}
