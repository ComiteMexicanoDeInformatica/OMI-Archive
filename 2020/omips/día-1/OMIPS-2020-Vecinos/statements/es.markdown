En el vecindario de Karel hay casas que están representadas por montones de 1 zumbador.

Una casa puede tener vecinos de la siguiente manera:

- Un vecino derecho es una casa que está en la misma fila pero en alguna columna a la derecha.
- Un vecino izquierdo es una casa que está en la misma fila pero en alguna columna a la izquierda.
- Un vecino superior es una casa que está en la misma columna pero en alguna fila hacia arriba.
- Un vecino inferior es una casa que está en la misma columna pero en alguna fila hacia abajo.

Un supervecino es una casa que tiene al menos un vecino de cada uno de los tipos (derecho, izquierdo, superior e inferior).

El alcalde quiere darle un reconocimiento a todos los supervecinos por ser buenos ciudadanos. Para eso necesita saber cuántos son y le ha pedido a Karel que le ayude con esta tarea.

# Problema

Ayuda a Karel a contar el número de supervecinos y dejar un montón de zumbadores con esa cantidad en la casilla $(1, 1)$.

# Ejemplo

## Entrada

![Ejemplo de Entrada](sample.in.png)

## Salida

![Ejemplo de Salida](sample.out.png)

- La casa en la posición $(2, 2)$ es un supervecino porque tiene vecinos en todas direcciones ($(1, 2)$, $(2, 1)$, $(4, 2)$, $(2, 3)$).
- La casa en la posición $(2, 3)$ es un supervecino porque tiene vecinos en todas direcciones ($(1, 3)$, $(2, 2)$, $(5, 3)$, $(2, 4)$).

# Consideraciones

- Karel empieza en casilla $(1, 1)$ orientado al norte
- Karel tiene infinitos zumbadores en la mochila
- No hay paredes internas en el mundo
- No importa la orientación ni la posición final de Karel
- Solo se evalúa la cantidad de zumbadores que Karel deja en la casilla $(1, 1)$.

## Subtareas

- **(42 puntos)**: no hay mas de 3 vecinos en cada columna y en cada fila.
- **(58 puntos)**: no hay consideraciones adicionales.
