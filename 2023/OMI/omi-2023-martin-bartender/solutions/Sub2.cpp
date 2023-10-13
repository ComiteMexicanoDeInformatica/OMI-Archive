#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define f first
#define s second
void solve() {
  int n, l;
  cin >> n >> l;
  vector<int> arr(n + 1);
  ll suma = 0;
  for (int k = 1; k <= n; k++) {
    cin >> arr[k];
    suma += arr[k];
  }
  for (int k = 1; k <= n; k++) {
    ll total = suma, uno = k - 1, dos = n - k, aux;
    aux = uno;
    aux *= uno + 1;
    aux /= 2;
    total += aux;
    aux = dos;
    aux *= dos + 1;
    aux /= 2;
    total += aux;
    cout << total << endl;
  }
}
int main() {
  solve();
  return 0;
}
