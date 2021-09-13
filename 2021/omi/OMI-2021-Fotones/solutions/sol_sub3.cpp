#include <algorithm>
#include <iostream>

#define lli long long
#define rep(i, a, b) for (lli i = (a); i <= (b); ++i)
#define repa(i, a, b) for (lli i = (a); i >= (b); --i)

#define nl "\n"
#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << nl

#define MAX_N 100003
#define posicion first
#define id second

#define norte 0
#define este 1
#define sur 2
#define oeste 3
#define inviertedir 2
#define horizontal 1

#define indefinido 0
#define infinito -1

lli n, e, F, C, f[MAX_N], c[MAX_N], ce, fe, visitado[4][MAX_N], dirlaser;
std::pair<lli, lli> sigespejo[5][MAX_N], sigexp;
char espejo[MAX_N], dire;

int simula(int direccion, int idEspejo) {
  if (!idEspejo) return 0;
  if (visitado[direccion][idEspejo]) return -1;

  visitado[direccion][idEspejo] = 1;
  int sigdir = direccion, sigid = 0;

  if (espejo[idEspejo] == '/')
    sigdir =
        (direccion == norte)
            ? este
            : (direccion == este) ? norte : (direccion == sur) ? oeste : sur;
  else
    sigdir =
        (direccion == norte)
            ? oeste
            : (direccion == oeste) ? norte : (direccion == sur) ? este : sur;
  sigid = sigespejo[sigdir][idEspejo].id;

  int res = simula(sigdir, sigid);
  return (res == -1) ? -1 : res + 1;
}

int main() {
  std::cin >> n >> F >> C;
  rep(i, 1, n) std::cin >> espejo[i] >> f[i] >> c[i];

  rep(i, 1, n) {
    rep(j, 1, n) {
      if (i == j) continue;
      if (f[i] == f[j]) {  // ESTAN EN LA MISMA FILA
        if (c[i] < c[j] &&
            (!sigespejo[este][i].id || sigespejo[este][i].posicion > c[j]))
          sigespejo[este][i] = {c[j], j};
        else if (c[i] > c[j] && (!sigespejo[oeste][i].id ||
                                 sigespejo[oeste][i].posicion < c[j]))
          sigespejo[oeste][i] = {c[j], j};
      } else if (c[i] == c[j]) {  // ESTAN EN LA MISMA COLUMNA
        if (f[i] < f[j] &&
            (!sigespejo[norte][i].id || sigespejo[norte][i].posicion > f[j]))
          sigespejo[norte][i] = {f[j], j};
        else if (f[i] > f[j] &&
                 (!sigespejo[sur][i].id || sigespejo[sur][i].posicion < f[j]))
          sigespejo[sur][i] = {f[j], j};
      }
    }
  }

  std::cin >> e >> dire >> fe >> ce;
  dirlaser = (dire == 'N') ? norte
                           : (dire == 'S') ? sur : (dire == 'E') ? este : oeste;
  if (dirlaser == norte) rep(i, 1, n) {
      if (c[i] == ce && f[i] > fe && (!sigexp.id || sigexp.posicion > f[i]))
        sigexp = {f[i], i};
    }
  else if (dirlaser == sur)
    rep(i, 1, n) {
      if (c[i] == ce && f[i] < fe && (!sigexp.id || sigexp.posicion < f[i]))
        sigexp = {f[i], i};
    }
  else if (dirlaser == este)
    rep(i, 1, n) {
      if (f[i] == fe && c[i] > ce && (!sigexp.id || sigexp.posicion > c[i]))
        sigexp = {c[i], i};
    }
  else if (dirlaser == oeste)
    rep(i, 1, n) {
      if (f[i] == fe && c[i] < ce && (!sigexp.id || sigexp.posicion < c[i]))
        sigexp = {c[i], i};
    }

  std::cout << simula(dirlaser, sigexp.id);

  return 0;
}
