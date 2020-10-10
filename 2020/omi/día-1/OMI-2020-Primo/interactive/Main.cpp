#include <math.h>
#include <stdio.h>
#include <string.h>

#include <iostream>
#include <vector>

#include "primo.h"

int n, x;
int xmin, xmax;
std::vector<int> primos;
int llamadas;

int primo(int posicion) {
  llamadas++;

  if (posicion < 0 || posicion >= primos.size()) {
    return 0;
  }

  if (posicion < xmin) {
    return primos[posicion];
  } else if (posicion >= xmax) {
    return primos[posicion + 1];
  } else {
    if ((posicion - xmin + 1) <= (xmax - posicion - 1)) {
      xmin = posicion + 1;
      return primos[posicion];
    } else {
      xmax = posicion;
      return primos[posicion + 1];
    }
  }
}

void SieveOfEratosthenes() {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));

  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) {
        prime[i] = false;
      }
    }
  }

  for (int p = 2; p <= n; p++) {
    if (prime[p]) {
      primos.push_back(p);
    }
  }
}

int main() {
  std::cin >> n >> x;
  llamadas = 0;
  float score = 0;
  int size;

  SieveOfEratosthenes();

  size = primos.size();

  if (x == -1) {
    xmin = 0;
    xmax = size;
  } else {
    xmin = xmax = x % size;
  }

  int respuesta = busca(n);

  if (llamadas > 0 && respuesta == primos[xmin]) {
    if (llamadas <= ceil(log2(size))) {
      score = 1;
    } else if (llamadas <= sqrt(size)) {
      score = 0.60;
    } else if (llamadas < size) {
      score = 0.30;
    } else if (llamadas == size) {
      score = 0.05;
    }
  }

  printf("%.2f\n", score);

  return 0;
}
