#include <iostream>
#include <windows.h>

#include "moebius.h"

int n;
long long casas[10000];
int indice_origen;
int indice_destino;
int indice_actual;
int contador;

long long avanza(long long numero_casas) {
  indice_actual = ((indice_actual + numero_casas) % n + n) % n;
  contador++;
  std::cerr << "avanzaste " << numero_casas << " casas "
            << " llegaste al #" << casas[indice_actual] << "\n";

  if (indice_actual == indice_destino) {
    std::cerr << "has encontrado la casa destino\n";
    std::cerr << "Numero de llamadas a avanza " << contador << "\n";
    exit(0);
  }

  return casas[indice_actual];
}

int main() {
  std::cin >> n >> indice_origen >> indice_destino;

  for (int i = 0; i < n; ++i) {
    std::cin >> casas[i];
  }

  indice_actual = indice_origen;

  encuentraCasa(casas[indice_origen], casas[indice_destino]);

  std::cerr << "Numero de llamadas a avanza " << contador << "\n";

  return 0;
}
