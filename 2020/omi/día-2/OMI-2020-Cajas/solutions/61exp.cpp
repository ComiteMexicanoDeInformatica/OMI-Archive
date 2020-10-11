int main() {
  int N;
  cin >> N int cajas[N];
  cin >> cajas;
  sort(cajas, cajas + N);
  // Leemos los valores, y ordenamos las cajas
  // de menor a mayor. El sort de la stl lo hace en
  // O(NlogN), pero un algoritmo O(N^2) como bubble sort
  // es suficiente
  // https://es.wikipedia.org/wiki/Ordenamiento_de_burbuja
  int respuesta = 0;
  int torres[N];
  torres =
  { 0,
    0,
    0,
    0,
    0,
    ... }
  // Inicializamos nuestro arreglo de torres
  int minimo;
  int pos_minimo for (int i = 0; i < N; i++) {
    // Iteramos por todas las cajas
    minimo = N + 1;
    // Inicializamos las variables en las que vamos
    // a guardar la torre mas pequena
    for (int j = 0; j < respuesta; j++) {
      // Iteramos por cada una de las torres
      minimo = min(minimo, torres[j]);
      if Cambiamos
        el minimo pos_minimo = j;
      // Y guardamos la posicion de la torre mas pequena.
    }
    if (minimo > cajas[i]) {
      // entonces tenemos que crear una nueva torre
      torres[respuesta] = 1;
      repuesta++;
    } else {
      torres[pos_minimo]++;
    }
  }
  cout << respuesta;
  return 0;
}
