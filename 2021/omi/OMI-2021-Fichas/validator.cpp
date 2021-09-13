#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <optional>
#include <set>
#include <vector>

int64_t iniMat[55][10005];
int64_t newMat[55][10005];

double score(std::istream& f, int64_t N, int64_t M) {
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) {
      int64_t x;
      if (!(f >> x)) return 0.0;
      // Validate value range
      if (x < 1 or x > N) {
        std::cerr << "Table value out of range\n";
        return 0.0;
      }
      newMat[i][j] = x;
    }

  // Check moves are valid
  for (int i = 1; i <= N; i++) {
    // Rows must be equal
    std::vector<int64_t> inirow, newrow;
    for (int j = 1; j <= M; j++) {
      inirow.push_back(iniMat[i][j]);
      newrow.push_back(newMat[i][j]);
    }
    sort(inirow.begin(), inirow.end());
    sort(newrow.begin(), newrow.end());
    if (inirow != newrow) {
      std::cerr << "Contestant made an invalid move\n";
      return 0.0;
    }
  }

  // Calculate score
  int64_t good = 0;
  for (int j = 1; j <= M; j++) {
    std::vector<int64_t> col;
    for (int i = 1; i <= N; i++) col.push_back(newMat[i][j]);
    sort(col.begin(), col.end());

    // Column is good if all numbers are different
    bool ok = true;
    for (int i = 1; i < N; i++)
      if (col[i] == col[i - 1]) ok = false;
    good += ok;
  }

  // Point percentage, depending on how many cols are good
  return (double)good / (double)M;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int64_t N, M;
  {
    std::ifstream f("data.in");
    f >> N >> M;
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= M; j++) f >> iniMat[i][j];
  }

  printf("%.2f\n", score(std::cin, N, M));
}
