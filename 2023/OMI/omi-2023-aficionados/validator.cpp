#include <fstream>
#include <iostream>

int n;
int V[100000];
int freq[1001];

int main() {
  //  Leer el caso original.
  {
    std::ifstream entrada_original("data.in", std::ifstream::in);
    entrada_original >> n;
    for (int i = 0; i < n; i++) entrada_original >> V[i];
  }

  bool respuesta = false;

  // Guardamos 1 si existe un subarreglo con elemento mayoritario
  // en "data.out", y un 0 si no.
  //(Habría que hacer los archivos data.out)
  /*
  {
    std::ifstream salida_original("data.out", std::ifstream::in);
    salida_original >> respuesta;
  }
  */

  if (V[0] == V[1]) respuesta = true;
  for (int i = 0; i < n - 2; i++) {
    if (V[i] == V[i + 1] || V[i] == V[i + 2] || V[i + 1] == V[i + 2])
      respuesta = true;
  }

  // lee entrada estándar para obtener la salida del concursante.
  // y determina si la respuesta es incorrecta
  if (respuesta) {
    int L, R;
    if (!(std::cin >> L >> R)) {
      std::cerr << "Error leyendo la salida del concursante\n";
      std::cout << 0.0 << '\n';
      return 0;
    }
    if (L >= R || L < 1 || R > n) {
      std::cerr << "La salida del concursante indica un rango inválido\n";
      std::cout << 0.0 << '\n';
      return 0;
    }
    L--, R--;
    int mx = 0;
    for (int i = L; i <= R; i++) {
      mx = std::max(++freq[V[i]], mx);
    }
    if (2 * mx <= R - L + 1) {
      std::cout << 0.0 << '\n';
      return 0;
    }
  } else {
    int res;
    if (!(std::cin >> res)) {
      std::cerr << "Error leyendo la salida del concursante\n";
      std::cout << 0.0 << '\n';
      return 0;
    }
    if (res != -1) {
      std::cerr << "La salida del concursante es inválida\n";
      std::cout << 0.0 << '\n';
      return 0;
    }
  }

  // Si la ejecución llega hasta aquí, la salida del concursante
  // es correcta.
  std::cout << 1.0 << '\n';
  return 0;
}
