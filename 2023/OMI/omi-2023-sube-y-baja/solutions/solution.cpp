#include <bits/stdc++.h>

using namespace std;
int main() {
  int n, q;
  cin >> n >> q;
  vector<int> arr(n + 1), crecp(n + 1), crecs(n + 1), decrecp(n + 1),
      decrecs(n + 1);
  for (int k = 1; k <= n; k++) cin >> arr[k];
  for (int k = 1; k <= n - 1; k++) {
    if (arr[k] > arr[k + 1]) crecp[k] = k;
    if (arr[k] < arr[k + 1]) decrecp[k] = k;
  }
  int st1 = n, st2 = n;
  for (int k = n; k >= 1; k--) {
    if (crecp[k] != 0) st1 = crecp[k];
    if (decrecp[k] != 0) st2 = decrecp[k];
    crecp[k] = st1, decrecp[k] = st2;
  }
  for (int k = n; k >= 2; k--) {
    if (arr[k] < arr[k - 1]) crecs[k] = k;
    if (arr[k] > arr[k - 1]) decrecs[k] = k;
  }
  st1 = 1, st2 = 1;
  for (int k = 1; k <= n; k++) {
    if (crecs[k] != 0) st1 = crecs[k];
    if (decrecs[k] != 0) st2 = decrecs[k];
    crecs[k] = st1, decrecs[k] = st2;
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (crecp[l] >= decrecs[r] || decrecp[l] >= crecs[r])
      cout << 1 << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
