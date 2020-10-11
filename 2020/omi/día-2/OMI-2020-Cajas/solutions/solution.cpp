#include <algorithm>
#include <iostream>

#define MAX 100005

int N, s[MAX];

bool ok(int k) {
  for (int i = 0; i < N; i++)
    if (s[i] < i / k) return false;
  return true;
}

int main() {
  std::cin >> N;
  for (int i = 0; i < N; i++) std::cin >> s[i];
  std::sort(s, s + N);

  int l = 1, r = N;
  while (l < r) {
    int m = (l + r) / 2;
    if (ok(m))
      r = m;
    else
      l = m + 1;
  }
  std::cout << l << "\n";
  return 0;
}