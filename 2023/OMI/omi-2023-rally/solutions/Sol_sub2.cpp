#include <bits/stdc++.h>
using namespace std;
int const Mxn = 3e5 + 1;
#define sz(a) (int)(a.size())

vector<int> g[Mxn];
char letra[Mxn];

vector<char> V;
string S;
int jump[26][Mxn];

void dfs(int node, int v, int parent = 0) {
  V.push_back(letra[node]);
  if (node == v) {
    S = "";
    for (auto e : V) S += e;
  }
  for (auto child : g[node]) {
    if (child != parent) dfs(child, v, node);
  }
  V.pop_back();
}

void build() {
  for (int i = 0; i < 26; i++) jump[i][sz(S) - 1] = -1;
  for (int i = sz(S) - 2; i >= 0; i--) {
    for (int j = 0; j < 26; j++) jump[j][i] = jump[j][i + 1];
    jump[(int)(S[i + 1] - 'a')][i] = i + 1;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
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
    if (S.size() == 0) dfs(x, y), build();

    int cnt = (S[0] == T[0]) ? 1 : 0, curr = 0;
    while (cnt < sz(T) && jump[(int)(T[cnt] - 'a')][curr] != -1) {
      curr = jump[(int)(T[cnt] - 'a')][curr];
      cnt++;
    }
    if (cnt == sz(T))
      cout << "SI" << '\n';
    else
      cout << "NO" << '\n';
  }
}
