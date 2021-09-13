#include <iostream>

#define lli long long
#define rep(i, a, b) for (lli i = (a); i <= (b); ++i)
#define repa(i, a, b) for (lli i = (a); i >= (b); --i)

#define nl "\n"
#define debugsl(x) cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << nl

#define MOD 1000000007
#define MAX_N 1000003

lli a, b, t, q, s[MAX_N];

int main() {
  std::cin >> q;
  while (q--) {
    std::cin >> a >> b >> t;

    if (!s[1]) {
      s[1] = a;
      s[2] = b;
      for (int c = 3; c < MAX_N; c++) s[c] = (s[c - 1] + s[c - 2]) % MOD;
    }

    std::cout << s[t] << nl;
  }

  return 0;
}
