#include <iostream>

#include "encuentrax.h"

using namespace std;

void encuentra(int N, int X, int K) {
  int lmin = pregunta(1);
  if (lmin == X) {
    posicion(1);
    return;
  }
  int l = 2, r = N, m, num;
  while (l <= r) {
    m = (l + r) / 2;
    if (l == r) {
      posicion(l);
      return;
    }
    num = pregunta(m);
    if (X == num) {
      posicion(m);
      return;
    }
    if (num > lmin) {
      if (X > num || X < lmin)
        l = m + 1;
      else
        r = m - 1;
    } else {
      if (X < num || X > lmin)
        r = m - 1;
      else
        l = m + 1;
    }
  }
}
