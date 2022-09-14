#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << "\n";

#define MAX 250000
#define MAXD 10000
#define MAXA 20

#define fuerza first
#define id second
#define fin first
#define maximo second

int n, a[MAX + 2], b[MAX + 2], d[MAX + 2], m[MAX + 2], res[MAX + 2];
int T, t[MAXD + 2], valordia[MAXD + 2];
int offset;
std::set<int> diasEnCero;
std::vector<std::pair<int, int> > eventos;
std::pair<int, int> stmax[MAX * 4 + 2];

void actualiza(int nodo, int val) {
  nodo = offset + nodo;  // PONLE EL OFFSET DEL SEGMENT TREE
  stmax[nodo].fin = val;
  stmax[nodo].maximo = std::max(0, val);
  nodo >>= 1;
  while (nodo) {
    int hi = nodo * 2;
    int hd = hi ^ 1;
    stmax[nodo].fin = stmax[hi].fin + stmax[hd].fin;
    stmax[nodo].maximo =
        std::max(stmax[hi].maximo, stmax[hd].maximo + stmax[hi].fin);
    nodo >>= 1;
  }
}

int main() {
  std::cin >> n >> T;
  for (int i = 1; i <= n; ++i) std::cin >> d[i] >> a[i] >> b[i] >> m[i];
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
    diasEnCero.emplace_hint(diasEnCero.end(), i);
  }
  std::sort(eventos.begin(), eventos.end());
  std::reverse(eventos.begin(), eventos.end());

  for (auto ev : eventos) {
    if (ev.id < 0) {  // ES DE TIPO DIA
      // CUANDO UN DIA APLICA SU DANIO CAMBIA A POSITIVO. LOS DIAS ADELANTE DE
      // EL SE VEN AFECTADOS, SI UN DIA ERA POSITIVO O NEGATIVO SUBE SU VALOR,
      // SI ERA CERO, PUEDE VOLVERSE NEGATIVO PARA TRATAR DE "REGRESAR" LA
      // GRAFICA A CERO. DEPENDIENDO DE SI EL VALOR DEL DIA AFECTADO ERA CERO O
      // NEGATIVO (NO PUEDE SER POSITIVO) SE DEBEN ACTUALIZAR 1 O 2 VALORES CERO
      // ADELANTE DE EL
      auto it = diasEnCero.lower_bound(-ev.id);
      int afectados;
      if (it != diasEnCero.end() && *it == -ev.id) {
        // ESE DIA TENIA VALOR 0, SOLO HAY QUE ACTUALIZAR UN 0 A NEGATIVO
        afectados = 1;
        it = diasEnCero.erase(it);  // BORRALO Y APUNTA AL SIGUIENTE
      } else
        afectados = 2;  // EL DIA YA ERA NEGATIVO, HAY QUE AFECTAR DOS CEROS.

      actualiza(-ev.id, 1);
      while (it != diasEnCero.end() && afectados) {
        actualiza(*it, -1);  // ACTUALIZA ESTE DIA PARA QUE SEA UN NEGATIVO
        it = diasEnCero.erase(it);  // BORRALO DE LOS CEROS
        --afectados;
      }
    } else {
      // SI ES UN EVENTO DE DIA, HAY QUE VER CUAL ES EL MAXIMO EN ESE MOMENTO,
      // MULTIPLICARLO POR EL DANIO ESPECIFICO DE ESE DIENTE Y VER SI SE CAE
      if (a[ev.id] * stmax[1].maximo >= m[ev.id]) res[ev.id] = 1;
    }
  }

  for (int i = 1; i <= n; ++i) std::cout << res[i] << " ";
  std::cout << "\n";

  return 0;
}