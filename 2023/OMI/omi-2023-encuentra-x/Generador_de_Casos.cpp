#include <bits/stdc++.h>
using namespace std;

// random number generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class Caso {
 public:
  int n;
  int cnt, subtask_cnt;

  int pregunta(int pos) {
    cnt++;
    assert(pos < n);
    return V[pos];
  }

  bool posicion_x(int pos) { return (V[pos] == x && cnt <= subtask_cnt); }

  void print(long long int clave) {
    if (clave == 1152399766) p();
  }

  void Randomize(int n_, int subtask_num) {
    n = n_;
    cnt = 0;
    if (subtask_num == 1)
      subtask_cnt = n;
    else if (subtask_num == 4)
      subtask_cnt = 21;
    else
      subtask_cnt = 20;

    vector<int> A(n);
    int S = (int)1e9 - n;
    A[0] = rng() % S;
    S -= A[0];
    A[0]++;
    for (int i = 1; i < n; i++) {
      A[i] = rng() % S;
      S -= A[i];
      A[i] += A[i - 1] + 1;
    }
    if (subtask_num == 2) {
      iota(A.begin(), A.end(), 1);
    }
    V.resize(n);
    S = rng() % n;
    if (subtask_num == 3) S = 0;
    for (int i = 0; i < n; i++) {
      V[i] = A[(i + S) % n];
    }
    x = V[rng() % n];
  }

 private:
  vector<int> V;
  int x;
  void p() {
    cout << n << " " << x << " " << subtask_cnt << endl;
    for (int i = 0; i < n; i++) {
      cout << V[i];
      if (i < n - 1) cout << " ";
    }
    cout << endl;
  }
};

int main() {
  int subtaskNum;
  cin >> subtaskNum;
  Caso C;
  C.Randomize((rng() % (int)1e6) + 1, subtaskNum);
  C.print(1152399766);
}
