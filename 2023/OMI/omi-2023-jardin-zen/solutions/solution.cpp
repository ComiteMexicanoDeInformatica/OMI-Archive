#include <bits/stdc++.h>

using namespace std;

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)
#define lli long long int
#define vi vector<int>
#define vlli vector<long long int>
#define pii pair<int, int>
#define plli pair<lli, lli>
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define repa(i, a, b) for (int i = (a); i >= (b); i--)
#define repv(x, v) for (auto x : v)
#define debug(x) cout << #x << " = " << x << endl
#define debugsl(x) cout << #x << " = " << x << ", "
#define debugarr(x, a, b)            \
  cout << #x << " = [";              \
  rep(i, a, b) cout << x[i] << ", "; \
  cout << "]\n"
#define pb push_back
#define nl "\n"

#define MAX 1000

int n, m, vis[MAX + 2][MAX + 2];
int dc[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, df[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
string jardin[MAX + 2];
queue<pii> q;

bool es_esquina(int f, int c) {
  if (jardin[f][c] == '.') return false;

  // ARRIBA - IZQUIERDA
  if (f > 1 && c > 0 && jardin[f - 1][c - 1] == '.' &&
      jardin[f - 1][c] == '.' && jardin[f][c - 1] == '.')
    return true;

  // ARRIBA - DERECHA
  if (f > 1 && c < m - 1 && jardin[f - 1][c + 1] == '.' &&
      jardin[f - 1][c] == '.' && jardin[f][c + 1] == '.')
    return true;

  // ABAJO - IZQUIERDA
  if (f < n && c > 0 && jardin[f + 1][c - 1] == '.' &&
      jardin[f + 1][c] == '.' && jardin[f][c - 1] == '.')
    return true;

  // ABAJO DERECHA
  if (f < n && c < m - 1 && jardin[f + 1][c + 1] == '.' &&
      jardin[f + 1][c] == '.' && jardin[f][c + 1] == '.')
    return true;

  return false;
}

int main() {
  fastio;

  cin >> n >> m;
  rep(i, 1, n) cin >> jardin[i];

  rep(fil, 1, n) {
    rep(col, 0, m - 1) {
      if (jardin[fil][col] == '#' && es_esquina(fil, col) && !vis[fil][col]) {
        vis[fil][col] = 1;
        q.push({fil, col});
      }
    }
  }

  while (!q.empty()) {
    int f = q.front().first;
    int c = q.front().second;
    q.pop();

    jardin[f][c] = '.';
    rep(d, 0, 7) {
      int nf = f + df[d];
      int nc = c + dc[d];
      if (nf >= 1 && nf <= n && nc >= 0 && nc < m && !vis[nf][nc] &&
          es_esquina(nf, nc)) {
        vis[nf][nc] = 1;
        q.push({nf, nc});
      }
    }
  }

  cout << nl;
  rep(fil, 1, n) cout << jardin[fil] << nl;

  return 0;
}
