#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()

vector<int> A, B;
bool solve(int l, int r) {
  auto it1 = lower_bound(all(A), l);
  auto it2 = lower_bound(all(A), r);
  auto it3 = lower_bound(all(B), l);
  auto it4 = lower_bound(all(B), r);
  if ((int)(it2 - it1) == 0 || (int)(it4 - it3) == 0) return 1;
  it2--;
  it4--;
  if (*it1 > *it4 || *it3 > *it2) return 1;
  return 0;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  vector<int> V(n);
  for (auto &e : V) cin >> e;
  for (int i = 0; i < n - 1; i++) {
    if (V[i] < V[i + 1]) A.push_back(i);
    if (V[i] > V[i + 1]) B.push_back(i);
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    if (solve(l, r))
      cout << "1\n";
    else
      cout << "0\n";
  }
}
