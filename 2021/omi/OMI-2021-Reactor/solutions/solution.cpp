#include <iostream>
#include <vector>

#define lli long long
#define rep(i, a, b) for (lli i = (a); i <= (b); ++i)
#define repa(i, a, b) for (lli i = (a); i >= (b); --i)

#define nl "\n"
#define debugsl(x) cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << endl

#define MAX_N 200003
#define bajo_nivel 0
#define grave 1
#define severa 2

lli n, m, r, a, b, causas[MAX_N], hojas, hojas_ciclo, tipo, visitado[MAX_N];
std::vector<lli> hijos[MAX_N];

void simula_falla(lli nodo) {
  for (auto h : hijos[nodo]) {
    ++causas[h];
    if (causas[h] == 1) simula_falla(h);
  }
}

void repara_falla(lli nodo) {
  --causas[nodo];
  if (causas[nodo] == 0) {
    for (auto h : hijos[nodo]) repara_falla(h);
  }
}

void cuenta_hojas(lli nodo, bool viene_de_ciclo) {
  visitado[nodo] = 1;

  if (!hijos[nodo].size()) {
    ++hojas;
    if (viene_de_ciclo) ++hojas_ciclo;
    return;
  }

  for (auto h : hijos[nodo]) {
    if (visitado[h]) continue;
    cuenta_hojas(h, viene_de_ciclo || (causas[nodo] > 0));
  }
}

int main() {
  std::cin >> n >> m >> r;
  rep(i, 1, m) {
    std::cin >> a >> b;
    hijos[a].push_back(b);
  }

  tipo = bajo_nivel;
  causas[r] = 1;
  simula_falla(r);
  repara_falla(r);

  rep(i, 1, n) {
    if (causas[i] == 1 && tipo == bajo_nivel)
      tipo = grave;
    else if (causas[i] == 2)
      tipo = severa;
  }

  cuenta_hojas(r, causas[r] > 0);

  if (tipo == bajo_nivel)
    std::cout << "B" << nl;
  else if (tipo == grave)
    std::cout << "G" << nl;
  else
    std::cout << "S" << nl;

  std::cout << hojas << " " << hojas_ciclo << nl;

  return 0;
}
