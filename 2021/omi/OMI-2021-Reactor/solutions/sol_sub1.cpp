#include <iostream>
#include <vector>

#define lli long long int
#define rep(i, a, b) for (lli i = (a); i <= (b); ++i)
#define repa(i, a, b) for (lli i = (a); i >= (b); --i)

#define nl "\n"
#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << std::endl

#define MAX_N 200003
#define bajo_nivel 0
#define grave 1
#define severa 2

lli n, m, r, a, b, causas[MAX_N], hojas, hojas_ciclo, tipo, visitado[MAX_N];
std::vector<lli> hijos[MAX_N];

void dfs(lli nodo) {
  visitado[nodo] = 1;
  if (hijos[nodo].size()) {
    for (auto hijo : hijos[nodo])
      if (!visitado[hijo]) dfs(hijo);
  } else
    ++hojas;
}

int main() {
  std::cin >> n >> m >> r;
  rep(i, 1, m) {
    std::cin >> a >> b;
    hijos[a].push_back(b);
  }

  std::cout << "B\n";
  dfs(r);
  std::cout << hojas << " 0\n";

  return 0;
}
