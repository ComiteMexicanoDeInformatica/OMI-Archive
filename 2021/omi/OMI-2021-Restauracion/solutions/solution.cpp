#include <algorithm>
#include <iostream>
#define MAX 500005

int N, K, sz;
int h[MAX], k[MAX];
int lis[MAX], pos[MAX];

void fixPyramid(int lim) {
  for (int i = 1; i < lim; i++) {
    int vl = lis[i] + 1;
    int x = pos[i] + 1;
    while (x < pos[i + 1]) {
      h[x] = vl++;
      x++;
    }
  }
}

int getPos(int x, bool rt) {
  int l = 2, r = sz + 1;
  int ans = -1;
  while (l <= r) {
    int m = (l + r) / 2;

    // Check if can place here on LIS
    bool ok = true;
    // Look left
    int dist = x - pos[m - 1];
    if (lis[m - 1] + dist > h[x]) ok = false;
    // Look right
    if (rt && m < sz) {
      dist = pos[m + 1] - x;
      if (h[x] + dist > pos[m + 1]) ok = false;
    }

    if (ok) {
      ans = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return ans;
}

void solve(int L, int R) {
  sz = 1;
  lis[sz] = h[L];
  pos[sz] = L;
  for (int i = L + 1; i < R; i++) {
    int in = getPos(i, 1);
    if (in != -1 && (in > sz || lis[in] > h[i])) {
      lis[in] = h[i];
      pos[in] = i;
      sz = std::max(sz, in);
    }
  }
  int in = getPos(R, 0);
  lis[in] = h[R];
  pos[in] = R;
  sz = std::max(sz, in);
  fixPyramid(in);
}

bool impossible() {
  for (int i = 1; i < K; i++) {
    int pos1 = k[i];
    int pos2 = k[i + 1];
    int dist = pos2 - pos1;
    if (h[pos1] + dist > h[pos2]) return true;
  }
  return false;
}

int main() {
  std::cin >> N >> K;
  for (int i = 1; i <= N; i++) std::cin >> h[i];
  for (int i = 1; i <= K; i++) std::cin >> k[i];

  k[++K] = 0;
  k[++K] = ++N;
  h[0] = -1;
  h[N] = 2000005;
  std::sort(k + 1, k + K + 1);

  if (impossible()) {
    std::cout << "-1\n";
    exit(0);
  }

  for (int i = 1; i < K; i++) solve(k[i], k[i + 1]);

  for (int i = 1; i < N; i++) std::cout << h[i] << " \n"[i == N];

  return 0;
}
