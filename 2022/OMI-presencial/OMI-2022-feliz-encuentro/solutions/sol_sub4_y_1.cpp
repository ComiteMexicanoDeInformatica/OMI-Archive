#include <iostream>
#include <set>

using namespace std;

#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << "\n";

#define MAX 100000

#define fin first
#define inicio second

int t, q, l, r, res;
string st;
std::set<std::pair<int, int> > rangos;

int main() {
  std::cin >> t >> q >> st;

  // HAZ UNA LISTA DE RANGOS DE CARACTERES IGUALES
  st += '*';  // SE AGREGA UN * AL FINAL PARA USAR COMO MARCADAOR DE FINAL
  l = r = 0;
  for (int i = 1; i <= t; ++i) {
    if (st[i] == st[i - 1])
      ++r;  // SI ESTE CARACTER ES IGUAL AL ANTERIOR, AUMENTA EL RANGO
    else {
      // AGREGA EL RANGO SIEMPRE Y CUANDO SEA MAYOR QUE 1, LOS DE 1 NO TIENEN
      // ENCUENTROS Y NO HACE SENTIDO AGREGARLOS
      if (l != r) rangos.emplace_hint(rangos.end(), r, l);
      l = r = i;
    }
  }

  // PARA CADA PREGUNTA BUSCA LOS RANGOS DONDE SE CRUZA.
  // DEBIDO A LAS RESTRICCIONES DEL SUBTASK, A LO MAS LA BUSQUEDA PASARA POR 100
  // RANGOS
  while (q--) {
    std::cin >> l >> r;
    --l;
    --r;
    res = 0;

    // BUSCA EL PRIMER RANGO CUYO FINAL ESTE DESPUES (O IGUAL) QUE EL INICIO DE
    // LA PREGUNTA.
    auto it = rangos.lower_bound({l, 0});
    while (it != rangos.end()) {
      // EL NUMERO DE FELICES ENCUENTROS DE ESTE RANGO ES IGUAL AL TAMAÑO DE LA
      // INTERSECION ENTRE EL RANGO Y LA PREGUNTA MENOS UNO.
      int interseccion = min((*it).fin, r) - max((*it).inicio, l) + 1;
      if (interseccion > 0) res += interseccion - 1;

      // AVANZA AL SIGUIENTE RANGO
      it++;

      // SI YA SE PASA DE LA PREGUNTA, TERMINA
      if ((*it).inicio > r) break;
    }
    std::cout << res << "\n";
  }
  return 0;
}
