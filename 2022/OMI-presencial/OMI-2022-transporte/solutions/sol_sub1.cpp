#include <iostream>
#include <vector>

#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << "\n";

#define lli long long

#define MAX 100000
#define LOG 17

#define distancia first
#define hijo second
#define idancestro second

#define idpregunta first

lli n, q, a, b, d, id, padre[MAX + 2], r;
std::vector<std::pair<lli, int> > hijos[MAX + 2];

void dfs_init(lli nodo, lli pad) {
  padre[nodo] = pad;

  for (auto h : hijos[nodo]) {
    if (h.hijo == pad) continue;
    dfs_init(h.hijo, nodo);
  }
}

lli dfs_solve(lli nodo, lli pad, lli prohibido) {
  lli x, y, m;
  x = y = 0;
  for (auto h : hijos[nodo]) {
    if (h.hijo == pad || h.hijo == prohibido) continue;
    m = dfs_solve(h.hijo, nodo, prohibido);
    if (m + h.distancia > x) {
      y = x;
      x = m + h.distancia;
    } else if (m + h.distancia > y)
      y = m + h.distancia;
  }

  r = x + y;

  return x;
}

int main() {
  // LEE LA ENTRADA
  std::cin >> n >> q;
  for (int i = 1; i < n; ++i) {
    std::cin >> a >> b >> d;
    hijos[a].push_back({d, b});
    hijos[b].push_back({d, a});
  }

  dfs_init(1, 0);

  for (int i = 1; i <= q; ++i) {
    std::cin >> a >> b;
    dfs_solve(a, 0, padre[b]);
    std::cout << r << "\n";
  }

  return 0;
}
