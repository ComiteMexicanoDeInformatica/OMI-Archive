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
lli hijos_profundos[2][MAX + 2];

void dfs_init(lli nodo, lli pad, lli distpadre) {
  padre[nodo] = pad;

  for (auto h : hijos[nodo]) {
    if (h.hijo == pad) continue;
    dfs_init(h.hijo, nodo, h.distancia);
    if (hijos_profundos[0][h.hijo] + h.distancia > hijos_profundos[0][nodo]) {
      hijos_profundos[1][nodo] = hijos_profundos[0][nodo];
      hijos_profundos[0][nodo] = hijos_profundos[0][h.hijo] + h.distancia;
    } else if (hijos_profundos[0][h.hijo] + h.distancia >
               hijos_profundos[1][nodo]) {
      hijos_profundos[1][nodo] = hijos_profundos[0][h.hijo] + h.distancia;
    }
  }
}

int main() {
  // LEE LA ENTRADA
  std::cin >> n >> q;
  for (int i = 1; i < n; ++i) {
    std::cin >> a >> b >> d;
    hijos[a].push_back({d, b});
    hijos[b].push_back({d, a});
  }

  dfs_init(1, 0, 0);

  for (int i = 1; i <= q; ++i) {
    std::cin >> a >> b;

    std::cout << hijos_profundos[0][b] + hijos_profundos[1][b] << "\n";
  }

  return 0;
}
