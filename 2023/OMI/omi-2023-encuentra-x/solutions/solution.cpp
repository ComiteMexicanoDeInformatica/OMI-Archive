#include <bits/stdc++.h>

#include "encuentrax.h"

using namespace std;
using ll = long long int;

void encuentra(int N, int X, int K) {
  ll ini = pregunta(1), pot = 1, pos = 0;
  while (pot <= N) pot *= 2;
  pot /= 2;
  if (X > ini) {
    while (pot > 1) {
      ll aux = pregunta((pos + pot) % N + 1);
      if (aux > ini && aux < X) {
        ini = aux;
        pos = (pos + pot) % N;
      }
      if (aux == X) {
        posicion((pos + pot) % N + 1);
        return;
      }
      pot /= 2;
    }
    pos = (pos + 1) % N;
    posicion(pos + 1);
  } else if (X < ini) {
    while (pot > 1) {
      ll aux = pregunta((pos - pot + N) % N + 1);
      if (aux > X && aux < ini) {
        ini = aux;
        pos = (pos - pot + N) % N;
      }
      if (aux == X) {
        posicion((pos - pot + N) % N + 1);
        return;
      }
      pot /= 2;
    }
    posicion((pos + N - 1) % N + 1);
  } else
    posicion(1);
  return;
}
