#include <algorithm>
#include <iostream>

#define lli long long
#define rep(i, a, b) for (lli i = (a); i <= (b); ++i)
#define repa(i, a, b) for (lli i = (a); i >= (b); --i)

#define nl "\n"
#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << nl

#define MAX_N 100003

lli n, k, d, h[MAX_N], deja[MAX_N], dejaq[MAX_N], ult, intactas[MAX_N],
    lis[MAX_N], llis[MAX_N], largolis, poslis, minimo, maximo, quiebre;
lli sigintacta[MAX_N], maxval[MAX_N], res[MAX_N];
lli l, r, mitad;

int main() {
  std::cin >> n >> k;
  rep(i, 1, n) std::cin >> h[i];
  rep(i, 1, k) std::cin >> intactas[i];
  std::sort(intactas + 1, intactas + 1 + k);
  h[0] = -1;
  h[n + 1] = 1100001;
  intactas[k + 1] = n + 1;

  // Valida que la restauracion sea posible.
  rep(i, 1, k) {
    d = h[intactas[i]] - h[intactas[i - 1]];
    if (d <= 0 || intactas[i] - intactas[i - 1] >= d) {
      std::cout << -1 << nl;
      return 0;
    }
  }

  rep(i, 1, k) dejaq[intactas[i]] = 1;
  sigintacta[n + 1] = n + 1;
  repa(i, n, 1) {
    if (dejaq[i])
      sigintacta[i] = i;
    else
      sigintacta[i] = sigintacta[i + 1];
  }
  rep(i, 1, n) {
    if (dejaq[i])
      maxval[i] = i;
    else
      maxval[i] = h[sigintacta[i]] - (sigintacta[i] - i);
  }

  ult = -1;
  rep(i, 1, n) {
    if (!dejaq[i] && (h[i] <= ult || h[i] > maxval[i])) {
      ult++;
      res[i] = ult;
    } else {
      ult = h[i];
      res[i] = h[i];
    }
  }

  // Construye la escalera
  rep(i, 1, n) { std::cout << res[i] << " "; }
  std::cout << nl;

  return 0;
}
