#include <bits/stdc++.h>

#include "rudolph.h"
using namespace std;

void Rudolph(int N) {
  int Aux[N], Ans[N];
  for (int i = 0; i < N; i++) Aux[i] = 2;
  int x;
  for (int i = 0; i < N; i++) {
    Aux[i] = 1;
    int aux = similitud(N, Aux);
    if (aux == 2) Ans[i] = 1, x = i;
    if (aux == 0) Ans[i] = 2;
    Aux[i] = 2;
  }
  for (int i = 3; i <= N; i++) {
    int L = 0, R = N - 1;
    while (L < R) {
      int Mid = (L + R) >> 1;
      for (int j = 0; j < N; j++) {
        if (j <= Mid)
          Aux[j] = i;
        else
          Aux[j] = 1;
      }
      Aux[x] = i;
      int aux = similitud(N, Aux);
      if (aux)
        R = Mid;
      else
        L = Mid + 1;
    }
    Ans[R] = i;
  }
  localizacion(N, Ans);
}
