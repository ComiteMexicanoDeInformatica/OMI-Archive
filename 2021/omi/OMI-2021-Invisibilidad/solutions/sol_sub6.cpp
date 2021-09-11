#include <iostream>
#include <queue>
#include <set>

#define lli long long
#define rep(i, a, b) for (lli i = (a); i <= (b); ++i)
#define repa(i, a, b) for (lli i = (a); i >= (b); --i)

#define nl "\n"
#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << nl

#define MAX_N 2003
#define MAX_TAM 502

#define peligrosa 1
#define tranquila 0

#define fila second.first
#define columna second.second
#define largo first

lli n, f, c, f1[MAX_N], f2[MAX_N], c1[MAX_N], c2[MAX_N], dsu[MAX_N], mi, ma,
    cnt;

bool contiguos(lli a, lli b) {
  if (c1[a] == c2[b] + 1 || c1[b] == c2[a] + 1) {  // horizontal
    return (f1[a] >= f1[b] && f1[a] <= f2[b] + 1) ||
           (f1[b] >= f1[a] && f1[b] <= f2[a] + 1);
  } else if (f1[a] == f2[b] + 1 || f1[b] == f2[a] + 1) {  // vertical
    return (c1[a] >= c1[b] && c1[a] <= c2[b] + 1) ||
           (c1[b] >= c1[a] && c1[b] <= c2[a] + 1);
  }
  return false;
}

lli bloque(lli a) { return (dsu[a] == a) ? a : dsu[a] = bloque(dsu[a]); }

void une(lli a, lli b) {
  lli ba = bloque(a);
  lli bb = bloque(b);
  if (ba != bb) dsu[ba] = bb;
}

int main() {
  std::cin >> n >> f >> c;
  for (int i = 1; i <= n; ++i) std::cin >> f1[i] >> c1[i] >> f2[i] >> c2[i];
  for (int i = 1; i <= n; ++i) dsu[i] = i;

  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (contiguos(i, j)) une(i, j);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (bloque(i) == i) {
      mi = c + 1;
      ma = 0;
      for (int j = 1; j <= n; j++) {
        if (bloque(j) == i) {
          mi = std::min(mi, c1[j]);
          ma = std::max(ma, c2[j]);
        }
      }
      if (mi == 1 && ma == c) cnt++;
    }
  }

  std::cout << cnt << nl;

  return 0;
}
