# Historia

Hace mucho tiempo, $N$ olímpicos de la OMI fueron de visita a la escuela de Matemágicos. Charly, el director de dicha escuela, decidió separar a los $N$ olímpicos en $M$ grupos, de tal manera que en cada grupo hubiera al menos una persona. Al hacer esto algo muy curioso sucedió: después de la visita a la escuela de Matemágicos, cada pareja de olímpicos que estuvo en el mismo grupo se volvieron amigos.

# Problema

Dados $N$ y $M$, el número de participantes y el número de grupos respectivamente, escribe un programa que encuentre el mínimo y el máximo número de parejas de amigos que se pudieron haber formado después de la visita a la escuela de Matemágicos.

# Entrada

La primera y única línea de entrada consta de dos enteros $N$ y $M$ representando el número de olímpicos y el número de equipos respectivamente.

# Salida

La única línea de salida debe contener dos enteros $k_{min}$ y $k_{max}$: el mínimo número posible de parejas de amigos, y el máximo número posible de parejas de amigos respectivamente.

# Ejemplo
||input
5 1
||output
10 10
||description
Hay 5 olímpicos y 1 grupo. Todos los olímpicos van en el mismo grupo. En un grupo de 5 pueden formarse 10 parejas de amigos, por lo tanto el mínimo número de parejas y el máximo número de parejas es 10.
||input
4 2
||output
2 3
||description
Hay 4 olímpicos y 2 grupos.  Una opción es crear 2 grupos con 2 olímpicos cada uno, en cuyo caso se forma una pareja de amigos por cada grupo para un total de 2 parejas.  La otra opción es dejar a 1 olímpico en el primer grupo y a 3 olímpicos en el segundo grupo.  En el primer grupo no se crea ninguna pareja y en el segundo se forman 3 parejas de amigos.  Estas son las únicas 2 opciones por lo que el mínimo de parejas que se puede formar es 2 y el máximo de parejas que se puede formar es 3.
||end

# Consideraciones

* $1 \leq N,M \leq 10^{9}$.
* Para un 60% de los casos $N, M \leq 2^{15}$.
