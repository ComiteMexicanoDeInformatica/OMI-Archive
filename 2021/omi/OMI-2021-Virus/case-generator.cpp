#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <set>

std::ofstream testPlan("testplan");

int randBetween(int a, int b) { return (rand() % (b - a + 1) + a); }

std::set<std::pair<int, int> > edges;
std::vector<int> infected;
std::vector<int> notInfected;

void generate(std::string prefix, int numberCases, std::pair<int, int> rangeN,
              std::pair<int, int> rangeM, std::pair<int, int> rangeK,
              bool lockedInfected, bool lockedOrder) {
  for (int testCase = 0; testCase < numberCases; testCase++) {
    std::ofstream testFile(prefix + "." + std::to_string(testCase) + ".in");
    testPlan << prefix << "." << std::to_string(testCase) << " 1" << std::endl;
    int n = randBetween(rangeN.first, rangeN.second);
    int limitM =
        (n <= 20000) ? std::min(rangeM.second, n * (n - 1) / 2) : rangeM.second;
    int m = randBetween(rangeM.first, limitM);
    int k = randBetween(rangeK.first, std::min(rangeK.second, n));
    testFile << n << " " << m << " " << k << std::endl;

    infected.clear();
    notInfected.clear();
    edges.clear();
    for (int i = 1; i <= n; i++) {
      infected.push_back(i);
    }
    if (!lockedInfected) std::random_shuffle(infected.begin(), infected.end());
    while (infected.size() > k) {
      notInfected.push_back(infected[infected.size() - 1]);
      infected.pop_back();
    }

    for (int i = 0; i < k; i++) {
      testFile << infected[i];
      if (i < k - 1)
        testFile << " ";
      else
        testFile << "\n";
    }

    for (int i = 0; i < m; i++) {
      bool fromInfected = (bool)randBetween(0, 1);
      bool toInfected = (bool)randBetween(0, 1);
      if (k == n) {
        fromInfected = true;
        toInfected = true;
      }
      int computer_a = 0, computer_b = 0;

      if (fromInfected) {
        int id = randBetween(0, infected.size() - 1);
        computer_a = infected[id];
      } else {
        int id = randBetween(0, notInfected.size() - 1);
        computer_a = notInfected[id];
      }

      if (toInfected) {
        int id = randBetween(0, infected.size() - 1);
        computer_b = infected[id];
      } else {
        int id = randBetween(0, notInfected.size() - 1);
        computer_b = notInfected[id];
      }

      if (computer_a == computer_b ||
          (edges.find(std::make_pair(computer_a, computer_b)) != edges.end())) {
        i--;
        continue;
      }
      edges.insert(std::make_pair(computer_a, computer_b));
      if (lockedOrder) {
        if (computer_a > computer_b) std::swap(computer_a, computer_b);
      }
      testFile << computer_a << " " << computer_b << std::endl;
    }
  }
}

int main() {
  // Solo hay una computadora infectada y es la computadora 1
  generate("sub1", 40, std::make_pair(50000, 100000),
           std::make_pair(50000, 100000), std::make_pair(1, 1), true, false);
  // N <= 3
  generate("sub2", 8, std::make_pair(2, 3), std::make_pair(1, 3),
           std::make_pair(1, 1), false, false);
  // M <= 10
  generate("sub3", 12, std::make_pair(50000, 100000), std::make_pair(1, 10),
           std::make_pair(1, 100000), false, false);
  // a_i < b_i para todos los mensajes
  generate("sub4", 20, std::make_pair(50000, 100000),
           std::make_pair(50000, 100000), std::make_pair(50000, 100000), false,
           true);
  // Sin restricciones adicionales
  generate("sub5", 20, std::make_pair(50000, 100000),
           std::make_pair(50000, 100000), std::make_pair(50000, 100000), false,
           false);
  return 0;
}