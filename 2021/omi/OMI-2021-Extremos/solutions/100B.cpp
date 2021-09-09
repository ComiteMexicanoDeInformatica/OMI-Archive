#include <iostream>
#include <set>
#include <vector>

#include "extremos.h"

void buscaExtremos(int n) {
  std::set<int> m, M;
  for (int i = 0; i < n; i += 2) {
    if (i + 1 >= n)
      m.insert(i), M.insert(i);
    else {
      if (esMenor(i + 1, i + 2))
        m.insert(i), M.insert(i + 1);
      else
        m.insert(i + 1), M.insert(i);
    }
  }
  int posMenor = *m.begin();
  m.erase(m.begin());
  for (auto i : m) {
    if (esMenor(i + 1, posMenor + 1)) posMenor = i;
  }
  int posMayor = *M.begin();
  M.erase(M.begin());
  for (auto i : M) {
    if (!esMenor(i + 1, posMayor + 1)) posMayor = i;
  }
  respuesta(posMenor + 1, posMayor + 1);
}
