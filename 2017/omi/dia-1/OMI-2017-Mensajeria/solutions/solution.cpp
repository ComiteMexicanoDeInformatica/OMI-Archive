#include <algorithm>
#include <iostream>

#define MAX 1000002
bool ok;
int n, k;
int v[MAX];
int s, mayor = 0;
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cin >> n >> k;
  for (int i = 0; i < n; i++) {
    std::cin >> v[i];
    mayor = std::max(mayor, v[i]);
    if (v[i] > k) {
      s += k;
      ok = true;
    } else
      s += v[i];
  }
  if (!ok) s += abs(mayor - k);
  std::cout << s << "\n";
}
