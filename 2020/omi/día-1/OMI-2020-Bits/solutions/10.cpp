#include <cmath>
#include <iostream>

int N, A, B, ans;

int bits(int x) {
  int on = 0;
  while (x) {
    if (x % 2 == 1) on++;
    x /= 2;
  }
  return on;
}

int main() {
  std::cin >> N >> A >> B;
  if (N > 5) exit(0);

  for (int a = 0; a < pow(2, N); a++)
    for (int b = 0; b < pow(2, N); b++) {
      int bitsa = bits(a);
      int bitsb = bits(b);
      if (bitsa != A or bitsb != B) continue;
      if (!((A == B && a == b) or (A > B && a > b) or (A < B && a < b))) ans++;
    }
  std::cout << ans << "\n";
  return 0;
}