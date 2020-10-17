#include <algorithm>
#include <iostream>

const int MAXN = 1000002;

int n, m;
std::pair<int, int> aristas[MAXN];
int R[MAXN];

void init() {
  int i = 0;
  while (i < m) {
    int nodo = aristas[i].first;
    int next = nodo + 1;
    for (; aristas[i].first == nodo; i++) {
      if (aristas[i].second == next) {
        R[nodo]++;
        next++;
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cin >> n >> m;
  for (int i = 0; i < m; i++) {
    std::cin >> aristas[i].first >> aristas[i].second;
    if (aristas[i].first > aristas[i].second)
      std::swap(aristas[i].first, aristas[i].second);
  }
  sort(aristas, aristas + m);
  std::fill(R, R + n, 1);
  init();

  int r = 1;
  for (int i = n - 2; i >= 0; i--) {
    R[i] = std::min(R[i] - 1, R[i + 1]) + 1;
    r = std::max(r, R[i]);
  }
  std::cout << r << "\n";
  return 0;
}
