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

lli n, m, inf, a, b, minimo, maximo, visitados[MAX_N], infectados[MAX_N];
std::vector<lli> mensajes[MAX_N];

int main() {
  std::cin >> n >> m >> inf;
  rep(i, 1, inf) {
    std::cin >> a;
    infectados[a] = 1;
  }

  minimo = inf;
  rep(i, 1, m) {
    std::cin >> a >> b;
    mensajes[b].push_back(a);
    if (infectados[a] == 1 && !infectados[b]) {
      infectados[b] = 2;
      minimo++;
    }
  }

  maximo = minimo;
  rep(i, 1, n) {
    if (infectados[i]) continue;
    for (auto origen : mensajes[i]) {
      if (infectados[origen]) {
        infectados[i] = 2;
        maximo++;
        break;
      }
    }
  }

  std::cout << minimo << " " << maximo << nl;

  return 0;
}
