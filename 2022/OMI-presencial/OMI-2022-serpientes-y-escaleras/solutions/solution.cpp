#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << "\n";

#define MAX 1000000
#define MAXP 2000001

int n, m, l, r, c, d, pos, res, pareja[MAXP + 2], ciclo[MAXP + 2],
    tam[MAXP + 2];
std::vector<int> ciclosPorTamano;

int main() {
  std::cin >> n >> m;
  std::iota(pareja, pareja + MAXP + 1, 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> l >> r;

    // PARA CADA POSICION CONFIGURA COMO SU PAREJA LA POSICION
    // DONDE ESTA EL OTRO EXTREMO DEL PORTAL
    pareja[l - 1] = r;
    pareja[r - 1] = l;
  }

  // VALIDA LOS CICLOS CON UNA ESTRUCTURA TIPO UNION FIND.
  // INICIALIZA LA ESTRUCTURA
  std::fill(tam, tam + MAXP + 1, 0);
  std::iota(ciclo, ciclo + MAXP + 1, 0);

  for (int i = 0; i <= MAXP; ++i) {
    if (ciclo[i] == i) {
      c = i;
      pos = pareja[i];
      ciclo[pos] = c;

      if (pos != c + 1) ++tam[c];
      while (pos < MAXP && pos != c) {
        if (pareja[pos] == pos + 1) {
          pos = pos + 1;
          ciclo[pos] = c;
        } else {
          pos = pareja[pos];
          ciclo[pos] = c;
          ++tam[c];
        }
      }

      // EL C ES UN CAMINO, NO UN CICLO, NO HAY QUE AGREGARLO
      if (c) ciclosPorTamano.push_back(c);
    }
  }

  // ORDENA LOS CICLOS POR TAMANO
  std::sort(ciclosPorTamano.begin(), ciclosPorTamano.end(),
            [&](int a, int b) { return tam[a] > tam[b]; });

  res = tam[0];
  d = m - ciclosPorTamano.size();
  if (d > 0) {
    res += (d >> 1) << 2;
    res += d & 1;
  }
  for (int i = 0; i < std::min(m, (int)ciclosPorTamano.size()); ++i)
    res += tam[ciclosPorTamano[i]] + 2;

  std::cout << res << "\n";

  return 0;
}