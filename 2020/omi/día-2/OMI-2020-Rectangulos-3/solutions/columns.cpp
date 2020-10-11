#include <iostream>
#include <utility>
#include <vector>

int main() {
  int w, h;
  std::cin >> w >> h;
  std::vector<std::pair<int, int>> x;
  int t = 0;

  int izq, der, abajo = 1;
  int arriba = h;

  for (izq = 1; izq <= w; t++, izq += t + 1) {
    x.push_back(std::make_pair(izq, std::min(izq + t, w)));
  }

  std::cout << x.size() << "\n";

  for (std::pair<int, int> i : x) {
    std::cout << i.first << " " << abajo << " " << i.second << " " << arriba
              << "\n";
  }

  return 0;
}
