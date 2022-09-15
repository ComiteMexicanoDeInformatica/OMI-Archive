#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

#define MAX 100000

long long n, d, e, p[MAX + 2];
std::set<std::pair<long long, int> > a;
std::set<std::pair<long long, int> >::iterator inicio, fin;
long long res, cnt, rango, vini, vfin;
long long c, x, punt;

int main() {
  std::cin >> n >> d;
  for (int i = 1; i <= n; ++i) {
    std::cin >> p[i];

    // emplace_hint EN UN SET PERMITE "SUGERIR" AL SET DONDE DEBE IR EL
    // ELEMENTO, LO QUE HACE MAS RAPIDA LA INSERCION COMO LOS ELEMENTOS VIENEN
    // ORDENADOS, DEBEN IR AL FINAL, LO QUE HACE QUE LA INSERCION SEA LINEAL
    a.emplace_hint(a.end(), p[i], i);
  }

  // REALIZA UNA VENTANA DESLIZANTE.
  rango = 2 * d;  // EL ANCHO DE LA VENTANA ES DE 2d

  // PROCESA EXAMEN POR EXAMEN
  std::cin >> e;
  for (int examen = 0; examen <= e; ++examen) {
    res = 0;  // INICIALIZA EL OPTIMO PARA ESTE EXAMEN
    inicio = fin = a.begin();
    cnt = 0;

    // LA PRIMERA VEZ NO LO HAGAS, YA QUE ES EL ARREGLO ORIGINAL
    if (examen) {
      // LEE LOS PUNTAJES QUE CAMBIARON Y ACTUALIZALOS EN EL ARREGLO TESTIGO
      std::cin >> c;
      while (c--) {
        std::cin >> x >> punt;
        // ELIMINA EL VALOR DEL SET Y ACTUALIZALO CON EL NUEVO
        a.erase({p[x], x});
        p[x] = punt;
        a.insert({p[x], x});
      }
    }

    // PROCESA LA VENTANA HASTA QUE EL INICIO HAYA PASADO POR TODAS LAS
    // POSICIONES
    while (inicio != a.end()) {
      vini = (*inicio).first;
      vfin = (fin != a.end()) ? (*fin).first : 4e9;

      // SI SE PUEDE AUMENTAR EL EXTREMO DERECHO DE LA VENTANA, HAZLO YA QUE
      // QUEREMOS LA MAS GRANDE
      if (vfin - vini <= rango) {
        ++fin;
        ++cnt;
      } else {
        // SI NO SE PUEDE CRECER EL EXTREMO DERECHO SIGNIFICA QUE ESTE ES EL
        // LIMITE DE UNA VENTANA HAY QUE REGISTRARLA COMO UN POSIBLE RESULTADO Y
        // MOVER AHORA EL EXTREMO IZQUIERDO HASTA QUE LA VENTANA SEA NUEVAMENTE
        // VALIDA
        res = std::max(
            res, cnt);  // VALIDA SI ESTA VENTANA ES MEJOR QUE LAS QUE TENIAS

        while (inicio != a.end() && vfin - vini > rango) {
          ++inicio;  // MUEVE EL INICIO HASTA QUE LA VENTANA SEA VALIDA
          vini = (*inicio).first;
          --cnt;
        }
      }
    }

    std::cout << res << "\n";
  }

  return 0;
}
