En algún lugar del mundo dónde está Karel hay una casilla que es la entrada secreta al cuartel de los Avengers.

Nick Fury dejó pistas regadas por el mundo para ayudarte a encontrar dicha entrada secreta, pero también dejó algunas pistas falsas para desorientar a los enemigos.

En el mundo hay montones de zumbadores que representan las pistas. La cantidad de zumbadores en cada montón representa la columna de la siguiente pista la cuál estará siempre en la fila de arriba.

En la primera fila sólo hay una pista. Esta pista siempre es real. En las demás filas puede haber pistas falsas. La única forma de llegar al cuartel es siguiendo las pistas reales.

Cuando una pista te lleve a una casilla sin zumbadores habrás llegado al cuartel.

# Problema

Ayuda a Karel a seguir las pistas reales y haz que se apague en la entrada del cuartel.

# Ejemplos

### Entrada

![Entrada1](sample.in.png)

### Salida

![Salida1](sample.out.png)

### Explicación

* La primera pista en (fila 1, columna 2) te dice que la siguienta pista está en la columna 1 en la fila de arriba, fila 2.
* La segunda pista en (fila 2, columna 1) te dice que la siguiente pista está en la columna 3, fila de arriba.
* Como no hay zumbadores en la casila (fila 3, columna 3) es la entrada al cuartel y Karel se debe apagar.

# Consideraciones

* Karel empieza en la casilla (1, 1) viendo al norte.
* Karel no tiene zumbadores en la mochila.
* No hay paredes internas en el mundo.
* Solo hay un montón de zumbadores en la primera fila.
* Los montones de zumbadores en el mundo siempre son menores al ancho del mundo.
* **Sólo importa la posición final de Karel.**
