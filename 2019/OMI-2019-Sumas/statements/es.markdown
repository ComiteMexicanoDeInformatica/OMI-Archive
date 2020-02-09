Cuando Star-Lord era miembro de los Ravangers, Yondu le encomendó la misión de recuperar una loza coloreada como tablero de ajedrez hecha de minerales caros, misma que se encontraba entre los restos de una nave que se estrelló.

Star-Lord recuperó la loza, pero desafortunadamente le tiró pintura encima y ya no tiene los colores originales.

La loza se puede representar como una cuadrícula con $N$ filas (numeradas de $0$ a $N - 1$ de arriba hacia abajo) y $M$ columnas (numeradas de $0$ a $M - 1$ de izquierda a derecha).

Cada casilla de la loza está pintada de un color que puede ser blanco o negro; además, cada casilla está hecha de un mineral distinto y por tanto tiene un valor diferente en el mercado negro, además es posible, para las casillas que se dañaron cuando se estrelló la nave, que el precio sea negativo.

Una cuadrícula está coloreada como un tablero de ajedrez si para toda casilla su color es distinto que el de sus casillas vecinas con las que comparte una arista; es decir, cada casilla puede tener a lo más 4 casillas vecinas.

En el mercado negro están de moda las lozas rectangulares coloreadas como tablero de ajedrez, así que nadie comprará una loza con un coloreado diferente o que no sea rectangular.

Por ejemplo, la siguiente cuadrícula está coloreada como un tablero de ajedrez:

![Cuadricula 1](grid1.png)

Esta segunda cuadrícula también está coloreada como tablero de ajedrez:

![Cuadricula 2](grid2.png)

Pero esta tercera cuadrícula **no** está coloreada como tablero de ajedrez:

![Cuadricula 3](grid3.png)

Dado que los Ravangers no son buenos artistas pero les gusta cortar cosas, no están dispuestos a pintar el tablero, pero están más que dispuestos a cortar un pedazo rectangular del mismo cuyos colores tengan el patrón de un tablero de ajedrez.

Como eso de encontrar soluciones óptimas tampoco se les da bien, han exigido tu cooperación para que cortes una sección de la loza original de manera que la sección cortada sea rectangular, esté coloreada como tablero de ajedrez y maximice su ganancia. La ganancia está dada por la suma de los valores de cada una de sus casillas.

El rectángulo que cortes puede ser de cualquier parte de la loza, incluso del centro. Y puede tener cualquier medida, incluso 1 x 1.

Este es un ejemplo de un corte válido

![Cuadricula 4](grid4.png)

Si hay mas de una solución que maximice su ganancia, cualquiera es igualmente aceptable.

# Entrada
En la primera línea 2 enteros: $N$, $M$ separados por un único espacio. El número de filas y columnas de la loza original.

En las siguientes $N$ lineas hay $M$ enteros, de manera que el $j$-ésimo entero de la $i$-ésima línea representa el valor de la casilla $(i - 1, j - 1)$.

En las siguientes $N$ lineas, $M$ enteros separados por espacios; representando los colores de cada casilla, un 0 ó 1 que representa el color blanco o negro respectivamente.

# Salida
Cuatro enteros separados por espacios $fil_1, col_1, fil_2$ y $col_2$, donde $(fil_1, col_1)$ es la casilla superior izquierda de la loza resultante y $(fil_2, col_2)$ es la casilla inferior derecha de la loza resultante.

# Ejemplo

||input
3 3
1 2 3
4 5 6
3 2 1
1 0 0
0 1 0
1 0 0
||output
0 0
2 1
||description
La mayor ganancia posible se obtiene al cortar la loza **rectangular** que contiene las casillas con valores 1, 2, 4, 5, 3 y 2.
||end

![Ejemplo](sample.png)

# Límites

* $1 \le N, M \le 300$.
* $0 \le | a_{i,j} | \le 10^9$.

## Subtareas

* Subtarea 1 (8 puntos):
  * $1 \le N \le 15$ y $0 \le | a_{i,j} | \le 10^6$.
* Subtarea 2 (10 puntos):
  * $1 \le N \le 30$ y $0 \le | a_{i,j} | \le 10^6$.
* Subtarea 3 (12 puntos):
  * $1 \le N \le 70$ .
* Subtarea 4 (15 puntos):
  * $1 \le a_{i,j} \le 10^9$ (No hay números negativos en la loza original).
* Subtarea 5 (23 puntos):
  * La loza original completa está coloreada tablero ajedrez.
* Subtarea 6 (32 puntos):
  * No hay consideraciones adicionales.
