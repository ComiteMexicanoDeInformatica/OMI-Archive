#include <bits/stdc++.h>

#include "rudolph.h"
using namespace std;

void Rudolph(int N) {
  int Aux[N], Ans[N];
  for (int i = 0; i < N; i++) Aux[i] = 2, Ans[i] = -1;

  for (int i = 0; i < N; i++) {
    Aux[i] = 1;
    int aux = similitud(N, Aux);
    if (aux == 2) Ans[i] = 1;
    if (aux == 0) Ans[i] = 2;
    Aux[i] = 2;
  }

  for (int i = 3; i <= N; i++) {
    int cnt = 0;
    map<int, int> cc;
    for (int j = 0; j < N; j++) {
      if (Ans[j] == -1) cc[j];
    }
    for (auto &[a, b] : cc) b = cnt++;
    int L = 0, R = cnt - 1;
    while (L < R) {
      int Mid = (L + R) >> 1;
      for (auto [a, b] : cc) {
        if (b <= Mid)
          Ans[a] = i;
        else
          Ans[a] = 1;
      }
      int aux = similitud(N, Ans) - i + 1;
      if (aux)
        R = Mid;
      else
        L = Mid + 1;
    }
    for (auto [a, b] : cc) {
      Ans[a] = -1;
      if (b == R) Ans[a] = i;
    }
  }
  localizacion(N, Ans);
}
