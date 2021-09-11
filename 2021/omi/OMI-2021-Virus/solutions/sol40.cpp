#include <iostream>
#include <queue>
#include <vector>

#define lli long long
#define rep(i, a, b) for (lli i = (a); i <= (b); ++i)
#define repa(i, a, b) for (lli i = (a); i >= (b); --i)

#define nl "\n"
#define debugsl(x) cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << nl

#define MAX_N 200003

lli n, m, inf, a, b, minimo, maximo, visitados[MAX_N], infectados[MAX_N];
std::vector<lli> hijos[MAX_N];
std::queue<lli> q;

int main() {
  std::cin >> n >> m >> inf;
  rep(i, 1, inf) {
    std::cin >> a;
    infectados[a] = 1;
  }

  minimo = maximo = inf;
  rep(i, 1, m) {
    std::cin >> a >> b;
    if (infectados[a] == 1 && !infectados[b]) {
      minimo++;
      infectados[b] = 2;
    }
  }

  std::cout << minimo << " " << minimo << nl;

  return 0;
}
