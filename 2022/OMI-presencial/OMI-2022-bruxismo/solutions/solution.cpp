#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << "\n";

#define MAX 250000
#define MAXD 10000
#define MAXA 15
#define MAXFRAC 256

#define fuerza first
#define id second
#define fin first
#define maximo second

int n, a[MAX + 2], b[MAX + 2], d[MAX + 2], m[MAX + 2], res[MAX + 2],
    frac[MAX + 2];
int T, t[MAXD + 2], valordia[MAXD + 2];
int offset;
std::set<std::pair<int, int> > diasEnCero[MAXFRAC];
std::vector<std::pair<int, int> > eventos;
std::pair<int, int> stmax[MAXFRAC][MAXD * 4 + 2];
int f, mult, fracciones[MAX + 2][MAXA + 2];
std::pair<int, int> factor[MAXA * MAXA];

void actualiza(int arbol, int nodo, int val) {
  nodo = offset + nodo;  // PONLE EL OFFSET DEL SEGMENT TREE
  stmax[arbol][nodo].fin = val;
  stmax[arbol][nodo].maximo = std::max(0, val);
  nodo >>= 1;
  while (nodo) {
    int hi = nodo * 2;
    int hd = hi ^ 1;
    stmax[arbol][nodo].fin = stmax[arbol][hi].fin + stmax[arbol][hd].fin;
    stmax[arbol][nodo].maximo =
        std::max(stmax[arbol][hi].maximo,
                 stmax[arbol][hd].maximo + stmax[arbol][hi].fin);
    nodo >>= 1;
  }
}

int main() {

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  // SI A y B SON DISTINTOS, LO QUE IMPORTA ES LA FRACCION IRREDUCIBLE A/B
  // YA QUE DOS DIENTES CON LA MISMA FRACCION IRREDUCIBLE SE COMPORTARAN
  // IGUAL. HAY QUE OBTENER LAS FRACCIONES IRREDUCIBLES QUE SE PUEDEN FORMAR
  // CON LOS NUMEROS DEL 1 AL 15.
  f = 1;
  for (int numerador = 1; numerador <= MAXA; ++numerador) {
    for (int denominador = 1; denominador <= MAXA; ++denominador) {
      if (fracciones[numerador][denominador]) continue;
      int mult = 1;
      int num = numerador;
      int den = denominador;
      while (num <= MAXA && den <= MAXA) {
        fracciones[num][den] = f;
        mult++;
        num = numerador * mult;
        den = denominador * mult;
      }
      factor[f] = {numerador, denominador};
      ++f;
    }
  }

  std::cin >> n >> T;
  for (int i = 1; i <= n; ++i) {
    std::cin >> d[i] >> a[i] >> b[i] >> m[i];
    frac[i] =
        fracciones[a[i]][b[i]];  // LA FRACCION A LA QUE PERTENECE ESTE DIENTE
  }
  for (int i = 1; i <= T; ++i) std::cin >> t[i];

  offset = 1;
  while (offset < T) offset <<= 1;
  --offset;

  // PARA OPTIMIZAR EL PROCESO SE VAN A PROCESAR LOS DIAS EN ORDEN DE FUERZA DE
  // MAYOR A MENOR Y EN PARALELO LOS DIENTES DE MAYOR A MENOR RESISTENCIA.  EL
  // OBJETIVO ES QUE CUANDO SE PROCESE UN DIENTE YA SE HAYAN PROCESADO TODOS LOS
  // DIAS DE FUERZA MAYOR A SU RESISTENCIA, ES DECIR, AQUELLOS DIAS EN LOS QUE
  // EL DIENTE SUFRIO DANO.
  for (int i = 1; i <= n; ++i) eventos.emplace_back(d[i], i);
  for (int i = 1; i <= T; ++i) {
    eventos.emplace_back(t[i], -i);
    for (int fr = 1; fr < f; fr++)
      diasEnCero[fr].emplace_hint(diasEnCero[fr].end(), i, 0);
  }
  std::sort(eventos.begin(), eventos.end());
  std::reverse(eventos.begin(), eventos.end());

  int cnt = 0;
  for (auto ev : eventos) {
    if (ev.id < 0) {
      ++cnt;
      // ES DE TIPO DIA
      // CUANDO UN DIA APLICA SU DANIO CAMBIA A POSITIVO. LOS DIAS ADELANTE DE
      // EL SE VEN AFECTADOS, SI UN DIA ERA POSITIVO O NEGATIVO SUBE SU VALOR,
      // SI ERA CERO, PUEDE VOLVERSE NEGATIVO PARA TRATAR DE "REGRESAR" LA
      // GRAFICA A CERO. DEPENDIENDO DE SI EL VALOR DEL DIA AFECTADO ERA CERO O
      // NEGATIVO (NO PUEDE SER POSITIVO) ES PROBABLE QUE SE REQUIERAN
      // ACTUALIZAR MULTIPLES VALORES
      for (int fr = 1; fr < f; ++fr) {
        auto it = diasEnCero[fr].lower_bound({-ev.id, 0});
        int afectacion;
        if (it != diasEnCero[fr].end() && (*it).first == -ev.id) {
          // ESE DIA AUN NO TENIA SU MAXIMO NEGATIVO, HAY QUE COMPENSAR EL VALOR
          afectacion = factor[fr].first + (*it).second;
          it = diasEnCero[fr].erase(it);  // BORRALO Y APUNTA AL SIGUIENTE

        } else {
          afectacion = factor[fr].first +
                       factor[fr].second;  // EL DIA YA ERA NEGATIVO HAY QUE
                                           // COMPENSARLO TAMBIEN.
        }

        actualiza(fr, -ev.id, factor[fr].first);  // PON EN POSITIVO EL ACTUAL

        while (it != diasEnCero[fr].end() && afectacion) {
          int actual = factor[fr].second - (*it).second;
          if (afectacion >= actual) {
            actualiza(fr, (*it).first, -factor[fr].second);

            it = diasEnCero[fr].erase(it);
            afectacion -= actual;
          } else {
            actual = (*it).second + afectacion;
            int dia = (*it).first;

            it = diasEnCero[fr].erase(it);
            diasEnCero[fr].emplace_hint(it, dia, actual);
            afectacion = 0;

            actualiza(fr, dia, -actual);
          }
        }
      }
    } else {
      // SI ES UN EVENTO DE DIENTE, HAY QUE VER CUAL ES EL MAXIMO EN ESE
      // MOMENTO, MULTIPLICARLO POR EL DANIO ESPECIFICO DE ESE DIENTE Y VER SI
      // SE CAE
      int maximo =
          stmax[frac[ev.id]][1].maximo * a[ev.id] / factor[frac[ev.id]].first;
      if (maximo >= m[ev.id]) res[ev.id] = 1;
    }
  }

  for (int i = 1; i <= n; ++i) std::cout << res[i] << " ";
  std::cout << "\n";

  return 0;
}
