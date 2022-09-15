Karel estaba disfrutando del recreo cuando llegó su archienemigo Warel a retarlo a un partido de _quemados_. Si nunca has jugado _quemados_, es un juego entre dos equipos de personas en donde cada equipo intenta eliminar a los jugadores del equipo contrario lanzándoles pelotas. Las reglas de los _quemados_ no son importantes para resolver este problema.

Karel es muy popular y todos sus compañeros siempre quieren estar en su equipo, por lo que en este reto, Karel y Warel acordaron formar los equipos de la siguiente manera:

Karel y Warel están en la misma casilla patio (La casilla dónde inicia Karel). Cada segundo, de forma alternada, uno de ellos podrá elegir a un jugador. En el segundo $1$ puede elegir Warel, luego en el segundo $2$ puede elegir Karel, segundo $3$ Warel, $4$ Karel, etc. Sin embargo, hay una condición especial. Cuando les toque escoger, Karel y Warel **únicamente pueden escoger a un jugador si está en la misma casilla que ellos.** Es decir, si en el momento en que le toque escoger a alguno de los dos, no hay ningún niño en la casilla de Karel y Warel, quien le toque escoger no podrá escoger a nadie. **Karel y Warel nunca se mueven de su lugar inicial,** pero **los demás niños se mueven siempre.** Cada segundo un niño se mueve una casilla al norte, sur, este u oeste. Lo único que no puede hacer es quedarse parado. Si un niño llega a la casilla donde están Karel y Warel y no lo eligen, tiene que seguirse moviendo.

El mundo de Karel es un rectángulo sin paredes internas que representa el patio de la escuela. Los montones de zumbadores en el mundo representan niños en el patio. En una casilla puede haber más de un niño, en cuyo caso habrá más de un zumbador.

Como todos los niños quieren estar en el equipo de Karel, todos se moverán haciendo lo posible por que los elija Karel. Ayuda a Karel a saber cuál es el máximo número de jugadores que pueden estar en su equipo.

# Problema

Escribe un programa que dados los niños en cada lugar del patio calcule ¿cuál es el máximo de jugadores que podrán ser elegidos por Karel? y deje un montón de zumbadores con esa cantidad en la casilla (1, 1)

# Ejemplos

## Entrada

![Mundo de entrada](sample.in.png)

## Salida

![Mundo de salida](sample.out.png)

## Descripción

El máximo número de jugadores que podrán quedar en el equipo de Karel es 2.

- El jugador que está en la casilla (1, 1) puede moverse en el segundo 1 al norte y en el segundo 2 al este. Como llega a la posición de Karel en el segundo 2, Karel lo puede elegir.
- El jugador que está en la casilla (1, 3) puede moverse en el segundo 1 al norte, en el segundo 2 al norte, segundo 3 al oeste, 4 al sur. Como llega a la posición de Karel en el segundo 4, Karel lo puede elegir. **Nota que si hubiera llegado a la posición de Karel en el segundo 2, al mismo tiempo que el jugador en la (1, 1), Karel sólo habría podido elegir a uno de ellos.**

El jugador en la casilla (3, 2) no importa como se mueva, nunca va a poder llegar a la posición de Karel en un segundo en el que Karel lo pueda elegir.

# Consideraciones

- Karel empieza en alguna casilla del patio con cualquier orientación.
- Karel lleva infinitos zumbadores en la mochila.
- **No importa la posición ni la orientación final de Karel**.
- **Para obtener los puntos de este problema, Karel debe dejar un montón de zumbadores con el resultado en la casilla (1, 1).**
- **En algunos casos Karel tendrá límite en la cantidad de instrucciones avanza que puede ejecutar.**

# Subtareas

**Para todas las subtareas, considera que $A$ es el área del patio de la escuela, es decir, la multiplicación del número de filas por el número de columnas.**

- (10 puntos): Karel empieza en la (1, 1), el mundo de Karel tiene altura 1.
- (15 puntos): Karel empieza en la (1, 1), **no hay límite** de veces que puedes llamar `avanza / move` y a lo más hay un niño por cada casilla del patio.
- (15 puntos): Karel empieza en la (1, 1), **no hay límite** de veces que puedes llamar `avanza / move`, puede haber cualquier cantidad de niños en una misma casilla.
- (15 puntos): Karel empieza en la (1, 1), puedes llamar `avanza / move` a lo más $2 \times A$ veces y a lo más hay un niño por cada casilla del patio.
- (15 puntos): Karel empieza en la (1, 1), puedes llamar `avanza / move` a lo más $2 \times A$ veces y puede haber cualquier cantidad de niños en una misma casilla.
- (15 puntos): Karel inicia en cualquier posición, **no hay límite** de veces que puedes llamar `avanza / move`.
- (15 puntos): Karel inicia en cualquier posición, puedes llamar `avanza / move` a lo más $2 \times A$ veces.
