#include <bits/stdc++.h>
using namespace std;
int const Mxn = 3e5 + 1;

int P[Mxn];
int depth[Mxn];
vector<int> g[Mxn];
char letra[Mxn];

void dfs(int node = 1, int parent = 1) {
  P[node] = parent;
  depth[node] = depth[parent] + 1;
  for (auto child : g[node]) {
    if (child != parent) dfs(child, node);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio();
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
    int u, v, cnt = 0;
    string S;
    cin >> u >> v >> S;
    string A = "", B = "";
    while (u != v) {
      if (depth[u] > depth[v]) {
        A += letra[u];
        u = P[u];
      } else {
        B += letra[v];
        v = P[v];
      }
    }
    A += letra[u];
    reverse(B.begin(), B.end());
    for (auto e : B) A += e;
    for (auto e : A) {
      if (cnt < (int)S.size() && e == S[cnt]) cnt++;
    }
    if (cnt == (int)S.size())
      cout << "SI\n";
    else
      cout << "NO\n";
  }
}
