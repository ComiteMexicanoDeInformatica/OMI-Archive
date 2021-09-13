#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

#define lli long long
#define rep(i, a, b) for (lli i = (a); i <= (b); ++i)
#define repa(i, a, b) for (lli i = (a); i >= (b); --i)

#define nl "\n"
#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << nl

#define MAX_N 50003

#define id second.second
#define tipo second.first
#define inicio 0ll
#define fin 1ll

#define fila first
#define idzona second

lli n, g, res, f, c, f1[MAX_N], f2[MAX_N], c1[MAX_N], c2[MAX_N], dsu[MAX_N],
    l[MAX_N], r[MAX_N];
std::vector<std::pair<lli, std::pair<lli, lli> > > eventos;
std::set<std::pair<lli, lli> > activos;

lli comp(lli a) {
  if (dsu[a] == a) return a;
  return dsu[a] = comp(dsu[a]);
}

void une(lli a, lli b) {
  lli ca = comp(a);
  lli cb = comp(b);
  if (ca != cb) dsu[cb] = ca;
}

int main() {
  std::cin >> n >> f >> c;
  rep(i, 1, n) {
    std::cin >> f1[i] >> c1[i] >> f2[i] >> c2[i];
    l[i] = c1[i];
    r[i] = c2[i];
    dsu[i] = i;
    eventos.push_back({c1[i], {inicio, i}});
    eventos.push_back({c2[i] + 1, {fin, i}});
  }
  std::sort(eventos.begin(), eventos.end());

  for (auto ev : eventos) {
    if (ev.tipo == inicio) {
      auto it = activos.upper_bound({f2[ev.id], 0});
      if (it != activos.end()) {
        if ((*it).fila == f2[ev.id] + 1) {
          une(ev.id, (*it).idzona);
        }  // se tocan verticalmente
        else if (f1[(*it).idzona] <= f2[ev.id]) {
          une(ev.id, (*it).idzona);
        }  // se tocan horizontal
      }

      it = activos.lower_bound({f1[ev.id] - 1, 0});
      if (it != activos.end()) {
        if ((*it).fila == f1[ev.id] - 1) {
          une(ev.id, (*it).idzona);
        }  // se tocan verticalmente
        else if (f2[(*it).idzona] >= f1[ev.id] &&
                 f1[(*it).idzona] <= f2[ev.id]) {
          une(ev.id, (*it).idzona);
        }  // horizontalmente
      }

      activos.insert({f1[ev.id], ev.id});
      if (f1[ev.id] != f2[ev.id]) activos.insert({f2[ev.id], ev.id});
    } else {
      activos.erase({f1[ev.id], ev.id});
      if (f1[ev.id] != f2[ev.id]) activos.erase({f2[ev.id], ev.id});
    }
  }

  rep(i, 1, n) {
    g = comp(i);
    l[g] = std::min(l[g], l[i]);
    r[g] = std::max(r[g], r[i]);
  }

  rep(i, 1, n) if (comp(i) == i && l[i] == 1 && r[i] == c) res++;

  std::cout << res << nl;

  return 0;
}
