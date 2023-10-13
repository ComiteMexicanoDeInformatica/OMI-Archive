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
  vector<ll> pref(m + m + 1);
  for (int k = m + m; k >= 1; k--) {
    if (marca1[k] != 0) la1 = k;
    minim[k] = min(minim[k], abs(la1 - k));
    ll uno = k - minim[k] + 1, dos = k + minim[k];
    if (minim[k] > 0 && marca[k] > 0) {
      uno = max((long long)2, uno);
      dos = min(m + m, dos);
      pref[uno] += marca[k], pref[dos] -= marca[k];
    }
  }
  ll maximo = 0;
  ll lleva = 0;
  for (int k = 2; k <= m + m; k++) {
    lleva += pref[k];
    if (marca1[k] == 0) {
      maximo = max(maximo, lleva);
    }
  }
  cout << max(maximo - c, (long long)0) << endl;
}

int main() {
  solve();
  return 0;
}