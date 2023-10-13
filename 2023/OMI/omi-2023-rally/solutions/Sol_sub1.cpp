#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)(a.size())
const int Mxn = 3e5 + 1;

vector<int> g[Mxn];
char letra[Mxn];

vector<char> V;
string S;

void dfs(int node, int v, int parent = 0) {
  V.push_back(letra[node]);
  if (node == v) {
    S = "";
    for (auto e : V) S += e;
  }
  for (auto child : g[node]) {
    if (child == parent) continue;
    dfs(child, v, node);
  }
  V.pop_back();
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  if (n > 1000) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) cin >> letra[i];
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    string T;
    cin >> T;
    int cnt = 0;
    dfs(x, y);
    for (auto e : S) {
      if (cnt < sz(T) && e == T[cnt]) cnt++;
    }
    if (cnt == sz(T))
      cout << "SI" << '\n';
    else
      cout << "NO" << '\n';
  }
}
