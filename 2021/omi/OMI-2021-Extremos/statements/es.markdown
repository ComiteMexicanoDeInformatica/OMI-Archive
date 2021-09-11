Existe un arreglo $A = [a_1, a_2, ... a_n]$ tal que $a_i \neq a_j$ para $i \neq j$. Debes encontrar la posición del menor y el mayor de ellos. Para hacerlo puedes invocar la función `esMenor(i, j)` que te devuelve verdadero si $a_i < a_j$ y falso si $a_i > a_j$.

# Problema

Encuentra la posición del mayor y menor número del arreglo invocando la menor cantidad de veces la función `esMenor(i, j)`.

# Implementación

Deberás implementar la función `void buscaExtremos(int n)`.

Para obtener información debes invocar la función `bool esMenor(int i, int j)` que devolverá `true` si el número en la posición $i$ es menor que el número en la posición $j$ y `false` en caso de que no lo sea. **Recuerda que los números van de la posición 1 a la $n$**.

Una vez que sepas la posición del mayor y menor número del arreglo deberás invocar la función `void respuesta(int posMenor, int posMayor)` a la que deberás pasarle como parámetros la posición de número menor y la posición del número mayor. **Sólo puedes invocar la función `respuesta` una vez**.

# Ejemplo

|| input
Función llamada
|| output
Valor devuelto
|| description
Descripción
|| input
buscaExtremos(3)
|| output
`-`
|| description
Esta será la llamada inicial a tu procedimiento `buscaExtremos`.
|| input
esMenor(1, 2)
|| output
false
|| description
El número en la posición $1$ es mayor que el número en la posición $2$.
|| input
esMenor(2, 3)
|| output
true
|| description
El número en la posición $2$ es menor que el número en la posición $3$ por lo tanto es el menor de todos.
|| input
esMenor(1, 3)
|| output
true
|| description
El número en la posición $1$ es menor que el número en la posición $3$ por lo tanto el número en la posición $3$ es el mayor de todos.
|| input
respuesta(2, 3)
|| output
`-`
|| description
Tras devolver el resultado usando la función respuesta tu programa debe terminar.
|| end

# Evaluación

Tu puntaje dependerá de la cantidad de veces que invoques la función `esMenor`. En algunas subtareas basta con que la cantidad de invocaciones sea menor que un límite para obtener los puntos. En la última subtarea tu puntaje dependerá de qué tanto te acerques al número de invocaciones de la solución oficial.

En cualquiera de los siguientes casos:

- Si al invocar la función `esMenor(i, j)` utilizas posiciones que están fuera del rango del arreglo, es decir, menores a $1$ o mayores a $n$,
- Si invocas la fución `respuesta(posMenor, posMayor)` más de una vez o
- Si excedes la cantidad máxima de invocaciones a `esMenor(i, j)` para esa subtarea.

obtendrás $0$ puntos.

#Limites

$1 \le N \le 500$

# Subtareas

- **(15 puntos)**: Obtienes _todos_ los puntos si invocas `esMenor` a lo más $n^2$ veces.
- **(30 puntos)**: Obtienes _todos_ los puntos si invocas `esMenor` a lo más $2n$ veces.
- **(55 puntos)**:
  - Si invocas `esMenor` $2n$ veces obtendrás $0$ puntos.
  - Si invocas `esMenor` a lo más el número de veces que lo hace la solución oficial obtendrás el $100%$ de los puntos.
  - Si invocas `esMenor` entre $2n$ y número de la solución oficial obtendrás una cantidad parcial de los puntos.

# Experimentación

{{libinteractive:download}}
