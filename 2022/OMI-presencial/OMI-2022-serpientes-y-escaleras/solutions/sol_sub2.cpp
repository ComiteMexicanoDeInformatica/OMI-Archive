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
  for (int i = 1; i <= n; ++i) {
    std::cin >> l >> r;

    // PARA CADA POSICION CONFIGURA COMO SU PAREJA LA POSICION
    // DONDE ESTA EL OTRO EXTREMO DEL PORTAL
    pareja[l] = r;
    pareja[r] = l;
  }

  // SIMULA EL RECORRIDO
  vis[0] = 1;
  pos = 1;
  while (pos <= 2 * n) {
    pos = pareja[pos];
    vis[pos] = 1;
    ++pos;
    ++res;
  }

  // SI HAY UN TRAMO POR EL QUE NO PASO, ENTONCES PUEDES AGREGAR DOS TRAMOS
  // MAS CON EL NUEVO PORTAL
  for (int i = 1; i <= n * 2; ++i) {
    if (!vis[i]) {
      res += 2;
      break;  // ESTO SOLO SE PUEDE HACER UNA VEZ
    }
  }

  // SIEMPRE PUEDES COLOCAR EL NUEVO PORTAL DE FORMA QUE LA FICHA PASE POR EL
  ++res;

  std::cout << res << "\n";

  return 0;
}
