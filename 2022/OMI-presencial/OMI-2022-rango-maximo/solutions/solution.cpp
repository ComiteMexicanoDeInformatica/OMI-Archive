#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << "\n";

#define MAX 100000
#define LOG 32

typedef struct NODO {
  int lazy;
  int maximo;
  int hi, hd;
};

int n, d, e, p[MAX + 2];
NODO st[MAX * LOG * 5];
long long c, x, punt, cont;

void propagaActualizacion(int nodo, int inicioNodo, int finNodo) {
  // SI EL NODO TIENE ALGO QUE PROPAGAR
  if (st[nodo].lazy) {
    // ACTUALIZA EL VALOR DEL MAXIMO DEL RANGO
    st[nodo].maximo += st[nodo].lazy;

    // PROPAGA LA ACTUALIZACION A SUS HIJOS SI LOS TIENE
    if (inicioNodo < finNodo) {
      // SI NO TIENE HIJOS, CREALOS
      if (!st[nodo].hi) {
        st[nodo].hi = cont++;
        st[nodo].hd = cont++;
      }
      st[st[nodo].hi].lazy += st[nodo].lazy;
      st[st[nodo].hd].lazy += st[nodo].lazy;
    }

    // LIMPIA EL VALOR DE PROPAGACION
    st[nodo].lazy = 0;
  }
}

void actualizaSegmentTree(int nodo, int inicioNodo, int finNodo,
                          int inicioIntervalo, int finIntervalo, int valor) {
  // PROPAGA LA ACTUALIZACION, SI HAY ALGUNA
  propagaActualizacion(nodo, inicioNodo, finNodo);

  if (inicioNodo > finNodo) return;  // SI EL NODO QUE SE BUSCA ES INVALIDO SAL.

  // SI EL NODO TIENE UN INTERVALO QUE NO INTERSECTA CON EL QUE SE BUSCA,
  // ENTONCES SAL
  if (inicioNodo > finIntervalo || finNodo < inicioIntervalo) return;

  // SI EL INTERVALO DEL NODO ESTA DENTRO DEL DE INTERES, ACTUALIZALO
  if (inicioNodo >= inicioIntervalo && finNodo <= finIntervalo) {
    st[nodo].lazy += valor;
    propagaActualizacion(nodo, inicioNodo, finNodo);
    return;
  }

  // SI NO TIENE HIJOS, CREALOS
  if (!st[nodo].hi) {
    st[nodo].hi = cont++;
    st[nodo].hd = cont++;
  }

  // SI EL INTERVALO DEL NODO SE INTERSECTA PARCIALMENTE CON EL DE INTERES, BAJA
  // RECURSIVAMENTE
  int mitad = (inicioNodo + finNodo) / 2;
  actualizaSegmentTree(st[nodo].hi, inicioNodo, mitad, inicioIntervalo,
                       finIntervalo, valor);
  actualizaSegmentTree(st[nodo].hd, mitad + 1, finNodo, inicioIntervalo,
                       finIntervalo, valor);
  st[nodo].maximo = max(st[st[nodo].hi].maximo, st[st[nodo].hd].maximo);
}

int main() {
  cont = 2;  // PRIMER NODO DISPONIBLE EN EL SEGMENT TREE

  std::cin >> n >> d;
  for (int i = 1; i <= n; ++i) {
    std::cin >> p[i];
    actualizaSegmentTree(1, 1, 1e9, max(1, p[i] - d), min((int)1e9, p[i] + d),
                         1);
  }

  // IMPRIME EL MAXIMO DEL RANGO TOTAL
  std::cout << st[1].maximo << "\n";

  // PROCESA EXAMEN POR EXAMEN
  std::cin >> e;
  while (e--) {
    // LEE LOS PUNTAJES QUE CAMBIARON Y ACTUALIZALOS EN EL ARREGLO TESTIGO
    std::cin >> c;
    while (c--) {
      std::cin >> x >> punt;
      // ELIMINA EL INTERVALO DE AFECTACION Y AGREGA EL NUEVO
      actualizaSegmentTree(1, 1, 1e9, max(1, p[x] - d), min((int)1e9, p[x] + d),
                           -1);
      p[x] = punt;
      actualizaSegmentTree(1, 1, 1e9, max(1, p[x] - d), min((int)1e9, p[x] + d),
                           +1);
    }
    std::cout << st[1].maximo << "\n";
  }

  return 0;
}
