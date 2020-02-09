Después de usar el simulador de resistencia, Thanos siguió practicando su chasquido con más simuladores. En esta ocasión, Thanos probó con un simulador de áreas metropolitanas. A Thanos no le gustan las *áreas metropolitanas*, y si en algún momento él ve que existe un *área metropolitana*, chasqueará los dedos.

Un *área metropolitana* es una sección de terreno cuadrada de lado $K$ en la que hay más de $LIM$ personas al mismo tiempo. Para sus pruebas, Thanos define un valor para $K$.

El simulador tiene un mapa que es una cuadrícula de $N$ filas y $M$ columnas. En cada casilla hay un edificio con cierta población inicial. Además, el simulador tiene $Q$ planes de migración. Cada plan de migración está representado por 4 enteros $i$, $j$, $x$ y $t$. Si $x$ es positivo, este plan representa la llegada de $x$ personas al edificio que está en la casilla con fila $i$ y columna $j$ en el segundo $t$. Si $x$ es negativo, este plan representa la salida de $x$ personas del edificio que está en la casilla con fila $i$ y columna $j$ en el segundo $t$. Todas las personas que llegan o se van de la ciudad lo hacen de manera instantánea. 

# Problema

Ayuda a Thanos y dile cuál es el primer segundo en el que deberá chasquear, o hazle saber que nunca chasqueará.

# Entrada

En la primer línea cuatro enteros: $N$, $M$, $K$, $LIM$. Las dimensiones de la ciudad ($N$, $M$), las dimensiones de un *área metropolitana* ($K$), y el límite de gente que puede haber en cualquier área de tamaño $K \times K$ al mismo tiempo ($LIM$).

Las siguientes $N$ lineas contendrán $M$ enteros. Cada entero $A_{i,j}$ representa la población inicial del edificio en la posición $[i,j]$

La siguiente línea contiene un único entero $Q$ que representa el número de planes de migración en el simulador.

Cada una de las siguientes $Q$ líneas contendrá 4 enteros separados por un espacio $i$, $j$, $x$ y $t$ que representan la casilla del edificio $[i,j]$, el número de personas que llegan (si $x > 0$) o que se van (si $x < 0$) y el segundo en que sucedió $t$ respectivamente. Se asegura que en un plan de migración nunca se irá más gente de la que hay en el edificio.

# Salida

Un único número, que represente el primer segundo en el que Thanos chasqueará los dedos. Si Thanos nunca chasqueará, imprime `-1`.

# Ejemplo

||input
3 3 2 15
1 2 1
4 3 2
1 5 2
3
2 2 6 4
1 2 10 6
1 3 7 2
||output
4
||description 
Ver explicación de ejemplo abajo.
||input
2 2 1 2
1 2
3 4
1
1 1 10 1
||output
0
||description 
Desde el inicio, ya existe un área metropolitana, por lo que Thanos puede chasquear en el segundo 0.
||input
2 2 1 100
99 2
3 4
2
1 1 1 2
1 1 -1 2
||output
-1
||description
En el segundo 2, llega una persona al edificio $[1,1]$. Además, en este mismo segundo, se va una persona del mismo edificio. Los planes ocurren al mismo tiempo, como no hay más planes y nunca existió un *área metropolitana*, Thanos no chasqueará nunca.
||end

En el ejemplo 1, exísten 4 áreas de 2x2 en la ciudad. 

![Areas1](areas_1.png)

Las áreas tienen población total de 10,8,12 y 13 respectivamente. 

En el segundo 2, llegán 7 personas al edificio en la posición $[1,3]$. En este segundo. las áreas se verán así:

![Areas2](areas_2.png)

Las áreas tienen población total de 10, 15, 12 y 13 respectivamente. Como ninguna excede el límite de 15, en este segundo todavía no hay *áreas metropolitanas*.

Después, en el segundo 4, llegan 6 personas al edificio $[2,2]$, y la ciudad se verá así: 

![Areas3](areas_3.png)

Las áreas tienen población 16, 21, 18 y 19 respectivamente. Como ya existe al menos un *área metropolitana*, Thanos debe chasquear los dedos en este segundo.

Ten en cuenta que en todos los segundos siguientes, Thanos podría chasquear los dedos, pero tú debes decirle el primer segundo en el que los debe chasquear.

# Límites

* $1 \le K \le N, M \le 250$.
* $0 \le Q \le 2 \times 10^4$.
* $ 1 \le LIM \le 10^{15}$.
* $A_{i,j} \le 10^6$
* $t_i \le 10^6$.
* $-10^6 \le x_i \le 10^6$.

# Notas

**En las primeras 5 subtareas, sólo llegará gente a la ciudad, es decir, $x > 0$.** 
  * $1 \le x_i \le 10^6$.

Todas las subtareas tienen sus casos agrupados. 

# Subtareas

* Subtarea 1 (7 puntos):
  * $1 \le K \le N, M \le 50$.
  * $Q = 0$.
* Subtarea 2 (7 puntos):
  * $1 \le N, M \le 50$.
  * $K = 1$.
  * $0 \le Q \le 2 \times 10^4$.
* Subtarea 3 (15 puntos):
  * $1 \le N, M \le 250$.
  * $K = 3$.
  * $0 \le Q \le 2 \times 10^4$.
* Subtarea 4 (20 puntos):
  * $1 \le K \le N, M \le 250$.
  * $0 \le Q \le 250$.
* Subtarea 5 (23 puntos):
  * $1 \le K \le N, M \le 250$.
  * $0 \le Q \le 2 \times 10^4$.
* Subtarea 6 (28 puntos):
  * $1 \le K \le N, M \le 250$.
  * $0 \le Q \le 2 \times 10^4$.
  * $-10^6 \le x_i \le 10^6$.
  * **En esta subtarea es la única en la que se va gente.**
