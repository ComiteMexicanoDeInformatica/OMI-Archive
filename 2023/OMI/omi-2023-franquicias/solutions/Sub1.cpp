#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
void solve() {
  ll n, m, fe, p;
  cin >> n >> m >> fe >> p;
  ll b, c;
  cin >> b >> c;
  vector<ll> marca1(m + m + 1);
  for (int k = 0; k < fe; k++) {
    int hk;
    cin >> hk;
    marca1[hk * 2] = 1;
  }
  vector<ll> marca(m + m + 1);
  ll uno;
  for (int k = 0; k < p; k++) {
    ll rs, re;
    cin >> rs >> re;
    uno = re;
    uno *= b;
    marca[rs * 2] = uno;
  }
  ll la1 = -1e9;
  vector<ll> minim(m + m + 1);
  for (int k = 1; k <= m + m; k++) {
    if (marca1[k] != 0) la1 = k;
    minim[k] = abs(la1 - k);
  }
  la1 = -1e9;
  for (int k = m + m; k >= 1; k--) {
    if (marca1[k] != 0) la1 = k;
    minim[k] = min(minim[k], abs(la1 - k));
  }
  ll maximo = 0;
  for (int k = 2; k <= m + m; k++) {
    if (marca1[k] == 0) {
      ll total = 0;
      for (int i = 1; i <= m + m; i++) {
        if (minim[i] > abs(k - i)) {
          total += marca[i];
        }
      }
      maximo = max(maximo, total);
    }
  }
  cout << maximo << endl;
}

int main() {
  solve();
  return 0;
}
