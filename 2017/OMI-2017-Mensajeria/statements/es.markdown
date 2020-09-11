# Descripción

Andrea, la matemágica alfa, administra toda la mensajería ultra secreta de la logia de los matemágicos. Como Andrea es muy buena en su trabajo, quiere minimizar el costo de enviar un mensaje a todos los cuarteles de la logia.

Andrea sabe que la logia tiene $N$ cuarteles ultra secretos en el estado de Querétaro y que están numerados de $0$ a $N-1$. También sabe que las rutas para enviar los mensajes van de cuartel a cuartel y funcionan de la siguiente manera:

 - El cuartel $0$ tiene una ruta de envío con el cuartel $1$.
 - El cuartel $1$ tiene una ruta de envío con el cuartel $2$.
 - Y así sucesivamente hasta el cuartel $N-1$ que tiene una ruta de mensajería con el cuartel $0$.

Las rutas de envío de un cuartel a otro tienen un costo ($a_i$) y funcionan en ambos sentidos, es decir, la ruta del cuartel $0$ al cuartel $1$ también funciona del cuartel $1$ al cuartel $0$ con el mismo costo.

Para minimizar los costos, Andrea puede poner centrales de envío en cualquier cuartel y enviar el mensaje desde todas las centrales disponibles al mismo tiempo.

Poner una central de envío tiene un costo $K$. 

Sin embargo, la ventaja de poner nuevas centrales de envío en otros cuarteles es que estos cuarteles ahora pueden enviar mensajes a los demás cuarteles sin ningún costo adicional más que el de las rutas usadas.

Para poder enviar el mensaje, Andrea siempre debe poner al menos la primer central de envío en alguno de los cuarteles.

# Problema

Ayuda a Andrea a minimizar el costo total de enviar un mensaje a todos los cuarteles de la logia.

# Entrada

En la primera línea se encuentran los enteros $N$ y $K$. En las siguientes $N$ líneas hay un entero $a_i$ representando el costo de la ruta de mensajería del cuartel $i$ al cuartel $i+1$.

# Salida

La suma que minimice el costo de enviar un mensaje, considerando el costo de poner las nuevas centrales de envío y el costo de todas las rutas usadas para enviar el mensaje a toda la logia.

# Ejemplo

||input
4 5
2
6
3
8
||output
15
||description
Andrea pone una central en el cuartel $1$ y en el cuartel $3$, cada una con costo $K$ (5 para este caso). Luego para enviar el mensaje al cuartel $0$, se toma la ruta desde el cuartel $1$ (con costo 2, recuerda que las rutas son bidireccionales y el costo de enviar de $0$ a $1$ es el mismo que de $1$ a $0$) y para el cuartel $2$ se toma la ruta desde el cuartel $3$ (con un costo 3), los cuarteles 1 y 3 reciben el mensaje sin costo por tener una central de envío. La suma total del costo es 15 = 5 + 5 + 3 + 3.
||input
2 3
2
5
||output
5
||description
Andrea pone una central en el cuartel $0$ y de éste se toma la ruta al cuartel $1$. El costo de poner una central en el cuartel $0$ es de 3. De ahí se envía al cuartel $1$ utilizando la ruta que va de $0$ a $1$ la cual tiene un costo 2. La suma del costo toal es 3 + 2 = 5.
||end

# Límites

* $2 \leq N \leq 1,000,000$
* $1 \leq a_i,K \leq 1,000$
* Para un 36% de los casos, $N \leq 1,000$
