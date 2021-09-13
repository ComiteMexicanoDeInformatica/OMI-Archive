#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

#define lli long long
#define rep(i, a, b) for (lli i = (a); i <= (b); ++i)
#define repa(i, a, b) for (lli i = (a); i >= (b); --i)

#define nl "\n"
#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << nl

#define MAX_N 52
#define MAX_M 10003

lli n, m, x, fprevio, mat[MAX_N][MAX_N], tablero[MAX_N][MAX_M];
std::set<lli> filas[MAX_N];

int main() {
  std::cin >> n >> m;

  rep(fil, 1, n) {
    rep(col, 1, m) {
      std::cin >> x;
      mat[fil][x]++;
      if (mat[fil][x] == 1) filas[x].insert(fil);
    }
  }

  // Construye el tablero
  rep(col, 1, m) {
    std::vector<lli> usada(n + 1, 0), columna(n + 1, 0);
    rep(color, 1, n) {
      // Si ya esta acomodada, saltatela
      if (columna[color]) continue;

      // Busca una fila donde ponerlo
      for (auto f : filas[color]) {
        if (!usada[f]) {
          tablero[f][col] = color;
          usada[f] = color;
          columna[color] = f;
          mat[f][color]--;
          if (!mat[f][color]) filas[color].erase(f);
          break;
        }
      }

      // Si no encontro fila, intercambia por alguna de las menores
      if (!columna[color]) {
        repa(colorprevio, color - 1, 1) {
          if (filas[color].count(columna[colorprevio]) > 0) {
            fprevio = columna[colorprevio];
            mat[fprevio][colorprevio]++;
            if (mat[fprevio][colorprevio] == 1)
              filas[colorprevio].insert(fprevio);
            columna[color] = fprevio;
            tablero[fprevio][col] = color;
            mat[fprevio][color]--;
            if (!mat[fprevio][color]) filas[color].erase(fprevio);
            columna[colorprevio] = 0;
            color = colorprevio - 1;
            break;
          }
        }
      }
    }
  }

  // Rellena los ceros
  rep(color, 1, n) {
    for (auto fil : filas[color]) {
      rep(col, 1, m) {
        if (!tablero[fil][col]) {
          tablero[fil][col] = color;
          mat[fil][color]--;
          if (!mat[fil][color]) break;
        }
      }
    }
  }

  rep(fil, 1, n) {
    rep(col, 1, m) std::cout << tablero[fil][col] << " ";
    std::cout << nl;
  }

  return 0;
}
