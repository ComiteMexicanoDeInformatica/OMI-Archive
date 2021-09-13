Probablemente hayas jugado _Among Us_. Si no lo has hecho, es un juego multi-jugador en el que el objetivo es descubrir al _impostor_ de entre el grupo de jugadores.

Los amigos de Karel están jugando _Among Us_ en el patio de la escuela. Uno de los amigos es _el impostor_ y la tarea de Karel es descubrirlo. Los amigos de Karel ya descubrieron quién es _el impostor_. Para ayudar a Karel, cada jugador, incluido _el impostor_, le dice a Karel a qué distancia se encuentra del _impostor_. Todos los jugadores dicen la verdad, salvo _el impostor_ que obviamente está mintiendo.

El patio es un mundo rectangular sin paredes internas en dónde los jugadores están representados como montones de zumbadores. En el montón que representa al jugador, la cantidad de zumbadores indica la distancia entre él y _el impostor_. La distancia se mide como la cantidad mínima de `avanza / move` que necesitaría el jugador para llegar desde su posición hasta la posición en la que se encuentra _el impostor_.

# Problema

Ayuda a Karel a determinar quién es _el impostor_ y a apagarse en la posición en la que se encuentra el montón que lo representa.

# Ejemplo

## Entrada

![Ejemplo de entrada](sample.in.png)

## Salida

![Ejemplo de salida](sample.out.png)

# Consideraciones

- Karel empieza en la casilla (1, 1) orientado al norte.
- Karel tiene infinitos zumbadores en la mochila.
- No hay paredes internas en el mundo.
- Habrá como mínimo $3$ amigos de Karel, _el impostor_ y al menos $2$ más.
- No hay más de un amigo en la misma posición.
- Todos los amigos de Karel, salvo _el impostor_ dicen la verdad.
- Para la evaluación, sólo importa la posición final de Karel.

# Subtareas

- **(24 puntos):** El mundo tiene alto $1$, _el impostor_ te dice una distancia a la que no hay ningún otro jugador y ninguna distancia, del _impostor_ o de los jugadores te saca del mundo.
- **(12 puntos):** El mundo tiene alto $1$.
- **(12 puntos):** No hay ningún jugador en la distancia reportada por _el impostor_.
- **(24 puntos):** Las distancias reportadas por los jugadores y por _el impostor_ nunca te llevan a una posición fuera del patio de la escuela.
- **(28 puntos):** Sin restricciones adicionales.
