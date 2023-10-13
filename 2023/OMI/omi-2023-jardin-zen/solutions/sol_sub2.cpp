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
string jardin[MAX + 2];
int minfil, mincol, maxfil, maxcol;
vector<int> df(4, 0), dc(4, 0);

void limpia_zona() {
  rep(fil, minfil, maxfil) {
    rep(col, mincol, maxcol) { jardin[fil][col] = '.'; }
  }
}

void conecta(int f, int c) {
  queue<pair<int, int> > q;

  q.push({f, c});
  while (!q.empty()) {
    int nf, nc;

    minfil = min(minfil, q.front().first);
    maxfil = max(maxfil, q.front().first);
    mincol = min(mincol, q.front().second);
    maxcol = max(maxcol, q.front().second);

    rep(d, 0, 3) {
      nf = q.front().first + df[d];
      nc = q.front().second + dc[d];
      if (nf > 0 && nf <= n && nc >= 0 && nc < m && jardin[nf][nc] == '.' &&
          !vis[nf][nc]) {
        vis[nf][nc] = 1;
        q.push({nf, nc});
      }
    }

    q.pop();
  }
}

int main() {
  fastio;

  dc[0] = df[2] = 1;
  dc[1] = df[3] = -1;

  cin >> n >> m;
  rep(i, 1, n) cin >> jardin[i];

  rep(fil, 1, n) {
    rep(col, 0, m - 1) {
      if (!vis[fil][col] && jardin[fil][col] == '.') {
        vis[fil][col] = 1;
        minfil = n + 1;
        maxfil = -1;
        mincol = m;
        maxcol = -1;

        conecta(fil, col);

        limpia_zona();
      }
    }
  }

  cout << nl;
  rep(fil, 1, n) cout << jardin[fil] << nl;

  return 0;
}
