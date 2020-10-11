#include <climits>
#include <iostream>
#include <queue>
#include <vector>

std::vector<std::vector<int> > mapa;
struct tri {
  int x, y, z;
  tri() : x(0), y(0), z(0) {}
  tri(int a, int b, int c) : x(a), y(b), z(c) {}
};
bool val(tri a) { return a.x > -1 and a.x < 1001 and a.y > -1 and a.y < 1001; }
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  mapa.assign(1005, std::vector<int>(1005, INT_MAX));
  int n, q, x, y;
  std::cin >> n >> q;
  while (n--) {
    std::cin >> x >> y;
    std::queue<tri> q;
    q.push(tri(x, y, 0));
    while (!q.empty()) {
      tri curr = q.front();
      q.pop();
      if (val(curr) and mapa[curr.x][curr.y] > curr.z) {
        mapa[curr.x][curr.y] = curr.z;
        for (int i = -1; i < 2; i++)
          for (int j = -1; j < 2; j++)
            q.push(tri(curr.x + i, curr.y + j, curr.z + 1));
      }
    }
  }
  while (q--) {
    std::cin >> x >> y;
    std::cout << mapa[x][y] << '\n';
  }
  return 0;
}
