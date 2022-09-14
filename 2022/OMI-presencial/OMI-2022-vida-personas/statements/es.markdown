Tu maestra te solicitó realizar un censo de las personas que han vivido en el territorio mexicano a lo largo de la historia, por suerte, te dio un listado de $N$ personas, cada una con su año de nacimiento $a_i$ y su año de fallecimiento $b_i$.

Tu maestra te dará una lista con $Q$ años, para cada año deberás responder:

- ¿Cuántas personas había vivas en ese año?
- ¿Cuántos años tenía la persona viva más jóven en ese año?
- ¿Cuántos años tenía la persona viva más anciana en ese año?

Para responder las preguntas debes considerar que las personas nacen al inicio del año $a_i$ y mueren al final del año $b_i$.

# Problema

Escribe un programa que reciba el listado de personas y conteste las preguntas de la maestra.

# Entrada

Tu programa debe leer de la entrada estándar:

- En la primera línea los números $N$ y $Q$, la cantidad de personas y la cantidad de preguntas de la maestra.
- En las siguientes $N$ líneas los enteros $a_i$ y $b_i$, la fecha de nacimiento y fallecimiento de la $i$-ésima persona.
- En las últimas $Q$ líneas el número $x_j$ que representa el año de la $j$-ésima pregunta.

# Salida

Tu programa deberá escribir a la salida estándar una línea por cada pregunta de la maestra con tres números, la cantidad de personas vivas en ese año, la edad de la persona viva más joven y la de la persona viva más anciana.

# Ejemplo

||input
6 6
2000 2012
2001 2042
1960 2000
1990 2040
1930 2010
1972 2037
1940
1980
1999
2000
2010
2050
||output
1 10 10
3 8 50
4 9 69
5 0 70
5 9 80
0 0 0
||description
Las personas vivas en cada año de interés de la maestra son:

- En 1940 estaban vivos los nacidos en [1930]
- En 1980 estaban vivos los nacidos en [1930, 1960, 1972]
- En 1999 estaban vivos los nacidos en [1930, 1960, 1972, 1990]
- En 2000 estaban vivos los nacidos en [1930, 1960, 1972, 1990, 2000]
- En 2010 estaban vivos los nacidos en [1930, 1972, 1990, 2000, 2001]
- En 2050 no había nadie vivo.
  ||end

# Límites

- $1 \leq N, Q \leq 10^5$ El número de personas y el número de preguntas.
- $1 \leq a_i, b_i \leq 10^9$ El año de nacimiento y fallecimiento de la $i$-ésima persona .

# Subtareas

- (5 puntos): $N, Q = 100$, $a_i = b_i$, $a_i, b_i \leq 100$.  Cada persona muere al final del año en el que nace.
- (10 puntos): $N, Q, a_i, b_i \leq 1000$.
- (23 puntos): $N \leq 1000$, $a_i, b_i \leq 50000$.
- (26 puntos): $a_i, b_i \leq 10^6$.
- (36 puntos): Sin restricciones adicionales.