#include <iostream>
int cajas[100001];
int tam[100001];
int main() {
  int n;
  std::cin >> n;
  int tem;
  for (int i = 0; i < n; i++) {
    std::cin >> tem;
    cajas[tem]++;
  }
  if (n == 0) {
    std::cout << 0;
    return 0;
  }
  int res = 0;
  int mini = 0;
  for (int i = 0; i < 50001; i++) {
    for (int j = 0; j < cajas[i]; j++) {
      if (res == 0) {
        res = 1;
        mini = 1;
        tam[1] = 1;
      } else {
        if (mini <= i) {
          tam[mini + 1]++;
          tam[mini]--;
          if (tam[mini] == 0) {
            mini++;
          }
        } else {
          mini = 1;
          res++;
          tam[1]++;
        }
      }
    }
  }
  std::cout << res;
  return 0;
}
