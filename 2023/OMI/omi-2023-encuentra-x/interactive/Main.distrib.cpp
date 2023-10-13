#include <iostream>

#include "encuentrax.h"

int N, X, K, cnt = 0;

int V[1000001];

int pregunta(int pos) {
  cnt++;
  if (pos < 1 || pos > N) {
    std::cerr << "ERROR: El indice pos = " << pos
              << " es invalido. No está entre 1 y " << N << "\n";
    std::cout << "0\n";
    exit(0);
  }

  if (cnt > K) {
    std::cerr << "ERROR: Tu programa ha realizado mas de K = " << K
              << "preguntas\n";
    std::cout << "0\n";
    exit(0);
  }
  return V[pos];
}

void posicion(int pos) {
  if (pos < 1 || pos > N || cnt > K) {
    std::cerr << "ERROR: El indice de la posicion de X (" << pos
              << ") es invalido\n";
    std::cout << "0\n";
  } else if (V[pos] != X) {
    std::cerr << "INCORRECTO: El numero X = " << X
              << " no esta en la posicion que reportas. "
              << "pos = " << pos;
    std::cout << "0\n";
  } else {
    std::cerr << "POSICION DE X CORRECTA!\n";
    std::cerr << "Tu programa hizo " << cnt << " preguntas\n";
    std::cout << "1\n";
  }
}

int main() {
  std::cin >> N >> X >> K;

  for (int i = 1; i <= N; i++) {
    std::cin >> V[i];
  }

  encuentra(N, X, K);
}
