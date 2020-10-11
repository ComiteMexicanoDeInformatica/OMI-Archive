#include <stdlib.h>

#include <iostream>

int N, Q;
int puntos_x[1010];
int puntos_y[1010];

int main() {
  // optimizacion de entrada
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  // Lectura de datos
  std::cin >> N >> Q;
  for (int i = 0; i < N; i++) {
    std::cin >> puntos_x[i] >> puntos_y[i];
  }
  int x, y;
  int respuesta = 0;
  for (int i = 0; i < Q; i++) {
    std::cin >> x >> y;
    // iniciar respuesta como maximo
    respuesta = 1000000000;
    // buscar la distancia al punto más cernaco
    for (int j = 0; j < N; j++) {
      respuesta = std::min(
          respuesta, std::max(abs(x - puntos_x[j]), abs(y - puntos_y[j])));
    }
    std::cout << respuesta << "\n";
  }
  return 0;
}