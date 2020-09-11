# Historia

Mientras paseabas por el Mercadito Queretano durante la OMI 2017, te encontraste con Ulises, uno de los míticos matemágicos timadores. A pesar de ser mundialmente conocido por ser el más estafador, no pudiste contener la emoción y le pediste que te mostrara un truco de matemagia.

Ulises seleccionó un grupo de números sin que tú los vieras y los descompuso gritando "*Deffindo semibinarius*". 

Cada número $x$ lo descompuso en la forma $x = 1 + 2 + 4 + ... + 2^{k-1} + r$ , donde $k \geq 0, 0 \leq r < 2^k$. Como buen olímpico, te diste cuenta que cualquier entero positivo se puede descomponer de esta manera de forma única. Por ejemplo, si el matemágico seleccionó los números $12, 17, 7$ y $1$, sus descomposiciones serían:

<center>
$12 = 1 + 2 + 4 + 5$
</center>

<center>
$17 = 1 + 2 + 4 + 8 + 2$
</center>

<center>
$7 = 1 + 2 + 4$
</center>

<center>
$1 = 1$
</center>

Después, Ulises gritó el hechizo "*Exposimise Ordenadus*" y juntó todas las descomposiciones de sus números en una lista ordenada. Por ejemplo, los números $12,17,7$ y $1$ generarían la lista $1,1,1,1,2,2,2,2,4,4,4,5,8$.

Todo se veía impresionante hasta que notaste que te robó tu cartera mientras gritaba los hechizos. Para devolverte la cartera, te pide que le digas la cantidad de números que seleccionó originalmente.

Gracias a todo tu entrenamiento detectaste otra estafa: puede existir más de una solución. Para recuperar tu cartera, debes decirle al matemágico timador todas las opciones posibles.

# Problema

Escribe un programa que te ayude a encontrar todas las posibles cantidades de números que seleccionó el matemágico originalmente y las escriba de forma ordenada creciente.

# Entrada

La primera línea contiene el entero $n$, la cantidad de números que tiene la lista final.

La siguiente línea tiene los $n$ enteros ordenados de la lista que te da el matemágico. 

# Salida

Imprime en una línea, ordenados de forma creciente, todos los posibles tamaños de la lista original de números. Si hubiera dos posibles listas con el mismo tamaño, debes escribir dicho tamaño solo una vez. Por ejemplo si hay dos listas posibles distintas, ambas de tamaño 2, tu salida debe contener el 2 solo una vez.

Si no existe una solución, imprime -1.

# Ejemplo

||input
8
1 1 2 2 3 4 5 8
||output
2
||description
En este caso, la única secuencia posible de números es de tamaño 2, es decir, la lista de números original fue $[6,20]$
||input
6
1 1 1 2 2 2
||output
2 3
||description
En este caso, las posibles listas originales son $[4, 5]$ y  $[3, 3, 3]$, por lo tanto la respuesta es 2 y 3, los tamaños posibles de las listas.
||input
5
1 2 4 4 4
||output
-1
||description
Te intentaron estafar pues no hay ninguna solución.
||end
# Consideraciones

* $1 \leq n \leq 10^5$
* Los elementos de la secuencia descompuesta serán mayor igual a 1 y menor igual a $10^{16}$
* Los elementos de la lista de entrada siempre estarán en orden creciente
