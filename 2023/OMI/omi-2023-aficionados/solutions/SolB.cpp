#include <bits/stdc++.h>
using namespace std;
const int Mxn = 2e5 + 1;

array<int, 2> ans = {-1, -1};
int freq[1001];
int A[Mxn];

void solve(int L, int R) {
  if (L == R) return;
  int Mid = (L + R) >> 1;
  solve(L, Mid);
  solve(Mid + 1, R);

  int mx = 0;
  for (int i = L; i <= R; i++) {
    mx = max(++freq[A[i]], mx);
  }
  if (mx > (R - L + 1) / 2) ans = {L, R};
  for (int i = L; i <= R; i++) {
    freq[A[i]]--;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> A[i];
  solve(1, n);
  if (ans[0] != -1)
    cout << ans[0] << " " << ans[1] << '\n';
  else
    cout << "-1\n";

  return 0;
}
