#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

const int MAXN = 1002;

int n, m;
char original[MAXN][MAXN];
char contestant[MAXN][MAXN];

void error(std::string msg) {
  std::cout << "0\n";
  std::cerr << msg << "\n";
  exit(0);
}

bool validCar(char c) { return c == '.' || c == '*' || c == 'N' || c == 'B'; }

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  {
    std::ifstream f("data.in");
    f >> n >> m;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) f >> original[i][j];
  }

  {
    std::string fila;
    for (int i = 0; i < n; ++i) {
      std::getline(std::cin, fila);

      while (fila.back() == '\n' || fila.back() == ' ' || fila.back() == '\r')
        fila.pop_back();

      if (fila.size() != m) error("Una fila no tiene m caracteres");
      for (int j = 0; j < m; ++j) contestant[i][j] = fila[j];
    }
    // check for trailing trash
    while (std::cin >> fila) {
      if (!fila.empty()) {
        for (auto c : fila) {
          if (c != ' ' && c != '\n') error("Traling trash");
        }
      }
    }
  }

  double vacios = 0;
  double puestos = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!validCar(contestant[i][j])) {
        // caracter no valido
        error("Caracter no valido");
      }
      if (original[i][j] == '*') {
        if (contestant[i][j] != '*')
          error("Matriz no coincide con la original");
      } else {
        vacios++;
        if (contestant[i][j] == '*') error("Pusiste * en casilla libre");
        if (contestant[i][j] == 'B' || contestant[i][j] == 'N') {
          // Checar si puso adyacentes del mismo color
          if (i > 0 && contestant[i - 1][j] == contestant[i][j])
            error("Matriz no cumple requerimientos de adyacencia.");
          if (j > 0 && contestant[i][j - 1] == contestant[i][j])
            error("Matriz no cumple requerimientos de adyacencia.");
          if (i < n - 1 && contestant[i + 1][j] == contestant[i][j])
            error("Matriz no cumple requerimientos de adyacencia.");
          if (j < m - 1 && contestant[i][j + 1] == contestant[i][j])
            error("Matriz no cumple requerimientos de adyacencia.");
          puestos++;
        }
      }
    }
  }

  if (vacios == 0) {
    // Para evitar división entre 0
    vacios++;
    puestos++;
  }

  std::cout << puestos / vacios << std::endl;
}
