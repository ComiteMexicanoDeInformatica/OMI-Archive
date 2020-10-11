#include <iostream>
#include <queue>
#include <utility>

int tablero[1010][1010];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, Q, x, y;
  std::queue<std::pair<int, int> > bfs;
  std::cin >> N >> Q;

  // inicializar tablero con valores inf
  for (int i = 0; i <= 1000; i++) {
    for (int j = 0; j <= 1000; j++) {
      tablero[i][j] = 1000000000;
    }
  }

  for (int i = 0; i < N; i++) {
    std::cin >> x >> y;
    // registrar el punto (x,y) como punto de inicio de la bfs
    tablero[x][y] = 0;
    bfs.push(std::make_pair(x, y));
  }

  // llenar tablero mediante la bfs
  int x_actual, y_actual;
  while (bfs.empty() == false) {
    x_actual = bfs.front().first;
    y_actual = bfs.front().second;
    bfs.pop();
    // expandir la busqueda a la izquierda
    if (x_actual - 1 >= 0 &&
        tablero[x_actual][y_actual] + 1 < tablero[x_actual - 1][y_actual]) {
      tablero[x_actual - 1][y_actual] = tablero[x_actual][y_actual] + 1;
      bfs.push(std::make_pair(x_actual - 1, y_actual));
    }
    // expandir la busqueda a la derecha
    if (x_actual + 1 <= 1000 &&
        tablero[x_actual][y_actual] + 1 < tablero[x_actual + 1][y_actual]) {
      tablero[x_actual + 1][y_actual] = tablero[x_actual][y_actual] + 1;
      bfs.push(std::make_pair(x_actual + 1, y_actual));
    }
    // expandir la busqueda a abajo
    if (y_actual - 1 >= 0 &&
        tablero[x_actual][y_actual] + 1 < tablero[x_actual][y_actual - 1]) {
      tablero[x_actual][y_actual - 1] = tablero[x_actual][y_actual] + 1;
      bfs.push(std::make_pair(x_actual, y_actual - 1));
    }
    // expandir la busqueda a arriba
    if (y_actual + 1 <= 1000 &&
        tablero[x_actual][y_actual] + 1 < tablero[x_actual][y_actual + 1]) {
      tablero[x_actual][y_actual + 1] = tablero[x_actual][y_actual] + 1;
      bfs.push(std::make_pair(x_actual, y_actual + 1));
    }
    // expanidr la busqueda abajo a la izquierda
    if (x_actual - 1 >= 0 && y_actual - 1 >= 0 &&
        tablero[x_actual][y_actual] + 1 < tablero[x_actual - 1][y_actual - 1]) {
      tablero[x_actual - 1][y_actual - 1] = tablero[x_actual][y_actual] + 1;
      bfs.push(std::make_pair(x_actual - 1, y_actual - 1));
    }
    // expanidr la busqueda arriba a la izquierda
    if (x_actual - 1 >= 0 && y_actual + 1 <= 1000 &&
        tablero[x_actual][y_actual] + 1 < tablero[x_actual - 1][y_actual + 1]) {
      tablero[x_actual - 1][y_actual + 1] = tablero[x_actual][y_actual] + 1;
      bfs.push(std::make_pair(x_actual - 1, y_actual + 1));
    }
    // expanidr la busqueda abajo a la derecha
    if (x_actual + 1 <= 1000 && y_actual - 1 >= 0 &&
        tablero[x_actual][y_actual] + 1 < tablero[x_actual + 1][y_actual - 1]) {
      tablero[x_actual + 1][y_actual - 1] = tablero[x_actual][y_actual] + 1;
      bfs.push(std::make_pair(x_actual + 1, y_actual - 1));
    }
    // expanidr la busqueda arriba a la derecha
    if (x_actual + 1 <= 1000 && y_actual + 1 <= 1000 &&
        tablero[x_actual][y_actual] + 1 < tablero[x_actual + 1][y_actual + 1]) {
      tablero[x_actual + 1][y_actual + 1] = tablero[x_actual][y_actual] + 1;
      bfs.push(std::make_pair(x_actual + 1, y_actual + 1));
    }
  }
  for (int i = 0; i < Q; i++) {
    std::cin >> x >> y;
    std::cout << tablero[x][y] << "\n";
  }
  return 0;
}