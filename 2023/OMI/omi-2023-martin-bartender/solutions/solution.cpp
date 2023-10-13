#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define f first
#define s second
void solve() {
  ll n, l;
  cin >> n >> l;
  vector<ll> arr(n + 1);
  for (int k = 1; k <= n; k++) {
    cin >> arr[k];
  }
  priority_queue<pair<ll, ll> > eliz, elde, rede, reiz;
  vector<pair<ll, ll> > ord;
  for (int k = 1; k <= n; k++) {
    ord.push_back({k + arr[k] - 1, k});
  }
  sort(ord.begin(), ord.end());
  ll suma = 0, total = 0;
  vector<int> marca(n + 1);
  for (int k = 0; k < n; k++) {
    if (k < l) {
      suma += ord[k].f;
      marca[ord[k].s] = 1;
      ord[k].f = arr[ord[k].s] + ord[k].s;
      elde.push(ord[k]);
    } else {
      ord[k].f = ord[k].s + arr[ord[k].s];
      ord[k].f *= -1;
      rede.push(ord[k]);
    }
  }
  // correcto
  for (int k = 1; k <= n; k++) {
    if (marca[k] == 1) total += arr[k] + k;
  }
  cout << suma << endl;
  ll cder = l, cizq = 0;
  // correcto de los Re queremos el menor y de los de el queremos el mayor
  for (int k = 2; k <= n; k++) {
    ll ent = 1;
    if (marca[k - 1] == 1) {
      total -= k - 1;
      total += n - (k - 1);
      cizq++, cder--;
      eliz.push({arr[k - 1] + n - (k - 1), k - 1});
    } else {
      reiz.push({-(arr[k - 1] + n - (k - 1)), k - 1});
    }
    // correcto
    while (ent == 1) {
      vector<pair<ll, ll> > cand, elim;
      while (rede.size() > 0) {
        pair<ll, ll> r = rede.top();
        if (r.s < k || marca[r.s] == 1) {
          rede.pop();
          continue;
        }
        cand.push_back({arr[r.s] + abs(r.s - k), r.s});
        break;
      }
      while (reiz.size() > 0) {
        pair<ll, ll> r = reiz.top();
        if (r.s >= k || marca[r.s] == 1) {
          reiz.pop();
          continue;
        }
        cand.push_back({arr[r.s] + abs(r.s - k), r.s});
        break;
      }
      while (elde.size() > 0) {
        pair<ll, ll> r = elde.top();
        if (r.s < k || marca[r.s] == 0) {
          elde.pop();
          continue;
        }
        elim.push_back({arr[r.s] + abs(r.s - k), r.s});
        break;
      }
      while (eliz.size() > 0) {
        pair<ll, ll> r = eliz.top();
        if (r.s >= k || marca[r.s] == 0) {
          eliz.pop();
          continue;
        }
        elim.push_back({arr[r.s] + abs(r.s - k), r.s});
        break;
      }
      // correcto
      sort(cand.begin(), cand.end());
      sort(elim.begin(), elim.end());
      reverse(elim.begin(), elim.end());
      if (elim.size() == 0 || cand.size() == 0) {
        break;
      }
      // correcto
      if (cand[0].f < elim[0].f) {
        marca[cand[0].s] = 1, marca[elim[0].s] = 0;
        total -= arr[elim[0].s];
        if (elim[0].s >= k) {
          total -= elim[0].s;
          cder--;
          rede.push({-(elim[0].s + arr[elim[0].s]), k});
        } else {
          total -= n - elim[0].s;
          cizq--;
          reiz.push({-(n - elim[0].s + arr[elim[0].s]), k});
        }
        total += arr[cand[0].s];
        if (cand[0].s >= k) {
          total += cand[0].s;
          cder++;
          elde.push({arr[cand[0].s] + cand[0].s, cand[0].s});
        } else {
          total += n - cand[0].s;
          cizq++;
          eliz.push({arr[cand[0].s] + n - cand[0].s, cand[0].s});
        }
      } else
        break;
    }
    ll ans = total;
    ll uno = cder;
    uno *= k;
    ans -= uno;
    uno = cizq;
    uno *= n - k;
    ans -= uno;
    cout << ans << endl;
  }
}
int main() {
  solve();
  return 0;
}
