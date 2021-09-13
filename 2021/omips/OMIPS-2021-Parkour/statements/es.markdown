Karel está aprendiendo Parkour. En caso de que no conozcas esa actividad, el Parkour se trata de hacer un recorrido yendo de un _obstáculo_ a otro mediante saltos acrobáticos.

Karel está adecuando una pista para practicar parkour. La pista tiene _obstáculos_ en diferentes posiciones. Como Karel es novato, no puede saltar distancias mayores a $X$, eso significa que si dos _obstáculos_ de la pista se encuentran a más de $X$ de distancia, Karel tiene que agregar un nuevo _obstáculo_ entre ellos.

Karel empieza su recorrido en el primer _obstáculo_ de la pista y lo termina en el último.

Las posiciones de los _obstáculos_ de la pista se representan como una lista **ordenada** de montones de zumbadores en la primera fila del mundo. Un montón con $n$ zumbadores significa que hay un _obstáculo_ en la posición $n$ (por ejemplo, un montón con $5$ zumbadores significa que hay un _obstáculo_ en la posición $5$ de la pista).

El valor de $X$, el salto más largo que puede dar Karel, está representado por un montón de zumbadores en la primera columna de la segunda fila del mundo.

# Problema

Ayuda a Karel a saber ¿cuál es el número mínimo de _obstáculos_ que tiene que agregar? y dejar un montón de zumbadores con ese número en la casilla (1, 1) del mundo.

# Ejemplo

## Entrada

![Entrada 1](entrada1.png)

## Salida

![Salida 1](salida1.png)

Es necesario agregar $6$ _obstáculos_ una opción es ponerlos en las posiciones $[15, 35, 45, 50, 70, 76]$

**Observa que si en el ejemplo anterior el salto máximo fuera de $1$ el resultado sería $19 + 34 + 21 = 74$, es decir del $5$ al $25$ se requiere agregar $19$ obstáculos, no $20$, ya que el de la posición $25$ ya está puesto.**

# Consideraciones

- Karel empieza en la casilla (1, 1) orientado al norte.
- Karel tiene infinitos zumbadores en la mochila.
- El mundo de Karel es de $100$ por $100$.
- No hay paredes internas en el mundo.
- La lista de posiciones de _obstáculos_ está ordenada y los valores están entre $1$ y $99$.
- Siempre habrá al menos dos _obstáculos_.
- Todos los _obstáculos_ están en posiciones distintas.
- El valor de $X$, el salto más largo que puede dar Karel, está entre $1$ y $30$.
- Para la evaluación sólo importa la cantidad de zumbadores que dejes en la casilla (1, 1).

# Subtareas

- **(27 puntos):** $X = 1$
- **(14 puntos):** La distancia entre dos _obstáculos_ consecutivos en la pista original es menor o igual a $2 * X$
- **(39 puntos):** Sin restricciones adicionales
- **(20 puntos):** Karel puede avanzar a lo más $4N + 2$ donde $N$ es la cantidad original de _obstáculos_ en la pista.
