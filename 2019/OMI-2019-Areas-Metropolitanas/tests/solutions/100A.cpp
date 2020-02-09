#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
const int MAXN = 252;

int n, m, k;
lld LIM;
int matriz[MAXN][MAXN];
lld suma[MAXN][MAXN];

struct ura {
  int i, j, x, t;
  bool operator < (const ura& u) { return t < u.t; }
} Q[20002];

struct segment_tree {
  lld tree[MAXN*5], lazy[MAXN*5];

  void construye(lld arr[ ], int nodo = 1, int ini = 1, int fin = m) {
    if (ini == fin) {
      tree[nodo] = arr[ini];
    } else {
      int med = (ini+fin)>>1;
      construye(arr, nodo<<1, ini, med);
      construye(arr, nodo<<1 | 1, med + 1, fin);
      tree[nodo] = max(tree[nodo<<1], tree[nodo<<1 | 1]);
    }
  }

  void propagate(int nodo) {
    tree[nodo] += lazy[nodo];
    lazy[nodo<<1] += lazy[nodo];
    lazy[nodo<<1 | 1] += lazy[nodo];
    lazy[nodo] = 0;
  }

  void update(int i, int j, int v, int nodo = 1, int ini = 1, int fin = m) {
    propagate(nodo);
    if (ini > j || fin < i) return;
    if (ini >= i && fin <= j) {
      lazy[nodo] += v;
      propagate(nodo);
    } else {
      int med = (ini+fin)>>1;
      update(i, j, v, nodo<<1, ini, med);
      update(i, j, v, nodo<<1 | 1, med + 1, fin);
      tree[nodo] = max(tree[nodo<<1], tree[nodo<<1 | 1]);
    }
  }

  lld maximo() {
    propagate(1);
    return tree[1];
  }

} st[MAXN];

void init() {
  lld arr[m+2] = {0};
  for (int i = k; i <= n; ++i) {
    for (int j = k; j <= m; ++j)
      arr[j] = suma[i][j] - suma[i-k][j] - suma[i][j-k] + suma[i-k][j-k];
    st[i].construye(arr);
  }
}

bool solucion() {
  for (int i = k; i <= n; ++i)
    if (st[i].maximo() > LIM)
      return true;
  return false;
}

void update(const ura& u) {
  for (int i = 0; i < k; ++i) {
    if (u.i + i > n) break;
    st[u.i+i].update(u.j, min(m, u.j+k-1), u.x);
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> k >> LIM;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      cin >> matriz[i][j];
      suma[i][j] = matriz[i][j] + suma[i-1][j] + suma[i][j-1] - suma[i-1][j-1];
    }
  init();

  int q; cin >> q;
  for (int i = 1; i <= q; ++i)
    cin >> Q[i].i >> Q[i].j >> Q[i].x >> Q[i].t;
  sort(Q+1, Q+q+1);

  for (int i = 0; i <= q; ++i) {
    update(Q[i]);
    for(; i < q && Q[i+1].t == Q[i].t; update(Q[++i]));
    if (solucion()) {
      cout << Q[i].t << "\n";
      return 0;
    }
  }
  cout << "-1\n";
  return 0;
}
