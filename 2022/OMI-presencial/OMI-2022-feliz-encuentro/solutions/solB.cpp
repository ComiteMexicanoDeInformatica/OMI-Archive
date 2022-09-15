#include <iostream>
#include <set>

using namespace std;

#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << "\n";

#define MAX 100000

int t, q, l, r, res, acumulado[MAX + 2];
string st;

int main() {
  std::cin >> t >> q >> st;

  // HAZ UNA CUENTA ACUMULADA DE LOS ENCUENTROS QUE HA HABIDO, ES DECIR,
  // acumulado[i] = NUMERO DE ENCUENTROS DESDE LA PRIMERA POSICION HASTA LA
  // POSICION i
  for (int i = 1; i < t; ++i) {
    acumulado[i] = acumulado[i - 1];  // SEGURO LLEVA LOS MISMOS ENCUENTROS QUE
                                      // LA POSICION ANTERIOR
    if (st[i] == st[i - 1])
      ++acumulado[i];  // SI EL ES UN ENCUENTRO, ENTONCES ACUMULA UNO MAS
  }

  // PARA SABER LA CANTIDAD DE ENCUENTROS DE LA POSICION r A LA l BASTA CON
  // RESTAR LA CANTIDAD DE ENCUENTROS HASTA l DE LA CANTIDAD DE ENCUENTROS HASTA
  // r
  while (q--) {
    std::cin >> l >> r;
    --l;
    --r;
    std::cout << acumulado[r] - acumulado[l] << "\n";
  }
  return 0;
}
