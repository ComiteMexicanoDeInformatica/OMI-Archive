#include "primo.h"

// Main
//	int primo(int posicion)

bool esPrimo(int x) {
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return false;
  return true;
}

int busca(int n) {
  int pos = 0;
  for (int i = 2; i <= n; i++) {
    if (!esPrimo(i)) continue;
    int x = primo(pos);
    if (x != i) return i;
    pos++;
  }
}