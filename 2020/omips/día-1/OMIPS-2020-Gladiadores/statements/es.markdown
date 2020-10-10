Karel volvió a la escuela y este año está tomando clases de historia. Está aprendiendo sobre las batallas que tenían los gladiadores del imperio Romano.

En una batalla, existen dos equipos de gladiadores que se enfrentan, el equipo del Este y el equipo del Oeste.
Cada gladiador está representado con un montón de zumbadores que indica su fuerza.
Cada equipo forma varias filas (todas del mismo número de gladiadores) y empieza la batalla en cada una de las filas. El gladiador del equipo Oeste que está más a la derecha se enfrenta con el gladiador del equipo Este que está más a la izquierda, como se muestra en la imagen.

![ejemplo batalla](batalla.png)

Un gladiador vence a otro y lo saca de combate cuando su fuerza es mayor a la del otro. Si un gladiador vence a su primer contrincante este pierde fuerza igual a la fuerza de su contrincante. Con la fuerza restante, el gladiador vencedor puede debilitar o vencer al siguiente gladiador de la fila del equipo contrario.

Cuando un gladiador se queda sin fuerza después de una batalla, sale del combate y el gladiador que está atrás de él en la fila entra a combate.

Karel vio dibujos de estas batallas y quiere que le ayudes a saber qué equipo ganaría cada batalla.

# Problema

En cada fila, entre cada equipo de gladiadores, hay 3 casillas vacías. Karel debe dejar en la casilla de en medio el resultado de la batalla de esa fila. Además, en la casilla $(1,1)$ debe dejar qué equipo fue el que ganó más batallas.

El resultado de una batalla es representado por montones de zumbadores:

- 1 zumbador: ganó el equipo del Oeste.
- 2 zumbadores: ganó el equipo del Este.
- 3 zumbadores: los equipos empataron.

# Ejemplo

## Entrada

![Ejemplo de Entrada](sample.in.png)

## Salida

![Ejemplo de Salida](sample.out.png)

- En la fila 2 gana el equipo Este.
- En la fila 3 hay un empate.
- En la fila 4 gana el equipo Este.

Al final ganó más batallas el equipo del Este por lo que Karel debe dejar 2 zumbador en la casilla $(1, 1)$

# Consideraciones

- Karel empieza en la casilla $(1,1)$ orientado al Norte.
- Karel no tiene zumbadores en la mochila.
- No hay paredes internas en el mundo.
- Las filas de gladiadores empiezan en la fila 2 y terminan al llegar a la pared al norte del mundo; no hay filas vacías.
- Todas las filas tienen la misma cantidad de gladiadores.
- Siempre hay 3 casillas vacías en el centro de la fila entre los dos equipos de gladiadores.
- No hay gladiadores con fuerza cero.
- En cada fila, la suma de las fuerzas de los gladiadores suma al menos 6.
- No importa la posición ni orientación final de Karel.
- Se evalúa la cantidad de zumbadores que Karel deja en la casilla $(1,1)$ y en la casilla vacía de en medio de cada fila.
- No hay zumbadores en la fila 1.
