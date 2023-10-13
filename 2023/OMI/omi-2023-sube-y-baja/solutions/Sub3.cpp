#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
int main() {
  int n, q;
  cin >> n >> q;
  vector<int> arr(n + 1);
  vector<int> pref(n + 1);
  for (int k = 1; k <= n; k++) {
    cin >> arr[k];
  }
  int lleva = 0;
  for (int k = 2; k <= n - 1; k++) {
    if ((arr[k - 1] > arr[k] && arr[k] < arr[k + 1]) ||
        (arr[k - 1] < arr[k] && arr[k] > arr[k + 1])) {
      lleva++;
    }
    pref[k] = lleva;
  }
  pref[n] = lleva;
  vector<pair<int, int> > queries(q + 1);
  int si = 1;
  for (int k = 1; k <= q; k++) {
    cin >> queries[k].f >> queries[k].s;
    if (queries[k].f + 2 != queries[k].s) si = 0;
  }
  for (int k = 1; k <= q; k++) {
    int l, r;
    l = queries[k].f, r = queries[k].s;
    if (si == 1) {
      cout << -1 << endl;
      continue;
    }
    if (r - l > 2) {
      int total = pref[r - 1] - pref[l];
      if (total > 1) {
        cout << 0 << endl;
      } else
        cout << 1 << endl;
    } else
      cout << 1 << endl;
  }
  return 0;
}
