#include <bits/stdc++.h>

#include "rudolph.h"
using namespace std;

void Rudolph(int N) {
  int A[N], Ans[N];
  for (int i = 0; i < N; i++) A[i] = Ans[i] = 1;
  for (int i = 2; i <= N; i++) {
    for (int j = 0; j < N; j++) {
      A[j] = i;
      if (similitud(N, A) == 2) {
        Ans[j] = i, A[j] = 1;
        break;
      }
      A[j] = 1;
    }
  }
  localizacion(N, Ans);
}
