A Karel le pidieron resolver un problema, pero estaba muy cansado y te pidió que lo resolvieras usando C++.

Karel tiene el arreglo $A$ con $N$ números, el $i$-ésimo de esos números tiene el valor $a_i$. Se dice que los valores del arreglo van _subiendo_ si al recorrerlos de izquierda a derecha cada nuevo valor va siendo mayor o igual que el anterior. De forma similar se dice que los valores del arreglo van _bajando_ si al recorrerlos de izquierda a derecha cada nuevo valor va siendo menor o igual que el anterior.

A Karel le van a hacer $Q$ preguntas, en cada pregunta le darán dos posiciones $L$ y $R$ con $1 \leq L < R \leq N$. Karel debe contar la cantidad de _cambios_ en el segmento que va desde $L$ hasta $R$ del arreglo. Un _cambio_ es cuando el arreglo cambia de ir _subiendo_ a ir _bajando_ o viceversa, de ir _bajando_ a ir _subiendo_.

Un segmento es _bueno_ si tiene **a lo más** un _cambio_. Para cada pregunta, Karel deberá contestar con un $1$ si el segmento es **bueno**, es decir, tiene **a lo más** un cambio o con un $0$ en caso de que tenga más de un _cambio_.

# Problema

Escribe un programa que dado el arreglo $A$ sea capaz de contestar las $Q$ preguntas determinando si el segmento es _bueno_ o no.

# Entrada

Tu programa deberá leer de la entrada estándar los siguiente datos:

- En la primera línea los números $N$ y $Q$. La cantidad de valores en el arreglo $A$ y la cantidad de preguntas que debe contestar Karel.
- En la siguiente línea habrá $N$ valores separados por espacio, el $i$-ésimo de ellos representa el valor $a_i$.
- En las últimas $Q$ líneas habrá dos números $L_j$ y $R_j$ que representan el rango de la $j$-ésima pregunta.

# Salida

Por cada pregunta tu programa deberá escribir a la salida estándar un número.

- Un valor $1$ representa que en el rango de la pregunta existe **a lo más** un _cambio_.
- Un valor $0$ representa que en el rango de la pregunta hay más de un _cambio_.

# Ejemplo

||input
10 4
5 6 7 7 4 2 1 1 3 5
1 10
1 4
1 5
5 10
||output
0
1
1
1
||description
En el segmento que comprende las posiciones de la $1$ a la $10$ existen dos cambios, primero el arreglo va _subiendo_ en la posición $5$ cambia a ir _bajando_ y posteriormente en la posición $9$ cambia de nuevo a ir _subiendo_. Por lo tanto el rango **no** es _bueno_.

En los otros tres segmentos el número de _cambios_ es de $1$ o $0$, por lo tanto son _buenos_.
||end

# Límites

- $1 \leq N, Q \leq 10^5$ La cantidad de números en el arreglo y la cantidad de preguntas.
- $0 \leq a_i \leq 10^6$
- $1 \leq L_j < R_j \leq N$ Los valores de la $j$-ésima pregunta.

# Subtareas

- (12 puntos): $L_j + 2 = R_j$. Los rangos de las preguntas siempre son de largo 3.
- (18 puntos): $1 \leq N, Q \leq 1000$.
- (30 puntos): Todos los valores $a_i$ del arreglo son distintos.
- (40 puntos): Sin restricciones adicionales.
