#include <iostream>
#define MAX 1000005
typedef long long ll;

ll preA[MAX];
ll preB[MAX];
ll A, B, I, P;
const int LIM = 1e6;
const ll MOD = 1e9 + 7;

void precalc() {
  preA[1] = preB[2] = 1;
  for (int i = 3; i <= LIM; i++) {
    preA[i] = (preA[i - 1] + preA[i - 2]) % MOD;
    preB[i] = (preB[i - 1] + preB[i - 2]) % MOD;
  }
}

void solve() {
  std::cin >> A >> B >> I;
  ll ans = (A * preA[I] + B * preB[I]) % MOD;
  std::cout << ans << "\n";
}

int main() {
  precalc();
  std::cin >> P;
  while (P--) solve();
  return 0;
}
