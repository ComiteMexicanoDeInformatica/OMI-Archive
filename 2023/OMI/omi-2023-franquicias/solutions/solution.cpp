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
  vector<ll> jeje(fe);
  for (int k = 0; k < fe; k++) {
    int hk;
    cin >> hk;
    jeje[k] = hk * 2;
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
  ll lleva = 0;
  for (int k = 2; k <= m + m; k++) {
    lleva += pref[k];
    pref[k] = lleva;
  }
  priority_queue<pair<ll, ll> > pq;
  for (int k = 0; k < fe - 1; k++) {
    // sacamos el mejor y el total
    ll jsj = 0, mej = -1e18;
    for (int i = jeje[k] + 1; i < jeje[k + 1]; i++) {
      jsj += marca[i];
      mej = max(mej, pref[i]);
    }
    pq.push({mej, jsj});
    // cout<<mej<<" "<<jsj<<endl;
  }
  ll jsj = 0;
  for (int k = 2; k < jeje[0]; k++) {
    jsj += marca[k];
  }
  pq.push({jsj, -1});
  jsj = 0;
  for (int k = jeje[fe - 1] + 1; k <= m + m; k++) {
    jsj += marca[k];
  }
  pq.push({jsj, -1});
  ll ans = 0, cnte = 0;
  while (pq.size() > 0 && pq.top().f > c && cnte < n) {
    cnte++;
    pair<ll, ll> r = pq.top();
    pq.pop();
    ans += r.f - c;
    if (r.s != -1) {
      pq.push({r.s - r.f, -1});
    }
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}
