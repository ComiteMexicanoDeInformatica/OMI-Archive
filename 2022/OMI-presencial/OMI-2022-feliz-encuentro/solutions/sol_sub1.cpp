#include <iostream>

using namespace std;

#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << "\n";

#define MAX 100000
int t, q, l, r, res;
string st;

int main() {
  std::cin >> t >> q >> st;

  // LEE CADA PREGUNTA Y RECORRE DESDE LA POSICION l HASTA LA r CONTANDO LOS
  // ENCUENTROS
  while (q--) {
    std::cin >> l >> r;

    // LOS ARREGLOS, VECTORES, STRINGS, ETC (estructuras indexadas) EN C++ SON
    // REFERIDAS AL 0 COMO LAS PREGUNTAS IRAN REFERIDAS A 1, ES NECESARIO
    // CORREGIR ESE OFFSET RESTANDOLE UNO TANTO A L COMO A R
    --l;
    --r;

    // INICIALIZA LA CUENTA A 0
    res = 0;

    // COMPARA CADA ELEMENTO CON SU ANTERIOR, ENTONCES SE EMPIEZA DESDE EL
    // SEGUNDO DEL RANGO Y HASTA EL ULTIMO
    for (int i = l + 1; i <= r; ++i) {
      if (st[i] == st[i - 1]) ++res;
    }

    std::cout << res << "\n";
  }
  return 0;
}
