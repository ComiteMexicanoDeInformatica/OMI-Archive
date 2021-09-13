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

lli n, f, c, c1, c2, ult, cnt;
std::pair<lli, lli> fils[MAX_N];

int main() {
  std::cin >> n >> f >> c;
  for (int i = 0; i < n; ++i)
    std::cin >> fils[i].first >> c1 >> fils[i].second >> c2;

  std::sort(fils, fils + n);

  ult = fils[0].first - 1;
  cnt = 1;
  for (int i = 0; i < n; ++i) {
    if (fils[i].first > ult + 1) ++cnt;
    ult = fils[i].second;
  }

  std::cout << cnt << nl;

  return 0;
}
