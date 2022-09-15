#include <algorithm>
#include <deque>
#include <iostream>
#include <stack>
#include <vector>

#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << "\n";

#define MAX 1000000

int n, q, a, b, edad;
int vivos[MAX + 2], joven[MAX + 2], viejo[MAX + 2];

int main() {
  // LEE LA ENTRADA
  std::cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a >> b;

    // EL CONTROL DE VIVOS SE LLEVA MARCANDO LOS INCIOS Y
    // FINES DE CADA INTERVALO CON UN +1 AL INICIO Y UN -1 AL FINAL
    ++vivos[a];
    --vivos[b + 1];  // SE DISMINUYE b + 1 PORQUE EN b TODAVIA ESTA VIVO

    // PARA LLEVAR EL CONTROL DE JOVENES SE MARCAN LOS ANIOS EN LOS QUE
    // NACIO ALGUIEN Y SE GUARDA SU ANIO DE FALLECIMIENTO.  POSTERIORMENTE
    // SE RECORRE EL INTERVALO COMPLETO CON UN STACK.
    // PARA LOS VIEJOS SE USA UN DEQUEUE
    joven[a] = std::max(joven[a], b);  // SI DOS PERSONAS NACEN EL MISMO ANIO
                                       // QUEDATE EL QUE VIVE MAS
  }

  // HAZ EL CONTROL DE VIVOS
  for (int i = 1; i <= MAX; ++i) vivos[i] += vivos[i - 1];

  std::stack<std::pair<int, int> > jovenes;
  std::deque<std::pair<int, int> > viejos;
  for (int i = 1; i <= MAX; ++i) {
    // INSERTA LA PERSONA VIVA EN EL STACK Y EL DEQUEUE
    if (joven[i]) {
      jovenes.push({i, joven[i]});
      viejos.push_back({i, joven[i]});
    }

    // ACTUALIZA LA PERSONA MAS JOVEN EN ESTE ANIO
    while (!jovenes.empty() && jovenes.top().second < i) jovenes.pop();
    if (!jovenes.empty())
      joven[i] = i - jovenes.top().first;
    else
      joven[i] = 0;

    // ACTUALIZA LA PERSONA MAS VIEJA ESE ANIO
    while (!viejos.empty() && viejos.front().second < i) viejos.pop_front();
    if (!viejos.empty()) viejo[i] = i - viejos.front().first;
  }

  // PARA CADA QUERY, CONTESTA CON LOS VALORES QUE PRECALCULASTE
  for (int i = 1; i <= q; ++i) {
    std::cin >> a;
    std::cout << vivos[a] << " " << joven[a] << " " << viejo[a] << "\n";
  }

  return 0;
}
