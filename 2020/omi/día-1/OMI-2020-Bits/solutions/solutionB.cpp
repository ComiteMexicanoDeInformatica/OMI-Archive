#include <iostream>

#define ll long long

ll pas[5001][5001];
int main() {
  const ll mod = 1000000007;
  ll ka, kb, n;
  std::cin >> n >> ka >> kb;
  if (kb > ka) {
    std::swap(ka, kb);
  }
  ll res = 0;
  for (ll a = 0; a <= n; a++) {
    for (ll b = 0; b <= n; b++) {
      if (b > a) {
        pas[a][b] = 0;
      } else {
        if (b == a || b == 0) {
          pas[a][b] = 1;
        } else {
          pas[a][b] = pas[a - 1][b - 1] + pas[a - 1][b];
          pas[a][b] %= mod;
        }
      }
    }
  }
  ll tem;
  ll temi;
  const ll cero = 0;
  for (ll a = 0; a < n; a++) {
    for (ll b = std::max(cero, (kb - 1) - (n - a - 1));
         b <= std::min(kb - 1, a); b++) {
      tem = pas[a][b];
      tem %= mod;
      temi = pas[(n - a - 1)][ka - b] * pas[(n - a - 1)][kb - b - 1];
      temi %= mod;
      tem *= temi;
      tem %= mod;
      res += tem;
      res %= mod;
      //	cout<<"b"<<b<<" "<<tem<<'\n';
    }
    //	cout<<"a"<<a<<" "<<res<<'\n';
  }
  if (ka == kb) {
    res *= 2;
    res %= mod;
  }
  std::cout << res;
  return 0;
}
