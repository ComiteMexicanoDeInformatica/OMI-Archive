Tu profesor de física construyó un dispositivo para experimentar con lasers. Este dispositivo consta de una cuadrícula de $F$ filas por $C$ columnas que tiene $N$ espejos en algunas de sus casillas. Los espejos se encuentran colocados en diagonal de forma que cuando un laser choca con alguno se desvía 90° como se muestra en la siguiente figura:

Tu profesor repetirá el siguiente experimento $E$ veces, él pondrá un rayo laser en alguna casilla orientado hacia norte, sur, este u oeste y lo disparará. Tu profesor desea en cuantos espejos se reflejará el laser antes de salir del dispositivo o si se quedará dando vueltas en el mismo.

# Problema

Escribe un problema que dado el tamaño de la cuadrícula y las posiciones de los $N$ espejos pueda dar el resultado para los $E$ experimentos de tu profesor.

# Entrada

- En la primera línea tres números enteros $N$, $F$ y $C$, el número espejos, de filas y de columnas del dispositivo.
- En las siguientes $N$ líneas habrá un caracter que **\\** o **/** indicando la posición del espejo seguida de dos números $f_i$ y $c_i$ que indican la fila y la columna del i-ésimo espejo.
- Un entero $E$, la cantidad de experimentos que hará tu profesor.
- En las siguientes $E$ líneas habrá un caracter que indica la orientación cuyo valor es **N**, **E**, **S** u **O** y dos enteros $f_j$ y $c_j$ que indican la fila y la columna del laser en el j-ésimo experimento.

# Salida

- Deberás escribir $E$ líneas, una por cada experimento. En cada línea deberá haber un número que indique la cantidad de espejos en los que el laser rebotó antes de salir del dispositivo o $-1$ si el laser se queda rebotando por siempre.

# Ejemplo

||input
5 8 8
/ 4 2
\ 4 3
/ 4 6
/ 7 3
\ 7 6
4
N 2 2
E 4 4
S 8 3
O 6 8
||output
2
-1
1
0
||description
(Hay que poner una imagen que explique el ejemplo)
||end

# Límites

- $1 \leq N \leq 10^5$
- $1 \leq E \leq 10^5$
- $3 \leq F, C \leq 10^5$
- $1 \leq f_i, f_j \leq F$
- $1 \leq c_i, c_j \leq C$

# Subtareas

- **( puntos)**: $N \leq 500$, $F, C \leq 100$, $E = 1$
- **( puntos)**: $N \leq 500$, $F, C \leq 100$
- **( puntos)**: $N \leq 1000$, $F, C \leq 10^5$, $E = 1$
- **( puntos)**: $N \leq 1000$, $F, C \leq 10^5$
- **( puntos)**: $N \leq 10^5$, $F, C \leq 10^5$, $E = 1$
- **( puntos)**: $N \leq 10^5$, $F, C \leq 10^5$
