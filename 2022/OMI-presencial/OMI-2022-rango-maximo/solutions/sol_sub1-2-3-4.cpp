#include <algorithm>
#include <iostream>
#include <set>

#define MAX 100000

long long n, d, e, p[MAX + 2], nuevo[MAX + 2];
long long res, cnt, rango, inicio, fin, vini, vfin;
long long c, x, punt;

int main() {
  std::cin >> n >> d;
  for (int i = 1; i <= n; ++i) std::cin >> p[i];

  // REALIZA UNA VENTANA DESLIZANTE.
  rango = 2 * d;  // EL ANCHO DE LA VENTANA ES DE 2d

  // PROCESA EXAMEN POR EXAMEN
  std::cin >> e;
  for (int examen = 0; examen <= e; ++examen) {
    res = 0;  // INICIALIZA EL OPTIMO PARA ESTE EXAMEN
    cnt = 0;

    // LA PRIMERA VEZ NO LO HAGAS, YA QUE ES EL ARREGLO ORIGINAL
    if (examen) {
      // LEE LOS PUNTAJES QUE CAMBIARON Y ACTUALIZALOS EN EL ARREGLO TESTIGO
      std::cin >> c;
      while (c--) {
        std::cin >> x >> punt;
        p[x] = punt;
      }
    }

    // COPIA LOS PUNTAJES AL ARREGLO DE REVISION Y ORDENALO
    for(int i = 1; i <= n; ++i) nuevo[i] = p[i];
    std::sort(nuevo + 1, nuevo + 1 + n);
    nuevo[n + 1] = 2e9;

    // PROCESA LA VENTANA HASTA QUE EL INICIO HAYA PASADO POR TODAS LAS
    // POSICIONES
    inicio = fin = 1;
    while (inicio <= n) {
      // SI SE PUEDE AUMENTAR EL EXTREMO DERECHO DE LA VENTANA, HAZLO YA QUE
      // QUEREMOS LA MAS GRANDE
      if (nuevo[fin] - nuevo[inicio] <= rango) {
        ++fin;
        ++cnt;
      } else {
        // SI NO SE PUEDE CRECER EL EXTREMO DERECHO SIGNIFICA QUE ESTE ES EL
        // LIMITE DE UNA VENTANA HAY QUE REGISTRARLA COMO UN POSIBLE RESULTADO Y
        // MOVER AHORA EL EXTREMO IZQUIERDO HASTA QUE LA VENTANA SEA NUEVAMENTE
        // VALIDA
        res = std::max(
            res, cnt);  // VALIDA SI ESTA VENTANA ES MEJOR QUE LAS QUE TENIAS

        while (inicio <= n && nuevo[fin] - nuevo[inicio] > rango) {
          ++inicio;  // MUEVE EL INICIO HASTA QUE LA VENTANA SEA VALIDA
          --cnt;
        }
      }
    }

    std::cout << res << "\n";
  }

  return 0;
}
