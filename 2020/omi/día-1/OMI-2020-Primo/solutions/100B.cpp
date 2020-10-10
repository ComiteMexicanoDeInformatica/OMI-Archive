#include <iostream>
#include <vector>

#include "primo.h"

typedef long long int lld;

void criba(int n, std::vector<int>& primos) {
  std::vector<bool> vis(n + 1);

  for (lld i = 2; i <= n; ++i) {
    if (vis[i]) continue;
    primos.push_back(i);
    for (lld j = i * i; j <= n; j += i) {
      vis[j] = true;
    }
  }
}

int busca(int n) {
  std::vector<int> primos;
  criba(n, primos);

  int l = 0, r = primos.size() - 1;
  while (l < r) {
    int med = (l + r) / 2;
    if (primo(med) == primos[med]) {
      l = med + 1;
    } else {
      r = med;
    }
  }
  return primos[l];
}
