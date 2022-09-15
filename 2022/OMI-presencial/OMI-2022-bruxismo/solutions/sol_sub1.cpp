#include <iostream>

#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << "\n";

#define MAX 250000

int n, T, a[MAX + 2], b[MAX + 2], d[MAX + 2], m[MAX + 2], t[MAX + 2];
int dano[MAX + 2];

int main() {
  std::cin >> n >> T;
  for (int i = 1; i <= n; ++i) std::cin >> d[i] >> a[i] >> b[i] >> m[i];
  for (int i = 1; i <= T; ++i) std::cin >> t[i];

  // SIMULA CADA DIA PARA MARCAR QUE DIENTES SE CAEN
  for (int dia = 1; dia <= T; ++dia) {
    for (int diente = 1; diente <= n; ++diente) {
      // SI ESE DIENTE YA SE CAYO, NO TIENE SENTIDO SEGUIRLO REVISANDO
      if (dano[diente] >= m[diente]) continue;

      // SI EL DIENTE SUFRE DANO ESA NOCHE, ACUMULALO, SI NO RECUPERALO SIN QUE
      // BAJE DE 0 SU DANO TOTAL
      if (t[dia] > d[diente])
        dano[diente] += a[diente];
      else
        dano[diente] = std::max(0, dano[diente] - b[diente]);
    }
  }

  for (int diente = 1; diente <= n; ++diente) {
    if (dano[diente] >= m[diente])
      std::cout << "1 ";
    else
      std::cout << "0 ";
  }
  std::cout << "\n";

  return 0;
}