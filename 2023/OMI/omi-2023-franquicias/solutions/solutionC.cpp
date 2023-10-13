#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <vector>
using namespace std;

namespace {

using ll = int64_t;
using uint = ll;
const uint MAX_POS = 1000010;

pair<double, ll> resuelveSegmento(const std::vector<ll>& programadores,
                                  ll inicio, ll fin) {
  // cout << inicio << " " << fin << endl;
  assert(fin > inicio);
  double centro = max(inicio + 0.5, 0.0);
  ll izq = inicio;
  ll der = inicio;
  ll suma = 0;
  double mejor_arg = inicio;
  ll mejor_valor = 0;
  for (; centro < fin && centro < MAX_POS; centro += 0.5) {
    while (izq - inicio <= centro - izq) {
      bool izq_en_rango = (izq >= 0 && izq < programadores.size());
      suma -= (izq_en_rango ? programadores[izq] : 0);
      ++izq;
    }
    while (der - centro < fin - der) {
      bool der_en_rango = (der >= 0 && der < programadores.size());
      suma += (der_en_rango ? programadores[der] : 0);
      ++der;
    }
    if (suma > mejor_valor) {
      mejor_valor = suma;
      mejor_arg = centro;
    }
    // cout << izq << " " << centro << " " << der << " " << suma << "\n";
  }
  return make_pair(mejor_arg, mejor_valor);
}

struct CasoDePrueba {
  std::vector<ll> programadores;
  std::vector<ll> competencia;
  uint costo_por_franquicia;
  ll gasto_por_programador;
  ll num_franquicias_agregar;
};

struct OpcionSolucion {
  ll num_rango;
  ll num_franquicia;
  ll utilidad;
  bool operator<(const OpcionSolucion& b) const {
    return utilidad < b.utilidad;
  }
};

class Resolvedor {
 private:
  CasoDePrueba caso;
  vector<ll> sumas_parciales;
  vector<ll> calculaSumasParciales(const vector<ll>& orig) {
    vector<ll> ret(MAX_POS);
    ret[0] = orig[0];
    for (uint i = 1; i < ret.size(); ++i) {
      ret[i] = ret[i - 1] + (i < orig.size() ? orig[i] : 0);
    }
    return ret;
  }
  ll sumaEnRango(ll indice_rango) {
    ll inicio = 0;
    if (indice_rango != -1) {
      inicio = caso.competencia[indice_rango];
    }
    ll fin = MAX_POS - 1;
    if (indice_rango + 1 != caso.competencia.size()) {
      fin = max(caso.competencia[indice_rango + 1] - 1LL, 0LL);
    }
    ll suma_dentro_rango = sumas_parciales[fin] - sumas_parciales[inicio];
    // cout << "Suma en rango " << indice_rango << " es " << suma_dentro_rango
    // << "\n";
    return suma_dentro_rango;
  }
  vector<OpcionSolucion> calcularOpciones() {
    vector<OpcionSolucion> opciones;
    for (ll i = -1; i < static_cast<ll>(caso.competencia.size()); ++i) {
      ll inicio = -1000000;
      if (i >= 0 && i < caso.competencia.size()) {
        inicio = caso.competencia[i];
      }
      ll fin = 2000000;
      if (i + 1 < caso.competencia.size()) {
        fin = caso.competencia[i + 1];
      }
      auto sol_1_franquicia = resuelveSegmento(caso.programadores, inicio, fin);
      ll utilidad_1_franquicia =
          sol_1_franquicia.second * caso.gasto_por_programador -
          caso.costo_por_franquicia;
      opciones.emplace_back(OpcionSolucion{.num_rango = i,
                                           .num_franquicia = 0,
                                           .utilidad = utilidad_1_franquicia});
      // Recordar que los rangos son excluyentes
      ll suma_dentro_rango = sumaEnRango(i);
      opciones.push_back(OpcionSolucion{
          .num_rango = i,
          .num_franquicia = 1,
          .utilidad = suma_dentro_rango * caso.gasto_por_programador -
                      2LL * caso.costo_por_franquicia - utilidad_1_franquicia});
    }
    return opciones;
  }
  vector<OpcionSolucion> eligeMejoresOpciones(vector<OpcionSolucion> opciones) {
    std::sort(opciones.rbegin(), opciones.rend());
    if (opciones.size() > caso.num_franquicias_agregar) {
      opciones.resize(caso.num_franquicias_agregar);
    }
    while (opciones.size() > 0 && opciones.back().utilidad <= 0) {
      opciones.pop_back();
    }
    return opciones;
  }

 public:
  Resolvedor(CasoDePrueba caso) : caso(caso) {
    sumas_parciales = calculaSumasParciales(caso.programadores);
  }
  ll resuelve() {
    vector<OpcionSolucion> todas_las_opciones = calcularOpciones();
    vector<OpcionSolucion> mejores_opciones =
        eligeMejoresOpciones(todas_las_opciones);
    ll utilidad_total = 0;
    for (const auto& opcion : mejores_opciones) {
      utilidad_total += opcion.utilidad;
    }
    return utilidad_total;
  }
};
}  // namespace

CasoDePrueba leer() {
  CasoDePrueba ret;
  ll largo_calle;
  ll num_franquicias;
  ll num_edificios;
  cin >> ret.num_franquicias_agregar >> largo_calle >> num_franquicias >>
      num_edificios;
  cin >> ret.gasto_por_programador >> ret.costo_por_franquicia;
  ret.competencia.resize(num_franquicias);
  for (ll& a : ret.competencia) {
    cin >> a;
  }
  ret.programadores.resize(largo_calle + 1);
  for (ll i = 0; i < num_edificios; ++i) {
    ll pos, val;
    cin >> pos >> val;
    ret.programadores[pos] = val;
  }
  return ret;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  auto caso = leer();
  Resolvedor resolvedor(caso);
  cout << resolvedor.resuelve() << "\n";
  return 0;
}
