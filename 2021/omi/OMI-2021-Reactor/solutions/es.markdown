## Observaciones necesarias

### Determinación del tipo de crisis

Observa que el tipo de crisis depende de si hay _ciclos_ en la red de conexiones que parten del reactor con la falla inicial. Un _ciclo_ es un camino de conexiones que parte de un reactor $a$ y vuelve a ese reactor $a$ luego de haber pasado por otros, por ejemplo 1 -> 2 -> 3 -> 1.

Cuando no existen _ciclos_ en la red, al reparar la falla inicial el primer reactor se vuelve estable, lo que hace que los reactores a los que está conectado se vuelvan estables y así sucesivamente y se tiene una _crisis_ de _bajo nivel_.

Ahora, si existen _ciclos_ en algún lugar de la red, por ejemplo 1 -> 2 -> 3 -> 4 -> 2 (hay un ciclo de reactor 2 al 4), el reactor 2 tiene dos causas de inestabilidad, la que le llega desde el reactor 1 y la que le llega del reactor 4. Al reparar la falla en el reactor 1, el reactor 2 sigue siendo inestable por el reactor 4 y todos los reactores del _ciclo_ continuarán inestables de forma indefinida. Esto ocasiona una _crisis_ de tipo _grave_.

Finalmente, si existe un reactor que pertenece a más de un _ciclo_, este reactor, al repararse la falla inicial seguirá con al menos dos causas de inestabilidad ocasionando una _crisis_ de tipo _severo_.

Determinar el tipo de _crisis_ depende por tanto de determinar si existen _ciclos_ y si existe algún nodo que pertenezca a más de un _ciclo_.

### Conteo del número de reactores que emiten radiación al medio ambiente

Los reactores que emiten radiación al medio ambiente son los nodos _hojas_ de la red de reactores, es decir, los nodos a los que llega la inestabilidad pero no están conectados a nada.

Para contar los emisores durante la falla, basta con contar cuántas _hojas_ hay en la estructura. Sin embargo para contar los emisores una vez reparada la falla es necesario tomar en cuenta únicamente las _hojas_ de la estructura que tengan como ancestro un _ciclo_.

## Subtareas 1 y 2, $a < b$ (24 + 12 = 36 puntos)

El hecho de que en todas las conexiones $a < b$ implica que es imposible formar un ciclo, ya que si todas las conexiones van de un número menor a uno mayor haría falta una que regrese de un mayor a un menor para formar un ciclo.

Al ser imposible formar ciclos las _crisis_ siempre son de _bajo nivel_. Por lo que para estas dos subtareas el tipo de _crisis_ siempre es **B**.

Para contar los reactores que emiten radiación al medio ambiente basta con saber las _hojas_ que están debajo del reactor inestable inicial. Lo anterior se puede saber fácilmente usando una DFS. Es necesario tener cuidado en no contar doble, la estructura que se forma con los reactores es lo que se conoce como una DAG (Grafo Acíclico Dirigido). En un DAG, a diferencia de un árbol, la cantidad de formas distintas de llegar de un nodo a otro puede crecer exponencialmente, de modo que si no se marcan los nodos como visitados, se puede llegar a una _hoja_ de distintas formas y contarla más de una vez.

El siguiente es un posible código para resolver las subtareas 1 y 2:

```
void dfs(lli nodo){
    visitado[nodo] = 1;
    if (hijos[nodo].size()){
        for (auto hijo : hijos[nodo]) if (!visitado[hijo]) dfs(hijo);
    }
    else ++hojas;
}

int main() {
  std::cin >> n >> m >> r;
  rep(i, 1, m) {
    std::cin >> a >> b;
    hijos[a].push_back(b);
  }

  std::cout << "B\n";
  dfs(r);
  std::cout << hojas << " 0\n";

  return 0;
}
```

## Subtarea 3 y 4, $a < b$ en todas menos una conexión (12 + 24 = 36 puntos)

Al existir una conexión que va de mayor a menor es posible que se forme un ciclo, de modo que la crisis puede ser de _bajo nivel_, _grave_ o incluso _severa_. El tipo de crisis depende de dos cosas:

- Que exista un ciclo.
- Que el reactor inicialmente _inestable_ pueda llegar a ese ciclo (o forme parte de él). Si existe un ciclo al que el reactor inicial puede llegar, la crisis sera _grave_ o _severa_.
- Que exista más de un camino que conecte a dos nodos del ciclo. Si existe más de un camino entre cualesquiera dos nodos del ciclo significa que habrá al menos un reactor que tendrá 2 o más causas de inestabilidad ocasionando una crisis _severa_.

En cuanto a los reactores que emiten radiación, el conteo de emisores con la falla activa es exactamente igual que en las subtareas anteriores. Para el caso de reactores que emiten radiación luego de arreglada la falla, es necesario contar únicamente las _hojas_ de los reactores que pertenecen al ciclo, ya que una vez reparada la falla, estos son los que continuarán inestables y por tanto los reactores a los que ellos están conectados continuarán emitiendo.

Un posible código para resolver las tareas 1, 2, 3 y 4 es el siguiente:

```
void dfs(lli nodo) {
  visitado[nodo] = 2;
  if (caminosCiclo[nodo]) llegoACiclo = true;
  if (hijos[nodo].size()) {for(auto hijo : hijos[nodo]) if (visitado[hijo] < 2) dfs(hijo);}
  else ++hojas;
}

void dfsciclo(lli nodo) {
  visitado[nodo] = 3;
  if (hijos[nodo].size()) {for(auto hijo : hijos[nodo]) if (visitado[hijo] < 3) dfsciclo(hijo);}
  else ++hojas_ciclo;
}

lli marcaCiclo(lli nodo){
    if (nodo == backa) return 1; // ES EL FINAL DEL CICLO
    if (visitado[nodo]) return caminosCiclo[nodo];
    visitado[nodo] = 1;
    for (auto h : hijos[nodo]) caminosCiclo[nodo] += marcaCiclo(h);
    return caminosCiclo[nodo];
}

int main() {
  std::cin >> n >> m >> r;
  rep(i, 1, m) {
    std::cin >> a >> b;
    if (a > b){
        backa = a;
        backb = b;
    }
    hijos[a].push_back(b);
  }

  if (backb) marcaCiclo(backb);

  dfs(r);
  if (!llegoACiclo)
    std::cout << "B\n" << hojas << " 0\n";
  else{
    dfsciclo(backb);
    if (caminosCiclo[backb] == 1) std::cout << "G\n" << hojas << " " << hojas_ciclo << "\n";
    else std::cout << "S\n" << hojas << " " << hojas_ciclo << "\n";
  }

  return 0;
}
```

## Subtarea 5, sin restricciones (28 puntos)

En la última subtarea pueden existir casos con cualquier tipo de crisis. Detectar crisis de tipo _severo_ implica poder detectar ciclos compuestos o anidados en un grafo, lo cual puede ser complejo de implementar, sin embargo en el problema no es necesario conocer el ciclo específicamente, basta con detectar si existe y eso se puede hacer de forma más sencilla.

Si se _simula_ la falla y se propaga la inestabilidad marcando la cantidad de causas de inestabilidad en cada reactor, todos aquellos nodos que sean inicio de algún ciclo tendrán un contador de causas mayor a 1, esto es porque la recursión llegó al menos 2 veces a ellos, una cuando lo encuentra y dos cuando se forma el ciclo. Si pertenecen a más de un ciclo tendrán un contador de causas incluso mayor.

La propagación de la _falla_ se hace sólo la primera vez que cada reactor se vuelve inestable, no tiene sentido hacerlo más de una vez ya que sus conexiones no cambian.

Si tienes un grafo con un ciclo 1 -> 2 -> 3 -> 1 y en el mismo grafo otro ciclo 2 -> 3 -> 4 -> 2 al hacer la _simulación_ recursiva los nodos $1$ y $2$ quedarán con dos causas de inestabilidad cada uno.

Después de terminar la simulación se procede a reparar la _falla_ eliminando una causa de inestabilidad en el reactor inicial. La _estabilidad_ se propaga siempre que el reactor actual tenga cero causas de inestabilidad.

Si luego de reparar la falla existen reactores inestables con una causa de inestabilidad hay ciclos simples, si existen reactores con dos causas de inestabilidad o mas, existen ciclos compuestos.

Finalmente, el conteo de _hojas_ se puede hacer de nuevo con una DFS utilizando en número de causas de inestabilidad en un reactor para saber si pertenece a un ciclo o no.

Un posible código para resolver el problema es el siguiente:

```
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
    else if (causas[i] >= 2)
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
```
