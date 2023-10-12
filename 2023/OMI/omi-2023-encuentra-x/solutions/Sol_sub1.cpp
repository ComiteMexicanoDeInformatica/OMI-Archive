#include <iostream>

#include "encuentrax.h"

using namespace std;

void encuentra(int N, int X, int K) {
  int num;
  for (int i = 1; i <= N; ++i) {
    num = pregunta(i);
    if (num == X) {
      posicion(i);
      return;
    }
  }
}
