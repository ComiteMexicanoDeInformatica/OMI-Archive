#include <iostream>

const int MAXN = 1002;
int n, m;

int main() {
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;
      std::cin >> c;
      if (c == '.') c = (i + j) & 1 ? 'N' : 'B';
      std::cout << c;
    }
    std::cout << "\n";
  }
  return 0;
}