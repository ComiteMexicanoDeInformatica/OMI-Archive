# Primera sub-tarea

Una solución $O(n^3 m^3)$ funciona.

La idea se trata de probar con todos los pares de esquinas cuáles son soluciones válidas, y entre todas las soluciones válidas, tomar aquella que tenga el mayor valor.

Algo así como:
```cpp
    vector<int> mejor_solucion;
    int64_t suma_mejor_solucion = -1;
    for (int f1 = 0; f1 < N; ++f1) {
      for (int c1 = 0; c1 < M; ++c2) {
        for (int f2 = f1; f2 < N; ++f1) {
          for (int c2 = c2; c2 < M; ++c2) {
            if (EsTableroDeAjedrez(f1, c1, f2, c2)) {
              int64_t suma = Sumar(f1, c1, f2, c2);
              if (suma > suma_mejor_solucion) {
                suma_mejor_solucion = suma;
        	mejor_solucion = {f1, c1, f2, c2};
              }
            }
          }
        }
      }
    }
```

Para calcular la suma de lo que hay entre 2 casillas $(f_1, c_1)$ y $(f_2, c_2)$ basta con iterar sobre todos los elementos:

```cpp
    int64_t Sumar(int f1, int c1, int f2, int c2) {
      int64_t suma = 0;
      for (int f = f1; f <= f2; ++f) {
        for (int c = c1; c <= c2; ++c) {
          suma += Precio[f][c];
        }
      }
      return suma;
    }
```

Para saber si una región de la cuadrícula está pintada como tablero de ajedrez, basta con verificar que no hay 2 casillas del mismo color que compartan una arista.

Una forma de hacerlo podría ser, para cada casilla, checar sus casillas vecinas dentro de la región y asegurarse que las 4 tengan el color opuesto y si alguna no cumple, la región no está coloreada como tablero de ajedrez.

Sin embargo es suficiente con que cada casilla compare su color con su casilla de arriba y su casilla izquierda, cuando dichas casillas estén en la región (ya si una casilla $A$ está a la derecha de una casilla $B$, entonces la casilla $B$ está a la izquierda de la casilla $A$, análogamente para arriba/abajo)

```cpp
    bool EsTableroDeAjedrez(int f1, int c1, int f2, int c2) {
      for (int f = f1; f <= f2; ++f) {
        for (int c = c1; c <= c2; ++c) {
          if (f > f1 && Color[f][c] == Color[f - 1][c]) {
            return false;
          }
          if (c > c1 && Color[f][c] == Color[f][c - 1]) {
            return false;
          }          
      }
      return true;
    }
```

Esta solución es $O(n^3 m^3)$ porque la cantidad de parejas de casillas es $O(n^2 m^2)$ y por cada par de casillas hay que ejecutar dos funciones de $O(nm)$

# Segunda sub-tarea

Para esta subtarea una solución $O(n^3m^2)$ funciona.

Las funciones EsTableroDeAjedrez y Sumar introducidas en la subtarea anterior se pueden calcular mucho más rápido(en $O(n)$ en lugar de $O(nm)$) usando programación dinámica.

## Cómo calcular EsTableroDeAjedrez más rápido

Vamos a crear una tabla llamada LongitudAlternante, donde LongitudAlternante[f][c] se refiere a la longitud más grande de una región pintada como tablero de ajedrez tal que $f_1 = f_2 = f$ (es decir, altura de una sola fila) y $c_2 = c$.

Vemos que la longitud alternante en una casilla $(f, c)$ es 1 si su color es igual que el de la casilla a su izquierda y en otro caso es la longitud alternante de su casilla a la izquierda más 1(porque es como tomar la región que acaba en la casilla a su izquierda y agregarle otra casilla).

Esta tabla se puede calcular llamando a esta función luego de leer la entrada y antes de llamar a EsTableroDeAjedrez:

```cpp
    void CalculaLongitudAlternante() {
      for (int f = 0; f < N; f++) {
        LongitudAlternante[f][0] = 1;
        for (int c = 1; c < M; c++) {
          LongitudAlternante[f][c] = 1;
          if (Color[f][c] != Color[f][c-1]) {
            LongitudAlternante[f][c] = LongitudAlternante[f][c - 1] + 1;
          }
        }
      }
    }
```

Para que una región $(f_1, c_1, f_2, c_2)$ esté pintada como tablero de ajedrez, se requiere que la longitud alternante de cada fila sea mayor o igual que la longitud de la región(osea, mayor que $c_2 - c_1$).

Además, se requiere que la última columna también tenga colores alternantes (todas las filas tienen colores alternantes en su totalidad y una columna es alternante, entonces todas las demás columnas lo son).

De esta manera, ya se puede escribir una versión de EsTableroDeAjedrez que corra en $O(n)$:

```cpp
    bool EsTableroDeAjedrez(int f1, int c1, int f2, int c2) {
      int longitud_region = c2 - c1 + 1;
      for (int f = f1; f <= f2; ++f) {
        if (LongitudAlternante[f][c2] < longitud_region) {
          return false;
        }
        if (f > f1 && Color[f][c2] == Color[f - 1][c2]) {
          return false;
        }
      }
      return true;
    }
```

## Cómo calcular las sumas de regiones mas rápido

Análogamente, vamos a crear una tabla llamada SumaHorizontal, de manera que SumaHorizontal[f][c] = Precio[f][0] + Precio[f][1] + ... + Precio[f][c].

Aquí sólo hay que notar que SumaHorizontal[f][c + 1] = SumaHorizontal[f][c] + Precio[f][c]:

```cpp
    void CalculaSumaHorizontal() {
      for (int f = 0; f < N; f++) {
        SumaHorizontal[f][0] = Precio[f][0];
        for (int c = 1; c < M; c++) {
          SumaHorizontal[f][c] = SumaHorizontal[f][c - 1] + Precio[f][c];
        }
      }
    }
```

Ahora, para calcular la suma con esta tabla, se puede usar el principio de [inclusión-exclusión](https://es.wikipedia.org/wiki/Principio_de_inclusi%C3%B3n-exclusi%C3%B3n), es decir:

Precio[f][c1] + Precio[f][c1 + 1] + ... + Precio[f][c2] = SumaHorizontal[f][c2] - SumaHorizontal[f][c1 - 1].

... y repetir lo mismo para cada fila.

Esto permite sumar una región en $O(n)$

```cpp
    int64_t Sumar(int f1, int c1, int f2, int c2) {
      int64_t suma = 0;
      for (int f = f1; f <= f2; ++f) {
        suma += SumaHorizontal[f][c2];
        if (c1 > 0) {
          suma -= SumaHorizontal[f][c1];
        }
      }
      return suma;
    }
```

# Tercera sub-tarea

Hay varias formas de hacer esta sub-tarea, aquí se presenta una que a juicio propio es la más sencilla.

## Mejorar la forma de calcular las sumas

Primero calcular una tabla Suma donde Suma[i][k] es la suma de los precios de todas las casillas $(f, c)$ con $f \le i$ y $c \le k$.

Usando inclusión-exclusión se tiene que:

Suma[i][k] = Suma[i - 1][k] + Suma[i][k - 1] - Suma[i - 1][k - 1]

Nuevamente, con inclusión-exclusión se puede calcular la suma de una región entera:

$SumaRegion(f_1, c_1, f_2, c_2) = Suma[f_2][c_2] - Suma[f_2][c_2 - 1] - Suma[f_2 - 1][c_2] + Suma[f_2 - 1][c2 - 1]$

## Mejorar la forma de ver si una región es tablero de ajedrez

Para saber si una región es tablero de ajedrez, es posible calcular una tabla con un 1 en las casillas que sigan cierto patrón de tablero y un 0 en las casillas que no sigan ese patrón de tablero y otra tabla para el otro patrón de tablero de ajedrez.

Pudiendo sumar cuántos 1s hay dentro de cada región en cada tabla, se puede saber si una región está pintada como tablero de Ajedrez.

Una forma más sencilla es recordando que $(f_1, c_1, f_2, c_2)$ sólo puede ser tablero si $(f_1, c_1, f_2 - 1, c_2)$ lo es.

Así que es posible iterar con $f_2$ en el bucle interno principal y usar la LongitudAlternante calculada en la subtarea anterior para calcular cada iteración en $O(1)$.

```cpp
    vector<int> mejor_solucion;
    int64_t suma_mejor_solucion = -1;
    for (int c1 = 0; f1 < M; ++c1) {
      for (int c2 = c1; c2 < M; ++c2) {
        for (int f1 = 0; f1 < N; ++f1) {
          for (int f2 = f1; f2 < N; ++f2) {
            if (LongitudAlternante[f2][c2] < c2 - c1 + 1) {
              break;
            }
            if (f2 > f1 && Color[f2][c2] == Color[f2 - 1][c2]) {
              break;
            }
            int64_t suma = Sumar(f1, c1, f2, c2);
            if (suma > suma_mejor_solucion) {
              suma_mejor_solucion = suma;
              mejor_solucion = {f1, c1, f2, c2};
            }
          }
        }
      }
    }
```

# Cuarta sub-tarea

En el caso de que no haya números negativos en la matriz de precios, el problema se puede resolver observando que si se fijan las filas $f_1$ y $f_2$ y la columna $c_2$, entonces hay que tomar el mínimo valor posible de $c_1$ de manera que la región siga siendo tablero de ajedrez.

Eso se puede calcular como $c_1 = c_2 - b + 1$ donde $b$ es la longitud de la región, que está dada por:

$b = min_{i=f_1}^{f_2} ( LongitudAlternante[i][c_2] )$

Este valor de b se puede ir actualizando en $O(1)$ en cada iteración volviendo a cambiar el bucle principal:

```cpp
    vector<int> mejor_solucion;
    int64_t suma_mejor_solucion = -1;
    for (int c2 = 0; c2 < M; ++c2) {
      for (int f1 = 0; f1 < N; ++f1) {
        int b = LongitudAlternante[f1][c2];
        for (int f2 = f1; f2 < N; ++f2) {
          if (LongitudAlternante[f2][c2] < b) {
            b = LongitudAlternante[f2][c2];
          }
          if (f2 > f1 && Color[f2][c2] == Color[f2 - 1][c2]) {
            break;
          }
          int c1 = c2 - b + 1;
          int64_t suma = Sumar(f1, c1, f2, c2);
          if (suma > suma_mejor_solucion) {
            suma_mejor_solucion = suma;
            mejor_solucion = {f1, c1, f2, c2};
          }
        }
      }
    }
```

Aquí hay que hacer notar que para recibir todos los puntos de esta subtarea y además los de las subtareas anteriores, es necesario correr el código de la subtarea anterior cuando $N \le 70$ y correr el de esta subtarea en otro caso.

# Solución de todos los casos

La idea consiste en resolver el problema dados $f_1$ y $f_2$ en $O(m)$ y hacerlo para todos los pares de filas (dando como resultado una solución de $O(n^2 m)$).

Una vez fijados $f_1$ y $f_2$, vamos a definir $T(c_2)$ como el valor de $c_1$ para la región optima dados $f_1$, $f_2$ y $c_2$, es decir aquel tal que $(f_1, T(c_2), f_2, c_2)$ es un tablero de ajedrez y que además maximiza la suma.

Aquí hay que darse cuenta que si ya se conoce $(f_1, T(c_2), f_2, c_2)$ y se quiere calcular $T(c_2 + 1)$, puede pasar una de 3 cosas:

* La región $(f_1, c_2 + 1, f_2, c_2 + 1)$ no es alternante, así que no hay región a tomar en cuenta.

* La región $(f_1, c_2 + 1, f_2, c_2 + 1)$ es alternante, pero está coloreada con el mismo patrón que la columna a su izquierda $(f_1, c_2, f_2, c_2)$, por lo que $T(c_2 + 1) = c_2 + 1$ (la única región posible sería de una sola columna).

* La región $(f_1, c_2 + 1, f_2, c_2 + 1)$ es alternante y es del patrón opuesto que el de la columna a su izquierda  $(f_1, c_2, f_2, c_2)$. En ese caso $T(c_2 + 1)$ puede tener 2 valores(hay que considerar ambos): $T(c_2 + 1) = c_2 + 1$ (una sola columna) ó $T(c_2 + 1) = T(c_2)$ (el óptimo en la columna de la izquierda, añadiéndole la nueva columna).

Las sumas se pueden calcular en tiempo constante(como ya se mencionó en la tercera sub-tarea). Para saber si un segmento de columna tiene colores alternantes en $O(1)$, se puede usar un procedimiento análogo al usado en la segunda sub-tarea para las filas.
