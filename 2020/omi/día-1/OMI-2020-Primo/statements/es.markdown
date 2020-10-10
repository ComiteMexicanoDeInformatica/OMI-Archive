Tapia organizó una fiesta con todos sus primos. Para ubicarlos fácilmente, Tapia usó todos los números primos no mayores a $n$ y le asignó uno de ellos a cada uno de sus primos. A la hora de partir el pastel, les pidió que se formaran en orden ascendente, de acuerdo al valor de su primo asignado, y ahí fue cuando se dio cuenta que se le había perdido un primo.

Tapia necesita tu ayuda para encontrar el valor de su primo perdido.

# Problema

Escribe una función que determine cuál es el primo perdido.

# Implementación

Deberás implementar la función `int busca(int n)` que regrese un entero, el primo perdido. Todos los primos son menor o igual a $n$.

Para obtener más información, debes utilizar la función `int primo(int posicion)` que devolverá el valor del primo que está en la posición `posicion` de la fila. Recuerda que el primer lugar de la fila es el $0$.

En caso de que preguntes por una posición menor a $0$ o mayor al número de primos en la fila, la función devolverá $0$.

# Ejemplo

|| input
Función llamada
|| output
Valor devuelto
|| description
Descripción
|| input
busca(12)
|| output
`-`
|| description
Esta será la llamada inicial a tu procedimiento `busca`.
|| input
primo(0)
|| output
2
|| description
En la posición $0$ de la fila se encuentra el $2$, tal como se espera.
|| input
primo(1)
|| output
3
|| description
En la posición $1$ de la fila se encuentra el $3$, tal como se espera.
|| input
primo(-1)
|| output
0
|| description
La función devuelve 0, pues se preguntó por una posición menor a 0.
|| input
primo(2)
|| output
7
|| description
En la posición $2$ de la fila se encuentra el $7$ donde se esperaba el $5$. Con esto ya sabes que el $5$ es el primo perdido. Aquí tu función `busca(12)` debe regresar $5$ y terminar la ejecución.
|| end

# Evaluación

Definamos $p$ como la cantidad de primos hasta $n$.

Los puntos que obtengas en cada caso dependerán del número de veces que llames a la función `primo(posicion)`:

- 100% por $\log_{2} p$ o menos llamadas.
- 60% por $\sqrt{p}$ o menos llamadas.
- 30% por menos de $p$ llamadas.
- 5% por $p$ llamadas.
- 0% por más de $p$ llamadas o por regresar una respuesta incorrecta.

# Subtareas

- **(70% de los casos):**
  - $2 \leq n \leq 10^5$
- **(30% de los casos):**
  - $2 \leq n \leq 10^7$
  - El comportamiento del evaluador será adaptativo. Esto quiere decir que en estos casos de prueba, el evaluador no tiene un primo perdido definido incialmente. Las respuestas dadas por el evaluador dependen de las llamadas anteriores a `primo(posicion)`, pero se te asegura que con las respuestas a estas llamadas siempre podrás encontrar al primo perdido.

# Experimentación

{{libinteractive:download}}

El evaluador de prueba recibe el archivo `sample.in`, con el siguiente formato:
En la primera línea tres enteros $N$, $K$ y $P$. $N$ representa el límite de los valores, $K$ representa el número de primos de $1$ a $N$ y $P$ es el primo perdido.
La siguiente línea contiene $K - 1$ números, todos los primos entre $1$ y $N$, a excepción de $P$, ordenados en forma ascendiente.

Para el caso de ejemplo anterior, `sample.in` se vería de la siguiente manera:

```
12 5 5
2 3 7 11
```

Otro posible ejemplo es:

```
20 8 17
2 3 5 7 11 13 19
```

Este ejemplo lo puedes copiar en el `sample.in`

Durante la ejecución, el evaluador de prueba imprimirá algunos mensajes para ayudarte a depurar tu solución. Al finalizar la ejecución de tu función, el evaluador de prueba imprimirá la respuesta que dió tu función `busca()` y el porcentaje de puntos que recibiría el caso.
