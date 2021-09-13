#include <iostream>
#include <vector>

#include "extremos.h"

void buscaExtremos(int n) {
  std::vector<int> mins, maxs;
  for (int i = 1; i + 1 <= n; i += 2) {
    if (esMenor(i, i + 1)) {
      mins.push_back(i);
      maxs.push_back(i + 1);
    } else {
      mins.push_back(i + 1);
      maxs.push_back(i);
    }
  }
  if (n % 2 != 0) {
    mins.push_back(n);
    maxs.push_back(n);
  }

  int mn = mins[0];
  for (int i = 1; i < mins.size(); i++)
    if (esMenor(mins[i], mn)) mn = mins[i];

  int mx = maxs[0];
  for (int i = 1; i < maxs.size(); i++)
    if (esMenor(mx, maxs[i])) mx = maxs[i];

  respuesta(mn, mx);
  return;
}
