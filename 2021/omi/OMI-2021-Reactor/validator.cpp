#include <fstream>
#include <iostream>

char ok_tipo, user_tipo;
int64_t ok_dur, ok_after;
int64_t user_dur, user_after;

const long double xx = 0.50;
const long double yy = 1.0 - xx;

void readCorrect() {
  std::ifstream f("data.out");
  f >> ok_tipo;
  f >> ok_dur >> ok_after;
  f.close();
}

double score(std::istream& f) {
  if (!(f >> user_tipo)) return 0;
  if (!(f >> user_dur)) return 0;
  if (!(f >> user_after)) return 0;

  long double score = 0.0;
  if (user_tipo == ok_tipo) score += xx;
  if (user_dur == ok_dur && user_after == ok_after) score += yy;
  return score;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  readCorrect();

  printf("%.2f\n", score(std::cin));
}