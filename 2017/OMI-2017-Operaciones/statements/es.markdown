# Historia

Ethan el matemágico ha empezado a armar su nuevo truco de magia y matemáticas. Este nuevo truco hará que Ethan se convierta en el más famoso de entre todos los matemágicos del mundo. Tú como mejor amigo de Ethan, has decidido ayudarle para que su acto no tenga fallas y logre su fama.

El truco de Ethan consiste en agarrar un número y modificarlo varias veces con alguno de los siguientes actos:

 - Sumarle 1 al número que tiene.
 - Restarle 1 al número que tiene.
 - Dividir entre 2 siempre y cuando el número que tiene sea par.

El truco termina cuando el número que tiene sea 1.

# Problema

Tu tarea es ayudar a Ethan a ejecutar su truco en el mínimo número de actos para que el truco sea asombroso.

Para hacer el truco más asombroso, el número inicial está expresado en notación binaria.

# Entrada

En la primera linea el entero $N$ que representa la cantidad de bits (cifras) del número binario inicial.

En la segunda linea una cadena de longitud $N$ que contiene $0$s y $1$s (sin separación). Esta cadena representa el número inicial. El primer carácter es el bit más significativo.

# Salida

Un entero que indique la mínima cantidad de actos que tiene que hacer Ethan el matemágico para que el número original asombrosamente se convierta en 1.

# Ejemplo

||input
2
11
||output
2
||description
3->2->1
El número inicial (en notación decimal) es 3.
La primera operación es restarle 1, con lo que queda como 2.
La segunda operación es dividirlo entre 2, con lo que se obtiene un 1 y el acto ha terminado después de 2 pasos.
||input
4
1010
||output
4
||description
10->5->4->2->1
El número inicial en notación decimal es 10.
Se divide entre 2 para obtener 5, se le resta 1 para obtener 4, se divide entre 2 para obtener 2, se divide entre 2 para obtener 1. El acto ha terminado después de 4 pasos.
||end

# Consideraciones
* $2\leq N \leq 10^6$
* Para un 27% de los casos $2\leq N \leq 20$
