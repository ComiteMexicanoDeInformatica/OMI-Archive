A Karel se le ha ocurrido una forma muy sencilla para comparar números:

Dados dos enteros no negativos, Karel dice que el número más grande de los dos es aquel que tenga la mayor cantidad de bits encendidos en su representación binaria. Si ambos números tienen la misma cantidad de bits encendidos, entonces dice que son iguales.

Desafortunadamente esta estrategia no siempre funciona. Ayuda a Karel a saber cuántas veces va a fallar su método si se comparan dos números de $N$ bits, en donde un número tiene exactamente $K_a$ bits encendidos en su representación binaria, y otro tiene exactamente $K_b$ bits encendidos en su representación binaria.

# Problema

Escribe un programa que reciba tres enteros: $N$, $K_a$ y $K_b$, e imprima la cantidad de pares de números de $N$ bits con los que el método de Karel falla, dado que uno de los números tiene $K_a$ bits encendidos y el otro tiene $K_b$ bits encendidos.

En caso de que la respuesta sea muy grande debes imprimir la respuesta módulo $10^9 + 7$.

# Entrada

Una línea con 3 enteros separados por un espacio entre ellos: $N$, $K_a$ y $K_b$.

# Salida

La cantidad de pares de números con los que el método de Karel falla, módulo $10^9 + 7$.

# Ejemplo

||examplefile
sample
||description
Los números de dos bits de longitud con exactamente un bit prendido son `1` (`01` en binario) y `2` (`10` en binario).

Como $K_a = K_b$, la respuesta de Karel siempre será "iguales".

Los pares posibles son:

- `1` y `1` Sí son iguales

- `1` y `2` No son iguales

- `2` y `1` No son iguales

- `2` y `2` Sí son iguales

El método de Karel falla en 2 ocasiones, por lo que debes imprimir 2.

||examplefile
sample2
||description

Como $K_a > K_b$, la respuesta de Karel siempre será que el primer número es mayor.

Los pares posibles son:

- `7` y `3` La respuesta de Karel es correcta

- `7` y `5` La respuesta de Karel es correcta

- `7` y `6` La respuesta de Karel es correcta

El método de Karel nunca falla, por lo que debes imprimir 0.

||examplefile
sample3
||description
En este caso hay 9 pares posibles, en donde el único que falla con el método de Karel es `4` y `3`, pues el primer número es mayor, pero Karel responderá que el segundo es mayor, pues tiene más bits encendidos.
||examplefile
sample4
||end

# Límites

- $1 \leq N \leq 5000$
- $0 \leq K_a, K_b \leq N$

# Subtareas

- **(10 puntos):** $N \leq 5$
- **(15 puntos):** $N \leq 16$
- **(20 puntos):** $N \leq 200$ y $K_a = K_b$
- **(25 puntos):** $N \leq 200$
- **(30 puntos):** No hay restricciones adicionales.

# Consideraciones

Todos los casos de cada subtarea están agrupados.
