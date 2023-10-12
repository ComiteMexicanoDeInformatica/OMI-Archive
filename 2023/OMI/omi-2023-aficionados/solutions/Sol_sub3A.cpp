#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> V(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> V[i];
  }
  for (int k = 1; k <= 10; k++) {
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + (V[i] == k);
    }
    for (int l = 1; l <= n; l++) {
      for (int r = l + 1; r <= n; r++) {
        if (pref[r] - pref[l - 1] > (r - l + 1) / 2) {
          cout << l << " " << r << '\n';
          return 0;
        }
      }
    }
  }
  cout << "-1\n";
  return 0;
}
