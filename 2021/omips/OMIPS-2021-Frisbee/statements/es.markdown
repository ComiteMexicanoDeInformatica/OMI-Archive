Karel está jugando al frisbee-golf. En el frisbee-golf el jugador debe lanzar un frisbee y lograr que caiga en una posición exacta.

Cuando Karel lanza el frisbee lo hace con una fuerza $N$. Por cada unidad de fuerza que usa, el frisbee puede moverse una casilla al _NORTE_, una al _ESTE_ o una al _NORESTE_. La siguiente figura muestra los movimientos.

![Movimientos](movimientos.png)

Lee la explicación de los ejemplos, en particular la del segundo ejemplo, para que te sea más claro el movimiento.

Karel quiere saber con cuánta fuerza debe lanzar el frisbee para que llegue a la posición deseada.

El mundo de Karel es un rectángulo sin paredes internas que representa el campo de juego. La posición donde debe caer el frisbee está representada por un montón con $1$ zumbador y es el único zumbador en el mundo. Karel inicia en alguna posición del campo orientado al norte.

# Problema

Escribe un programa que le diga a Karel cuánta fuerza debe usar para llegar a la posición deseada y deje un montón de zumbadores con esa cantidad en la casilla $(1, 1)$.

# Ejemplo 1

![Entrada 1](entrada1.png)

En este mundo Karel necesitaría lanzar el frisbee con una fuerza de $5$ para llegar a la posición deseada, por lo que debe dejar un montón de $5$ zumbadores en la casilla $(1, 1)$

# Ejemplo 2

![Entrada 2](entrada2.png)

En este mundo Karel necesitaría lanzar el frisbee con una fuerza de $4$ para llegar a la posición deseada **necesita 3 movimientos al norte y 1 movimiento al noreste**. Karel no inicia en la posición $(1, 1)$, aun así, el resultado, $4$ zumbadores, debe quedar en la casilla $(1, 1)$

# Consideraciones

- Karel inicia alguna casilla del mundo orientado al norte.
- Karel tiene infinitos zumbadores en la mochila.
- Sólo habra $1$ zumbador en el mundo que representa el lugar a dónde se quiere lazar el frisbee.
- El zumbador nunca estará al sur o al oeste de la posición inicial de Karel.
- Karel nunca inicia sobre la posición a la que debe llegar el frisbee.
- Para la evaluación, sólo importan los zumbadores que dejes en la casilla $(1, 1)$.

# Evaluación

- **En casos de prueba con valor de 66 puntos:** Karel inicia en la casilla $(1, 1)$.
- **En casos de prueba con valor de 34 puntos:** Karel inicia una posición distinta de la casilla $(1, 1)$.
