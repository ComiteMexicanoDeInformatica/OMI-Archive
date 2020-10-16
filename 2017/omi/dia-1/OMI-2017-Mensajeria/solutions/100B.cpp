#include <iostream>
#include <algorithm>

int n, k;
int S;

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cin >> n >> k;
  int mayor = -(1 << 30);
  bool flag = false;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    mayor = std::max(mayor, x);
    S += x < k ? x : k;
  }
  if (mayor < k) S += k - mayor;
  std::cout << S << "\n";
  return 0;
}
