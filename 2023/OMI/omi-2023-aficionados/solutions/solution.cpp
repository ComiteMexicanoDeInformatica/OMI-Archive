#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<int> V(n);
  for (auto &e : V) cin >> e;

  if (V[0] == V[1]) {
    cout << "1 2\n";
    return 0;
  }

  for (int i = 0; i < n - 2; i++) {
    if (V[i] == V[i + 1] || V[i] == V[i + 2] || V[i + 1] == V[i + 2]) {
      cout << i + 1 << " " << i + 3 << endl;
      return 0;
    }
  }

  cout << "-1\n";
  return 0;
}
