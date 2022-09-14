#include <iostream>
#include <vector>

#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << "\n";

#define lli long long

#define MAX 100000
#define LOG 17

#define distancia first
#define hijo second
#define idancestro second

#define idpregunta first

lli n, q, a, b, d, id, padre[MAX + 2];
std::vector<std::pair<lli, int> > hijos[MAX + 2];
std::vector<std::pair<int, int> > preguntas[MAX + 2];
int nivel[MAX + 2], max_hijo[MAX + 2], dist_max_hijo[MAX + 2];
lli respuesta[MAX + 2];
std::pair<lli, int> dist_padre[LOG + 1][MAX + 2];
lli hijos_profundos[2][MAX + 2];

typedef struct monotone_node {
  lli largo_hijo;
  lli dist_acum;
  int ancestro;
};
monotone_node ms[MAX + 2];
int st_ancestros[LOG + 1][MAX + 2];

void dfs_init(lli nodo, lli pad, lli niv, lli distpadre) {
  nivel[nodo] = niv;
  padre[nodo] = pad;
  dist_padre[0][nodo] = {distpadre, pad};
  for (int bit = 1; bit <= LOG; ++bit) {
    dist_padre[bit][nodo].idancestro =
        dist_padre[bit - 1][dist_padre[bit - 1][nodo].idancestro].idancestro;
    dist_padre[bit][nodo].distancia =
        dist_padre[bit - 1][nodo].distancia +
        dist_padre[bit - 1][dist_padre[bit - 1][nodo].idancestro].distancia;
  }

  for (auto h : hijos[nodo]) {
    if (h.hijo == pad) continue;
    dfs_init(h.hijo, nodo, niv + 1, h.distancia);
    if (hijos_profundos[0][h.hijo] + h.distancia > hijos_profundos[0][nodo]) {
      max_hijo[nodo] = h.hijo;
      dist_max_hijo[nodo] = h.distancia;
      hijos_profundos[1][nodo] = hijos_profundos[0][nodo];
      hijos_profundos[0][nodo] = hijos_profundos[0][h.hijo] + h.distancia;
    } else if (hijos_profundos[0][h.hijo] + h.distancia >
               hijos_profundos[1][nodo]) {
      hijos_profundos[1][nodo] = hijos_profundos[0][h.hijo] + h.distancia;
    }
  }
}

lli distancia(lli u, lli v) {
  int nu = nivel[u];
  int nv = nivel[v];
  int dif = nu - nv;
  lli sum = 0;
  for (int bit = 0; bit <= LOG; ++bit) {
    if (dif & (1 << bit)) {
      sum += dist_padre[bit][u].distancia;
      u = dist_padre[bit][u].idancestro;
    }
  }
  return sum;
}

void actualiza_monotone_stack(lli nodo, lli disthijo, lli distpadre) {
  lli pos = padre[nodo];
  lli dist_acumulada = distpadre;
  while (pos && disthijo >= dist_acumulada + ms[pos].largo_hijo) {
    dist_acumulada += ms[pos].dist_acum;
    pos = ms[pos].ancestro;
  }
  ms[nodo].largo_hijo = disthijo;
  ms[nodo].dist_acum = dist_acumulada;
  ms[nodo].ancestro = pos;

  st_ancestros[0][nodo] = pos;
  for (int bit = 1; bit <= LOG; ++bit)
    st_ancestros[bit][nodo] =
        st_ancestros[bit - 1][st_ancestros[bit - 1][nodo]];
}

void dfs_solve(lli nodo, lli pad, lli distpadre) {
  // RESUELVE TODAS LAS PREGUNTAS QUE PASAN POR ESTE NODO
  for (auto p : preguntas[nodo]) {
    b = nivel[p.hijo];  // OBTEN EL NIVEL DEL ANCESTRO

    // HAZ UNA BUSQUEDA BINARIA SOBRE EL MONOTONE STACK PARA VER EL MAXIMO
    // DEBAJO DE b
    lli pos = pad;
    for (int bit = LOG; bit >= 0; --bit) {
      if (nivel[st_ancestros[bit][pos]] >= b) pos = st_ancestros[bit][pos];
    }

    lli dist_ancestro = 0;
    if (nivel[pos] >= b)
      dist_ancestro = distancia(nodo, pos) + ms[pos].largo_hijo;

    lli x = dist_ancestro;
    lli y = hijos_profundos[0][nodo];
    lli z = hijos_profundos[1][nodo];

    if (x < y) std::swap(x, y);
    if (y < z) std::swap(y, z);

    respuesta[p.idpregunta] = x + y;
  }

  // RESUELVE PARA EL HIJO MAXIMO
  if (max_hijo[nodo]) {
    actualiza_monotone_stack(nodo, hijos_profundos[1][nodo], distpadre);
    dfs_solve(max_hijo[nodo], nodo, dist_max_hijo[nodo]);
  }

  // RESUELVE PARA LOS DEMAS HIJOS
  if (hijos[nodo].size() > 2 || (hijos[nodo].size() == 2 && nodo == 1)) {
    actualiza_monotone_stack(nodo, hijos_profundos[0][nodo], distpadre);
    for (auto h : hijos[nodo]) {
      if (h.hijo == pad || h.hijo == max_hijo[nodo]) continue;
      dfs_solve(h.hijo, nodo, h.distancia);
    }
  }
}

int main() {
  // LEE LA ENTRADA
  std::cin >> n >> q;
  for (int i = 1; i < n; ++i) {
    std::cin >> a >> b >> d;
    hijos[a].push_back({d, b});
    hijos[b].push_back({d, a});
  }
  for (int i = 1; i <= q; ++i) {
    std::cin >> a >> b;
    preguntas[a].push_back({i, b});
  }

  dfs_init(1, 0, 1, 0);

  dfs_solve(1, 0, 0);

  for (int i = 1; i <= q; ++i) std::cout << respuesta[i] << "\n";

  return 0;
}
