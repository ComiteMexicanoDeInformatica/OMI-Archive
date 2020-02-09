Karel, fanático de la Lucha Libre, va a asistir a la Arena Ciudad de México a la Triplemanía XXIII.

Este año la triple A organizó un torneo especial en el que participarán $n$ equipos, cada uno conformado por $m$ luchadores. Cada luchador pertenece a una cierta división. El torneo consiste de rondas consecutivas en donde cada equipo manda un representante al cuadrilátero para un combate de todos contra todos. Solo califican a la siguiente ronda los equipos que mandaron al luchador con la división más alta del combate. El torneo termina en cuanto solo haya un equipo participando y este equipo es el ganador.

# Problema

Tu tarea es ayudar a Karel a saber qué equipo resultará ganador del torneo.

El mundo consiste en un rectángulo de $n$ filas y $m$ columnas. La cantidad de zumbadores en la fila $i$ y columna $j$ representa la división del luchador que representará al equipo $i$ en la ronda $j$, si es que el equipo no ha sido eliminado antes de dicha ronda. En otras palabras, cada fila representa un equipo y cada columna representa una ronda.

Deberás situar a Karel en la casilla más a la izquierda de la fila que representa el equipo ganador.

# Ejemplo

### Entrada

![Ejemplo de entrada](entrada.png)

### Salida

![Ejemplo de salida](salida.png)

### Explicación

En la ronda 1 todos los luchadores pertenecen a la misma división y todos los equipos pasan a la ronda 2.

En la ronda 2, todos los luchadores son vencidos por el de división uno y únicamente califica el equipo 2. En ese momento, el equipo 2 es ganador del torneo.

# Consideraciones

* Karel inicia en la casilla (1,1) viendo al norte.
* Karel no tiene zumbadores en la mochila.
* La división de los luchadores va desde 1 hasta 99, siendo 1 la división más alta y 99 la más baja.
* Las únicas paredes son las que delimitan el mundo.
* El tamaño del mundo va desde 2x2 hasta 10x10.
* No importa la orientación final de Karel.
* No importan los zumbadores finales del mundo.
* Solo importa la posición final de Karel.
* Se te asegura que siempre habrá un solo equipo ganador.

# Subtareas

* En el 8% de los casos habrá exactamente 2 rondas.
* En el 9% de los casos habrá exactamente 3 rondas.
