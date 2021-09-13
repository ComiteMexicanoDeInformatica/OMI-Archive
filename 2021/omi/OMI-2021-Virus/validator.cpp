#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <optional>
#include <set>
#include <vector>

int64_t ok_min, ok_max;
int64_t user_min, user_max;

const long double xx = 0.25;

void readCorrect() {
  std::ifstream f("data.out");
  f >> ok_min >> ok_max;
  f.close();
}

double score(std::istream& f) {
  if (!(f >> user_min)) return 0;
  if (!(f >> user_max)) return 0;

  long double score = 0.0;
  if (user_min == ok_min) score += 0.4;
  if (user_max == ok_max) score += 0.6;
  return score;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  readCorrect();

  printf("%.2f\n", score(std::cin));
}