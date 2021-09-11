#include <iostream>
#include <set>
#define MAX 200005

struct Rect {
  int x1, y1, x2, y2;
};

int N, F, C;
Rect a[MAX];
int id[MAX], mn[MAX], mx[MAX];

bool intersect(Rect u, Rect v) {
  return !(u.x2 + 1 < v.x1 || u.x1 > v.x2 + 1 || u.y2 + 1 < v.y1 ||
           u.y1 > v.y2 + 1);
}

int find(int x) {
  if (x == id[x]) return x;
  return id[x] = find(id[x]);
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);
  mn[u] = std::min(mn[u], mn[v]);
  mx[u] = std::max(mx[u], mx[v]);
  id[v] = u;
}

int main() {
  std::cin >> N >> F >> C;
  for (int i = 1; i <= N; i++)
    std::cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;

  for (int i = 1; i <= N; i++) {
    mn[i] = a[i].y1;
    mx[i] = a[i].y2;
    id[i] = i;
  }

  for (int i = 1; i <= N; i++)
    for (int j = i + 1; j <= N; j++)
      if (intersect(a[i], a[j])) merge(i, j);

  std::set<int> ans;
  for (int i = 1; i <= N; i++) {
    int g = find(i);
    if (mn[g] == 1 && mx[g] == C) ans.insert(g);
  }

  std::cout << ans.size() << "\n";
  return 0;
}
