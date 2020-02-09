#include <bits/stdc++.h>
using namespace std;
typedef pair < int, int > pii;
typedef long long int lld;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; ++i)
    cin >> arr[i];

  if (n == 1) {
    cout << "0\n";
    return 0;
  }

  int ans = -1;
  for(int f = -1; f <= 1; ++f) for (int s = -1; s <= 1; ++s) {
    arr[0] += f; arr[1] += s;

    bool progresion = true;
    int cnt = abs(f) + abs(s);
    int k = arr[1] - arr[0];
    int act = arr[0];

    for (int i = 1; i < n; ++i) {
      act += k;
      if (abs(act - arr[i]) > 1) {
        progresion = false;
        break;
      }
      cnt += abs(act - arr[i]);
    }
    if (progresion) ans = ans == -1 ? cnt : min(ans, cnt);

    arr[0] -= f; arr[1] -= s;
  }

  cout << ans << "\n";
  return 0;
}
