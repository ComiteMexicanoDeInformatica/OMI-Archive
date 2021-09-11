Marco acaba de descubrir la secuencia de Fibonacci. La secuencia de Fibonacci es una secuencia númerica muy famosa de los números $1, 1, 2, 3, 5, 8, 13, 21, 34, ...$. Al _i-ésimo_ término de la secuencia de Fibonacci se le llama $F_i$.

El siguiente número de la secuencia se obtiene sumando los dos anteriores, por ejemplo:

- $F_1 = 1$
- $F_2 = 1$
- $F_3 = F_1 + F_2 = 1 + 1 = 2$
- $F_4 = F_2 + F_3 = 1 + 2 = 3$
- ...

De modo que la secuencia está determinada por los dos primeros términos $F_1$ y $F_2$ y todos los demás se van calculando en base a esos dos.

Marco quiere inventar su propia secuencia a la que llamará _secuencia de Marconacci_ y se pregunta que pasaría si usa la misma construcción pero con $F_1$ y $F_2$ distintos, por ejemplo, si $F_1 = 3$ y $F_2 = 4$, en ese caso la secuencia sería: $3, 4, 7, 11, 18, 29, ...$.

Ayuda a Marco a experimentar con diferentes valores iniciales para que pueda elegir la _secuencia de Marconacci_ ideal. Marco te hará $P$ preguntas, en cada pregunta te dará los dos valores iniciales $A$ y $B$ de la secuencia y te pedirá que calcules el valor del término $i$.

# Problema

Escribe un programa que sea capaz de contestar las preguntas de Marco.

**NOTA: ** Debido a que los valores en la _secuencia de Marconacci_ pueden ser **muy** grandes deberás expresar el resultado módulo $10^9 + 7$. Recuerda que para sacar el módulo en C/C++ se usa el operador `%` y que para manipular números de ese rango lo recomendable es utilizar variables de tipo `long long`.

# Entrada

- La primera línea tiene el número $P$, la cantidad de preguntas que te hará Marco.
- Las siguientes $P$ líneas contienen tres números $A$, $B$ e $i$ que representan el primer y segundo número de la secuencia respectivamente y el término del que se desea conocer el valor.

# Salida

- Debes escribir $P$ líneas, una por cada pregunta. La línea debe contener un entero que representa el valor del término solicitado módulo $10^9 + 7$.

# Ejemplo

||input
5
1 1 9
3 4 1
5 10 2
3 4 6
7 3 7585
||output
34
3
10
29
814888492
||description
La primera pregunta usa los valores iniciales de la secuencia de Fibonacci. El 9no término de Fibonacci es 34.

La segunda pregunta pide el primer término de la secuencia, el resultado es $3$.

La tercera pregunta pide al segundo término de la secuencia, el resultado el $10$.

La cuarta pregunta usa los valores de ejemplo de la descripción, el sexto término de la serie es $29$.

La quinta pregunta te permitirá ver si estás haciendo un correcto manejo de el módulo y los tipos de variable.
||end

# Límites

- $0 \leq A, B \leq 10^6$
- $1 \leq P \leq 10^5$
- $1 \leq i \leq 10^6$

# Subtareas

- **(5 puntos)**: $i \leq 30$
- **(10 puntos)**: $P = 1$
- **(15 puntos)**: El valor de $A$ y $B$ es el mismo para todas las preguntas.
- **(30 puntos)**: $P, i \leq 1000$
- **(40 puntos)**: Sin restricciones adicionales
