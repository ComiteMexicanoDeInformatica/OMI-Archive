#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> V(n);
  for (int i = 0; i < n; i++) {
    cin >> V[i];
  }
  for (int l = 0; l < n; l++) {
    for (int r = l + 1; r < n; r++) {
      for (int k = 1; k <= 1000; k++) {
        int cnt = 0;
        for (int i = l; i <= r; i++) {
          if (V[i] == k) cnt++;
        }
        if (cnt > (r - l + 1) / 2) {
          cout << l + 1 << " " << r + 1 << '\n';
          return 0;
        }
      }
    }
  }
  cout << "-1\n" << endl;
  return 0;
}
