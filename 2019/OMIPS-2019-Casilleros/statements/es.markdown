# Historia

Karel Morales fue castigado en la escuela por faltar a una clase (estaba salvando a un cachorrito, pero eso es un
secreto) y su castigo es asegurarse de que al final de la tarde, las puertas de todos los casilleros estén cerradas.

Después de que todos salen de clases a medio día, todas los casilleros están cerrados. Desafortunadamente hay
muchos alumnos hiperactivos que se pasean por la escuela por la tarde y les gusta cambiar el estado de los
casilleros (es decir, si está cerrado lo abren y si está abierto lo cierran).

El pasillo con casilleros es un cuarto rectangular de largo $n$ y alto 1. En la primera casilla del pasillo
está la puerta de entrada, y las siguientes $n - 1$ casillas tienen un casillero cada una.

El primer alumno inquieto de la tarde siempre avanza una casilla, cambia un casillero, avanza otra casilla,
cambia otro casillero, y así sucesivamente hasta llegar al lado contrario.

El segundo alumno inquieto también recorre todo el pasillo pero de 2 en 2: avanza 2 casillas, cambia un casillero, avanza 2 casillas,
cambia otro casillero, y así sucesivamente hasta llegar al lado contrario.

El tercer alumno de 3 en 3, el cuarto de 4 en 4, y así hasta $n - 1$.

Karel dedujo que si al inicio de la tarde abre los casilleros que normalmente quedan abiertos al final, entonces
ese día al final de la tarde todos los casilleros estarán cerrados y no necesitará presentarse en caso de que
esté combatiendo el crimen.

# Problema

Karel Morales quiere saber qué casilleros quedan abiertos al final de un día normal.

Deberás indicar esos lugares colocando un zumbador en ellos, dejando el resto del mundo sin zumbadores.

# Ejemplos

### Entrada

![Entrada](entrada.png)

### Salida

![Salida](salida.png)

# Consideraciones

* Karel inicia en $(1, 1)$ orientado al norte
* Karel tiene $n$ zumbadores en la mochila.
* El mundo es un cuarto de una sola fila y $n$ columnas sin muros interiores.
* El valor de $n$ estará entre 1 y 5000
* Karel no puede avanzar más de 5000 veces.
* Para un conjunto de casos de prueba con valor de 50 puntos, el valor de $n$ será menor o igual que 50
