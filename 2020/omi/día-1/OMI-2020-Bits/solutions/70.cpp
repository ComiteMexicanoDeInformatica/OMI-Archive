#include <cstring>
#include <iostream>
typedef long long ll;

ll N, A, B, correct;
const ll MAX = 205;
const ll MOD = 1e9 + 7;
ll memo[MAX][MAX][MAX];
ll nck[MAX][MAX];

ll dp(ll pos, ll a, ll b) {
  if (memo[pos][a][b] != -1) return memo[pos][a][b];
  if (pos == 0) return 0;

  ll ans = 0;
  // Prende ambos
  if (a > 0 && b > 0) ans = dp(pos - 1, a - 1, b - 1) % MOD;
  // No prendas ninguno
  ans = (ans + dp(pos - 1, a, b)) % MOD;
  // Si solo prendemos A no habrá error, por lo que no lo consideraremos

  // Solo prendemos B, causa error para todo adelante
  if (b > 0) {
    ll tmp = (nck[pos - 1][a] * nck[pos - 1][b - 1]) % MOD;
    ans = (ans + tmp) % MOD;
  }

  return memo[pos][a][b] = ans;
}

int main() {
  std::cin >> N >> A >> B;
  if (N > 200) exit(0);

  for (ll n = 0; n <= N; n++)
    for (ll k = 0; k <= n; k++) {
      if (k == 0 or k == n)
        nck[n][k] = 1;
      else
        nck[n][k] = (nck[n - 1][k] + nck[n - 1][k - 1]) % MOD;
    }

  if (A == B) {
    ll ans = (nck[N][A] * nck[N][B]) % MOD;
    ans = (ans - nck[N][A] + MOD) % MOD;
    std::cout << ans << "\n";
    exit(0);
  }
  if (A < B) std::swap(A, B);

  memset(memo, -1, sizeof memo);
  std::cout << dp(N, A, B) << "\n";
  return 0;
}
