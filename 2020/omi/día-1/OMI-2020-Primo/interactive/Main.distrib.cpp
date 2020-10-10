#include <math.h>

#include <iostream>

#include "primo.h"

int n, k, perdido;

int primos[10000001];
int llamadas;

int primo(int posicion) {
  llamadas++;

  int r = 0;
  if (posicion >= 0 && posicion < k - 1) {
    r = primos[posicion];
  }

  std::cout << "primo(" << posicion << ")  -> " << r << std::endl;

  return r;
}

int main() {
  std::cin >> n >> k >> perdido;
  for (int i = 0; i < k - 1; i++) {
    std::cin >> primos[i];
  }

  llamadas = 0;

  std::cout << "Llamando a función busca(" << n << ")" << std::endl;

  int respuesta = busca(n);

  std::cout << "Respuesta: " << respuesta << std::endl;

  if (llamadas == 0) {
    std::cout << "Respuesta incorrecta, no se vale adivinar ";
    return 0;
  }

  if (respuesta != perdido) {
    std::cout << "Respuesta incorrecta, se esperaba " << perdido;
    return 0;
  }

  int score = 0;
  if (llamadas <= ceil(log2(k))) {
    score = 100;
  } else if (llamadas <= sqrt(k)) {
    score = 60;
  } else if (llamadas < k) {
    score = 30;
  } else if (llamadas == k) {
    score = 5;
  }

  std::cout << "Respuesta correcta\n";
  std::cout << "Puntaje para este caso " << score << "%" << std::endl;

  return 0;
}
