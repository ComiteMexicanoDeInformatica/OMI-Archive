#include <iostream>

#define MAX 505

int N;
char a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];

// Funcion que comprueba si a[][] y b[][] son iguales
bool iguales() {
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      if (a[i][j] != b[i][j]) return false;
  return true;
}

int main() {
  std::cin >> N;

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) std::cin >> a[i][j];

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) std::cin >> b[i][j];

  if (iguales()) {
    std::cout << "IGUALES\n";
    return 0;
  }

  std::cout << "DIFERENTES\n";
  return 0;
}
