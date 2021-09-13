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
int64_t mini, maxi, inflection;

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

  ff >> mini;
  if (mini == -1)
    impossible = 1;
  else
    ff >> maxi >> inflection;

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
    return 0.0;
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

  // User
  int changes = 0;
  for (int i = 1; i <= N; i++)
    if (user[i] != ini[i]) changes++;

  if (changes > maxi)
    return 0.0;
  else if (changes == maxi)
    return 0.1;
  else if (changes == mini)
    return 1.0;
  else if (changes >= inflection) {
    int difmin = maxi - inflection;
    int difanswer = maxi - changes;
    return 0.1 + (difanswer * 0.15 / difmin);
  }

  int difmax = inflection - mini;
  int difanswer = inflection - changes;
  return 0.25 + (difanswer * 0.75 / difmax);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  readTestCase();
  readCorrect();

  printf("%.2f\n", score(std::cin));
}