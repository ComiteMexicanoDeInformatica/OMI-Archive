#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <optional>
#include <set>
#include <vector>

const int MAX = 5e5 + 5;
int64_t N, K;
int64_t ini[MAX], same[MAX], user[MAX];
int64_t correct[MAX];
bool impossible;

const long double xx = 0.25;

void readTestCase() {
  std::ifstream f("data.in");
  f >> N >> K;
  for (int i = 1; i <= N; i++) f >> ini[i];
  for (int i = 1; i <= K; i++) f >> same[i];
  f.close();
}

void readCorrect() {
  std::ifstream ff("data.out");
  for (int i = 1; i <= N; i++) {
    ff >> correct[i];
    if (i == 1 && correct[i] == -1) {
      impossible = 1;
      return;
    }
  }
  ff.close();
}

double score(std::istream& f) {
  if (impossible) {
    int64_t x;
    if (!(f >> x))
      std::cout << "0\n";
    else if (x != -1)
      std::cout << "0\n";
    else if (f >> x)
      std::cout << "0\n";
    else
      std::cout << "1\n";
    exit(0);
  }

  for (int i = 1; i <= N; i++) {
    if (!(f >> user[i])) return 0.0;
  }

  if (f >> user[0]) return 0.0;

  // Check no modifications to K steps
  for (int i = 1; i <= K; i++)
    if (ini[same[i]] != user[same[i]]) {
      std::cerr
          << "Se modifico uno de los escalones que no se debian de modificar\n";
      return 0.0;
    }

  // Check it is ascending
  for (int i = 2; i <= N; i++)
    if (user[i - 1] >= user[i]) {
      std::cerr << "Escalera no esta en orden creciente\n";
      return 0.0;
    }

  // Optimal
  int opt = 0;
  for (int i = 1; i <= N; i++)
    if (correct[i] != ini[i]) opt++;

  // User
  int changes = 0;
  for (int i = 1; i <= N; i++)
    if (user[i] != ini[i]) changes++;

  if (changes <= opt) return 1.0;

  long double score = (long double)opt / (long double)changes;
  return std::max(score, xx);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  readTestCase();
  readCorrect();

  printf("%.2f\n", score(std::cin));
}