# Historia

Roque el filósofo, el malvado archienemigo de los matemágicos, está preparando un misil para destruir el cuartel de la logia. Para evitarlo han colocado un rastreador en Roque para encontrar la ubicación secreta del misil.

Los matemágicos acaban de recibir la señal del rastreador con la ruta que Roque utilizó para llegar hasta él. La ruta está representada por una cadena de caracteres, cada caracter representa un paso a una casilla de la ruta y estos caracteres pueden ser:

* 'L' indicando que Roque se movió una casilla a la izquierda
* 'R' indicando que Roque se movió una casilla a la derecha
* 'U' indicando que Roque se movió una casilla hacia arriba
* 'D' indicando que Roque se movió una casilla hacia abajo

Los matemágicos podrán detener a tiempo el lanzamiento del misil si la ruta que Roque les dio es la más corta hasta él. En caso de que, utilizando solo casillas por las que Roque pasó, exista otra ruta al misil que llegue en menos pasos, no lo podrán detener.

Por ejemplo, en este caso, Roque utilizó la ruta más corta posible y lograrán detener el misil:

![S](si.png)

Pero en este otro caso existe una ruta al misil que utiliza solo casillas por las que Roque pasó pero llega en menos pasos, por lo tanto, los matemágicos no lograrán detenerlo:

![N](no.png)

# Problema

Tu trabajo es escribir un programa que dada la cadena de pasos que realizó Roque, escriba la letra *S* si la ruta era la ruta más corta posible o *N* si existía una ruta más corta.

# Entrada

En la primer línea se encuentra un entero $N$ que es el número de pasos que Roque utilizó.

En la segunda línea se encuentra una cadena de $N$ caracteres que describe los pasos de la ruta.

# Salida

Deberás escribir la letra mayúscula *S* si Roque utilizó la ruta más corta posible o la letra mayúscula *N* si existía una ruta más corta distinta a la que Roque tomó.

# Ejemplo

||input
8
ULLUURRR
||output
S
||description
Esta entrada corresponde a la primera figura de la descripción del problema.
||input
10
UUULLDDRRR
||output
N
||description
Esta entrada corresponde a la segunda figura de la descripción del problema.
||end

# Consideraciones

* $1 \leq N \leq 10^6$
* Para un 24% de los casos $1 \leq N \leq 1000$
* Para un 60% de los casos $1 \leq N \leq 20000$
