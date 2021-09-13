#include <iostream>
#include <set>
#define MAX 54

int N, M, disp;
std::set<int> ady[MAX];
int a[MAX][MAX];
int ans[MAX][10005];
bool vis[MAX];
int match[MAX];

bool kuhn(int x) {
  if (vis[x]) return false;
  vis[x] = true;
  for (auto v : ady[x])
    if (match[v] == -1 || kuhn(match[v])) {
      match[v] = x;
      return true;
    }
  return false;
}

bool bipartite_matching() {
  for (int i = 1; i <= N; i++) match[i] = -1;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) vis[j] = 0;
    kuhn(i);
  }

  for (int i = 1; i <= N; i++)
    if (match[i] == -1) return false;
  return true;
}

int main() {
  std::cin >> N >> M;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) {
      int x;
      std::cin >> x;
      a[i][x]++;
    }

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      if (a[i][j]) {
        ady[i].insert(j);
      }

  while (bipartite_matching()) {
    int mn = M;
    for (int i = 1; i <= N; i++) mn = std::min(mn, a[match[i]][i]);

    for (int i = 1; i <= N; i++) {
      int v = match[i];
      a[v][i] -= mn;
      if (a[v][i] == 0) {
        ady[v].erase(i);
      }
    }

    while (mn--) {
      disp++;
      for (int i = 1; i <= N; i++) ans[match[i]][disp] = i;
    }
  }

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) std::cout << ans[i][j] << " \n"[j == M];
  return 0;
}
