#include <iostream>

#define lli long long
#define rep(i, a, b) for (lli i = (a); i <= (b); ++i)
#define repa(i, a, b) for (lli i = (a); i >= (b); --i)

#define nl "\n"
#define debugsl(x) cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << nl

#define MOD 1000000007
#define MAX_N 1000003

lli a, b, x, t, q, f[MAX_N];

int main() {
  std::cin >> q;
  while (q--) {
    std::cin >> a >> b >> t;

    if (t == 1)
      std::cout << a << nl;
    else if (t == 2)
      std::cout << b << nl;
    else {
      for (int c = 3; c <= t; c++) {
        x = a + b;
        x %= MOD;
        a = b;
        b = x;
      }
      std::cout << x << nl;
    }
  }

  return 0;
}
