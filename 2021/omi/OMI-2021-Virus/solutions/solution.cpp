#include <iostream>
#include <queue>
#include <vector>
#define MAX 200005
typedef long long ll;

int N, M, K;
bool infected[MAX];
std::vector<int> ady[MAX];
std::vector<int> iniciales;

int findMax() {
  for (int i = 1; i <= N; i++) infected[i] = false;
  std::queue<int> q;
  for (auto ini : iniciales) {
    infected[ini] = true;
    q.push(ini);
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (auto v : ady[x])
      if (!infected[v]) {
        infected[v] = true;
        q.push(v);
      }
  }
  int ans = 0;
  for (int i = 1; i <= N; i++)
    if (infected[i]) ans++;
  return ans;
}

int findMin() {
  for (int i = 1; i <= N; i++) infected[i] = false;
  for (auto ini : iniciales) {
    infected[ini] = true;
    for (auto v : ady[ini]) infected[v] = true;
  }
  int ans = 0;
  for (int i = 1; i <= N; i++)
    if (infected[i]) ans++;
  return ans;
}

int main() {
  std::cin >> N >> M >> K;
  for (int i = 1; i <= K; i++) {
    int x;
    std::cin >> x;
    iniciales.push_back(x);
  }

  for (int i = 1; i <= M; i++) {
    int a, b;
    std::cin >> a >> b;
    ady[a].push_back(b);
  }

  std::cout << findMin() << " " << findMax() << "\n";
  return 0;
}
