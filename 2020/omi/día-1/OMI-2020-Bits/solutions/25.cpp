#include <cmath>
#include <iostream>
#include <map>
#include <vector>

const int MOD = 1e9 + 7;
int N, A, B, ans;
std::vector<int> bitsa, bitsb;

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
  if (N > 16) exit(0);

  for (int i = 0; i < pow(2, N); i++) {
    if (bits(i) == A) bitsa.push_back(i);
    if (bits(i) == B) bitsb.push_back(i);
  }

  if (A == B) {
    ans += bitsa.size() * bitsb.size();
    std::map<int, int> mp;
    for (auto& x : bitsa) mp[x]++;
    for (auto& x : bitsb) ans -= mp[x];
  } else if (A > B) {
    int ptb = 0;
    for (auto& a : bitsa) {
      while (ptb < bitsb.size() && bitsb[ptb] < a) ptb++;
      ans += bitsb.size() - ptb;
    }
  } else {
    int pta = 0;
    for (auto& b : bitsb) {
      while (pta < bitsa.size() && bitsa[pta] < b) pta++;
      ans += bitsa.size() - pta;
    }
  }

  std::cout << ans << "\n";
  return 0;
}