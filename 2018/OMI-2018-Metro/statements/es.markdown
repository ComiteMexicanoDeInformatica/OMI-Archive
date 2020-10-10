# Descripci�n

El metro de la Ciudad de M�xico es uno de los sistemas de metro m�s grandes del mundo. Desafortunadamente, el metro que acabas de abordar tiene una falla mec�nica con sus puertas.

El metro que abordaste tiene $P$ puertas, de ellas $D$ se encuentran defectuosas. Al momento de intentar cerrar una puerta defectuosa, autom�ticamente se se abren otro subconjunto definido de puertas
(que puede contener a la puerta que acabas de cerrar).

Para no perder tu oportunidad de transitar el famoso metro de la Ciudad de M�xico, ofreciste tus habilidades como programador para intentar resolver el problema.

Se te har�n $Q$ preguntas, cada una con una configuraci�n de puertas inicialmente abiertas. Debes responder para cada pregunta si es posible cerrar todas las puertas.

# Entrada

En la primera l�nea los enteros $P$, $D$ y $Q$.

Cada una de las siguientes $D$ l�neas iniciar� con dos enteros $X_i$ y $D_i$ donde $X_i$ indica el �ndice la puerta defectuosa y $D_i$ la cantidad de puertas que abre la puerta $X_i$ al cerrarla. En la misma l�nea seguir�n $D_i$ enteros que indican los �ndices de las puertas que se abrir�n al cerrar la puerta $X_i$.

Las siguientes $Q$ l�neas describen las preguntas. Cada una de las l�neas iniciar� con un entero $Q_i$ que indica la cantidad de puertas inicialmente abiertas. En la misma l�nea, seguir�n $Q_i$ enteros que indican los �ndices de las puertas inicialmente abiertas.

# Salida

Debes imprimir Q l�neas. La $i$-�sima l�nea tiene que ser el car�cter 'S' si es posible cerrar todas las puertas en la pregunta $i$ o el car�cter 'N' si no es posible.

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
y $Q = 2$ (se te har�n 2 preguntas).  
Al cerrar la puerta 2, se abrir� una puerta, que es la n�mero 1.  
Al cerrar la puerta 1, se abrir� una puerta, que es la n�mero 2.  
En la primera pregunta, la puerta 3 est� abierta y las dem�s cerradas. Por lo tanto s�lo hay que cerrar la puerta 3, como esta no es defectuosa, ninguna otra se abrir� y todas las puertas pueden quedar cerradas (la respuesta a esa pregunta es `S`).  
En la segunda pregunta, se encuentran abiertas las puertas 1 y 2 y no es posible cerrar una sin que se abra la otra (la respuesta a esa pregunta es `N`).
||end

# L�mites

- $1 \leq P \leq 10^5$
- La suma de todos los $D_i$ no ser� mayor que $10^6$.
- La suma de todos los $Q_i$ no ser� mayor que $10^6$.
- El �ndice de las puertas siempre estar� entre $1$ y $P$ inclusive.

# Subtareas

- Para un 20% de los casos $1 \leq P,Q,D \leq 100$,
- Para un 20% de los casos $1 \leq P,Q,D \leq 2000$,
- Para un 10% de los casos $1 \leq Q,D \leq 1000$ y $1 \leq P \leq 10^5$.
- Para el 50% de los casos restantes no hay consideraciones adicionales.
