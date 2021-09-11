## Obtención del mínimo (40 puntos)

Observa que los mensajes que salieron de una computadora infectada invariablemente infectarán a la computadora destino, sin embargo, para minimizar el número de computadoras infectadas lo deseable es que las _nuevas_ computadoras infectadas ya no infecten a nadie más.  Esto es posible si dichas computadoras envían todos sus mensajes previo a recibir el mensaje infectado.

No es necesario ordenar los mensajes explícitamente, basta saber que sería posible ordenarlos y considerar que la infección sólo se propaga de las infectadas originalmente a aquellas que reciben un mensaje directo de estas.

Un posible codigo para obtener 40 puntos es el siguiente:

```
int main()
{
    std::cin >> n >> m >> inf;
    rep(i, 1, inf){
        std::cin >> a;
        infectados[a] = 1;
    }

    minimo = maximo = inf;
    rep(i, 1, m){
        std::cin >> a >> b;
        if (infectados[a] == 1 && !infectados[b]){
            minimo++;
            infectados[b] = 2;
        }
    }

    std::cout << minimo << " " << minimo << nl;

    return 0;
}
```

## Obtención del máximo (60 puntos)

Para el máximo de computadoras se busca que cada mensaje que pueda infectar, lo haga. Esto es posible si el orden de los mensajes es tal que primero salgan aquellos mensajes que provengan de una computadora infectada.

La técnica anterior se conoce como búsqueda en amplitud y normalmente se implementa con una cola (queue).

Un posible código para obtener los 100 puntos es el siguiente:

```
lli n, m, inf, a, b, minimo, maximo, visitados[MAX_N], infectados[MAX_N];
std::vector<lli> hijos[MAX_N];
std::queue<lli> q;

int main() {
  std::cin >> n >> m >> inf;
  rep(i, 1, inf) {
    std::cin >> a;
    infectados[a] = 1;
  }

  minimo = maximo = inf;
  rep(i, 1, m) {
    std::cin >> a >> b;
    hijos[a].push_back(b);
    if (infectados[a] == 1 && infectados[b] == 0) {
      ++minimo;
      infectados[b] = 2;
      q.push(b);
    }
  }

  while (!q.empty()) {
    ++maximo;
    for (auto h : hijos[q.front()]) {
      if (infectados[h] == 0) {
        infectados[h] = 2;
        q.push(h);
      }
    }
    q.pop();
  }

  std::cout << minimo << " " << maximo << nl;

  return 0;
}
```

## Subtarea 1, la única computadora infectada es la computadora $1$ (40 puntos)

La subtarea 1 permite hacer una búsqueda en amplitud con un único origen, la computadora $1$, en vez de varios orígenes como el problema plantea.

## Subtarea 2, $N \leq 3$ (8 puntos)

La subtarea 2 tiene límites que permiten checar de forma manual todas las configuraciones.  En total puede haber $6$ mensajes distintos por lo que hay un total de $2^6 = 64$ posibles configuraciones de mensajes y un total de $2^3 = 8$ configuraciones posibles para las máquinas inicialmente infectadas.

## Subtarea 3, $M \leq 10$ (12 puntos)

En la subtarea 3 el número de mensajes es tal que permite simular todos los posibles ordenamientos y verificar el número de computadoras infectadas en cada caso.  Esta solución puede resolver también la subtarea 2.

Un posible código para obtener los puntos de esta subtarea es el siguiente:


```
int main()
{
    std::cin >> n >> m >> inf;
    rep(i, 1, inf){
        std::cin >> k;
        infectados[k] = 1;
    }

    rep(i, 1, m) std::cin >> a[i] >> b[i];

    rep(i, 0, m - 1) perm[i] = i + 1;
    minimo = n;
    maximo = 0;
    p = 2;
    do{
        tmp = inf;
        rep(i, 0, m - 1){
            orig = a[perm[i]];
            dest = b[perm[i]];
            if ((infectados[orig] == 1 || infectados[orig] == p) && infectados[dest] != 1 && infectados[dest] != p){
                tmp++;
                infectados[dest] = p;
            }
        }
        p++;
        minimo = std::min(minimo, tmp);
        maximo = std::max(maximo, tmp);
    }while(std::next_permutation(perm, perm + m));

    std::cout << minimo << " " << maximo << nl;

    return 0;
}
```

## Subtarea 4, $a_i < b_i$ (20 puntos).

Las condiciones de la subtarea 4 permiten obtener el máximo sin necesidad de implementar una búsqueda en amplitud. Ya que los mensajes van siempre de una computadora con número menor a una mayor, para cada computadora basta con saber si alguna de las computadoras que le enviaron mensaje puede estar infectada.

Un posible código para obtener los puntos de esta subtarea es el siguiente:

```
int main() {
  std::cin >> n >> m >> inf;
  rep(i, 1, inf) {
    std::cin >> a;
    infectados[a] = 1;
  }

  minimo = inf;
  rep(i, 1, m) {
    std::cin >> a >> b;
    mensajes[b].push_back(a);
    if (infectados[a] == 1 && !infectados[b]){
        infectados[b] = 2;
        minimo++;
    }
  }

  maximo = minimo;
  rep(i, 1, n){
      if (infectados[i]) continue;
      for (auto origen : mensajes[i]){
        if (infectados[origen]){
            infectados[i] = 2;
            maximo++;
            break;
        }
      }
  }

  std::cout << minimo << " " << maximo << nl;

  return 0;
}
```
