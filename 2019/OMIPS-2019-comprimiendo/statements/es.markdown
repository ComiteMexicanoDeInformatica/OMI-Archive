# Historia

Ha llegado la temporada de cosechar zumbadores en la granja de Karel.

El mundo de Karel es un rectángulo con una cerca que divide la granja de zumbadores del granero. La cerca es una pared horizontal que cubre todo el ancho del mundo, menos la casilla de hasta la derecha que es la entrada. El granero siempre está en la parte norte y la granja en la parte sur.

También sabes que la granja siempre es 2 veces mas alta que el granero y tiene el mismo ancho.

Para que Karel pueda meter todos los beepers en el granero debe recoger dos montones y dejarlos juntos dentro del granero.

# Problema

Ayuda a Karel a mover los montones de zumbadores de la granja al granero, juntándolos en parejas y dejándolos dentro del granero en el mismo orden.

# Ejemplos

### Entrada

![Entrada1](sample.in.png)

### Salida

![Salida1](sample.out.png)

### Explicación
* Karel recoge los 4 zumbadores de las casillas (1, 1) y (1, 2) y deja 8 zumbadores en la casilla (1, 13).
* Hace lo mismo con los zumbadores de la casilla (1,3) y (1, 4) para dejarlos en la casilla (1, 14).
* Sigue haciendo el mismo proceso hasta que todos los zumbadores de la granja están dentro del granero.

# Consideraciones

* Karel inicia en la casilla (1,1) viendo al norte.
* Karel tiene infinitos zumbadores en la mochila.
* Las únicas paredes en el mundo son las que lo delimitan y la cerca que divide al granero de la granja. Siempre dejando la esquina derecha abierta.
* Todas las posiciones dentro de la granja tienen al menos 1 zumbador.
* Se evalúan todos los zumbadores del mundo

# Subtareas

* Para obtener el 65% de los puntos de este problema puedes usar la instrucción `avanza()` todas las veces que quieras
* Para el 35% restante, solo puedes usar la instruccion `avanza()` a lo más 2 veces por cada casilla en el mundo .
