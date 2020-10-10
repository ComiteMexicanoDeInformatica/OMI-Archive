#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

#include "primo.h"

std::vector<int> primes;

void SieveOfEratosthenes(int n) {
  bool prime[n + 1];
  std::memset(prime, true, sizeof(prime));

  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) {
        prime[i] = false;
      }
    }
  }

  for (int p = 2; p <= n; p++) {
    if (prime[p]) {
      primes.push_back(p);
    }
  }
}

int busca(int n) {
  int a, b = 0;
  int md = 0;
  int resp = 0;
  bool greater = false;

  SieveOfEratosthenes(n);

  b = primes.size();

  while (a != b) {
    md = (a + b - 1) / 2;
    resp = primo(md);

    greater = (resp == primes[md]);

    std::cout << "a: " << a << " b: " << b << " mid: " << md
              << " mayor: " << greater << std::endl;

    if (greater) {
      a = md + 1;
    } else {
      b = md;
    }
  }

  if (greater) {
    md++;
  }

  return primes[md];
}
