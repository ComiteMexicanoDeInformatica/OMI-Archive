#include <bits/stdc++.h>
using namespace std;

struct caso {
  int n, q;
  string S;
  vector<array<int, 2>> Edges, Queries;
  vector<string> Palabras;
  void print() {
    cout << n << " " << q << '\n';
    cout << S << endl;
    for (auto [u, v] : Edges) {
      cout << u << " " << v << '\n';
    }
    for (int i = 0; i < q; i++) {
      auto [u, v] = Queries[i];
      cout << u << " " << v << " " << Palabras[i] << '\n';
    }
  }
};

namespace casos_random {

// random number generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Códigos de Prüfer para generar árboles aleatorios.
auto Prufer(int n) -> vector<array<int, 2>> {
  vector<array<int, 2>> Edges;
  vector<int> V(n - 2);
  for (int i = 0; i < n - 2; i++) V[i] = (rng() % n) + 1;
  priority_queue<int> Q;
  vector<int> freq(n + 1, 0);
  for (int i = 0; i < n - 2; i++) freq[V[i]]++;
  for (int i = 1; i <= n; i++)
    if (!freq[i]) Q.push(i);
  for (int i = 0; i < n - 2; i++) {
    Edges.push_back({V[i], Q.top()});
    Q.pop();
    if (--freq[V[i]] == 0) Q.push(V[i]);
  }
  int u = Q.top();
  Q.pop();
  int v = Q.top();
  Edges.push_back({u, v});
  return Edges;
}

auto generate_case(int n, int q, int s) -> caso {
  // Genera un caso aleatorio con un árbol de n nodos, q preguntas
  // y la suma de las palabras en las preguntas es a lo más s + q.
  caso C;
  C.n = n, C.q = q;
  C.Edges = Prufer(n);
  for (int i = 0; i < n; i++) {
    C.S += (char)('a' + (rng() % 26));
  }
  for (int i = 0; i < q; i++) {
    int u = (rng() % n) + 1, v = (rng() % n) + 1;
    if (u == v) v = (v == n) ? 1 : v + 1;
    C.Queries.push_back({(rng() % n) + 1, (rng() % n) + 1});
  }
  // s = max(1, s - q);
  for (int i = 0; i < q; i++) {
    int k = (rng() % s);
    string Cadena = "";
    for (int j = 0; j <= k; j++) {
      Cadena += (char)('a' + (rng() % 26));
    }
    C.Palabras.push_back(Cadena);
    s -= k;
  }
  return C;
}

int rngm(int x) { return (rng() % 4 != 0) ? x : (rng() % (x - 1)) + 2; }

auto make_case(int subtask_number)
    -> caso {  // Crea un caso para una subtask en particular.
  const int MXN = 3e5, Mxn = 1e5, mxn = 1e3;
  if (subtask_number == 1) {
    return generate_case(rngm(mxn), rngm(mxn), rngm(mxn));
  }
  if (subtask_number == 2) {
    caso C = generate_case(rngm(Mxn), rngm(Mxn), rngm(Mxn));
    array<int, 2> aux = {(rng() % C.n) + 1, (rng() % C.n) + 1};
    for (auto &x : C.Queries) x = aux;
    return C;
  }
  if (subtask_number == 3) {
    caso C = generate_case(rngm(Mxn), rngm(Mxn), rngm(Mxn));
    for (int i = 0; i < C.n - 1; i++) {
      C.Edges[i] = {i + 1, i + 2};
    }
    return C;
  }
  if (subtask_number == 4) {
    return generate_case(rngm(Mxn), rngm(Mxn), rngm(Mxn));
  }
  return generate_case(rngm(MXN), rngm(MXN), rngm(MXN));
}

}  // namespace casos_random

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int subtask_number;
  cin >> subtask_number;
  caso C = casos_random::make_case(subtask_number);
  C.print();
}
