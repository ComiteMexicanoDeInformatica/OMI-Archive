#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)(a.size())
const int Mxn = 3e5 + 1;
const int LOGN = 18;

vector<int> g[Mxn];
int jump[26][Mxn];
int ST[LOGN + 1][Mxn];
int depth[Mxn];
int tin[Mxn], tout[Mxn];
char letra[Mxn];
int cnt = 0;

void dfs(int node = 1, int parent = 1) {
  for (int i = 0; i < 26; i++) {
    jump[i][node] = jump[i][parent];
  }
  if (node != 1) jump[(int)(letra[parent] - 'a')][node] = parent;

  depth[node] = depth[parent] + 1;
  ST[0][node] = parent;
  for (int i = 1; i <= LOGN; i++) {
    ST[i][node] = ST[i - 1][ST[i - 1][node]];
  }

  tin[node] = cnt++;
  for (auto child : g[node]) {
    if (child != parent) dfs(child, node);
  }
  tout[node] = cnt++;
}

int LCA(int A, int B) {
  if (depth[A] < depth[B]) swap(A, B);
  for (int i = 0; i <= LOGN; i++) {
    if (((depth[A] - depth[B]) >> i) & 1) A = ST[i][A];
  }
  if (A == B) return A;
  for (int i = LOGN; i >= 0; i--) {
    if (ST[i][A] != ST[i][B]) A = ST[i][A], B = ST[i][B];
  }
  return ST[0][A];
}

bool es_ancestro(int A, int B) {
  return (tin[A] <= tin[B] && tout[B] <= tout[A]);
}

int Can(int u, int v, string& S) {
  int x = (letra[u] == S[0] && !es_ancestro(u, v)) ? 1 : 0, curr = u;

  while (x < sz(S) && jump[(int)(S[x] - 'a')][curr] != -1) {
    if (es_ancestro(jump[(int)(S[x] - 'a')][curr], v)) return x;
    curr = jump[(int)(S[x] - 'a')][curr];
    x++;
  }

  return x;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int i = 0; i < 26; i++) {
    jump[i][1] = -1;
  }
  depth[1] = 0;

  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> letra[i];
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs();
  while (q--) {
    int u, v;
    string S;
    cin >> u >> v >> S;
    string T = S;
    reverse(T.begin(), T.end());
    int a = Can(u, v, S), b = Can(v, u, T);
    if (a + b >= sz(S))
      cout << "SI\n";
    else if (a + b == sz(S) - 1 && letra[LCA(u, v)] == S[a])
      cout << "SI\n";
    else
      cout << "NO\n";
  }
}
