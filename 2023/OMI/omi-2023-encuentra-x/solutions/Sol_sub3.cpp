#include <iostream>

#include "encuentrax.h"

using namespace std;

void encuentra(int N, int X, int K) {
  int l = 1, r = N, m, num;
  while (l <= r) {
    m = (l + r) / 2;
    num = pregunta(m);
    if (num == X) {
      posicion(m);
      return;
    }
    if (num > X)
      r = m - 1;
    else
      l = m + 1;
  }
}
