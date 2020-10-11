#include <algorithm>
#include <iostream>

int N, s[12], ans;

int main() {
  std::cin >> N;
  ans = N;
  for (int i = 0; i < N; i++) std::cin >> s[i];
  std::sort(s, s + N);

  do {
    int tmp = 1, can = s[0];
    for (int i = 1; i < N; i++) {
      if (can == 0) {
        can = s[i];
        tmp++;
      } else {
        can = std::min(can - 1, s[i]);
      }
    }
    ans = std::min(ans, tmp);
  } while (std::next_permutation(s, s + N));
  std::cout << ans;
  return 0;
}