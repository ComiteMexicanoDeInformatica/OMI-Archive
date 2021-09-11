## Subtarea 1, $N \leq 500$, $F, C \leq 100$, $E = 1$ (9 puntos)

Los límites de la primera subtarea y el que sea únicamente un experimento, permite resolver el problema simulando el recorrido del laser hasta que salga del dispositivo. Es importante tener cuidado con los experimentos que se ciclan para lo cual es conveniente utilizar un arreglo de visitados.

En el siguiente código se muestra una simulación recursiva.  La simulación podría no ser recursiva, pero hacerla así servirá para subtareas futuras.

```
int simula(int direccion, int fila, int columna){
  if (disp[fila][columna] == 'X') return 0;
  if (visitado[fila][columna]) return -1;

  visitado[fila][columna] = 1;
  int res, cnt = 0, sigdir = direccion, sigfila = fila, sigcolumna = columna;

  if (disp[fila][columna] == '.'){
    sigfila = (direccion == sur) ? sigfila - 1 : (direccion == norte) ? sigfila + 1 : sigfila;
    sigcolumna = (direccion == oeste) ? sigcolumna - 1 : (direccion == este) ? sigcolumna + 1 : sigcolumna;
  }
  else if (disp[fila][columna] == '/'){
    sigfila = (direccion == oeste) ? sigfila - 1 : (direccion == este) ? sigfila + 1 : sigfila;
    sigcolumna = (direccion == sur) ? sigcolumna - 1 : (direccion == norte) ? sigcolumna + 1 : sigcolumna;
    sigdir = (direccion == norte) ? este : (direccion == este) ? norte : (direccion == sur) ? oeste : norte;
    ++cnt;
  }
  else {
    sigfila = (direccion == este) ? sigfila - 1 : (direccion == oeste) ? sigfila + 1 : sigfila;
    sigcolumna = (direccion == norte) ? sigcolumna - 1 : (direccion == sur) ? sigcolumna + 1 : sigcolumna;
    sigdir = (direccion == norte) ? oeste : (direccion == oeste) ? norte : (direccion == sur) ? este : sur;
    ++cnt;
  }

  if ((res = simula(sigdir, sigfila, sigcolumna)) == -1) return -1;
  else return cnt + res;
}

int main() {
  std::cin >> n >> F >> C;
  rep(fil, 0, F + 1)
      rep(col, 0, C + 1)
          disp[fil][col] = (!fil || fil == F + 1 || !col || col == C + 1) ? 'X' : '.';

  rep(i, 1, n) {
    std::cin >> espejo[i] >> f[i] >> c[i];
    disp[f[i]][c[i]] = espejo[i];
  }

  std::cin >> e >> dire >> fe >> ce;
  dirlaser = (dire == 'N') ? norte : (dire == 'S') ? sur : (dire == 'E') ? este : oeste;
  std::cout << simula(dirlaser, fe, ce);

  return 0;
}
```

## Subtarea 2, $N \leq 500$, $F, C \leq 100$ (10 puntos)

El tamaño del dispositivo en la segunda subtarea premite simular el dispositivo en memoria, sin embargo, para contestar todos los experimentos no sería viable simular en el tiempo de ejecución. Es necesario optimizar.

Observa que en muchos de los experimentos el laser recorrera casillas repetidas. Hay únicamente $400$ casillas de salida (el perímetro del dispositivo) y puede haber $10^5$ experimentos, eso quiere decir que es muy probable que haya experimentos que salgan por el mismo lugar y recorran tramos repetidos. Dado que el espacio es pequeño es posible memorizar el resultado de pasar por una casilla en una cierta dirección cuando pasemos y si volvemos a requerir ese resultado no tener que volver a calcularlo.

La implementación recursiva de la subtarea anterior se puede modificar para que almacene este resultado y lo devuelva en caso de tenerlo.

El siguiente código muestra una forma posible de hacerlo:

```
  if (disp[fila][columna] == 'X') return 1; // DEVUELVE 1 PARA DIFERENCIAR EN LA MEMORIA LOS QUE YA PASASTE
  if (visitado[fila][columna] == experimento) return -1;
  if (memoria[direccion][fila][columna]) return memoria[direccion][fila][columna]; // SI YA LO VISITASTE

  visitado[fila][columna] = experimento;
  int res, cnt = 0, sigdir = direccion, sigfila = fila, sigcolumna = columna;

  if (disp[fila][columna] == '.'){
    sigfila = (direccion == sur) ? sigfila - 1 : (direccion == norte) ? sigfila + 1 : sigfila;
    sigcolumna = (direccion == oeste) ? sigcolumna - 1 : (direccion == este) ? sigcolumna + 1 : sigcolumna;
  }
  else if (disp[fila][columna] == '/'){
    sigfila = (direccion == oeste) ? sigfila - 1 : (direccion == este) ? sigfila + 1 : sigfila;
    sigcolumna = (direccion == sur) ? sigcolumna - 1 : (direccion == norte) ? sigcolumna + 1 : sigcolumna;
    sigdir = (direccion == norte) ? este : (direccion == este) ? norte : (direccion == sur) ? oeste : norte;
    ++cnt;
  }
  else {
    sigfila = (direccion == este) ? sigfila - 1 : (direccion == oeste) ? sigfila + 1 : sigfila;
    sigcolumna = (direccion == norte) ? sigcolumna - 1 : (direccion == sur) ? sigcolumna + 1 : sigcolumna;
    sigdir = (direccion == norte) ? oeste : (direccion == oeste) ? norte : (direccion == sur) ? este : sur;
    ++cnt;
  }

  res = simula(sigdir, sigfila, sigcolumna, experimento);
  if (res != -1) res += cnt;

  memoria[direccion][fila][columna] = res;
  return res;
}
```

## Subtarea 3, $N \leq 1000$, $F, C \leq 10^5$, $E = 1$ (13 puntos)

En la tercera subtarea, al ser sólo un experimento podemos de nuevo simular, sin embargo, el tamaño del dispositivo es muy grande para mantenerlo en memoria, por lo que es necesario buscar otra forma de representarlo.

Observa que el láser sólo se ve afectado cuando pasa por una casilla con espejo, de modo que una representación guardando únicamente los espejos debe ser posible. Más aún si un láser sale de un espejo sólo tiene dos destinos: a) salir del dispositivo; b) chocar con el siguiente espejo en la dirección correspondiente. Por lo tanto, para simular el recorrido basta con saber, para cada espejo, el siguiente espejo en cada una de las cuatro direcciones.

El número de espejos permite revisar todas las parejas de espejos para determinar cuál espejo sigue de cualquier otro.

El siguiente código muestra una forma posible de resolver la subtarea 3:

```
int simula(int direccion, int idEspejo){
  if (!idEspejo) return 0;
  if (visitado[idEspejo]) return -1;

  visitado[idEspejo] = 1;
  int sigdir = direccion, sigid = 0;

  if (espejo[idEspejo] == '/') sigdir = (direccion == norte) ? este : (direccion == este) ? norte : (direccion == sur) ? oeste : sur;
  else sigdir = (direccion == norte) ? oeste : (direccion == oeste) ? norte : (direccion == sur) ? este : sur;
  sigid = sigespejo[sigdir][idEspejo].id;

  int res = simula(sigdir, sigid);
  return (res == -1) ? -1 : res + 1;
}

int main() {
  std::cin >> n >> F >> C;
  rep(i, 1, n) std::cin >> espejo[i] >> f[i] >> c[i];

  rep(i, 1, n){
      rep(j, 1, n){
          if (i == j) continue;
          if (f[i] == f[j]){ // ESTAN EN LA MISMA FILA
            if (c[i] < c[j] && (!sigespejo[este][i].id || sigespejo[este][i].posicion > c[j])) sigespejo[este][i] = {c[j], j};
            else if (c[i] > c[j] && (!sigespejo[oeste][i].id || sigespejo[oeste][i].posicion < c[j])) sigespejo[oeste][i] = {c[j], j};
          }
          else if (c[i] == c[j]){ // ESTAN EN LA MISMA COLUMNA
            if (f[i] < f[j] && (!sigespejo[norte][i].id || sigespejo[norte][i].posicion > f[j])) sigespejo[norte][i] = {f[j], j};
            else if (f[i] > f[j] && (!sigespejo[sur][i].id || sigespejo[sur][i].posicion < f[j])) sigespejo[sur][i] = {f[j], j};
          }
      }
  }

  std::cin >> e >> dire >> fe >> ce;
  dirlaser = (dire == 'N') ? norte : (dire == 'S') ? sur : (dire == 'E') ? este : oeste;
  if (dirlaser == norte) rep(i, 1, n){ if (c[i] == ce && f[i] > fe && (!sigexp.id || sigexp.posicion > f[i])) sigexp = {f[i], i}; }
  else if (dirlaser == sur) rep(i, 1, n){ if (c[i] == ce && f[i] < fe && (!sigexp.id || sigexp.posicion < f[i])) sigexp = {f[i], i}; }
  else if (dirlaser == este) rep(i, 1, n){ if (f[i] == fe && c[i] > ce && (!sigexp.id || sigexp.posicion > c[i])) sigexp = {c[i], i}; }
  else if (dirlaser == oeste) rep(i, 1, n){ if (f[i] == fe && c[i] < ce && (!sigexp.id || sigexp.posicion < c[i])) sigexp = {c[i], i}; }

  std::cout << simula(dirlaser, sigexp.id);

  return 0;
}
```

## Subtarea 4, $N \leq 1000$, $F, C \leq 10^5$ (20 puntos)

Al igual que con la subtarea 2, en la subtarea 4 es necesario memorizar los resultados de los espejos por los que ya pasamos.

Además en la subtarea 3 se busca el primer espejo con el que choca el láser de forma lineal, para poder contestar todos los experimentos es necesario encontrar el primer espejo en forma logarítmica, esto se puede lograr usando un map y sets.

El siguiente código muestra una forma de resolver la subtarea 4:

```
int simula(int direccion, int idEspejo, int experimento){
  if (!idEspejo) return 0;
  if (visitado[idEspejo] == experimento) return -1;
  if (memoria[direccion][idEspejo]) return memoria[direccion][idEspejo];

  visitado[idEspejo] = experimento;
  int sigdir = direccion, sigid = 0;

  if (espejo[idEspejo] == '/') sigdir = (direccion == norte) ? este : (direccion == este) ? norte : (direccion == sur) ? oeste : sur;
  else sigdir = (direccion == norte) ? oeste : (direccion == oeste) ? norte : (direccion == sur) ? este : sur;
  sigid = sigespejo[sigdir][idEspejo].id;

  int res = simula(sigdir, sigid, experimento);
  if (res == -1) return memoria[direccion][idEspejo] = -1;
  else return memoria[direccion][idEspejo] = res + 1;
}

int main() {
  std::map<lli, std::set< std::pair<lli, lli> > > mapafilas, mapacolumnas;
  std::cin >> n >> F >> C;
  rep(i, 1, n){
      std::cin >> espejo[i] >> f[i] >> c[i];
      mapafilas[f[i]].insert({c[i], i});
      mapacolumnas[c[i]].insert({f[i], i});
  }

  rep(i, 1, n){
      rep(j, 1, n){
          if (i == j) continue;
          if (f[i] == f[j]){ // ESTAN EN LA MISMA FILA
            if (c[i] < c[j] && (!sigespejo[este][i].id || sigespejo[este][i].posicion > c[j])) sigespejo[este][i] = {c[j], j};
            else if (c[i] > c[j] && (!sigespejo[oeste][i].id || sigespejo[oeste][i].posicion < c[j])) sigespejo[oeste][i] = {c[j], j};
          }
          else if (c[i] == c[j]){ // ESTAN EN LA MISMA COLUMNA
            if (f[i] < f[j] && (!sigespejo[norte][i].id || sigespejo[norte][i].posicion > f[j])) sigespejo[norte][i] = {f[j], j};
            else if (f[i] > f[j] && (!sigespejo[sur][i].id || sigespejo[sur][i].posicion < f[j])) sigespejo[sur][i] = {f[j], j};
          }
      }
  }

  std::cin >> e;
  rep(experimento, 1, e){
    std::cin >> dire >> fe >> ce;

    dirlaser = (dire == 'N') ? norte : (dire == 'S') ? sur : (dire == 'E') ? este : oeste;
    sigexp = {0, 0};

    if ((dirlaser == norte || dirlaser == sur) && mapacolumnas.count(ce)) {
        auto it = mapacolumnas[ce].upper_bound({fe, 0});
        if (dirlaser == norte && it != mapacolumnas[ce].end()) sigexp = *it;
        else if (dirlaser == sur && it != mapacolumnas[ce].begin()) sigexp = *(--it);
    }
    else if ((dirlaser == este || dirlaser == oeste) && mapafilas.count(fe)) {
        auto it = mapafilas[fe].upper_bound({ce, 0});
        if (dirlaser == este && it != mapafilas[fe].end()) sigexp = *it;
        else if (dirlaser == oeste && it != mapafilas[fe].begin()) sigexp = *(--it);
    }

    std::cout << simula(dirlaser, sigexp.id, experimento) << nl;
  }

  return 0;
}
```

## Subtarea 5 y 6 (18 y 30 puntos)

En las subtareas 5 y 6 la simulación con y sin memoria es exactamente igual que en las subtareas 3 y 4.  La diferencia en este par de subtareas es en el número de espejos.  Para poder resoverla en tiempo es necesario poder obtener el _sigEspejo_ en un tiempo menor que cuadrado.

Afortunadamente, recorriendo los sets de la subtarea 4 es posible hacerlo.

El siguiente código muestra cómo obtener el siguiente espejo:

```
  for (auto fila : mapafilas){
    lli prev = 0;
    auto it = fila.second.begin();
    while (it != fila.second.end()){
        sigespejo[oeste][(*it).id] = {0, prev};
        sigespejo[este][prev] = {0, (*it).id};
        prev = (*it).id;
        it++;
    }
  }
  for (auto columna : mapacolumnas){
    lli prev = 0;
    auto it = columna.second.begin();
    while (it != columna.second.end()){
        sigespejo[sur][(*it).id] = {0, prev};
        sigespejo[norte][prev] = {0, (*it).id};
        prev = (*it).id;
        it++;
    }
  }
```


