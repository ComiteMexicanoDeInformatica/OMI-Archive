#include <iostream>

#define MAX 2000009
int n;
int r;
char v[MAX];
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cin >> n;
  for (int i = n - 1; i >= 0; i--) {
    std::cin >> v[i];
  }
  for (int i = 0; i < n;) {
    if (i == n - 2 && v[i] == '1' && v[i + 1] == '1') {
      r += 2;
      break;
    }
    if (v[i] == '1' && i == n - 1) break;
    if (v[i] == '1') {
      r++;
      v[i] = '0';
      if (i + 1 < n && v[i + 1] != '0') {
        int j = i + 1;
        while (j < n && v[j] != '0') {
          v[j++] = '0';
        }
        if (j == n) {
          n++;
        }
        v[j] = '1';
      }
    } else {
      i++;
      r++;
    }
  }
  std::cout << r << "\n";
}
