#include <algorithm>
#include <iostream>

int n;

const int MAXN = 502;
char A[MAXN][MAXN], B[MAXN][MAXN];
char aux[MAXN][MAXN];

bool iguales = false;

void compara() {
  bool flag = true;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) flag &= A[i][j] == B[i][j];
  iguales |= flag;
}

void gira90() {
  // copiamos en aux
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) aux[i][j] = A[i][j];
  // Giramos en A
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      A[i][j] = aux[j][n - i - 1];
    }
  }
}

void invierteVert() {
  for (int i = 0; i < n / 2; ++i)
    for (int j = 0; j < n; ++j) std::swap(A[i][j], A[n - i - 1][j]);
}

void invierteHor() {
  for (int j = 0; j < n / 2; ++j)
    for (int i = 0; i < n; ++i) std::swap(A[i][j], A[i][n - j - 1]);
}

int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) std::cin >> A[i][j];

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) std::cin >> B[i][j];

  // Giramos
  for (int t = 0; t < 4; ++t) {
    for (int r = 0; r < 4; ++r) {
      if (r & 1) invierteVert();
      if (r & 2) invierteHor();
      compara();
      if (r & 1) invierteVert();
      if (r & 2) invierteHor();
    }
    gira90();
  }

  std::cout << (iguales ? "IGUALES" : "DIFERENTES") << "\n";

  return 0;
}
