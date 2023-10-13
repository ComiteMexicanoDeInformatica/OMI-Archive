#include <bits/stdc++.h>

#include "rudolph.h"

namespace {
using std::cerr;
using std::set;
using std::string;
using std::vector;

template <typename T>
void imprime(const std::vector<T>& vec) {
#if 0
    for (auto a : vec) {
        std::cerr << int(a);
    }
    std::cerr << "\n";
#endif
}

class UnionFind {
 public:
  UnionFind(int n) {
    Padre.resize(n);
    TamComponente.resize(n);
    num_vertices = n;
    for (int i = 0; i < n; ++i) {
      Padre[i] = i;
      Raices.insert(i);
      TamComponente[i] = 1;
    }
  }
  int obtenRaiz(int vertice) {
    if (Padre[vertice] != vertice) {
      Padre[vertice] = obtenRaiz(Padre[vertice]);
    }
    return Padre[vertice];
  }
  int obtenTamComponente(int vertice) {
    return TamComponente[obtenRaiz(vertice)];
  }
  void unir(int a, int b) {
    int r_a = obtenRaiz(a);
    int r_b = obtenRaiz(b);
    if (r_a == r_b) {
      return;
    }
    TamComponente[r_a] += TamComponente[r_b];
    Padre[r_b] = r_a;
    Raices.erase(r_b);
  }
  int size() { return num_vertices; }
  bool borraComponente(int v) {
    const int raiz = obtenRaiz(v);
    if (Raices.find(raiz) == Raices.end()) {
      return false;
    }
    Raices.erase(raiz);
    num_vertices -= TamComponente[raiz];
    return true;
  }
  vector<int> obtenRaices() {
    std::vector<int> ret;
    ret.reserve(Raices.size());
    for (int r : Raices) {
      ret.push_back(r);
    }
    return ret;
  }
  vector<int> obtenComponente(int vertice) {
    const int raiz = obtenRaiz(vertice);
    vector<int> ret;
    for (int i = 0; i < Padre.size(); ++i) {
      if (obtenRaiz(i) == raiz) {
        ret.push_back(i);
      }
    }
    return ret;
  }

 private:
  vector<int> Padre;
  vector<int> TamComponente;
  set<int> Raices;
  int num_vertices;
};

enum class TipoRespuesta { R01, R10, IGUALES };

class DecifradorBits {
 private:
  int N;
  int restantes_1s;
  int restantes_0s;
  UnionFind union_find;

  TipoRespuesta preguntaBits(int a, int b, int pos) {
    std::vector<int> query(N);
    for (int indice = 0, val = 1; val <= N; ++indice, ++val) {
      if (val & (1 << pos)) {
        query[indice] = a;
        continue;
      }
      query[indice] = b;
    }
    const int s = similitud(N, &query[0]);
    if (s == 2) {
      return TipoRespuesta::R10;
    }
    if (s == 0) {
      return TipoRespuesta::R01;
    }
    return TipoRespuesta::IGUALES;
  }

  int cuentaBits1(int N, int pos) {
    int ret = 0;
    for (int i = 1; i <= N; ++i) {
      if (i & (1 << pos)) {
        ++ret;
      }
    }
    return ret;
  }

  void asignaValor(bool valor, const vector<int>& indices,
                   vector<bool>& salida) {
    for (const int vertice : union_find.obtenComponente(indices[0])) {
      salida[vertice] = valor;
    }
    union_find.borraComponente(indices[0]);
    if (valor) {
      restantes_1s -= indices.size();
      return;
    }
    restantes_0s -= indices.size();
  }

 public:
  DecifradorBits(int N) : union_find(N + 1) {
    this->N = N;
    union_find.borraComponente(0);
  }

  vector<bool> decifraBit(int num_bit) && {
    restantes_1s = cuentaBits1(N, num_bit);
    restantes_0s = N - restantes_1s;
    vector<bool> ret(N + 1);
    while (union_find.size() > 0) {
      vector<int> raices = union_find.obtenRaices();
      if (raices.size() == 1) {
        bool valor = restantes_1s > 0;
        asignaValor(valor, /*indices=*/union_find.obtenComponente(raices[0]),
                    /*salida=*/ret);
        break;
      }
      for (int i = 0; i + 1 < raices.size(); i += 2) {
        int a = raices[i];
        int b = raices[i + 1];
        TipoRespuesta r = preguntaBits(a, b, num_bit);
        if (r != TipoRespuesta::IGUALES) {
          const bool valor_a = r == TipoRespuesta::R10;
          const bool valor_b = !valor_a;
          asignaValor(valor_a, /*indices=*/union_find.obtenComponente(a),
                      /*salida=*/ret);
          asignaValor(valor_b, /*indices=*/union_find.obtenComponente(b),
                      /*salida=*/ret);
          continue;
        }
        union_find.unir(a, b);
      }
    }
    return ret;
  }
};

vector<int> invertir(const vector<int>& perm) {
  vector<int> ret(perm.size());
  for (int i = 0; i < perm.size(); ++i) {
    ret[perm[i] - 1] = i + 1;
  }
  return ret;
}

std::vector<int> buscaPermutacion(int N) {
  vector<int> perm_inv(N);
  for (int bit_num = 0, bit = 1; bit <= N; ++bit_num, bit *= 2) {
    std::vector<bool> valor_bit = DecifradorBits(N).decifraBit(bit_num);
    for (int i = 0; i < perm_inv.size(); ++i) {
      if (valor_bit[i + 1]) {
        perm_inv[i] |= bit;
      }
    }
  }
  return invertir(perm_inv);
}

}  // namespace

void Rudolph(int N) {
  std::vector<int> sol = buscaPermutacion(N);
  imprime(sol);
  localizacion(N, &sol[0]);
}