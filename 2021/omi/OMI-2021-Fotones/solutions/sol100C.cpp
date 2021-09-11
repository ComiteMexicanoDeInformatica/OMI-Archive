#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

#define lli long long
#define rep(i, a, b) for (lli i = (a); i <= (b); ++i)
#define repa(i, a, b) for (lli i = (a); i >= (b); --i)

#define nl "\n"
#define debugsl(x) cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << nl

#define MAX_N 100003
#define coord first
#define id second

#define norte 0
#define este 1
#define sur 2
#define oeste 3
#define inviertedir 2
#define horizontal 1

#define indefinido 0
#define infinito -1

lli n, e, fil, col, f[MAX_N], c[MAX_N], dirlaser;
char ce, espejo[MAX_N];
std::unordered_map<lli, std::vector<std::pair<lli, lli> > > mapfil, mapcol;
lli dp[4][MAX_N];
lli mi, ma;

void bb(std::vector<std::pair<lli, lli> > &v, lli x) {
  lli l, r, mitad;
  l = 0;
  r = v.size() - 1;
  mi = ma = 0;

  if (!v.size()) return;

  while (l <= r) {
    mitad = (l + r) / 2;
    if (v[mitad].coord < x) {
      l = mitad + 1;
      mi = v[mitad].id;
    } else {
      r = mitad - 1;
      if (v[mitad].coord > x)
        ma = v[mitad].id;
      else if (mitad + 1 < v.size())
        ma = v[mitad + 1].id;
    }
  }
}

lli siguienteEspejo(lli fil, lli col, lli dir) {
  if (dir & horizontal) {
    bb(mapfil[fil], col);
    if (dir == este)
      return ma;
    else
      return mi;
  } else {
    bb(mapcol[col], fil);
    if (dir == norte)
      return ma;
    else
      return mi;
  }
}

void dfs(lli nodo, lli dir) {
  if (dp[dir][nodo] != indefinido) return;

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
    mapfil[f[i]].push_back({c[i], i});
    mapcol[c[i]].push_back({f[i], i});
  }

  auto it = mapfil.begin();
  while (it != mapfil.end()) {
    std::sort((*it).second.begin(), (*it).second.end());
    it++;
  }
  it = mapcol.begin();
  while (it != mapfil.end()) {
    std::sort((*it).second.begin(), (*it).second.end());
    it++;
  }

  rep(i, 1, n) rep(dir, norte, oeste) if (dp[dir][i] == indefinido) dfs(i, dir);

  lli sigespejo, sigdir;
  std::vector<lli> resultados;
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
      resultados.push_back(dp[sigdir][sigespejo]);
    else
      resultados.push_back(0);
  }

  for (auto r : resultados) std::cout << r << "\n";

  return 0;
}
