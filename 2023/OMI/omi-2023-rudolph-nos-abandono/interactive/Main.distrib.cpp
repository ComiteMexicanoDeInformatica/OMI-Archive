#include <algorithm>
#include <iostream>

#include "rudolph.h"
using namespace std;

int N, max_queries, min_queries, cnt = 0;
int V[4096];

int similitud(int _, int A[]) {
  if (cnt > max_queries) {
    cerr << "Has llamado la función similitud " << cnt
         << " veces, más de las que tenías permitido." << endl;
    cout << "0\n";
    exit(0);
  }
  if (_ != N) {
    cerr << "El tamaño del arreglo es distinto a N." << endl;
    cout << "0\n";
    exit(0);
  }
  cnt++;
  int aux = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] < 1 && A[i] > N) {
      cerr << "Hay valores del arreglo que son inválidos." << endl;
      cout << "0\n";
      exit(0);
    }
    aux += (A[i] == V[i]) ? 1 : 0;
  }
  return aux;
}

void localizacion(int _, int A[]) {
  if (_ != N) {
    cerr << "El tamaño del arreglo es distinto a N." << endl;
    cout << "0\n";
    exit(0);
  }
  int aux = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] < 1 && A[i] > N) {
      cerr << "Hay valores del arreglo que son inválidos." << endl;
      cout << "0\n";
      exit(0);
    }
    aux += (A[i] == V[i]) ? 1 : 0;
  }
  if (aux != N) {
    cerr << "El arreglo encontrado no coincide con la permutación del juez."
         << endl;
    cout << "0\n";
    exit(0);
  }
  if (max_queries == min_queries) {
    if (cnt <= max_queries) {
      cout << "1\n";
    } else {
      cerr << "Realisaste más preguntas que las permitidas." << endl;
      cout << "0\n";
      exit(0);
    }
  } else {
    double aux = (double(cnt - min_queries) / (max_queries - min_queries));
    aux = min(1.0, 1.0 - aux);
    if (aux + 0.01 >= 1.0) aux = 1;
    cout << aux << endl;
  }
}

int main() {
  cin >> N >> min_queries >> max_queries;

  for (int i = 0; i < N; i++) {
    cin >> V[i];
  }

  Rudolph(N);
}
