#include <algorithm>
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

lli n, f, c, f1, f2, ult;
std::pair<lli, lli> cols[MAX_N];

int main() {
  std::cin >> n >> f >> c;
  for (int i = 0; i < n; ++i)
    std::cin >> f1 >> cols[i].first >> f2 >> cols[i].second;

  std::sort(cols, cols + n);

  ult = 0;
  for (int i = 0; i < n; ++i) {
    // Si la siguiente zona no esta pegada a la última que terminó entonces hay
    // un hueco
    if (cols[i].first > ult + 1) {
      std::cout << 0 << nl;
      return 0;
    }
    ult = cols[i].second;  // Actualiza el nuevo final
  }

  if (ult == c)
    std::cout << 1 << nl;
  else
    std::cout << 0 << nl;

  return 0;
}
