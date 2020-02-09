# Descripción

El metro de la Ciudad de México es uno de los sistemas de metro más grandes del mundo. Desafortunadamente, el metro que acabas  de abordar tiene una falla mecánica con sus puertas.

El metro que abordaste tiene $P$ puertas, de ellas $D$ se encuentran defectuosas. Al momento de intentar cerrar una puerta defectuosa, automáticamente se se abren otro subconjunto definido de puertas
(que puede contener a la puerta que acabas de cerrar).

Para no perder tu oportunidad de transitar el famoso metro de la Ciudad de México, ofreciste tus habilidades como programador para intentar resolver el problema.

Se te harán $Q$ preguntas, cada una con una configuración de puertas inicialmente abiertas. Debes responder para cada pregunta si es posible cerrar todas las puertas. 


# Entrada

En la primera línea los enteros $P$, $D$ y $Q$.

Cada una de las siguientes $D$ líneas iniciará con dos enteros $X_i$ y $D_i$ donde $X_i$ indica el índice la puerta defectuosa y $D_i$ la cantidad de puertas que abre la puerta $X_i$ al cerrarla. En la misma línea seguirán $D_i$ enteros que indican los índices de las puertas que se abrirán al cerrar la puerta $X_i$.

Las siguientes $Q$ líneas describen las preguntas. Cada una de las líneas iniciará con un entero $Q_i$ que indica la cantidad de puertas inicialmente abiertas. En la misma línea, seguirán $Q_i$ enteros que indican los índices de las puertas inicialmente abiertas. 

# Salida

Debes imprimir Q líneas. La $i$-ésima línea tiene que ser el carácter 'S' si es posible cerrar todas las puertas en la pregunta $i$ o el carácter 'N' si no es posible.

# Ejemplo

||input
3 2 2
2 1 1
1 1 2
1 3
2 1 2
||output
S
N
||description
En el ejemplo se tiene $P = 3$ (hay 3 puertas), $D = 2$ (2 puertas son defectuosas)
y $Q = 2$ (se te harán 2 preguntas).  
Al cerrar la puerta 2, se abrirá una puerta, que es la número 1.  
Al cerrar la puerta 1, se abrirá una puerta, que es la número 2.  
En la primera pregunta, la puerta 3 está abierta y las demás cerradas. Por lo tanto sólo hay que cerrar la puerta 3, como esta no es defectuosa, ninguna otra se abrirá y todas las puertas pueden quedar cerradas (la respuesta a esa pregunta es `S`).  
En la segunda pregunta, se encuentran abiertas las puertas 1 y 2 y no es posible cerrar una sin que se abra la otra (la respuesta a esa pregunta es `N`).
||end

# Límites

* $1 \leq P \leq 10^5$
* La suma de todos los $D_i$ no será mayor que $10^6$.
* La suma de todos los $Q_i$ no será mayor que $10^6$.
* El índice de las puertas siempre estará entre $1$ y $P$ inclusive.

# Subtareas

* Para un 20% de los casos $1 \leq P,Q,D \leq 100$,
* Para un 20% de los casos $1 \leq P,Q,D \leq 2000$,
* Para un 10% de los casos $1 \leq Q,D \leq 1000$ y $1 \leq P \leq 10^5$.
* Para el 50% de los casos restantes no hay consideraciones adicionales.
