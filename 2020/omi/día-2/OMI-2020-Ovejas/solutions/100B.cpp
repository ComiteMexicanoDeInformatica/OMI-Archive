#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#define fi first
#define se second
std::vector<std::vector<int> > mapa;
bool val(std::pair<int, int> a) {
  return a.fi > -1 and a.fi < 1001 and a.se > -1 and a.se < 1001;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  mapa.assign(1005, std::vector<int>(1005, INT_MAX));
  int n, q, x, y;
  std::cin >> n >> q;
  std::queue<std::pair<int, int> > que;
  while (n--) {
    std::cin >> x >> y;
    mapa[x][y] = 0;
    que.push({x, y});
  }
  while (!que.empty()) {
    std::pair<int, int> curr = que.front();
    que.pop();
    for (int i = -1; i < 2; i++)
      for (int j = -1; j < 2; j++) {
        if (val({curr.fi + i, curr.se + j}) and
            mapa[curr.fi][curr.se] + 1 < mapa[curr.fi + i][curr.se + j]) {
          mapa[curr.fi + i][curr.se + j] = mapa[curr.fi][curr.se] + 1;
          que.push({curr.fi + i, curr.se + j});
        }
      }
  }
  while (q--) {
    std::cin >> x >> y;
    std::cout << mapa[x][y] << '\n';
  }
  return 0;
}
