#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define lli long long
#define rep(i, a, b) for (lli i = (a); i <= (b); ++i)
#define repa(i, a, b) for (lli i = (a); i >= (b); --i)

#define nl "\n"
#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << nl

#define MAX_N 200003

lli n, m, inf, tmp, k, p, a[MAX_N], b[MAX_N], orig, dest, minimo, maximo,
    perm[MAX_N], infectados[MAX_N];

int main() {
  std::cin >> n >> m >> inf;
  rep(i, 1, inf) {
    std::cin >> k;
    infectados[k] = 1;
  }

  if (m > 10) return 0;

  rep(i, 1, m) std::cin >> a[i] >> b[i];

  rep(i, 0, m - 1) perm[i] = i + 1;
  minimo = n;
  maximo = 0;
  p = 2;
  do {
    tmp = inf;
    rep(i, 0, m - 1) {
      orig = a[perm[i]];
      dest = b[perm[i]];
      if ((infectados[orig] == 1 || infectados[orig] == p) &&
          infectados[dest] != 1 && infectados[dest] != p) {
        tmp++;
        infectados[dest] = p;
      }
    }
    p++;
    minimo = std::min(minimo, tmp);
    maximo = std::max(maximo, tmp);
  } while (std::next_permutation(perm, perm + m));

  std::cout << minimo << " " << maximo << nl;

  return 0;
}
