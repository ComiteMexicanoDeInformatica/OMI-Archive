#include <iostream>

#define MAX 505

int N;
char a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];

// Funcion para girar a[][] 90 grados
void gira90() {
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) c[j][N - i + 1] = a[i][j];

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) a[i][j] = c[i][j];
}

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

  // Probaremos rotar 0, 90, 180 o 270 grados
  for (int i = 0; i < 4; i++) {
    // Checamos si son la misma matriz
    if (iguales()) {
      std::cout << "IGUALES\n";
      return 0;
    }
    gira90();
  }

  // Ya probamos todas las posibilidades, por lo que son diferentes
  std::cout << "DIFERENTES\n";
  return 0;
}
