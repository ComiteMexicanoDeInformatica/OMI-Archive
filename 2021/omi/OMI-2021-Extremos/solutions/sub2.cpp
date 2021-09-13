#include <iostream>
#include <vector>

#include "extremos.h"

void buscaExtremos(int n) {
  int mn = 1, mx = 1;
  for (int i = 2; i <= n; i++) {
    if (esMenor(i, mn)) mn = i;
    if (esMenor(mx, i)) mx = i;
  }

  respuesta(mn, mx);
  return;
}
