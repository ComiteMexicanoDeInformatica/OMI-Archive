#include <bits/stdc++.h>
using namespace std;

struct Caso {
  int N, M, Q;
  vector<vector<int>> Grid;
  vector<array<int, 4>> Queries;
  auto print() {
    cout << N << " " << M << '\n';
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cout << ((Grid[i][j]) ? '.' : '#');
      }
      cout << '\n';
    }
    cout << Q << '\n';
    for (auto [a, b, c, d] : Queries) {
      cout << a << " " << b << " " << c << " " << d << '\n';
    }
  }
};

// Random Number Generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Agrega ruido a la matriz.
auto AddNoise(vector<vector<int>>& Grid, int N, int M, int p) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if ((rng() % p) == 0) Grid[i][j] ^= 1;
    }
  }
}

// Escala la matriz a un nuevo tamaño.
auto Escale(vector<vector<int>>& Grid, int N, int M, int newN, int newM)
    -> vector<vector<int>> {
  int deltaN = (newN + N) / N, deltaM = (newM + M) / M;
  vector<vector<int>> newGrid(newN, vector<int>(newM));
  for (int i = 0; i < newN; i++) {
    for (int j = 0; j < newM; j++) {
      newGrid[i][j] = Grid[i / deltaN][j / deltaM];
    }
  }
  return newGrid;
}

// Genera un Caso.
auto GenerateCase(int N, int M, int smallN, int smallM, int Q, int p1, int p2)
    -> Caso {
  Caso C;
  C.N = N, C.M = M, C.Q = Q;
  C.Grid = vector<vector<int>>(smallN, vector<int>(smallM, 1));
  AddNoise(C.Grid, smallN, smallM, p1);
  C.Grid = Escale(C.Grid, smallN, smallM, N, M);
  AddNoise(C.Grid, N, M, p2);

  for (int i = 0; i < Q; i++) {
    int a = rng() % N + 1;
    int b = rng() % M + 1;
    int c = rng() % N + 1;
    int d = rng() % M + 1;
    C.Queries.push_back({a, b, c, d});
  }
  return C;
}

auto GenerateBySubtask(int SubtaskNum) -> Caso {
  if (SubtaskNum == 1) {
    Caso C = GenerateCase(20, 20, rng() % 20 + 1, rng() % 20 + 1, 20,
                          rng() % 10 + 1, rng() % 10 + 1);
    return C;
  }
  if (SubtaskNum == 2) {
    Caso C = GenerateCase(500, 500, rng() % 500 + 1, rng() % 500 + 1, 1,
                          rng() % 10 + 1, rng() % 10 + 1);
    return C;
  }
  if (SubtaskNum == 3) {
    Caso C = GenerateCase(100, 100, rng() % 100 + 1, rng() % 100 + 1, 30000,
                          rng() % 10 + 1, rng() % 10 + 1);
    return C;
  }
  assert(SubtaskNum == 4);
  Caso C = GenerateCase(500, 500, rng() % 500 + 1, rng() % 500 + 1, 30000,
                        rng() % 10 + 1, rng() % 10 + 1);
  return C;
}

int main() {
  int SubtaskNum;
  cin >> SubtaskNum;
  Caso C = GenerateBySubtask(SubtaskNum);
  C.print();
}
