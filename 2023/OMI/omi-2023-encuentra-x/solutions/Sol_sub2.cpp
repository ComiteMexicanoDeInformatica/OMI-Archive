#include <iostream>

#include "encuentrax.h"

using namespace std;

void encuentra(int N, int X, int K) {
  int num = pregunta(1);
  if (X >= num) {
    posicion(X - num + 1);
    return;
  }
  posicion(X + (N - num + 1));
}
