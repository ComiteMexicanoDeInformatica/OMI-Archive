Karel está de vacaciones y cuenta con mucho tiempo libre, por lo que ha decidido leer uno de los libros de su vieja colección. Ayuda a Karel a encontrar el libro que quiere leer. 

# Problema

Determina el libro que Karel debe leer.

Los libros de Karel están representados por montones de 1 zumbador y todos se encuentran en la segunda fila del mundo. Además Karel ha numerado sus libros de uno en uno, de izquierda a derecha. El primer libro de izquierda a derecha es el libro 1, el siguiente es el libro 2, y así sucesivamente.

En la casilla (1,1) habrá un montón de zumbadores que representan el número del libro que Karel va a leer. Deberás apagar a Karel en el libro que corresponde al número que se encuentra en la casilla (1,1).

# Ejemplos

### Entrada

![Entrada](entrada.png)

### Salida

![Salida](salida.png)

#Explicación

Para este caso el número en la casilla (1,1) es 4, así que Karel debe apagarse en el cuarto libro.

# Consideraciones

* Karel inicia en la casilla (1,1) viendo al norte.
* Sólo habrá montones de zumbadores en la segunda fila y en la casilla (1,1).
* Los montones de zumbadores de la fila 2 siempre son de 1 zumbador.
* Las únicas paredes son las que delimitan el mundo.
* El montón de zumbadores en la casilla (1,1) será de 1 hasta 100 zumbadores.
* Nunca habrá menos libros de los que se indican en la casilla (1,1).
* Sólo se evaluará que la posición final de Karel sea correcta.

# Evaluación

* En el 57% de los casos Karel no tiene zumbadores en la mochila.
* En el 43% de los casos Karel tiene infinitos zumbadores en la mochila.
