#include <iostream>
#include <vector>

#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << "\n";

#define MAX 100000
#define MAXLETRA 26

int t, n, letra, largo[MAX + 2], posPalabra[MAX + 2], res[MAX + 2];
std::string st, palabra[MAX + 2];
std::vector<int> palabrasConLetra[MAXLETRA + 2];

int main() {
  std::cin >> t >> n >> st;

  // PARA CADA PALABRA INSERTALA EN UNA COLA DEPENDIENDO DE CUAL
  // ES LA SIGUIENTE LETRA QUE BUSCA
  for (int i = 1; i <= n; ++i) {
    std::cin >> largo[i] >> palabra[i];
    posPalabra[i] = 0;
    palabrasConLetra[palabra[i][0] - 'a'].push_back(i);
  }

  // AHORA VE RECORRIENDO EL TEXTO COMPLETO Y CADA QUE ENCUENTRES UNA LETRA
  // AVANZA TODAS LAS PALABRAS QUE ESTAN ESPERANDO ESA LETRA
  for (int i = 0; i < t; ++i) {
    letra = st[i] - 'a';
    std::vector<int> tmp;
    while (palabrasConLetra[letra].size()) {
      int p = palabrasConLetra[letra].back();
      ++posPalabra[p];
      if (posPalabra[p] == largo[p])
        res[p] = 1;
      else
        tmp.push_back(p);
      palabrasConLetra[letra].pop_back();
    }

    for (auto p : tmp) {
      letra = palabra[p][posPalabra[p]] - 'a';
      palabrasConLetra[letra].push_back(p);
    }
  }

  // ESCRIBE LOS RESULTADOS
  for (int i = 1; i <= n; ++i) std::cout << res[i] << "\n";

  return 0;
}
