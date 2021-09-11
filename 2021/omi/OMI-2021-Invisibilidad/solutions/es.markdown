## Subtarea 1, $F = 3, N = 1$ (6 puntos)

Dado que hay $3$ filas y de acuerdo al texto no puede haber zonas peligrosas ni en la fila $1$ ni en la $F$, sólo puede haber zonas peligrosas en la fila $2$.

Observa que la única forma en que Harry se ve forzado a pasar por la zona peligrosa, dado que sólo hay $1$, es si la zona peligrosa ocupa el ancho completo de la ciudad. Revisar esto basta para obtener los puntos de la subtarea.

Un posible código para hacerlo es el siguiente:

```
int main()
{
    std::cin >> n >> f >> c;
    std::cin >> f1 >> c1 >> f2 >> c2;

    if (c1 == 1 && c2 == c) std::cout << 1 << nl;
    else std::cout << 0 << nl;

    return 0;
}
```

## Subtarea 2, $F = 3, C \leq 1000$ (10 puntos)

Esta subtarea es similar a la 1 salvo que ahora pueden existir múltiples zonas peligrosas. Observa nuevamente que Harry sólo se verá forzado a pasar por una zona peligrosa si la segunda fila está ocupada en su totalidad por zonas peligrosas.

El texto asegura que las zonas no se traslapan, por lo que dado el límite de las columnas, es posible marcar todas las zonas peligrosas y validar si toda la fila está ocupada.

Un posible código que resuelve la subtarea 2 es el siguiente:

```
int main()
{
    std::cin >> n >> f >> c;
    for(int i = 1; i <= n; ++i){
        std::cin >> f1 >> c1 >> f2 >> c2;
        for(int col = c1; col <= c2; ++col) cols[col] = 1;
    }

    for(int col = 1; col <= c; ++col) if (cols[col]) ++cnt;

    if (cnt == c) std::cout << 1 << nl;
    else std::cout << 0 << nl;

    return 0;
}
```

## Subtarea 3, $F = 3$ (12 puntos)

La subtarea 3 difiere de la 2 en el límite de columnas.  El límite de columnas es tal que la memoria y tiempo no son suficientes para marcar las zonas. Por lo tanto es necesario saber si la segunda fila está ocupada por completo sin necesidad de marcar.

Una forma simple de hacer esta validación es ordenar las zonas peligrosas por columna de inicio y validar que se vayan llenando todos los espacios.

Un posible código que resuelve las primeras 3 subtareas es el siguiente:

```
lli n, f, c, f1, f2, ult;
std::pair<lli, lli> cols[MAX_N];

int main()
{
    std::cin >> n >> f >> c;
    for(int i = 0; i < n; ++i) std::cin >> f1 >> cols[i].first >> f2 >> cols[i].second;

    std::sort(cols, cols + n);

    ult = 0;
    for (int i = 0; i < n; ++i){
        // Si la siguiente zona no esta pegada a la última que terminó entonces hay un hueco
        if (cols[i].first > ult + 1){
            std::cout << 0 << nl;
            return 0;
        }
        ult = cols[i].second; // Actualiza el nuevo final
    }

    if (ult == c) std::cout << 1 << nl;
    else std::cout << 0 << nl;

    return 0;
}
```

## Subtarea 4, $C = 1$ (9 puntos)

Dado que sólo hay 1 columna, el número de veces que Harry debe ponerse la capa es igual a la cantidad de zonas separadas que existan.  

Una forma de validarlo es usar una técnica similar a la de la subtarea 3 pero esta vez con las filas. Ordenar las zonas por fila y recorrerlas contando la cantidad de zonas separadas.

Un posible código que resuelve la subtarea 4 es el siguiente:

```
int main()
{
    std::cin >> n >> f >> c;
    for(int i = 0; i < n; ++i) std::cin >> fils[i].first >> c1 >> fils[i].second >> c2;

    std::sort(fils, fils + n);

    ult = fils[0].first - 1;
    for (int i = 0; i < n; ++i){
        if (fils[i].first > ult + 1) ++cnt;
        ult = fils[i].second;
    }

    std::cout << cnt << nl;

    return 0;
}
```

## Subtarea 5, $F, C \leq 500$, $N \leq 100$ (20 puntos)

Los límites de la subtarea 5 permiten crear una matriz en la que se marquen las zonas peligrosas y posteriormente hacer una búsqueda priorizada para encontrar el camino que usa menos veces la capa.

Durante la búsqueda es importante tomar en cuenta que mientras usa la capa, Harry puede moverse en diagonal, pero cuando no la usa, no lo tiene permitido.

Un posible código para resolver la subtarea 5 es el siguiente:

```
lli n, f, c, f1, f2, c1, c2, ciudad[MAX_TAM][MAX_TAM], visitados[MAX_TAM][MAX_TAM];
std::set< std::pair <lli, std::pair<lli, lli> > > q;

int main() {
  std::cin >> n >> f >> c;
  for (int i = 1; i <= n; ++i) {
    std::cin >> f1 >> c1 >> f2 >> c2;
    for (int fil = f1; fil <= f2; ++fil)
        for (int col = c1; col <= c2; ++col) ciudad[fil][col] = peligrosa;
  }

  for (int fil = 0; fil <= f + 1; ++fil) visitados[fil][0] = visitados[fil][c + 1] = 1;
  for (int col = 0; col <= c + 1; ++col) visitados[0][col] = visitados[f + 1][col] = 1;

  q.insert({0, {1, 1}}); // Empieza en la posición (1, 1) sin haber usado la capa
  lli fil, col, tam;
  while(!q.empty()){
    fil = (*q.begin()).fila;
    col = (*q.begin()).columna;
    tam = (*q.begin()).largo;
    q.erase(q.begin());
    if (fil == f){ // Si ya encontro un camino a la última fila, termina
        std::cout << tam << nl;
        return 0;
    }

    visitados[fil][col] = 1;
    // prueba las 8 direcciones
    for(int dfil = -1; dfil <= 1; ++dfil){
        for(int dcol = -1; dcol <= 1; ++dcol){
            if (ciudad[fil][col] == tranquila && dfil != 0 && dcol != 0) continue; //Si no trae la capa no puede moverse en diagonal
            f1 = fil + dfil;
            c1 = col + dcol;
            if (!visitados[f1][c1]){
                if (ciudad[f1][c1] == peligrosa && ciudad[fil][col] == tranquila)
                    q.insert({tam + 1, {f1, c1}});
                else
                    q.insert({tam, {f1, c1}});
            }
        }
    }
  }

  return 0;
}
```

## Subtareas 6 y 7 (43 puntos)

Para resolver las subtareas 6 y 7 es necesario generalizar la observación de las subtareas anteriores, en específico, que Harry tiene que usar su capa si hay un conjunto de zonas riesgosas contiguas que abarque el ancho total del mundo.

Dos zonas riesgosas se consideran contiguas si se tocan vertical u horizontalmente y si se tocan en una esquina.  Esto es debido a que cuando Harry no trae la capa no puede moverse en diagonal, por lo que si hay dos zonas riesgosas tocandose en una esquina y Harry está en alguna de las casillas _no riesgosas_, forzosamente debe pasar por alguna de las dos zonas peligrosas para llegar a la otra zona _no riesgosa_.

Llamemos a un conjunto de zonas riesgosas contiguas un _bloque riesgoso_.  Observa que una vez dentro del _bloque_, Harry puede moverse libremente a cualquier casilla del mismo sin necesidad de quitarse la capa. Además observa que si hay dos _bloques_ riesgosos distintos que van desde la primera columna a la última, forzosamente debe existir una zona no riesgosa entre ambos, de otra forma serían el mismo _bloque_.

De las observaciones anteriores se concluye que la cantidad de veces que Harry debe usar la capa es igual a la cantidad de _bloques_ que cubran la totalidad de las columnas.

Para ambos casos se requiere utilizar alguna estructura de DSU (Disjoint Set Union) para llevar el control de las zonas riesgosas que forman un _bloque_.

La diferencia entre la subtarea 6 y la 7 es el método que uses para validar qué zonas son contiguas.

### Subatarea 6, $N \leq 2000$ (20 puntos)

La subtarea 6 tiene una cantidad de zonas que permite revisar todas las zonas contra todas en tiempo cuadrado.

Un posible código para resovler la subtarea 6 es el siguiente:

```
lli n, f, c, f1[MAX_N], f2[MAX_N], c1[MAX_N], c2[MAX_N], dsu[MAX_N], mi, ma, cnt;

bool contiguos(lli a, lli b){
    if (c1[a] == c2[b] + 1 || c1[b] == c2[a] + 1){ // horizontal
        return (f1[a] >= f1[b] && f1[a] <= f2[b] + 1) || (f1[b] >= f1[a] && f1[b] <= f2[a] + 1);
    }
    else if (f1[a] == f2[b] + 1 || f1[b] == f2[a] + 1){ // vertical
        return (c1[a] >= c1[b] && c1[a] <= c2[b] + 1) || (c1[b] >= c1[a] && c1[b] <= c2[a] + 1);
    }
    return false;
}

lli bloque(lli a){
    return (dsu[a] == a) ? a : dsu[a] = bloque(dsu[a]);
}

void une(lli a, lli b){
    lli ba = bloque(a);
    lli bb = bloque(b);
    if (ba != bb) dsu[ba] = bb;
}

int main() {
  std::cin >> n >> f >> c;
  for (int i = 1; i <= n; ++i) std::cin >> f1[i] >> c1[i] >> f2[i] >> c2[i];
  for (int i = 1; i <= n; ++i) dsu[i] = i;

  for (int i = 1; i < n; i++){
    for (int j = i + 1; j <= n; j++){
        if (contiguos(i, j)) une(i, j);
    }
  }

  for (int i = 1; i <= n; i++){
    if (bloque(i) == i){
        mi = c + 1;
        ma = 0;
        for (int j = 1; j <= n; j++){
            if (bloque(j) == i){
                mi = std::min(mi, c1[j]);
                ma = std::max(ma, c2[j]);
            }
        }
        if (mi == 1 && ma == c) cnt++;
    }
  }

  std::cout << cnt << nl;

  return 0;
}
```

### Sutarea 7 (23 puntos)

La subtarea 7 requiere que se puedan obtener los _bloques_ en un tiempo menor a cuadrado.  Una forma de hacerlo es mediante un barrido tomando provecho que las zonas no se traslapan.

Considera cada zona peligrosa como el par de líneas verticales y el par de líneas horizontales que lo delimitan. 

A las líneas verticales les llamaremos _eventos_ y hay de dos tipos, de _inicio_ y de _fin_. Los eventos de _inicio_ corresponden a la columna de la izquierda y los de _fin_ a la columna de la derecha.

A las líneas horizontales les llamaremos _zonas activas_ y las mantendremos ordenadas, puede ser usando un _set_ de C++.

Ahora ordena los _eventos_ de todas las zonas y procésalos de grande a chico con el siguiente algoritmo:

- Si el _evento_ es un evento de _inicio_ entonces...
  - Busca en las _zonas activas_ si hay una que toque verticalmente a la zona del _evento_. Como las _zonas activas_ están ordenadas, esto puede hacerse en tiempo logarítmico.
  - Busca en las _zonas activas_ si hay una que toque horizontalmente a la zona del _evento_. Esto se puede hacer igualmente en tiempo logarítmico.
  - Si encontraste alguna _zona activa_ que toque a la del evento, únelas.
  - Agrega las dos líneas horizontales que corresponden a este evento al listado de _zonas activas_.
- Si el _evento_ es de _fin_ entonces...
  - Elimina las líneas horizontales que corresponden a este evento del listado de _zonas activas_.
  
Dado que habrá un número de eventos igual a $2N$ y paracada evento se hace un proceso logarítmico. La solución tiene una complejidad $O(N logN)$

Un posible código para resolver el problema es el siguiente: 

```
int main() {
  std::cin >> n >> f >> c;
  rep(i, 1, n) {
    std::cin >> f1[i] >> c1[i] >> f2[i] >> c2[i];
    l[i] = c1[i];
    r[i] = c2[i];
    dsu[i] = i;
    eventos.push_back({c1[i], {inicio, i}});
    eventos.push_back({c2[i] + 1, {fin, i}});
  }
  std::sort(eventos.begin(), eventos.end());

  for (auto ev : eventos) {
    if (ev.tipo == inicio) {
      auto it = activos.upper_bound({f2[ev.id], 0});
      if (it != activos.end()){
        if ((*it).fila == f2[ev.id] + 1) { une(ev.id, (*it).idzona); }// se tocan verticalmente
        else if (f1[(*it).idzona] <= f2[ev.id]) { une(ev.id, (*it).idzona); }// se tocan horizontal
      }

      it = activos.lower_bound({f1[ev.id] - 1, 0});
      if (it != activos.end()){
        if ((*it).fila == f1[ev.id] - 1) { une(ev.id, (*it).idzona); }// se tocan verticalmente
        else if (f2[(*it).idzona] >= f1[ev.id] && f1[(*it).idzona] <= f1[ev.id]) { une(ev.id, (*it).idzona); }// horizontalmente
      }

      activos.insert({f1[ev.id], ev.id});
      if (f1[ev.id] != f2[ev.id]) activos.insert({f2[ev.id], ev.id});
    } else {
      activos.erase({f1[ev.id], ev.id});
      if (f1[ev.id] != f2[ev.id]) activos.erase({f2[ev.id], ev.id});
    }
  }

  rep(i, 1, n) {
    g = comp(i);
    l[g] = std::min(l[g], l[i]);
    r[g] = std::max(r[g], r[i]);
  }

  rep(i, 1, n) if (comp(i) == i && l[i] == 1 && r[i] == c) res++;

  std::cout << res << nl;

  return 0;
}
```

