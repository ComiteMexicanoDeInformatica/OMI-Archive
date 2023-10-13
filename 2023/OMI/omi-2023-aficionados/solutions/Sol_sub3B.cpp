#include <bits/stdc++.h>
using namespace std;

int freq[1001];
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> V(n);
  for (int i = 0; i < n; i++) {
    cin >> V[i];
  }
  for (int l = 0; l < n; l++) {
    int mx = 1;
    freq[V[l]]++;
    for (int r = l + 1; r < n; r++) {
      mx = max(++freq[V[r]], mx);
      if (mx > (r - l + 1) / 2) {
        cout << l + 1 << " " << r + 1 << '\n';
        return 0;
      }
    }
    for (int i = l; i < n; i++) {
      freq[V[i]]--;
    }
  }
  cout << "-1\n";
  return 0;
}
