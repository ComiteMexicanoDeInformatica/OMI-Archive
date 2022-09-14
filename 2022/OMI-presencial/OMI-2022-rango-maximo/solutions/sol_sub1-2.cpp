#include <iostream>

using namespace std;

#define MAX 100000

long long n, d, e, a[MAX + 2];
long long res, cnt, inicio, fin, rango;

int main() {
  std::cin >> n >> d;
  for (int i = 1; i <= n; ++i) std::cin >> a[i];

  std::cin >> e;

  // REALIZA UNA VENTANA DESLIZANTE.
  rango = 2 * d;  // EL ANCHO DE LA VENTANA ES DE 2d
  inicio = fin = 1;

  // PARA FACILITAR LA IMPLEMENTACION, SE PUEDE PONER UN VALOR MUY GRANDE EN LA
  // POSICION n + 1 PARA EVITAR TENER QUE ESTAR VALIDANDO POR EL FINAL DE LA
  // VENTANA.
  a[n + 1] = 4e9;

  // PROCESA LA VENTANA HASTA QUE EL INICIO HAYA PASADO POR TODAS LAS POSICIONES
  while (inicio <= n) {
    // SI SE PUEDE AUMENTAR EL EXTREMO DERECHO DE LA VENTANA, HAZLO YA QUE
    // QUEREMOS LA MAS GRANDE
    if (a[fin] - a[inicio] <= rango)
      ++fin;
    else {
      // SI NO SE PUEDE CRECER EL EXTREMO DERECHO SIGNIFICA QUE ESTE ES EL
      // LIMITE DE UNA VENTANA HAY QUE REGISTRARLA COMO UN POSIBLE RESULTADO Y
      // MOVER AHORA EL EXTREMO IZQUIERDO HASTA QUE LA VENTANA SEA NUEVAMENTE
      // VALIDA
      res = std::max(
          res,
          fin - inicio);  // VALIDA SI ESTA VENTANA ES MEJOR QUE LAS QUE TENIAS

      while (a[fin] - a[inicio] > rango)
        ++inicio;  // MUEVE EL INICIO HASTA QUE LA VENTANA SEA VALIDA
    }
  }

  std::cout << res << "\n";

  return 0;
}
