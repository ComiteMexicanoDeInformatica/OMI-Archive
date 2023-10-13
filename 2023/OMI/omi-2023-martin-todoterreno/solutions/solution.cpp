#include <bits/stdc++.h>
using namespace std;
int dp[505][505];
int siguiente[505][505];
vector<pair<int, int>> p[505];
pair<int, int> querys[2][30005];
int res[30005];
int fada[250000];
int v[503][503];
int padre(int a) {
  if (fada[a] == a) return a;
  return (fada[a] = padre(fada[a]));
}
void unir(int a, int b) {
  fada[padre(b)] = padre(a);
  return;
}
int c = 0;
int k = 0;
void f(int x, int y, int T) {
  if (max(dp[x + 1][y], max(dp[x][y + 1], dp[x + 1][y + 1])) >= T + 1) return;
  k++;
  for (int i = x; i > x - T; i--) {
    int Y = y;
    if (v[i][y] != 0) {
      unir(v[i][y], k);
      Y = siguiente[i][y];
    }
    for (int j = Y; j > y - T; j--) {
      if (v[i][j] != 0) {
        unir(v[i][j], k);
        break;
      }
      siguiente[i][j] = y - T;
      v[i][j] = padre(k);
    }
    if (v[i][y + 1] != 0) {
      unir(v[i][y + 1], k);
    }
    if (v[i][y - T] != 0) {
      unir(v[i][y - T], k);
    }
  }
  for (int j = y; j > y - T; j--) {
    c++;
    if (v[x + 1][j] != 0) {
      unir(v[x + 1][j], k);
    }
    if (v[x - T][j] != 0) {
      unir(v[x - T][j], k);
    }
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(res, -1, sizeof(res));
  for (int i = 0; i < 250000; i++) fada[i] = i;
  int N, M;
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      char x;
      cin >> x;
      if (x == '#')
        dp[i][j] = 0;
      else {
        dp[i][j] = 1;
        int k = min(dp[i - 1][j], dp[i][j - 1]);
        dp[i][j] = k + (bool)(dp[i - k][j - k]);
        p[dp[i][j]].push_back({i, j});
      }
    }
  }
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    cin >> querys[0][i].first >> querys[0][i].second >> querys[1][i].first >>
        querys[1][i].second;
  }
  for (int T = min(N, M); T > 0; T--) {
    for (auto a : p[T]) {
      f(a.first, a.second, T);
    }
    for (int i = 0; i < Q; i++) {
      if (res[i] == -1 && v[querys[0][i].first][querys[0][i].second] != 0 &&
          padre(v[querys[0][i].first][querys[0][i].second]) ==
              padre(v[querys[1][i].first][querys[1][i].second])) {
        res[i] = T;
      }
    }
  }
  for (int i = 0; i < Q; i++) {
    cout << res[i] << "\n";
  }
  return 0;
}
