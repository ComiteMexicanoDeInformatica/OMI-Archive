# Descripción

La avenida Paseo de la Reforma de la Ciudad de México es conocida por tener una gran cantidad de edificios altos. 

Podemos describir la avenida Paseo de la Reforma como una fila de $n$ edificios consecutivos con alturas $a=\\{ a_0,a_1,\ldots,a_{n-1} \\}$, es decir $a_i$ denota la altura en metros del edificio $i$.

Como parte de tu visita a la Ciudad de México, quieres tomar una foto de la avenida Paseo de la Reforma de tal forma que aparezcan una gran cantidad de edificios. Para esto, quieres encontrar la mayor cantidad de edificios contiguos que formen una escalera estrictamente descendente. Es decir, quieres encontrar la mayor $k$ tal que $a_i > a_{i+1} > ... > a_{i+k-1}$ para alguna $i$.




# Entrada

En la primera línea el entero $n$.
En la segunda línea, los $n$ enteros $a_i$ separados por un espacio.

# Salida

El entero $k$, es decir la mayor cantidad de edificios contiguos que sean estrictamente descendentes en su altura.

# Ejemplo

||input
5
3 8 5 2 2
||output
3
||description
Los edificios con altura 8, 5 y 2 forman la secuencia contigua estrictamente decreciente más grande. El último 2 no es parte de la secuencia ya que debe ser estrictamente decreciente.
||input
9
9 8 7 6 5 4 3 2 1
||output
9
||description
Todos los edificios forman una secuencia estrictamente decreciente. 
||end

# Límites

* $1 \leq n \leq 10^5$
* $0 \leq a_i \leq 2^{16}$

# Subtareas

* Para el 56% de los casos $1 \leq n \leq 1000.$