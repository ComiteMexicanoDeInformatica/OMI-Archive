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

int n, m;
string jardin[MAX + 2];

int main() {
  fastio;

  cin >> n >> m;
  rep(i, 1, n) cin >> jardin[i];

  rep(fil, 1, n) {
    // LOS UNICOS QUE PUEDEN HACER QUE CAMBIE SON LAS FILAS ".."
    if (jardin[fil][0] == '.' && jardin[fil][1] == '.') {
      repa(f, fil - 1, 1) {
        if (jardin[f][0] == '.' ^ jardin[f][1] == '.')
          jardin[f][0] = jardin[f][1] = '.';
        else
          break;
      }
      rep(f, fil + 1, n) {
        if (jardin[f][0] == '.' || jardin[f][1] == '.')
          jardin[f][0] = jardin[f][1] = '.';
        else
          break;
      }
    }
  }

  rep(fil, 1, n) cout << jardin[fil] << nl;

  return 0;
}
