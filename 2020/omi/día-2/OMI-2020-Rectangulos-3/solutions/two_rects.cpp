#include <iostream>

int main() {
  int w, h;
  std::cin >> w >> h;

  std::cout << 2 << "\n"
            << 1 << " " << 1 << " " << 1 << " " << h << "\n"
            << 3 << " " << 1 << " " << w << " " << h << "\n";

  return 0;
}
