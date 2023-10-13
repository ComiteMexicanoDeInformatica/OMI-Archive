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
  vector<ll> marca1(m + 1);
  for (int k = 0; k < fe; k++) {
    int hk;
    cin >> hk;
    marca1[hk] = 1;
  }
  vector<ll> marca(m + 1);
  ll uno;
  for (int k = 0; k < p; k++) {
    ll rs, re;
    cin >> rs >> re;
    uno = re;
    uno *= b;
    marca[rs] = uno;
  }
  ll la1 = -1e9;
  vector<ll> minim(m + 1);
  for (int k = 1; k <= m; k++) {
    if (marca1[k] != 0) la1 = k;
    minim[k] = abs(la1 - k);
  }
  la1 = -1e9;
  for (int k = m; k >= 1; k--) {
    if (marca1[k] != 0) la1 = k;
    minim[k] = min(minim[k], abs(la1 - k));
  }
  ll total = 0;
  for (int k = 1; k <= m; k++) {
    if (marca1[k] == 0) {
      total += marca[k];
    }
  }
  cout << total << endl;
}

int main() {
  solve();
  return 0;
}
