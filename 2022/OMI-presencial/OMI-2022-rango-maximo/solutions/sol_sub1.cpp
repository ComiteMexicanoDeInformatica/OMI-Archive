#include <iostream>

using namespace std;

#define MAX 100000

int n, d, e, a[MAX + 2];
int res, cnt, minimo, maximo;

int main() {
  std::cin >> n >> d;
  for (int i = 1; i <= n; ++i) std::cin >> a[i];

  std::cin >> e;

  // VALIDA TODOS LOS POSIBLES PUNTAJES
  for (int puntaje = 1; puntaje <= 1000; ++puntaje) {
    // PARA CADA PUNTAJE REVISA CUANTOS ELEMENTOS HAY DENTRO DEL RANGO PERMITIDO
    cnt = 0;
    minimo = puntaje - d;
    maximo = puntaje + d;
    for (int i = 1; i <= n; ++i) {
      // SI EL PUNTAJE ESTA EN EL RANGO, AUMENTA LA CUENTA.
      if (a[i] >= minimo && a[i] <= maximo) ++cnt;
    }

    // QUEDATE CON EL MAXIMO QUE ENCUENTRES.
    res = std::max(res, cnt);
  }

  std::cout << res << "\n";

  return 0;
}
