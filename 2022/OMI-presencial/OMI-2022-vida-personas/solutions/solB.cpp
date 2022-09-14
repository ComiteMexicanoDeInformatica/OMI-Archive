#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << "\n";

#define MAX 1000000

#define nacimiento 0
#define pregunta 1
#define muerte 2

#define fecha first.first
#define tipo first.second
#define id second

std::vector<pair<pair<int, int>, int> > eventos;
int n, q, a, b;
int resultados[3][MAX + 2], vivo[MAX + 2];

int main() {
  // LEE LA ENTRADA Y GENERA LOS EVENTOS.
  // LOS EVENTOS DEBEN IR ORDENADOS POR AÑO Y LUEGO TIPO,
  // EN EL TIPO LA PREFERENCIA DEBE SER: NACIMIENTO, PREGUNTA, MUERTE
  std::cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a >> b;
    eventos.push_back({{a, nacimiento}, i});
    eventos.push_back({{b, muerte}, i});
  }
  for (int i = 1; i <= q; ++i) {
    std::cin >> a;
    eventos.push_back({{a, pregunta}, i});
  }

  // ORDENA LOS EVENTOS
  std::sort(eventos.begin(), eventos.end());

  // PROCESA LOS EVENTOS
  int personasVivas = 0;
  std::deque<pair<int, int> > vivos;
  for (auto ev : eventos) {
    if (ev.tipo == nacimiento) {
      // SI ES UN NACIMIENTO, REGISTRA QUE HAY UNA PERSONA VIVA MAS
      // Y GUARDA A DICHA PERSONA EN LA LISTA DE PERSONAS VIVAS PARA CONTESTAR
      // PREGUNTAS
      ++personasVivas;
      vivo[ev.id] = 1;
      vivos.push_back({ev.fecha, ev.id});
    } else if (ev.tipo == pregunta) {
      // PARA LAS PREGUNTAS DEBEMOS DE CONTESAR LOS SIGUIENTE DATOS:
      // PERSONAS VIVAS, ESE VALOR ESTAN EN LA VARIABLE personas vivas
      resultados[0][ev.id] = personasVivas;

      // PARA LA PERSONA MAS JOVEN Y MAS ANCIANA SE USA EL DEQUE DE vivos
      // ES IMPORTANTE IR ELMINANDO A LAS PERSONAS QUE YA NO ESTAN VIVAS DE LOS
      // EXTREMOS DEL DEQUE QUITA LOS NO-VIVOS DEL INICIO
      while (!vivos.empty() && !vivo[vivos.front().id]) vivos.pop_front();

      // QUITA LOS NO-VIVOS DEL FINAL
      while (!vivos.empty() && !vivo[vivos.back().id]) vivos.pop_back();

      if (vivos.empty())
        resultados[1][ev.id] = resultados[2][ev.id] =
            0;  // SI NO HAY NADIE VIVO DEVUELVE CEROS
      else {
        resultados[1][ev.id] = ev.fecha - vivos.back().first;
        resultados[2][ev.id] = ev.fecha - vivos.front().first;
      }
    } else {
      // CUANDO UNA PERSONA MUERE :( HAY QUE DISMINUIR LA CUENTA DE VIVOS
      // Y MARCARLA COMO NO VIVA PARA CUANDO SEA NECESARIO SACARLA DEL DEQUE
      --personasVivas;
      vivo[ev.id] = 0;
    }
  }

  for (int i = 1; i <= q; ++i) {
    for (int j = 0; j < 3; ++j) {
      std::cout << resultados[j][i] << " ";
    }
    std::cout << "\n";
  }

  return 0;
}
