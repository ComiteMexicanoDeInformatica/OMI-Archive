#include <iostream>

#include "extremos.h"

int N;
int vals[1005];
int preguntas;
bool solved;
const long double xx = 0.25;

void respuesta(int posMenor, int posMayor) {
  int mn = 1, mx = 1;
  for (int i = 2; i <= N; i++) {
    if (vals[i] < vals[mn]) mn = i;
    if (vals[i] > vals[mx]) mx = i;
  }
  if (posMenor != mn) {
    std::cerr << "Posicion " << posMenor << "no contiene al mínimo\n";
    std::cout << "0\n";
    exit(0);
  }
  if (posMayor != mx) {
    std::cerr << "Posicion " << posMenor << "no contiene al maximo\n";
    std::cout << "0\n";
    exit(0);
  }

  // Es correcto, pero calcula puntos
  std::cerr << "Correcto! Tu programa realizo " << preguntas << " preguntas\n";
  std::cerr << "Tu programa obtendría puntos por este caso :)\n";
  exit(0);
}

bool esMenor(int i, int j) {
  if (i < 1 or i > N) {
    std::cerr << "ERROR: El indice i = " << i
              << " es invalido. No está entre 1 y " << N << "\n";
    std::cout << "0\n";
    exit(0);
  }
  if (j < 1 or j > N) {
    std::cerr << "ERROR: El indice j = " << j
              << " es invalido. No está entre 1 y " << N << "\n";
    std::cout << "0\n";
    exit(0);
  }
  if (i == j) {
    std::cerr << "ERROR: El indice i no puede ser igual al indice j\n";
    std::cout << "0\n";
    exit(0);
  }
  preguntas++;
  if (preguntas > N * N) {
    std::cout << "Preguntas fue llamado más de N^2 veces.\n";
    std::cout << "0\n";
    exit(0);
  }
  return vals[i] < vals[j];
}

int main() {
  std::cin >> N;
  for (int i = 1; i <= N; i++) std::cin >> vals[i];

  buscaExtremos(N);
  return 0;
}
