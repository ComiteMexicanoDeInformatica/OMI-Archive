#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)(a.size())
int const Mxn = 3e5 + 1;

vector<int> g[Mxn];

string S[2];
int jump[2][26][Mxn];

void build() {
  for (int i = 0; i < 26; i++) jump[0][i][sz(S[0]) - 1] = -1;
  for (int i = sz(S[0]) - 2; i >= 0; i--) {
    for (int j = 0; j < 26; j++) jump[0][j][i] = jump[0][j][i + 1];
    jump[0][S[0][i + 1] - 'a'][i] = i + 1;
  }
  for (int i = 0; i < 26; i++) jump[1][i][sz(S[1]) - 1] = -1;
  for (int i = sz(S[1]) - 2; i >= 0; i--) {
    for (int j = 0; j < 26; j++) jump[1][j][i] = jump[1][j][i + 1];
    jump[1][S[1][i + 1] - 'a'][i] = i + 1;
  }
}

bool query(int u, int v, string T, int x) {
  int cnt = (S[x][u] == T[0]) ? 1 : 0, curr = u;
  while (cnt < sz(T) && jump[x][T[cnt] - 'a'][curr] != -1 &&
         jump[x][T[cnt] - 'a'][curr] <= v) {
    curr = jump[x][T[cnt] - 'a'][curr];
    cnt++;
  }
  return (cnt == sz(T));
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q >> S[0];
  S[1] = S[0];
  reverse(S[1].begin(), S[1].end());
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  build();

  while (q--) {
    cout << endl;
    int u, v, x = 0;
    cin >> u >> v;
    string T;
    cin >> T;
    u--, v--;
    if (u > v) {
      u = sz(S[0]) - u - 1;
      v = sz(S[0]) - v - 1;
      x = 1;
    }
    if (query(u, v, T, x))
      cout << "SI" << '\n';
    else
      cout << "NO" << '\n';
  }
}
