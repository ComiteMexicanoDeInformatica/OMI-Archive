#include "primo.h"

// Main
// int primo(int posicion)

#include <algorithm>
#include <chrono>
#include <random>
#include <vector>
#define pii std::pair<int, int>
#define fi first
#define se second

bool noPr[100000005];
std::vector<pii> p;
std::vector<int> p2;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

bool isPrime(int x) {
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return false;
  return true;
}

void getPrimes(int N) {
  for (int i = 2; i <= N; i++)
    if (isPrime(i)) {
      p.push_back({i, p.size()});
      p2.push_back(i);
    }
}

int busca(int n) {
  getPrimes(n);
  std::shuffle(p.begin(), p.end(), rng);
  int l = 0;
  int r = p.size() - 1;
  for (auto x : p) {
    if (x.se < l or x.se > r) continue;
    int q = primo(x.se);
    if (x.fi == q)
      l = x.se + 1;
    else
      r = x.se;
  }
  return p2[r];
}
