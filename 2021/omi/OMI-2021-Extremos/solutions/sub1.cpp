#include <iostream>
#include <vector>

#include "extremos.h"

void buscaExtremos(int n) {
  std::vector<int> ord(n);
  for (int i = 0; i < n; i++) ord[i] = i + 1;

  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (esMenor(ord[j], ord[i])) std::swap(ord[j], ord[i]);
  respuesta(ord[0], ord[n - 1]);
  return;
}
