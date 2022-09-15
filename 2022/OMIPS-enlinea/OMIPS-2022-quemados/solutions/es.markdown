# Solución oficial para Karel y los Quemados (OMIPS 2022)

Podemos colorear el mapa como tablero de ajedrez. En la siguiente imagen, las
casillas con un zumbador representan un color y las casillas sin zumbador
representan otro color. Supongamos sin pérdida de generalidad que Karel empieza
siempre en una posición sin zumbador.

![Coloración](image.png)

Observemos que cada segundo, los niños que están en una posición con zumbador
se mueven a una posición sin zumbador y viceversa, los niños que están en una
posición sin zumbador se mueven a una posición con zumbador. De esta manera,
por cada dos segundos que transcurren, los niños que están en una posición con
zumbador se mueven a una posición con zumbador y los niños que están en una
posición sin zumbador se mueven a una posición sin zumbador. Puesto que Karel
elige únicamente a los niños que lleguen a él en los segundos
$2, 4, 6, 8, \ldots$, Karel podrá elegir solamente a los niños que empezaron en
una casilla sin zumbador.

Por lo tanto, el problema consiste en contar cuantos niños se encuentran en una
casilla con el mismo color que la casilla de Karel, o lo que es equivalente,
contar cuantos niños se encuentran a una cantidad par de pasos desde la
posición en donde inicia Karel. Recordemos que para algunas subtareas, el
máximo número de llamadas a `avanza / move` es $2 \times A$, donde $A$ es el
número de casillas en el mundo, lo cual implica que debemos evitar pasar más
de dos veces por una misma casilla. Una manera de recorrer todas las casillas
con esta restricción y terminar en la casilla $(1, 1)$ es la siguiente

![Caso de ejemplo](sample.png)

En la misma imagen se marca las casillas a las que puede llegar Karel dando una cantidad par de pasos. Karel únicamente contará cuantos zumbadores hay en esas posiciones.

El siguiente código es la solución oficial

{{solution.kj}}
