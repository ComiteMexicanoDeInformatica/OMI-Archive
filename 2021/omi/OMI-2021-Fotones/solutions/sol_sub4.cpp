#include <algorithm>
#include <iostream>
#include <map>
#include <set>

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

lli n, e, F, C, f[MAX_N], c[MAX_N], ce, fe, visitado[4][MAX_N], dirlaser,
    memoria[4][MAX_N];
std::pair<lli, lli> sigespejo[5][MAX_N], sigexp;
char espejo[MAX_N], dire;

int simula(int direccion, int idEspejo, int experimento) {
  if (!idEspejo) return 0;
  if (visitado[direccion][idEspejo] == experimento) return -1;
  if (memoria[direccion][idEspejo]) return memoria[direccion][idEspejo];

  visitado[direccion][idEspejo] = experimento;
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

  int res = simula(sigdir, sigid, experimento);
  if (res == -1)
    return memoria[direccion][idEspejo] = -1;
  else
    return memoria[direccion][idEspejo] = res + 1;
}

int main() {
  std::map<lli, std::set<std::pair<lli, lli> > > mapafilas, mapacolumnas;
  std::cin >> n >> F >> C;
  rep(i, 1, n) {
    std::cin >> espejo[i] >> f[i] >> c[i];
    mapafilas[f[i]].insert({c[i], i});
    mapacolumnas[c[i]].insert({f[i], i});
  }

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

  std::cin >> e;
  rep(experimento, 1, e) {
    std::cin >> dire >> fe >> ce;

    dirlaser = (dire == 'N')
                   ? norte
                   : (dire == 'S') ? sur : (dire == 'E') ? este : oeste;
    sigexp = {0, 0};

    if ((dirlaser == norte || dirlaser == sur) && mapacolumnas.count(ce)) {
      auto it = mapacolumnas[ce].upper_bound({fe, 0});
      if (dirlaser == norte && it != mapacolumnas[ce].end())
        sigexp = *it;
      else if (dirlaser == sur && it != mapacolumnas[ce].begin())
        sigexp = *(--it);
    } else if ((dirlaser == este || dirlaser == oeste) && mapafilas.count(fe)) {
      auto it = mapafilas[fe].upper_bound({ce, 0});
      if (dirlaser == este && it != mapafilas[fe].end())
        sigexp = *it;
      else if (dirlaser == oeste && it != mapafilas[fe].begin())
        sigexp = *(--it);
    }

    std::cout << simula(dirlaser, sigexp.id, experimento) << nl;
  }

  return 0;
}
