#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define f first
#define s second
void solve() {
  int n, l;
  cin >> n >> l;
  vector<int> arr(n + 1);
  for (int k = 1; k <= n; k++) {
    cin >> arr[k];
  }
  priority_queue<pair<int, int> > der, izq;
  for (int k = 1; k <= n; k++) {
    der.push({-(k + arr[k]), k});
  }
  for (int k = 1; k <= n; k++) {
    int uno = 1e9, dos = 1e9;
    while (der.size() > 0) {
      pair<int, int> le = der.top();
      if (le.s >= k) {
        uno = arr[le.s] + abs(le.s - k);
        break;
      }
      der.pop();
    }
    if (izq.size() > 0) {
      pair<int, int> le = izq.top();
      dos = arr[le.s] + abs(le.s - k);
    }
    izq.push({-(arr[k] + n - k), k});
    cout << min(uno, dos) << endl;
  }
}
int main() {
  solve();
  return 0;
}
