#include <array>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "../../../LibKarel/cpp/libkarel.h"
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<array<int, 3>> dd;

int W = 100, H = 100;
vector<vector<bool>> vis;
vector<array<int, 3>> Path;

bool legal(int x, int y) {
  if (vis[x][y]) return 0;
  if (x < 2 || x > W - 1) return 0;
  if (y < 2 || y > H - 1) return 0;
  return 1;
}

void randomize(int p, int q) {
  if (rng() % p < q) {
    for (int i = 0; i < 3; i++) {
      int j = (rng() % (4 - i)) + i;
      swap(dd[i], dd[j]);
    }
  }
}

void search(int x, int y, int p, int q) {
  vis[x][y] = true;
  for (auto [dx, dy, t] : dd) {
    if (!legal(x + dx, y + dy)) continue;
    Path.push_back({x + dx, y + dy, t});
    randomize(p, q);
    search(x + dx, y + dy, p, q);
    break;
  }
}

void make_random(string case_name = "test.in", bool flag_corners = false,
                 bool flag_consecutive = false, int p = 2, int q = 2,
                 long long int P = 2, long long int Q = 2) {
  MundoKarel Mundo(W, H);
  vis.clear();
  vis.assign(W + 1, vector<bool>(H + 1, false));
  Path.clear();

  array<int, 2> Start = {(rng() % (W - 2)) + 2, (rng() % (H - 2)) + 2};
  Mundo.xKarel = Start[0];
  Mundo.yKarel = Start[1];
  Mundo.mochilaKarel = -1;
  Mundo.direccionKarel = 1;

  dd.clear();
  dd = {{1, 0, 1}, {0, 1, 2}, {0, -1, 0}, {-1, 0, 3}};

  Path.push_back({Start[0], Start[1], 1});
  vis[Start[0] - 1][Start[1]] = true;

  if (P < Q) swap(P, Q);
  if (p < q) swap(p, q);
  if (Q > P / 2)
    P += Q;  // la probabilidad de hacer un hueco es al menos un medio.
  search(Start[0], Start[1], p, q);

  bool almenosuna = false;

  for (auto [x, y, t] : Path) {
    for (int i = 0; i < 4; i++) Mundo.setWall(x, y, i);
  }
  for (auto [x, y, t] : Path) {
    Mundo.unsetWall(x, y, t);
  }
  bool last = false;
  for (int i = 0; auto [x, y, t] : Path) {
    i++;
    if (i != 1 && !vis[x][y - 1] && i != (int)Path.size()) {
      auto [a, b, c] = Path[i];

      if (flag_consecutive && last) {
        last = false;
        continue;
      }
      if (flag_corners && (t == 0 || c == 2)) {
        last = true;
        continue;
      }
      if (!almenosuna || rng() % P >= Q) {
        Mundo.unsetWall(x, y, 2);
        Mundo.posicionDump.insert({x, y});
        last = true;
        almenosuna = true;
      }
    }
  }

  if (!almenosuna) {
    make_random(case_name, flag_corners, flag_consecutive, p, q, P, Q);
    return;
  }

  Mundo.print_to_file(case_name);
}

void make_maze(string case_name) {
  MundoKarel Mundo(W, H);
  vis.clear();
  vis.assign(W + 1, vector<bool>(H + 1, false));
  Path.clear();

  array<int, 2> Start = {(rng() % (W - 2)) + 2, (rng() % (H - 2)) + 2};
  Mundo.xKarel = Start[0];
  Mundo.yKarel = Start[1];
  Mundo.mochilaKarel = -1;
  Mundo.direccionKarel = 0;

  dd.clear();
  dd = {{0, 1, 2}, {0, -1, 0}, {1, 0, 1}, {-1, 0, 3}};

  Path.push_back({Start[0], Start[1], 2});
  vis[Start[0]][Start[1] - 1] = true;

  int p = rng(), q = rng();
  if (p < q) swap(q, p);
  search(Start[0], Start[1], p, q);

  for (auto [x, y, t] : Path) {
    for (int i = 0; i < 4; i++) Mundo.setWall(x, y, i);
  }
  for (auto [x, y, t] : Path) {
    Mundo.unsetWall(x, y, t);
  }
  bool flag = false;
  for (int i = 0; auto [x, y, t] : Path) {
    i++;
    if (i != 1 && !vis[x][y - 1] && i != (int)Path.size()) {
      auto [a, b, c] = Path[i];
      if (t == 0 || c == 2) continue;
      Mundo.unsetWall(x, y, 2);
      Mundo.posicionDump.insert({x, y});
      flag = true;
      break;
    }
  }
  if (!flag) {
    make_maze(case_name);
    return;
  }
  Mundo.print_to_file(case_name);
}

void make_line_west(string case_name) {
  MundoKarel Mundo(W, H);
  int K = rng() % (W - 2) + 1;
  int p = rng() % 10 + 1;
  Mundo.direccionKarel = 1;
  Mundo.xKarel = 2;
  Mundo.yKarel = 2;
  bool flag = true;
  Mundo.mochilaKarel = -1;
  Mundo.setWall(K, 2, 3);
  for (int i = 2; i <= K; i++) {
    Mundo.setWall(i, 2, 0);
    if (i != 2 && i != K && flag && rng() % p == 0) {
      flag = false;
      Mundo.posicionDump.insert({i, 2});
    } else {
      Mundo.setWall(i, 2, 2);
      flag = true;
    }
  }
  Mundo.print_to_file(case_name);
}

void make_line_east(string case_name) {
  MundoKarel Mundo(W, H);
  int K = rng() % (W - 2) + 1;
  int p = rng() % 10 + 1;
  Mundo.direccionKarel = 3;
  Mundo.xKarel = K;
  Mundo.yKarel = 2;
  bool flag = true;
  Mundo.mochilaKarel = -1;
  Mundo.setWall(2, 2, 1);
  for (int i = K; i >= 2; i--) {
    Mundo.setWall(i, 2, 0);
    if (i != 2 && i != K && flag && rng() % p == 0) {
      flag = false;
      Mundo.posicionDump.insert({i, 2});
    } else {
      Mundo.setWall(i, 2, 2);
      flag = true;
    }
  }
  Mundo.print_to_file(case_name);
}

void maradona(string case_name) {
  if (rng() & 1)
    make_line_east(case_name);
  else
    make_line_west(case_name);
}

void make_case(string case_name, int cnt) {
  if (cnt <= 6) {  // genera un laberinto con un único agujero que no está en
                   // una esquina.
    make_maze(case_name);
    return;
  }
  if (cnt <= 13) {
    maradona(case_name);  // genera una linea con agujeros no consecutivos.
    return;
  }
  if (cnt <= 15) {  // agujeros no consecutivos y tampoco en esquinas.
                    // Probabilidad de giros es mínima.
    make_random(case_name, true, true, 2, 0, rng(), rng());
    return;
  }
  if (cnt <= 30) {  // agujeros no consecutivos, pero no en esquinas.
                    // Probabilidad de giro es aleatoria.
    make_random(case_name, true, true, rng(), rng(), rng(), rng());
    return;
  }
  if (cnt <= 40) {  // puede haber agujeros consecutivos, pero no en esquinas.
                    // Probabilidad de giro es aleatoria.
    make_random(case_name, true, false, rng(), rng(), rng(), rng());
    return;
  }
  make_random(case_name, false, false, rng(), rng(), rng(), rng());
}

int main() {
  string line;
  ifstream testplan;
  testplan.open("testplan");
  int cnt = 0;
  while (getline(testplan, line)) {
    cnt++;
    cout << cnt << endl;
    string case_name = "";
    for (char e : line) {
      if (e == ' ') break;
      case_name += e;
    }
    case_name += ".in";
    make_case(case_name, cnt);
  }
  testplan.close();
}
