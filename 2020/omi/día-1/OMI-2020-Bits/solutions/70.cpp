#include <cstring>
#include <iostream>

int N, A, B, correct;
const int MAX = 205;
const int MOD = 1e9 + 7;
int memo[MAX][MAX][MAX][3];

// t = quien es mayor (2 = A / 1 = B / 0 = iguales)
int dp(int pos, int a, int b, int t) {
  if (memo[pos][a][b][t] != -1) return memo[pos][a][b][t];

  if (pos > N) {
    if (!a && !b && t != correct) return 1;
    return 0;
  }

  long long ans = 0;

  // No prendas ninguno
  ans = (ans + dp(pos + 1, a, b, t)) % MOD;

  // Prende los dos
  if (a > 0 && b > 0) ans = (ans + dp(pos + 1, a - 1, b - 1, t)) % MOD;

  // Prende a, no b
  if (a > 0) ans = (ans + dp(pos + 1, a - 1, b, (t ? t : 2))) % MOD;

  // Prende b, no a
  if (b > 0) ans = (ans + dp(pos + 1, a, b - 1, (t ? t : 1))) % MOD;

  return memo[pos][a][b][t] = ans;
}

int main() {
  std::cin >> N >> A >> B;
  if (N > 200) exit(0);
  if (A > B) correct = 2;
  if (B > A) correct = 1;
  memset(memo, -1, sizeof memo);
  std::cout << dp(1, A, B, 0) << "\n";
  return 0;
}