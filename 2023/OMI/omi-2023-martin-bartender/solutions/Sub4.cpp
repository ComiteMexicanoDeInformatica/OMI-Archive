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
  vector<int> rec(n);
  if (n <= 1000) {
    for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
        rec[i - 1] = arr[i] + abs(i - k);
      }
      sort(rec.begin(), rec.end());
      ll total = 0;
      for (int i = 0; i < l; i++) {
        total += rec[i];
      }
      cout << total << endl;
    }
  } else
    l = rec[n + 3];
}
int main() {
  solve();
  return 0;
}
