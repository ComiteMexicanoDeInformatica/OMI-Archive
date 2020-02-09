#include "moebius.h"

// Main
//	long long avanza(long long casas)

void encuentraCasa(long long origen, long long destino) {
  long long actual = origen;

  while (actual != destino) {
    actual = avanza(1);
  }
}
