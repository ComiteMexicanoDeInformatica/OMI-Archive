El COMI, Comité de Objetos Mal Implementados, construyó un jardín zen de $N$ filas por $M$ columnas formado por arena y piedras. Los miembros del COMI esperaban descansar allí, pero se dieron cuenta de que lo habían construido terriblemente.

Para que el jardín zen sea cómodo, cualquier área _conectada_ de arena debe ser un rectángulo sin piedras en medio. Dos casillas de arena se consideran _conectadas_ si comparten un lado.

Ahora te han solicitado, como experto constructor, que elimines la menor cantidad de piedras posible para lograr un jardín zen cómodo.

![Ejemplo_Simulacion](ejemplo_simulacion.gif)

En este ejemplo, las casillas amarillas son la arena y la grises son las piedras.

# Problema

Dado una matriz de $N \times M$, quita la menor cantidad de piedras para que el jardín zen sea cómodo e imprime cómo quedaría.

# Entrada

Tu programa deberá leer de la entrada estándar los siguientes datos:

- En la primera línea los enteros $N$ y $M$, la cantidad de filas y la cantidad de columnas del jardín zen respectivamente.
- En las siguientes $N$ líneas habrá una cadena con $M$ caractéres. Un '.' si la casilla es arena y '#' si en la casilla hay una piedra.

# Salida

Tu programa deberá escribir a la salida estándar una matriz de $N \times M$, cómo quedaría el jardín zen tras haber quitado la menor cantidad de piedras.

**Tu solución recibirá WA si hay una piedra donde antes no la había o si el jardín zen no es cómodo**.

# Ejemplo

||input

6 6
###...
#.#...
..#...
..#.##
..##.#
###..#

||output

###...
..#...
..#...
..#...
..#...
###...

||description

Es el caso de la descripción.

||end

# Límites

1<=N,M<=1000

# Subtareas

- **(13 puntos)**: $M = 2$
- **(26 puntos)**: La cantidad de áreas conectadas de arena será la misma en la entrada que en la solución.
- **(29 puntos)**: $1 \leq N, M \leq 100$.
- **(32 puntos)**: Sin restricciones adicionales.
