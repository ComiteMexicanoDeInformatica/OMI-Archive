# Historia

Alexis y varios otros de sus amigos matemágicos se encuentran en la Convención Nacional de Matemáticas y Magia. Alexis, como quiere fomentar que sus amigos compartan su magia y conocimiento, se le han ocurrido algunas ideas para que todos convivan más.

Una de las ideas de Alexis es juntar al grupo más grande de amigos que se conozcan todos entre sí. Esto es, que cada persona del grupo sea amigo de todas y cada una de las otras personas en ese mismo grupo.

Esta es una tarea muy fácil para Alexis y las tareas fáciles no son cool, por lo que Alexis quiere añadir una restricción a esta idea. Para ello, lo que va a hacer Alexis es numerar del $0$ al $N-1$ a las $N$ personas de la convención. Después va a juntar al grupo más grande de amigos que se conozcan todos entre sí, de tal forma que en ese grupo de personas sus números sean consecutivos.

# Problema

Ayuda a Alexis a compartir la magia y el conocimiento juntando al grupo más grande de personas que cumplan con la restricción de su idea cool (recuerda que la restricción cool es que todos los miembros de un grupo además de ser amigos entre si, tengan números consecutivos).

# Entrada

En la primera línea los enteros $N$ y $M$, representando el número de asistentes a la convención y el número de amistades respectivamente. Cada una de las siguientes $M$ líneas tendrá dos enteros $a_i$ $b_i$ que indican que la persona $a_i$ es amiga de la persona $b_i$ y viceversa.

# Salida

Un entero representando el tamaño del grupo más grande de personas que cumplan con la restricción cool de Alexis.

# Ejemplo

||input
4 4
0 3
1 2
0 2
1 0
||output
3
||description
Las personas 0, 1 y 2 forman el grupo más grande de amigos que se conocen todos entre sí y que además son números consecutivos.
||input
2 1
0 1
||output
2
||description

||end

# Consideraciones
* $2\leq N \leq 1,000,000$
* $1\leq M \leq 200,000$
* Para un 20% de los casos, $1\leq N \leq 200$
* Para un 40% de los casos, $1\leq N \leq 1000$
* Para un 40% de los casos, $1\leq M \leq 1000$
* No hay personas que sean amigas de sí mismas
* No hay amistades repetidas
