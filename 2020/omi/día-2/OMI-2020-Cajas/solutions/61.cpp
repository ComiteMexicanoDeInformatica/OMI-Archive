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

  for (int i = 1; i <= N; i++)
    if (ok(i)) {
      std::cout << i << "\n";
      exit(0);
    }
  return 0;
}