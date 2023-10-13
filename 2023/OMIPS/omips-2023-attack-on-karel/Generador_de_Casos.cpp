#include <chrono>
#include <random>

#include "../../../LibKarel/cpp/libkarel.h"
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void make_case(string case_name, int subtask_num) {
  Mundo mundo;
  mundo.width = 100;
  mundo.height = 100;
  mundo.xKarel = 1;
  mundo.yKarel = 1;
  mundo.direccionKarel = 0;
  int N = (rng() % 99) + 1;
  if (subtask_num == 1) N = 2;
  vector<int> V;
  V.resize(N + 2, 0);
  if (subtask_num == 2) {
    int S = 100;
    for (int i = 2; i < N + 2; i++) {
      V[i] = rng() % S;
      S -= V[i];
      V[i] += V[i - 1];
    }
  } else if (subtask_num == 3) {
    int S = 100 - N;
    for (int i = 2; i < N + 2; i++) {
      V[i] = rng() % S;
      S -= V[i];
      V[i] += V[i - 1] + 1;
    }
  } else {
    for (int i = 2; i < N + 2; i++) {
      V[i] = (rng() % 99) + 1;
    }
  }
  for (int i = 2; i < N + 2; i++) {
    mundo.beepers.push_back({1, i, V[i]});
  }
  mundo.print_to_file(case_name);
}

int main() {
  string line;
  ifstream testplan;
  testplan.open("testplan");
  while (getline(testplan, line)) {
    string case_name = "";
    for (int i = 0; i <= 5; i++) {
      case_name += line[i];
    }
    case_name += ".in";
    make_case(case_name, (int)(line[3] - '0'));
  }
  testplan.close();
}
