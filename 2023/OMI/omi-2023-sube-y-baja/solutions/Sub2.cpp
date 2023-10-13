#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> arr(n + 1);
  for (int k = 1; k <= n; k++) {
    cin >> arr[k];
  }
  vector<pair<int, int> > queries(q + 1);
  int si = 1;
  for (int k = 1; k <= q; k++) {
    cin >> queries[k].f >> queries[k].s;
    if (queries[k].f + 2 != queries[k].s) si = 0;
  }
  for (int k = 1; k <= q; k++) {
    int l, r;
    l = queries[k].f, r = queries[k].s;
    int cnt = 0;
    int ind = -1;
    for (int k = l; k <= r; k++) {
      if (ind == 0) {
        if (arr[k] < arr[k - 1]) {
          ind = 1;
          cnt++;
        }
      } else {
        if (ind == 1) {
          if (arr[k] > arr[k - 1]) {
            ind = 0;
            cnt++;
          }
        } else {
          if (arr[k] > arr[l]) {
            ind = 0;
          }
          if (arr[k] < arr[l]) {
            ind = 1;
          }
        }
      }
    }
    if (si == 1) {
      cout << -1 << endl;
      continue;
    }
    if (cnt <= 1) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
  }
}
int main() {
  solve();
  return 0;
}
