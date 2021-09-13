#include <iostream>

#define lli long long
#define rep(i, a, b) for (lli i = (a); i <= (b); ++i)
#define repa(i, a, b) for (lli i = (a); i >= (b); --i)

#define nl "\n"
#define debugsl(x) cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << nl

#define MOD 1000000007
#define MAX_N 1000003

lli a, b, t, q, f[MAX_N];

int main() {
  f[1] = f[2] = 1;
  rep(i, 3, MAX_N - 1) f[i] = (f[i - 1] + f[i - 2]) % MOD;

  std::cin >> q;
  while (q--) {
    std::cin >> a >> b >> t;

    if (t == 1)
      std::cout << a << nl;
    else if (t == 2)
      std::cout << b << nl;
    else {
      t = (((a * f[t - 2]) % MOD) + ((b * f[t - 1]) % MOD)) % MOD;
      std::cout << t << nl;
    }
  }

  return 0;
}
