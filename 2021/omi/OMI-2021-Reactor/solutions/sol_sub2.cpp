#include <iostream>
#include <vector>

#define lli long long int
#define rep(i, a, b) for (lli i = (a); i <= (b); ++i)
#define repa(i, a, b) for (lli i = (a); i >= (b); --i)

#define nl "\n"
#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << std::endl

#define MAX_N 200003
#define bajo_nivel 0
#define grave 1
#define severa 2

lli n, m, r, a, b, backa, backb, hojas, caminosCiclo[MAX_N], hojas_ciclo,
    visitado[MAX_N];
bool llegoACiclo = false;
std::vector<lli> hijos[MAX_N];

void dfs(lli nodo) {
  visitado[nodo] = 2;
  if (caminosCiclo[nodo]) llegoACiclo = true;
  if (hijos[nodo].size()) {
    for (auto hijo : hijos[nodo])
      if (visitado[hijo] < 2) dfs(hijo);
  } else
    ++hojas;
}

void dfsciclo(lli nodo) {
  visitado[nodo] = 3;
  if (hijos[nodo].size()) {
    for (auto hijo : hijos[nodo])
      if (visitado[hijo] < 3) dfsciclo(hijo);
  } else
    ++hojas_ciclo;
}

lli marcaCiclo(lli nodo) {
  if (nodo == backa) return 1;  // ES EL FINAL DEL CICLO
  if (visitado[nodo]) return caminosCiclo[nodo];
  visitado[nodo] = 1;
  for (auto h : hijos[nodo]) caminosCiclo[nodo] += marcaCiclo(h);
  return caminosCiclo[nodo];
}

int main() {
  std::cin >> n >> m >> r;
  rep(i, 1, m) {
    std::cin >> a >> b;
    if (a > b) {
      backa = a;
      backb = b;
    }
    hijos[a].push_back(b);
  }

  if (backb) marcaCiclo(backb);

  dfs(r);
  if (!llegoACiclo)
    std::cout << "B\n" << hojas << " 0\n";
  else {
    dfsciclo(backb);
    if (caminosCiclo[backb] == 1)
      std::cout << "G\n" << hojas << " " << hojas_ciclo << "\n";
    else
      std::cout << "S\n" << hojas << " " << hojas_ciclo << "\n";
  }

  return 0;
}
