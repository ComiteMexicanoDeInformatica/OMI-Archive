#include <iostream>
#include <map>
#include <set>

#define lli long long
#define rep(i, a, b) for (lli i = (a); i <= (b); ++i)
#define repa(i, a, b) for (lli i = (a); i >= (b); --i)

#define nl "\n"
#define debugsl(x) cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << nl

#define MAX_N 100003
#define id second

#define norte 0
#define este 1
#define sur 2
#define oeste 3
#define inviertedir 2

#define indefinido -2
#define infinito -1

lli n, e, fil, col, f[MAX_N], c[MAX_N], dirlaser;
char ce, espejo[MAX_N];
std::map<lli, std::set<std::pair<lli, lli>>> mapfil, mapcol;
std::set<std::pair<lli, lli>> s;
lli dp[4][MAX_N];

lli siguienteEspejo(lli fil, lli col, lli dir) {
  std::set<std::pair<lli, lli>>::iterator it;

  if (dir == norte) {
    it = mapcol[col].upper_bound({fil + 1, 0});
    if (it == mapcol[col].end()) return 0;
  } else if (dir == este) {
    it = mapfil[fil].upper_bound({col + 1, 0});
    if (it == mapfil[fil].end()) return 0;
  } else if (dir == sur) {
    it = mapcol[col].lower_bound({fil, 0});
    if (it == mapcol[col].begin())
      return 0;
    else
      it--;
  } else {
    it = mapfil[fil].lower_bound({col, 0});
    if (it == mapfil[fil].begin())
      return 0;
    else
      it--;
  }

  return (*it).id;
}

void dfs(lli nodo, lli dir) {
  if (dp[dir][nodo] > indefinido) return;

  dp[dir][nodo] = infinito;

  lli sigdir;
  if (espejo[nodo] == '/') {
    if (dir == norte)
      sigdir = oeste;
    else if (dir == este)
      sigdir = sur;
    else if (dir == sur)
      sigdir = este;
    else
      sigdir = norte;
  } else {
    if (dir == norte)
      sigdir = este;
    else if (dir == este)
      sigdir = norte;
    else if (dir == sur)
      sigdir = oeste;
    else
      sigdir = sur;
  }

  lli sigespejo = siguienteEspejo(f[nodo], c[nodo], sigdir);
  if (!sigespejo)
    dp[dir][nodo] = 1;
  else {
    sigdir ^= inviertedir;
    dfs(sigespejo, sigdir);
    dp[dir][nodo] = (dp[sigdir][sigespejo] == infinito)
                        ? infinito
                        : dp[sigdir][sigespejo] + 1;
  }
}

int main() {
  std::cin >> n >> fil >> col;
  rep(i, 1, n) {
    std::cin >> espejo[i] >> f[i] >> c[i];
    mapfil[f[i]].insert({c[i], i});
    mapcol[c[i]].insert({f[i], i});
    rep(j, 0, 3) dp[j][i] = indefinido;
  }

  rep(i, 1, n) {
    rep(dir, norte, oeste) {
      if (dp[dir][i] == indefinido) dfs(i, dir);
    }
  }

  lli sigespejo, sigdir;
  std::cin >> e;
  rep(i, 1, e) {
    std::cin >> ce >> fil >> col;
    if (ce == 'N') {
      sigdir = sur;
      sigespejo = siguienteEspejo(fil, col, norte);
    } else if (ce == 'E') {
      sigdir = oeste;
      sigespejo = siguienteEspejo(fil, col, este);
    } else if (ce == 'S') {
      sigdir = norte;
      sigespejo = siguienteEspejo(fil, col, sur);
    } else {
      sigdir = este;
      sigespejo = siguienteEspejo(fil, col, oeste);
    }

    if (sigespejo)
      std::cout << dp[sigdir][sigespejo] << nl;
    else
      std::cout << "0" << nl;
  }

  return 0;
}
