#include <bits/stdc++.h>
using namespace std;

vector<int> V;
int Num_queries = 0;

int similitud(vector<int> A) {
  Num_queries++;
  int cnt = 0;
  int N = (int)A.size();
  for (int i = 0; i < N; i++) {
    cnt += ((V[i] == A[i]) ? 1 : 0);
  }
  return cnt;
}

auto solve1(int N) -> vector<int> {
  Num_queries = 0;
  vector<int> A(N, 1), Ans(N, 1);
  for (int i = 2; i <= N; i++) {
    for (int j = 0; j < N; j++) {
      A[j] = i;
      if (similitud(A) == 2) {
        Ans[j] = i, A[j] = 1;
        break;
      }
      A[j] = 1;
    }
  }
  return Ans;
}

auto solve2(int N) -> vector<int> {
  Num_queries = 0;
  vector<int> Aux(N, 2), Ans(N);
  int x;
  for (int i = 0; i < N; i++) {
    Aux[i] = 1;
    int aux = similitud(Aux);
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
      int aux = similitud(Aux);
      if (aux)
        R = Mid;
      else
        L = Mid + 1;
    }
    Ans[R] = i;
  }

  return Ans;
}

auto solve3(int N) -> vector<int> {
  Num_queries = 0;
  vector<int> Aux(N, 2), Ans(N, -1);

  for (int i = 0; i < N; i++) {
    Aux[i] = 1;
    int aux = similitud(Aux);
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
      int aux = similitud(Ans) - i + 1;
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

  return Ans;
}

// Random Number Generator. Mersenne Twister.
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

auto solve(int N) -> vector<int> {  // Solución oficial.
  vector<int> Ans(N, -1);
  Num_queries = 0;
  // fisher-yates-knuth shuffle
  // (mismo algoritmo que std::random_shuffle, pero uso mi propio rng)
  vector<int> A(N);
  iota(A.begin(), A.end(), 1);
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

    // compresion de coordenadas
    int cnt = 0, LOGN = 0;
    map<int, int> cc;
    for (int j = 0; j < N; j++) {
      if (Ans[j] == -1) cc[j];
    }
    for (auto &[a, b] : cc) b = cnt++;

    while (1 << (LOGN + 1) <= cnt) LOGN++;

    // Primeras LOGN queries.
    for (int k = 0; k <= LOGN; k++) {
      for (auto [a, b] : cc) {
        if ((b >> k) & 1)
          Ans[a] = x;
        else
          Ans[a] = y;
      }
      int aux = similitud(Ans) - i;
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
      int aux = similitud(Ans) - i;
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
  // localizacion(Ans);
  return Ans;
}

void generate_case(int N, int Subtask_num) {
  if (Subtask_num == 1) {
    N = (rng() % 100) + 1;
  }
  V.resize(N);
  iota(V.begin(), V.end(), 1);
  for (int i = 0; i < N - 1; i++) {
    int j = (rng() % (N - i)) + i;
    swap(V[i], V[j]);
  }
  int L, R;
  if (Subtask_num == 1) {
    solve1(N);
    L = R = Num_queries;
  }
  if (Subtask_num == 2) {
    solve2(N);
    L = R = Num_queries;
  }
  if (Subtask_num == 3) {
    solve3(N);
    L = R = Num_queries;
  }
  if (Subtask_num == 4) {
    solve3(N);
    R = Num_queries;
    L = 1e9;
    for (int i = 0; i < 10; i++) {
      solve(N);
      L = max(Num_queries, L);
    }
  }
  cout << N << " " << L << " " << R << endl;
  for (int i = 0; i < N - 1; i++) {
    cout << V[i] << " ";
  }
  cout << V[N - 1] << endl;
}

int main() {
  int Subtask_num;
  cin >> Subtask_num;
  generate_case(4096, Subtask_num);
}
