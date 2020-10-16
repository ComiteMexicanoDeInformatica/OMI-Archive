#include <algorithm>
#include <iostream>
#include <string>
#define lld long long int

const int MAXN = 1000002;

int n;
std::string S;

int dp[MAXN][2];
void DP() {
  dp[0][1] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      if (!((S[i] - '0' + j) & 1)) {
        dp[i][j] = dp[i - 1][j] + 1;
      } else {
        dp[i][j] = std::min(dp[i - 1][0], dp[i - 1][1]) + 2;
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cin >> n;
  std::cin >> S;
  DP();
  std::cout << dp[n - 1][0] << "\n";
  return 0;
}
