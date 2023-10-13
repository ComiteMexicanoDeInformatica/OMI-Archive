#include <bits/stdc++.h>

#include "rudolph.h"
using namespace std;
// Random Number Generator.
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void Rudolph(int N) {  // Solución oficial.
  int A[N], Ans[N];
  for (int i = 0; i < N; i++) A[i] = i + 1, Ans[i] = -1;
  // fisher-yates-knuth shuffle
  // (mismo algoritmo que std::random_shuffle, pero uso mi propio rng)
  for (int i = 0; i < N - 1; i++) {
    int j = (rng() % (N - i)) + i;
    swap(A[i], A[j]);
  }
  for (int i = 0; i + 1 < N; i += 2) {
    int x = A[i], y = A[i + 1];
    // X es la posición de x en la permutación.
    // Y es la posición de y en la permutación.
    // Z = ~(X^Y).
    int X = 0, Y = 0, Z = 0;
    // compresión de coordenadas.
    int cnt = 0, LOGN = 0;
    map<int, int> cc;
    for (int j = 0; j < N; j++) {
      if (Ans[j] == -1) cc[j];
    }
    for (auto &[a, b] : cc) b = cnt++;
    while (1 << (LOGN + 1) <= cnt) LOGN++;
    // Primeras LOGN queries para determinar Z y los bits que difieren en X y Y.
    for (int k = 0; k <= LOGN; k++) {
      for (auto [a, b] : cc) {
        if ((b >> k) & 1)
          Ans[a] = x;
        else
          Ans[a] = y;
      }
      int aux = similitud(N, Ans) - i;
      if (aux == 2) X ^= 1 << k;
      if (aux == 0) Y ^= 1 << k;
      if (aux == 1) Z ^= 1 << k;
    }
    // Sin perdida de generalidad, Y tiene el bit t encendido.
    if (Y == 0) swap(X, Y), swap(x, y);
    int t = 0;
    for (int k = 0; k <= LOGN; k++) {
      if ((Y >> k) & 1) t = k;
    }
    // Queries sobre los bits que comparten.
    for (int k = 0; k <= LOGN; k++) {
      if (((Z >> k) & 1) == 0) continue;
      for (auto [a, b] : cc) {
        if ((b >> k) & 1)
          Ans[a] = x;
        else if ((b >> t) & 1)
          Ans[a] = x;
        else
          Ans[a] = y;
      }
      int aux = similitud(N, Ans) - i;
      if (aux == 1) X ^= 1 << k, Y ^= 1 << k;
    }
    // reinicializar los valores
    for (auto [a, b] : cc) {
      Ans[a] = -1;
      if (b == X) Ans[a] = x;
      if (b == Y) Ans[a] = y;
    }
  }
  // Si N es impar, hay un valor que no has agregado a la respuesta.
  for (int i = 0; i < N; i++) {
    if (Ans[i] == -1) Ans[i] = A[N - 1];
  }
  localizacion(N, Ans);
}
