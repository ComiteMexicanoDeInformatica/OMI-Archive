#include <iostream>
#define MAX 105

int N, F, C, E;
char a[MAX][MAX];
bool vis[MAX][MAX][4];
const int INF = 1e9;

// N = 0, S = 1, E = 2, O = 3
int mov[4][2]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int getDir(char x) {
  if (x == 'N') return 0;
  if (x == 'S') return 1;
  if (x == 'E') return 2;
  return 3;
}

int dfs(int x, int y, int dir) {
  if (x < 1 or y < 1 or x > F or y > C) return 0;
  if (vis[x][y][dir]) return -INF;
  vis[x][y][dir] = true;
  x += mov[dir][0];
  y += mov[dir][1];
  if (a[x][y] == '/') {
    dir = (dir + 2) % 4;
    return dfs(x, y, dir) + 1;
  } else if (a[x][y] == '\\') {
    dir = (3 - dir);
    return dfs(x, y, dir) + 1;
  } else
    return dfs(x, y, dir);
}

int main() {
  std::cin >> N >> F >> C;
  for (int i = 1; i <= N; i++) {
    char t;
    int x, y;
    std::cin >> t >> x >> y;
    a[x][y] = t;
  }
  std::cin >> E;
  while (E--) {
    char d;
    int x, y;
    std::cin >> d >> x >> y;
    std::cout << std::max(dfs(x, y, getDir(d)), -1) << "\n";
  }
  return 0;
}
