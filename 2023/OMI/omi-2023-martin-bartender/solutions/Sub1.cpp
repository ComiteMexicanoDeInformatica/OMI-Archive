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
  ll total = 0, aux;
  ll izq = 0, der = n - 1, uno, dos, mit1 = (l - 1) - ((l - 1) / 2),
     mit2 = (l - 1) / 2, usa1, usa2;
  for (int k = 1; k <= n; k++) {
    aux = arr[k];
    aux *= l;
    total = aux;
    uno = max(izq, der), dos = min(izq, der);
    usa2 = min(mit2, dos);
    usa1 = mit1 + mit2 - usa2;
    aux = usa1;
    aux *= usa1 + 1;
    aux /= 2;
    total += aux;
    aux = usa2;
    aux *= usa2 + 1;
    aux /= 2;
    total += aux;
    izq++, der--;
    cout << total << endl;
  }
}
int main() {
  solve();
  return 0;
}
