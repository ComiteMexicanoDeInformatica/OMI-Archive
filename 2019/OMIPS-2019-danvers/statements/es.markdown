# Historia

Karel Danvers tiene la misión de clausurar los túneles de transporte que usan los Kree. 

Cada túnel está representado por una fila de zumbadores, los montones de zumbadores en la fila representan el ancho del túnel en esa sección. Para poder usar un túnel, los Kree requieren que la diferencia de ancho entre la parte más delgada y más gruesa del túnel sea mayor o igual a $5$. Karel Danvers debe clausurar todos los túneles que cumplan con esa condición.

En el mundo habrá múltiples túneles, cada uno en una fila distinta iniciando en la fila 1. 

# Problema

Ayuda a Karel Danvers a determinar qué túneles pueden ser usados por los Kree y clausurarlos.  Para clausurar un túnel, Karel Danvers debe recoger todos los zumbadores de la fila que representa ese túnel.

**Los túneles que no pueden ser usados por los Kree, no deben ser clausurados**.

# Ejemplos

### Entrada

![Entrada1](sample.3x8.in.png)

### Salida

![Salida1](sample.3x8.out.png)

### Explicación

La sección más ancha del túnel en la fila 1, tiene ancho 7 y la más delgada tiene ancho 1. La diferencia entre la sección más ancha y la más delgada es 6, esto quiere decir que el túnel **SÍ** debe ser clausurado.

La sección más ancha del túnel en la fila 2, tiene ancho 8 y la más delgada, ancho 4. La diferencia entre ambas es 4, esto quiere decir que el túnel **NO** debe ser clausurado.

# Consideraciones

* Karel inicia en la casilla 1,1 viendo al norte.
* Karel tiene 0 zumbadores en la mochila.
* Las únicas paredes en el mundo son las que lo delimitan.
* El mundo siempre medirá 100x100.
* No importa la posición ni orientación final de Karel.
* Debes **recoger todos** los zumbadores de los **túneles que pueden ser usados** por los Kree.
* Debes **dejar sin modificar** los zumbadores de los **túneles que no pueden** ser usados por los Kree.
* El ancho de cualquier sección de los túneles siempre es mayor a 0, es decir, si llegas a una posición sin zumbadores es el final del túnel.
* Cada túnel está en una fila iniciando en la fila 1. No hay filas en blanco entre los túneles.
* El largo de un túnel puede ser entre 2 y 100.
* Los túneles pueden ser de diferente largo.
* Todos los túneles inician en la columna 1.
