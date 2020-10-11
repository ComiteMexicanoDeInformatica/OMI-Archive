#include <iostream>

int n, m;
char mat[1005][1005];

int main() {
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> mat[i][j];
      if (mat[i][j] == '.') {
        if ((i + j) % 2 == 0)
          mat[i][j] = 'B';
        else
          mat[i][j] = 'W';
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << mat[i][j];
    }
    std::cout << "\n";
  }
  std::cout << ":)";
}
