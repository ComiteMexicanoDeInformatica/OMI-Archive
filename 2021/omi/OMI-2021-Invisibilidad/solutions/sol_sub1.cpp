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

lli n, f, c, f1, f2, c1, c2;

int main() {
  std::cin >> n >> f >> c;
  std::cin >> f1 >> c1 >> f2 >> c2;

  if (c1 == 1 && c2 == c)
    std::cout << 1 << nl;
  else
    std::cout << 0 << nl;

  return 0;
}
