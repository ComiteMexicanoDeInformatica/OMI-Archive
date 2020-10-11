#include <iostream>

int mat[1201][1202];
int N, Q;
int main() {
  // optimizar io
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cin >> N >> Q;
  int x, y;
  for (int i = 0; i < N; i++) {
    std::cin >> x >> y;
    mat[x][y] = 1;
  }
  for (int i = 0; i < Q; i++) {
    std::cin >> x >> y;
    int dis = 2000;
    for (int ii = -10; ii <= 10; ii++) {
      for (int jj = -10; jj <= 10; jj++) {
        if (x + ii >= 0 && y + jj >= 0) {
          if (mat[x + ii][y + jj] == 0) continue;
          dis = std::min(dis, std::max(abs(ii), abs(jj)));
        }
      }
    }
    std::cout << dis << "\n";
  }
  return 0;
}