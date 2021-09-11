#include <algorithm>
#include <iostream>

#define lli long long
#define rep(i, a, b) for (lli i = (a); i <= (b); ++i)
#define repa(i, a, b) for (lli i = (a); i >= (b); --i)

#define nl "\n"
#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << nl

#define MAX_N 100003
#define coord first
#define id second

#define norte 0
#define este 1
#define sur 2
#define oeste 3
#define inviertedir 2
#define horizontal 1

#define indefinido 0
#define infinito -1

lli n, e, F, C, f[MAX_N], c[MAX_N], dirlaser, fe, ce, visitado[4][102][102];
char espejo[MAX_N], disp[102][102], dire;

int simula(int direccion, int fila, int columna) {
  if (disp[fila][columna] == 'X') return 0;
  if (visitado[direccion][fila][columna]) return -1;

  visitado[direccion][fila][columna] = 1;
  int res, cnt = 0, sigdir = direccion, sigfila = fila, sigcolumna = columna;

  if (disp[fila][columna] == '.') {
    sigfila = (direccion == sur) ? sigfila - 1
                                 : (direccion == norte) ? sigfila + 1 : sigfila;
    sigcolumna = (direccion == oeste)
                     ? sigcolumna - 1
                     : (direccion == este) ? sigcolumna + 1 : sigcolumna;
  } else if (disp[fila][columna] == '/') {
    sigfila = (direccion == oeste)
                  ? sigfila - 1
                  : (direccion == este) ? sigfila + 1 : sigfila;
    sigcolumna = (direccion == sur)
                     ? sigcolumna - 1
                     : (direccion == norte) ? sigcolumna + 1 : sigcolumna;
    sigdir =
        (direccion == norte)
            ? este
            : (direccion == este) ? norte : (direccion == sur) ? oeste : sur;
    ++cnt;
  } else {
    sigfila = (direccion == este)
                  ? sigfila - 1
                  : (direccion == oeste) ? sigfila + 1 : sigfila;
    sigcolumna = (direccion == norte)
                     ? sigcolumna - 1
                     : (direccion == sur) ? sigcolumna + 1 : sigcolumna;
    sigdir =
        (direccion == norte)
            ? oeste
            : (direccion == oeste) ? norte : (direccion == sur) ? este : sur;
    ++cnt;
  }

  if ((res = simula(sigdir, sigfila, sigcolumna)) == -1)
    return -1;
  else
    return cnt + res;
}

int main() {
  std::cin >> n >> F >> C;
  rep(fil, 0, F + 1) rep(col, 0, C + 1) disp[fil][col] =
      (!fil || fil == F + 1 || !col || col == C + 1) ? 'X' : '.';

  rep(i, 1, n) {
    std::cin >> espejo[i] >> f[i] >> c[i];
    disp[f[i]][c[i]] = espejo[i];
  }

  std::cin >> e >> dire >> fe >> ce;
  dirlaser = (dire == 'N') ? norte
                           : (dire == 'S') ? sur : (dire == 'E') ? este : oeste;
  std::cout << simula(dirlaser, fe, ce);

  return 0;
}
