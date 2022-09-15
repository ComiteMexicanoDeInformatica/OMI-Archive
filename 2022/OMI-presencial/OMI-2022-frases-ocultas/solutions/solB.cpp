#include <iostream>
#include <set>

#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << "\n";

#define MAX 100000
#define MAXLETRA 26

int t, n, largo, posTexto, letra;
std::string st, palabra[MAX + 2];
std::set<int> posicionLetra[MAXLETRA + 2];

int main() {
  std::cin >> t >> n >> st;

  for (int i = 1; i <= n; ++i) std::cin >> largo >> palabra[i];

  // RECORRE EL TEXTO Y GUARDA UNA LISTA DE LAS POSICIONES DE CADA LETRA EN EL
  // TEXTO
  for (int i = 0; i < t; ++i) posicionLetra[st[i] - 'a'].insert(i);

  // PARA CADA PALABRA BUSCA LAS LETRAS DE LA PALABRA PERO EN VEZ DE RECORRER EL
  // TEXTO USA LOS SETS.
  for (int p = 1; p <= n; ++p) {
    bool ok = true;
    posTexto = -1;
    for (int l = 0; (std::size_t)l < palabra[p].size(); ++l) {
      letra = palabra[p][l] - 'a';
      auto it = posicionLetra[letra].upper_bound(posTexto);
      if (it == posicionLetra[letra].end()) {
        ok = false;
        break;
      }
      posTexto = (*it);  // AVANZA LA POSICION DEL TEXTO
    }
    if (ok)
      std::cout << "1\n";
    else
      std::cout << "0\n";
  }

  return 0;
}
