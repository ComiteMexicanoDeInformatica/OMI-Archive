El Papalote Museo del Niño de la Ciudad de México tiene una gran cantidad de juegos. Sin embargo,
uno en particular captó tu atención por su dificultad.

El juego consiste en un tablero de $N$ filas y $M$ columnas donde cada casilla tiene un número entero. Un movimiento en el juego es escoger una fila y cambiar el signo de cada número en esa fila. El otro posible movimiento consiste en escoger una columna y cambiar el signo de cada número en esa columna. El objetivo del juego es hacer que la suma de los números de cada columna y cada fila del tablero sea no negativa.

# Problema

Encuentra a qué columnas y qué filas del tablero debes cambiar el signo de sus números para que la suma de los números de cada renglón y cada fila sea no negativa.  

# Entrada

La primera línea contiene los enteros $N$ y $M$, separados por un espacio. Después $N$ líneas, cada una con $M$ números enteros separados por un espacio, representando el tablero del problema.

Las filas están enumeradas del $1$ al $N$ y las columnas del $1$ al $M$. 

# Salida

La primera línea contiene un entero $a$: el número de filas en donde se aplicó un movimiento. Después, un espacio y una lista de $a$ números que representan las filas donde se aplicó cada movimiento.

La segunda línea contiene un entero $b$: el número de columnas en donde se aplicó un movimiento. Después, un espacio y una lista de $b$ números que representan las columnas donde se aplicó cada movimiento.

Si hay varias soluciones, puedes imprimir cualquiera.

Debes asegurarte que $0 \leq a, b \leq NM$. Además, si alguna de las operaciones tiene un número inválido de fila o columna,
obtendrás 0 puntos en ese caso.

# Ejemplo

||input
4 1 
-1 
-1 
-1 
-1
||output
4 1 2 3 4 
0
||input
2 4 
-1 -1 -1 2 
1 1 1 1
||output
1 1 
1 4
||end

# Límites

* $1 \leq N,M \leq 100$
* Cada número en el tablero $t_{i,j}$ cumple que $|t_{i,j}| \leq 100$

# Subtareas

* En el 32% de los casos $1 \leq N,M \leq 10$.
* En el 68% restante no hay restricciones adicionales.
