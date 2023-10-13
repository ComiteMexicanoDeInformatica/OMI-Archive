#include <bits/stdc++.h>

#include "rudolph.h"

void y_Rudolph(int N) {
  std::vector<int> sol(N, 1);
  for (int i = 0; i < N; ++i) {
    int mejor_arg = 0;
    int mejor = -1;
    for (int k = 1; k <= N; ++k) {
      sol[i] = k;
      int iguales = similitud(&sol[0]);
      if (iguales > mejor) {
        mejor_arg = k;
        mejor = iguales;
      } else if (iguales < mejor) {
        break;
      }
    }
    sol[i] = mejor_arg;
  }
  for (int a : sol) {
    std::cerr << a;
  }
  std::cerr << "\n";
  localizacion(&sol[0]);
}
