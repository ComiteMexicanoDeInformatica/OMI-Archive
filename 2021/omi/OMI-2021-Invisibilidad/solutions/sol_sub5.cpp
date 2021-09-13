#include <iostream>
#include <queue>
#include <set>

#define lli long long
#define rep(i, a, b) for (lli i = (a); i <= (b); ++i)
#define repa(i, a, b) for (lli i = (a); i >= (b); --i)

#define nl "\n"
#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << nl

#define MAX_N 2003
#define MAX_TAM 1002

#define peligrosa 1
#define tranquila 0

#define fila second.first
#define columna second.second
#define largo first

lli n, f, c, f1, f2, c1, c2, ciudad[MAX_TAM][MAX_TAM],
    visitados[MAX_TAM][MAX_TAM];
std::set<std::pair<lli, std::pair<lli, lli> > > q;

int main() {
  std::cin >> n >> f >> c;
  if (f > 1000 || c > 1000) return 0;
  for (int i = 1; i <= n; ++i) {
    std::cin >> f1 >> c1 >> f2 >> c2;
    for (int fil = f1; fil <= f2; ++fil)
      for (int col = c1; col <= c2; ++col) ciudad[fil][col] = peligrosa;
  }

  for (int fil = 0; fil <= f + 1; ++fil)
    visitados[fil][0] = visitados[fil][c + 1] = 1;
  for (int col = 0; col <= c + 1; ++col)
    visitados[0][col] = visitados[f + 1][col] = 1;

  q.insert(
      {0, {1, 1}});  // Empieza en la posición (1, 1) sin haber usado la capa
  lli fil, col, tam;
  while (!q.empty()) {
    fil = (*q.begin()).fila;
    col = (*q.begin()).columna;
    tam = (*q.begin()).largo;
    q.erase(q.begin());
    if (fil == f) {  // Si ya encontro un camino a la última fila, termina
      std::cout << tam << nl;
      return 0;
    }

    visitados[fil][col] = 1;
    // prueba las 8 direcciones
    for (int dfil = -1; dfil <= 1; ++dfil) {
      for (int dcol = -1; dcol <= 1; ++dcol) {
        if (ciudad[fil][col] == tranquila && dfil != 0 && dcol != 0)
          continue;  // Si no trae la capa no puede moverse en diagonal
        f1 = fil + dfil;
        c1 = col + dcol;
        if (!visitados[f1][c1]) {
          if (ciudad[f1][c1] == peligrosa && ciudad[fil][col] == tranquila)
            q.insert({tam + 1, {f1, c1}});
          else
            q.insert({tam, {f1, c1}});
        }
      }
    }
  }

  return 0;
}
