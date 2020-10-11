#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

#define pii std::pair<int, int>
#define fi first
#define se second
#define MAX 2505
typedef long long ll;

struct rect {
  ll x1, y1, x2, y2;
};

int N, M;

bool mapa[MAX][MAX];
// Usado para visualizar resultado
void printMap(std::vector<rect>& v) {
  std::ofstream fout("mapa.out");
  memset(mapa, 0, sizeof mapa);
  for (auto& r : v) {
    for (int i = r.x1; i <= r.x2; i++)
      for (int j = r.y1; j <= r.y2; j++) mapa[i][j] = 1;
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) fout << (mapa[i][j] ? "X" : ".");
    fout << "\n";
  }
  fout.close();
}

void printRect(std::vector<rect>& v) {
  std::cout << v.size() << "\n";
  for (auto r : v)
    std::cout << r.x1 << " " << r.y1 << " " << r.x2 << " " << r.y2 << "\n";
}

ll getScore(std::vector<rect>& v) {
  ll tot = 0, rep = 0, dist = 0;
  std::map<pii, bool> mp;
  for (auto r : v) {
    ll h = r.x2 - r.x1 + 1;
    ll w = r.y2 - r.y1 + 1;
    tot += h * w;
    if (!mp[{h, w}]) {
      dist++;
      mp[{h, w}] = 1;
    } else
      rep++;
  }
  return (tot - rep) * dist;
}

ll f(ll cnt) { return ((cnt * (cnt + 3)) / 2) - 1; }

void addLastRectsDn(std::vector<rect>& v, ll limN, ll limM, ll tam) {
  tam--;
  if (tam < 1) return;

  ll lng = 1;
  std::map<ll, bool> dont;
  for (auto& r : v)
    if (r.y2 - r.y1 + 1 == tam) dont[r.x2 - r.x1 + 1] = 1;

  ll in = 1;
  while (in <= limN) {
    ll to = in + lng - 1;
    if (to >= limN) to = limN;

    ll nxtlng = lng + 1;
    while (dont[nxtlng]) nxtlng++;

    ll nxt = to + 1 + nxtlng;
    if (nxt > limN) to = limN;

    v.push_back({in, limM - tam + 1, to, limM});
    in = to + 2;
    lng = nxtlng;
  }
}

void addLastRectsRt(std::vector<rect>& v, ll limN, ll limM, ll tam) {
  tam--;
  if (tam < 1) return;

  ll lng = 1;
  std::map<ll, bool> dont;
  for (auto& r : v)
    if (r.x2 - r.x1 + 1 == tam) dont[r.y2 - r.y1 + 1] = 1;
  while (dont[lng]) lng++;

  ll in = 1;
  while (in <= limM) {
    ll to = in + lng - 1;
    if (to >= limM) to = limM;

    ll nxtlng = lng + 1;
    while (dont[nxtlng]) nxtlng++;
    ll nxt = to + 1 + nxtlng;
    if (nxt > limM) to = limM;

    v.push_back({limN - tam + 1, in, limN, to});
    in = to + 2;
    lng = nxtlng;
  }
}

void extendRt(std::vector<rect>& v) {
  ll bigy2 = 0;
  for (auto r : v) bigy2 = std::max(bigy2, r.y2);

  for (auto& r : v)
    if (r.y2 == bigy2) r.y2 = M;
}

void extendDn(std::vector<rect>& v) {
  ll bigx2 = 0;
  for (auto r : v) bigx2 = std::max(bigx2, r.x2);

  for (auto& r : v)
    if (r.x2 == bigx2) r.x2 = N;
}

void build(std::vector<rect>& v) {
  ll limDn = 0, limRt = 0;
  while (f(limDn + 1) <= N) limDn++;
  while (f(limRt + 1) <= M) limRt++;

  ll sobraDn = N - f(limDn);
  ll sobraRt = M - f(limRt);

  // Crea los rectangulos basicos
  for (int d = 1; d <= limDn; d++)
    for (int r = 1; r <= limRt; r++) {
      rect nw;
      nw.x2 = f(d);
      nw.x1 = nw.x2 - d + 1;
      nw.y2 = f(r);
      nw.y1 = nw.y2 - r + 1;
      v.push_back(nw);
    }

  std::vector<rect> bst = v;

  for (int ordDR = 0; ordDR < 2; ordDR++) {
    for (int extRt = 0; extRt < 2; extRt++) {
      for (int extDn = 0; extDn < 2; extDn++) {
        std::vector<rect> v2 = v;

        if (extRt) extendRt(v2);
        if (extDn) extendDn(v2);

        if (ordDR) {
          if (!extRt) addLastRectsDn(v2, N, M, sobraRt);
          if (!extDn) addLastRectsRt(v2, N, M - sobraRt, sobraDn);
        } else {
          if (!extDn) addLastRectsRt(v2, N, M, sobraDn);
          if (!extRt) addLastRectsDn(v2, N - sobraDn, M, sobraRt);
        }

        if (getScore(v2) > getScore(bst)) bst = v2;
      }
    }
  }

  v = bst;
}

void solve(int n, int m) {
  N = n, M = m;
  std::vector<rect> bst;
  build(bst);
  printRect(bst);
  // cout << getScore(bst) << "\n";
  // printMap(bst);
}

int main() {
  int n, m;
  std::cin >> n >> m;
  solve(n, m);
  return 0;
}