#include <iostream>
#include <queue>
const int MaxN = 101;
bool vis[MaxN][MaxN];
int mapa[MaxN][MaxN];
int mov[8][2] = {{0, 1}, {0, -1},  {1, 0},  {1, -1},
                 {1, 1}, {-1, -1}, {-1, 0}, {-1, 1}};
struct node {
  int x, y, pasos;
};
std::queue<node> cola;
void bfs(int x, int y) {
  node actual, sig;
  while (!cola.empty()) cola.pop();
  int i;
  actual.x = x, actual.y = y, actual.pasos = 0;
  if (mapa[x][y] == 1) {  // Si ya estoy sobre una oveja
    std::cout << "0\n";
    return;
  }
  vis[x][y] = 1;
  cola.push(actual);
  while (!cola.empty()) {
    actual = cola.front();
    cola.pop();
    for (i = 0; i < 8; i++) {
      sig.x = actual.x + mov[i][0];
      sig.y = actual.y + mov[i][1];
      if (sig.x < 0 || sig.x > 100 || sig.y < 0 || sig.y > 100) continue;
      if (vis[sig.x][sig.y]) continue;
      vis[sig.x][sig.y] = 1;
      sig.pasos = actual.pasos + 1;
      if (mapa[sig.x][sig.y] == 1) {
        // Encontré una oveja, entonces esa es mi respuesta
        std::cout << sig.pasos << "\n";
        return;
      }
      cola.push(sig);
    }
  }
}

int main() {
  int N, Q, i, j, x, y;
  std::cin >> N >> Q;
  for (i = 0; i < N; i++) {
    std::cin >> x >> y;
    mapa[x][y] = 1;
  }
  while (Q--) {
    std::cin >> x >> y;
    bfs(x, y);
    for (i = 0; i <= 100; i++) {
      for (j = 0; j <= 100; j++) {
        vis[i][j] = 0;
      }
    }
  }
}
