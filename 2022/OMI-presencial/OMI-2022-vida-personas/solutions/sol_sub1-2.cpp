#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << "\n";

#define MAX 100000

int n, q, a, b, edad;
int vivos[MAX + 2], joven[MAX + 2], viejo[MAX + 2];

int main() {
  // INICIALIZA LOS JOVENES
  for(int i = 1; i <= MAX; ++i) joven[i] = MAX + 1;

  // LEE LA ENTRADA
  std::cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a >> b;

    // RECORRE EL INTERVALO DE ANIOS DE CADA PERSONA LLEVANDO
    // LA CUENTA DE SU EDAD Y ACTUALIZANDO, PARA CADA ANIO,
    // LA CANTIDAD DE PERSONAS VIVAS, LA MAS JOVEN Y LA MAS VIEJA
    edad = 0;
    for(int j = a; j <= b; ++j){
        ++vivos[j]; // INCREMENTA LOS VIVOS ESE ANIO

        // ACTUALIZA EL MAS JOVEN VIVO ESTE ANIO
        if (joven[j] <= MAX) joven[j] = std::min(joven[j], edad);
        else joven[j] = edad;

        // ACTUALIZA EL MAS VIEJO VIVO ESTE ANIO
        viejo[j] = std::max(viejo[j], edad);

        ++edad; // AUMENTA LA EDAD DE LA PERSONA
    }
  }

  // LOS QUE NO TUVIERON PERSONA JOVEN, PONLOS EN CERO
  for(int i = 1; i <= MAX; ++i) if (joven[i] == MAX + 1) joven[i] = 0;

  // PARA CADA QUERY, CONTESTA CON LOS VALORES QUE PRECALCULASTE
  for (int i = 1; i <= q; ++i) {
    std::cin >> a;
    std::cout << vivos[a] << " " << joven[a] << " " << viejo[a] << "\n";
  }

  return 0;
}
