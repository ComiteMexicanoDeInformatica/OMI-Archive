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

// Funcion que cambia dos columnas
void cambiaCols(int i, int j) {
  for (int k = 1; k <= N; k++) std::swap(a[k][i], a[k][j]);
}

// Funcion que invierte la matriz sobre el eje vertical
void invVer() {
  for (int i = 1; i <= N / 2; i++) cambiaCols(i, N - i + 1);
}

// Funcion que cambia dos filas
void cambiaFilas(int i, int j) {
  for (int k = 1; k <= N; k++) std::swap(a[i][k], a[j][k]);
}

// Funcion que invierte la matriz sobre el eje horizontal
void invHor() {
  for (int i = 1; i <= N / 2; i++) cambiaFilas(i, N - i + 1);
}

int main() {
  std::cin >> N;

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) std::cin >> a[i][j];

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) std::cin >> b[i][j];

  // Probaremos con/sin inversion horizontal
  for (int j = 0; j < 2; j++) {
    // Probaremos con/sin inversion vertical
    for (int k = 0; k < 2; k++) {
      // Checamos si son la misma matriz
      if (iguales()) {
        std::cout << "IGUALES\n";
        return 0;
      }
      invVer();
    }
    invHor();
  }

  // Ya probamos todas las posibilidades, por lo que son diferentes
  std::cout << "DIFERENTES\n";
  return 0;
}
