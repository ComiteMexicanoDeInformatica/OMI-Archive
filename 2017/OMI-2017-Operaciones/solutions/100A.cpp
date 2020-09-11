#include <bits/stdc++.h>
#define lld long long int
using namespace std;
const int MAXN = 1000002;

int n;
string S;

int dp[MAXN][2];
void DP() {
    dp[0][1] = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 2; j++) {
            if(!((S[i] - '0' + j) & 1)) {
                dp[i][j] = dp[i - 1][j] + 1;
            } else {
                dp[i][j] = min(dp[i - 1][0], dp[i - 1][1]) + 2;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    cin >> S;
    DP();
    cout << dp[n - 1][0] << "\n";
    return 0;
}
