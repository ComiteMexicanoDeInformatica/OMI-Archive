#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define sz(a) (ll)(a.size())

int main() {
  int n, k;
  cin >> n >> k;
  multiset<pair<int, int>> A, B, C;
  vector<int> V(n);
  for (int i = 0; i < n; i++) {
    cin >> V[i];
    C.insert({V[i] + i, i});
  }

  ll sumA = 0, sumB = 0;
  for (int i = 0; i < k; i++) {
    B.insert(*C.begin());
    sumB += C.begin()->first;
    C.erase(*C.begin());
  }

  for (int i = 0; i < n; i++) {
    while (sz(A) && sz(C) && A.rbegin()->first + i > C.begin()->first - i) {
      sumA -= A.rbegin()->first;
      A.erase(*A.rbegin());
      sumB += C.begin()->first;
      B.insert(*C.begin());
      C.erase(*C.begin());
    }

    cout << sumA + sumB + (sz(A) - sz(B)) * i << " ";

    if (C.count({V[i] + i, i})) C.erase({V[i] + i, i});
    if (B.count({V[i] + i, i})) {
      B.erase({V[i] + i, i});
      sumB -= V[i] + i;
      A.insert({V[i] - i, i});
      sumB += V[i] - i;
    }
  }
  cout << endl;
}
