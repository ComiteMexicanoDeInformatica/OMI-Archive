#include <iostream>

#define lli long long
#define rep(i, a, b) for (lli i = (a); i <= (b); ++i)
#define repa(i, a, b) for (lli i = (a); i >= (b); --i)

#define nl "\n"
#define debugsl(x) cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << nl

#define MAX_N 2003

#define id second.second
#define tipo second.first
#define inicio 0ll
#define fin 1ll

#define fila first
#define idzona second

lli n, f, c, f1, f2, c1, c2, cols[MAX_N], cnt;

int main() {
  std::cin >> n >> f >> c;
  for (int i = 1; i <= n; ++i) {
    std::cin >> f1 >> c1 >> f2 >> c2;
    for (int col = c1; col <= c2; ++col) cols[col] = 1;
  }

  for (int col = 1; col <= c; ++col)
    if (cols[col]) ++cnt;

  if (cnt == c)
    std::cout << 1 << nl;
  else
    std::cout << 0 << nl;

  return 0;
}
