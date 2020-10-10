#include <cmath>
#include <iostream>
#include <map>
#include <vector>
typedef long long ll;

const int MOD = 1e9 + 7;
int N, A, B, ans;
std::vector<int> bitsa, bitsb;
const ll LIM = 5000;
ll fact[LIM + 5];
ll finv[LIM + 5];

int bits(int x) {
  int on = 0;
  while (x) {
    if (x % 2 == 1) on++;
    x /= 2;
  }
  return on;
}

ll fastpow(ll b, ll e) {
  ll ans = 1;
  while (e > 0) {
    if (e & 1) ans = (ans * b) % MOD;

    b = (b * b) % MOD;
    e >>= 1;
  }
  return ans;
}

ll nCk(ll n, ll k) { return (fact[n] * ((finv[k] * finv[n - k]) % MOD)) % MOD; }

int main() {
  std::cin >> N >> A >> B;
  if (N > 16) {
    fact[0] = finv[0] = 1;
    for (ll i = 1; i <= LIM; i++) fact[i] = (fact[i - 1] * i) % MOD;

    finv[LIM] = fastpow(fact[LIM], MOD - 2);

    for (ll i = LIM - 1; i >= 1; i--) finv[i] = (finv[i + 1] * (i + 1)) % MOD;
    ll ans = (nCk(N, A) * nCk(N, A)) % MOD;
    ans = (ans - nCk(N, A) + MOD) % MOD;
    std::cout << ans << "\n";
    exit(0);
  }

  for (int i = 0; i < pow(2, N); i++) {
    if (bits(i) == A) bitsa.push_back(i);
    if (bits(i) == B) bitsb.push_back(i);
  }

  if (A == B) {
    ans += bitsa.size() * bitsb.size();
    std::map<int, int> mp;
    for (auto& x : bitsa) mp[x]++;
    for (auto& x : bitsb) ans -= mp[x];
  } else if (A > B) {
    int ptb = 0;
    for (auto& a : bitsa) {
      while (ptb < bitsb.size() && bitsb[ptb] < a) ptb++;
      ans += bitsb.size() - ptb;
    }
  } else {
    int pta = 0;
    for (auto& b : bitsb) {
      while (pta < bitsa.size() && bitsa[pta] < b) pta++;
      ans += bitsa.size() - pta;
    }
  }

  std::cout << ans << "\n";
  return 0;
}