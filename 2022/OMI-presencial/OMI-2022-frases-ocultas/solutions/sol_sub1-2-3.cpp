#include <iostream>

#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << "\n";

#define MAX 100000

int t, n, largo, posPalabra;
std::string st, palabra[MAX + 2];

int main() {
  std::cin >> t >> n >> st;

  for (int i = 1; i <= n; ++i) std::cin >> largo >> palabra[i];

  // UNA FRASE APARECE EN EL TEXTO SI AL TOMAR SUS LETRAS DE IZQUIERDA A DERECHA
  // ES POSIBLE ENCONTRARLAS EN EL MISMO ORDEN EN EL TEXTO.
  // PARA RESOLVER EL PROBLEMA PODEMOS IR RECORRIENDO CADA PALABRA Y
  // BUSCAR EN EL TEXTO SI LAS LETRAS APARECEN EN EL MISMO ORDEN
  for (int p = 1; p <= n; ++p) {
    palabra[p] += '_';  // AGREGA UN MARCADOR AL FINAL PARA NO PASARTE
    posPalabra = 0;     // EMPIEZA EN LA PRIMERA LETRA DE LA PALABRA
    for (int posTexto = 0; posTexto < t; ++posTexto) {
      if (palabra[p][posPalabra] == st[posTexto]) {
        // SI LAS LETRAS SON IGUALES, AVANZA UNO LA POSICION EN LA PALABRA
        ++posPalabra;
        if (palabra[p][posPalabra] == '_') break;
      }
    }

    // SI LLEGO AL MARCADOR FINAL, SI LA ENCONTRO, ESCRIBE UNO Y TERMINA.
    if (palabra[p][posPalabra] == '_')
      std::cout << "1\n";
    else
      std::cout << "0\n";
  }

  return 0;
}
