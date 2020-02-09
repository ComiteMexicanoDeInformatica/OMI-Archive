# Historia

Karel obtuvo el Guantelete del Infinito y lo usó para multiplicar sus montones de zumbadores. Karel tiene una columna inicial con montones de zumbadores que copió varias veces.

Karel tiene poca experiencia usando el Guantelete, así que comete errores cada vez que copia la columna. En cada copia los montones pueden cambiar de posición, y además uno de los montones puede cambiar de tamaño. Sin embargo, el montón que cambia siempre es el mismo.

Karel quiere mejorar sus habilidades para usar el Guantelete del Infinito, por lo que necesita saber la suma de los montones que no cambiaron de tamaño.

# Problema

Ayuda a Karel a averiguar cuál es la suma de los montones que permanecen sin cambio, y deja la suma en la casilla (1,1).

# Ejemplo

### Entrada

![Entrada1](sample.5x5.in.png)

### Salida

![Salida1](sample.5x5.out.png)

### Explicación:

Los montones de 1, 2, 3, y 4 zumbadores no cambian de tamaño. Estos montones suman 10 zumbadores, que debes dejar en la casilla (1,1).

# Consideraciones

* Karel inicia en la casilla (1,1) viendo al norte.
* Karel tiene infinitos zumbadores en la mochila.
* No hay zumbadores en la columna 1.
* El mundo siempre medirá 100x100.
* Ninguna casilla tendrá más de 99 zumbadores.
* No hay montones con 0 zumbadores.
* Las únicas paredes en el mundo son las que lo delimitan.
* Todas las columnas son de la misma altura.
* Todos los montones de una columna son diferentes.
* Hay al menos 3 columnas.
* Las columnas tendrán al menos 3 montones.
* El montón que cambia será diferente al menos una vez.
* No importa la posición ni orientación final de Karel.
* Sólo se evalúan los zumbadores en la casilla (1,1).
