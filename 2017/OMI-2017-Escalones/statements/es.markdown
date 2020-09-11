# Historia

Un pasatiempo de los matemágicos es hacer estadísticas y como una de tus pruebas de admisión deberás demostrar que eres capaz de manipular datos para lograr el objetivo que se te pida.

Los matemágicos te han dado una serie de datos que se utilizarán para hacer un gráfico, pero quitaron algunos de los valores. Además, te dieron una lista (no ordenada) de números que puedes utilizar para rellenar los datos faltantes.

En cualquier lugar donde falte un dato puedes utilizar cualquiera de los números de la lista.

# Problema

Rellena los valores faltantes en la serie con números de la lista de modo que la suma de las diferencias entre valores contiguos sea la mínima posible. En caso de que exista más de una solución, cualquiera de ellas será considerada como válida.

De cada diferencia tienes que sumar el valor absoluto.

# Entrada

En la primera línea habrá dos enteros, $n$ y $m$, el número de datos en la serie y el número de valores en la lista respectivamente. En la segunda línea habrá $n$ enteros $s_i$ que representan los valores de la serie (un valor 0 representa un hueco en la serie que deberás rellenar). En la tercera línea habrá $m$ enteros $v_i$ que representan la lista de números que puedes usar para rellenar (recuerda que esta lista no viene ordenada y puedes usar cada número tantas veces como quieras).

# Salida

En la primera línea deberás imprimir la menor suma posible de las diferencias. En la segunda línea deberás imprimir $n$ enteros representando la serie final. Si hay varias soluciones cualquiera de ellas que imprimas será considerada como válida.

# Ejemplo

||input
2 3
10 0
1 5 20
||output
5
10 5
||description
El segundo valor de la serie inicial es cero, por lo que debes rellenarlo con algún valor de los de la lista. En el ejemplo se llena con un 5 por lo que la suma de las diferencias es igual a $10 - 5 = 5$.
||input
3 4
8 0 5
2 6 12 7
||output
3
8 7 5
||description
La serie tiene un valor por rellenar, si se llena con 7, la suma de las diferencias queda como $(8-7) + (7-5) = 1 + 2 = 3$. En este problema utilizar un 6 para llenar el hueco también es una solución válida.
||end

# Consideraciones

* $1 \leq n, m, v_i \leq 1,000,000$
* $0 \leq s_i \leq 1,000,000$
* Los valores de la lista de números para rellenar no están ordenados.
* Para el 28% de los casos $1 \leq n, m \leq 1,000$
* Para el 70% de los casos $1 \leq n, m \leq 200,000$
