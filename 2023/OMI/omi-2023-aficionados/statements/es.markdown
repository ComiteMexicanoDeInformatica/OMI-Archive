Mañana inicia la convención de aficionados al deporte que has estado organizando. Aficionados de todo el país acudirán a tu evento, por lo que debes asegurarte que no sucedan contratiempos.

Para ingresar a la convención, los aficionados deben formarse en una fila. Sabes que si varios aficionados del mismo equipo están cerca, pueden generar desorden. En específico, si en cualquier segmento contiguo de la fila, de al menos dos personas, la cantidad de aficionados de un equipo es mayor que el resto de aficionados en ese segmento, la fila se considera _inestable_.

Para evitar los conflictos, decidiste escribir un programa que dada la fila determine si es o no _inestable_ para que puedas corregirlo a tiempo.

# Problema

Escribe un programa que dada la fila de aficionados y el equipo favorito de cada uno determine si existe algún segmento de la fila que sea _inestable_. En caso de que la fila sea _inestable_ tu programa deberá escribir algún segmento de la misma donde exista inestabilidad. En caso contrario deberá escribir un $-1$ para indicar que la fila es estable.

# Entrada

Tu programa deberá leer de la entrada estándar los siguientes datos:

- En la primera línea el número $N$, la cantidad de aficionados en la fila.
- En la segunda línea $N$ números enteros separados por espacio, el $i$-ésimo de estos números representa el equipo favorito del aficionado en la posición $i$ de la fila.

# Salida

Tu programa deberá escribir a la salida estándar los siguientes datos:

- Si la fila **NO es _inestable_**, tu programa deberá escribir únicamente un $-1$.
- Si la fila es _inestable_, tu programa deberá escribir dos números $L$ y $R$ separados por un espacio que indican que el segmento que inicia en la posición $L$ y termina en la posición $R$ de la fila, es inestable.

En caso de que existan varios segmentos que son inestables, cualquiera de ellos que escribas se considera correcto.

# Ejemplo

||input
8
5 2 3 5 3 2 3 5
||output
3 7
||description
El segmento de la fila que inicia en la posición $3$ y termina en la posición $7$ es de aficionados que apoyan a los equipos $[3, 5, 3, 2, 3]$. En este segmento hay tres aficionados del equipo $3$ y sólo dos aficionados de otros equipos. Por lo tanto, ese segmento hace que la fila sea _inestable_.
||input
5
1 2 3 4 5
||output
-1
||description
Todos los aficionados de la fila apoyan a distintos equipos, por lo tanto la fila es estable.
||end

# Límites

- $2 \leq N \leq 2 \cdot 10^5$ El número de aficionados en la fila.
- $1 \leq a_i \leq 1000$ El equipo del $i$-ésimo aficionado.

# Subtareas

- (15 puntos): $N \leq 30$
- (20 puntos): $N \leq 500$
- (25 puntos): $N \leq 5000$, $a_i \leq 10$. Sólo hay 10 equipos distintos a los que apoyan los aficionados.
- (40 puntos): Sin restricciones adicionales
