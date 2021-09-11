#include <algorithm>
#include <iostream>
#define MAX 100005

struct Espejo {
  int x, y, id;
  char t;
};

int N, F, C, Q;
Espejo esp[MAX];
int ordX[MAX];
int ordY[MAX];
int nxt[MAX * 4];
bool vis[MAX * 4];
int tam[MAX * 4];
const int NORTE = 0;
const int SUR = 1;
const int ESTE = 2;
const int OESTE = 3;

int findLowY(int y) {
  int l = 1, r = N;
  while (l < r) {
    int m = (l + r) / 2;
    if (esp[ordY[m]].y >= y)
      r = m;
    else
      l = m + 1;
  }
  if (esp[ordY[l]].y != y) return -1;
  return l;
}

int findLowX(int x) {
  int l = 1, r = N;
  while (l < r) {
    int m = (l + r) / 2;
    if (esp[ordX[m]].x >= x)
      r = m;
    else
      l = m + 1;
  }
  if (esp[ordX[l]].x != x) return -1;
  return l;
}

int findHighY(int y) {
  int l = 1, r = N;
  while (l < r) {
    int m = (l + r + 1) / 2;
    if (esp[ordY[m]].y <= y)
      l = m;
    else
      r = m - 1;
  }
  if (esp[ordY[l]].y != y) return -1;
  return l;
}

int findHighX(int x) {
  int l = 1, r = N;
  while (l < r) {
    int m = (l + r + 1) / 2;
    if (esp[ordX[m]].x <= x)
      l = m;
    else
      r = m - 1;
  }
  if (esp[ordX[l]].x != x) return -1;
  return l;
}

int dfs(int x) {
  if (vis[x]) return tam[x];
  if (!nxt[x]) return 1;
  tam[x] = -1;
  vis[x] = 1;
  if (dfs(nxt[x]) == -1) return tam[x] = -1;
  return tam[x] = dfs(nxt[x]) + 1;
}

int queryN(int x, int y) {
  int l = findLowY(y);
  int r = findHighY(y);
  if (l == -1) return 0;
  while (l < r) {
    int m = (l + r) / 2;
    if (esp[ordY[m]].x >= x)
      r = m;
    else
      l = m + 1;
  }
  Espejo e = esp[ordY[l]];
  if (e.x < x) return 0;
  if (e.t == '/')
    return dfs(4 * e.id + ESTE);
  else
    return dfs(4 * e.id + OESTE);
}

int queryS(int x, int y) {
  int l = findLowY(y);
  int r = findHighY(y);
  if (l == -1) return 0;
  while (l < r) {
    int m = (l + r + 1) / 2;
    if (esp[ordY[m]].x <= x)
      l = m;
    else
      r = m - 1;
  }
  Espejo e = esp[ordY[l]];
  if (e.x > x) return 0;
  if (e.t == '/')
    return dfs(4 * e.id + OESTE);
  else
    return dfs(4 * e.id + ESTE);
}

int queryE(int x, int y) {
  int l = findLowX(x);
  int r = findHighX(x);
  if (l == -1) return 0;
  while (l < r) {
    int m = (l + r) / 2;
    if (esp[ordX[m]].y >= y)
      r = m;
    else
      l = m + 1;
  }
  Espejo e = esp[ordX[l]];
  if (e.y < y) return 0;
  if (e.t == '/')
    return dfs(4 * e.id + NORTE);
  else
    return dfs(4 * e.id + SUR);
}

int queryO(int x, int y) {
  int l = findLowX(x);
  int r = findHighX(x);
  if (l == -1) return 0;
  while (l < r) {
    int m = (l + r + 1) / 2;
    if (esp[ordX[m]].y <= y)
      l = m;
    else
      r = m - 1;
  }
  Espejo e = esp[ordX[l]];
  if (e.y > y) return 0;
  if (e.t == '/')
    return dfs(4 * e.id + SUR);
  else
    return dfs(4 * e.id + ESTE);
}

bool cmpX(int a, int b) {
  if (esp[a].x != esp[b].x) return esp[a].x < esp[b].x;
  return esp[a].y < esp[b].y;
}

bool cmpY(int a, int b) {
  if (esp[a].y != esp[b].y) return esp[a].y < esp[b].y;
  return esp[a].x < esp[b].x;
}

void agregaHorizontal(Espejo a, Espejo b) {
  if (b.t == '/')
    nxt[4 * a.id + ESTE] = 4 * b.id + NORTE;
  else
    nxt[4 * a.id + ESTE] = 4 * b.id + SUR;
  if (a.t == '/')
    nxt[4 * b.id + OESTE] = 4 * b.id + SUR;
  else
    nxt[4 * b.id + OESTE] = 4 * b.id + NORTE;
}

void agregaVertical(Espejo a, Espejo b) {
  if (b.t == '/')
    nxt[4 * a.id + NORTE] = 4 * b.id + ESTE;
  else
    nxt[4 * a.id + NORTE] = 4 * b.id + OESTE;
  if (a.t == '/')
    nxt[4 * b.id + SUR] = 4 * b.id + OESTE;
  else
    nxt[4 * b.id + SUR] = 4 * b.id + ESTE;
}

void construyeGrafo() {
  for (int i = 1; i <= N; i++) ordX[i] = ordY[i] = i;

  std::sort(ordX + 1, ordX + N + 1, cmpX);
  std::sort(ordY + 1, ordY + N + 1, cmpY);

  // Genera aristas horizontales
  int l = 1;
  while (l <= N) {
    int r = l;
    while (r + 1 <= N && esp[ordX[r + 1]].x == esp[ordX[l]].x) r++;
    for (int i = l; i < r; i++)
      agregaHorizontal(esp[ordX[i]], esp[ordX[i + 1]]);
    l = r + 1;
  }

  // Genera aristas verticales
  l = 1;
  while (l <= N) {
    int r = l;
    while (r + 1 <= N && esp[ordY[r + 1]].y == esp[ordY[l]].y) r++;
    for (int i = l; i < r; i++) agregaVertical(esp[ordY[i]], esp[ordY[i + 1]]);
    l = r + 1;
  }
}

int main() {
  std::cin >> N >> F >> C;
  for (int i = 1; i <= N; i++) {
    std::cin >> esp[i].t >> esp[i].x >> esp[i].y;
    esp[i].id = i;
  }

  construyeGrafo();
  std::cin >> Q;
  while (Q--) {
    char t;
    int x, y;
    std::cin >> t >> x >> y;
    if (t == 'N') std::cout << queryN(x, y) << "\n";
    if (t == 'S') std::cout << queryS(x, y) << "\n";
    if (t == 'E') std::cout << queryE(x, y) << "\n";
    if (t == 'O') std::cout << queryO(x, y) << "\n";
  }
  return 0;
}
