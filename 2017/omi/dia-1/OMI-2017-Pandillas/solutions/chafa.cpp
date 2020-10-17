#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  std::vector<std::pair<int, int> > E(m);
  std::vector<int> largo(n);
  int i;

  for (i = 0; i < m; i++) {
    std::cin >> E[i].first >> E[i].second;
    if (E[i].first > E[i].second) std::swap(E[i].first, E[i].second);
  }
  sort(E.begin(), E.end());

  for (i = 0; i < n; i++) largo[i] = i;

  int res = 1;
  for (i = m - 1; i >= 0; i--) {
    if (largo[E[i].second] == E[i].first + 1) largo[E[i].second] = E[i].first;
    res = std::max(res, E[i].second - largo[E[i].second] + 1);
  }

  std::cout << res << "\n";

  return 0;
}