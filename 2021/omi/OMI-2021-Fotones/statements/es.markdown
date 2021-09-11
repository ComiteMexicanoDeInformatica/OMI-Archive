Tu profesor de física construyó un dispositivo para experimentar con lasers. Este dispositivo consta de una cuadrícula de $F$ filas por $C$ columnas que tiene $N$ espejos. Cada espejo ocupa exactamente una casilla y se encuentra colocado en diagonal de forma que cuando un láser choca con él se desvía 90° como se muestra en la siguiente figura:

![Figura1](figura1.png)

Tu profesor repetirá el siguiente experimento $E$ veces: él pondrá un rayo láser en alguna casilla orientado hacia norte, sur, este u oeste y lo disparará. Tu profesor desea saber en cuantos espejos se reflejará el láser antes de salir del dispositivo o si se quedará dando vueltas en el mismo.

# Problema

Escribe un problema que dado el tamaño de la cuadrícula y las posiciones de los $N$ espejos pueda dar el resultado para los $E$ experimentos de tu profesor.

# Entrada

- En la primera línea tres números enteros $N$, $F$ y $C$, el número espejos, de filas y de columnas del dispositivo.
- En las siguientes $N$ líneas habrá un caracter que **\\** o **/** indicando la posición del espejo seguida de dos números $f_i$ y $c_i$ que indican la fila y la columna del _i-ésimo_ espejo.
- Un entero $E$, la cantidad de experimentos que hará tu profesor.
- En las siguientes $E$ líneas habrá un caracter que indica la orientación cuyo valor es **N**, **E**, **S** u **O** y dos enteros $f_j$ y $c_j$ que indican la fila y la columna del laser en el _j-ésimo_ experimento.

Se te asegura que el láser nunca se coloca en la misma casilla que un espejo.

**Para este problema considera que la fila $1$ está al sur (abajo) y la fila $F$ está al norte (arriba). De igual forma la columna $1$ está al oeste (izquierda) y la columna $C$ está al este (derecha). Observa también que la posición del láser y los espejos están dadas primero la fila y luego la columna.**

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
La imagen de la descripción muestra el primer experimento del profesor y como rebota con dos espejos antes de salir del dispositivo.

![Ejemplo](ejemplo.png)

La imagen previa muestra el segundo experimento en el que el laser continúa rebotando por siempre dentro del dispositivo.

||end

# Límites

- $1 \leq N \leq 10^5$
- $1 \leq E \leq 10^5$
- $3 \leq F, C \leq 10^5$
- $1 \leq f_i, f_j \leq F$
- $1 \leq c_i, c_j \leq C$

# Subtareas

- **(9 puntos)**: $N \leq 500$, $F, C \leq 100$, $E = 1$
- **(10 puntos)**: $N \leq 500$, $F, C \leq 100$
- **(13 puntos)**: $N \leq 1000$, $F, C \leq 10^5$, $E = 1$
- **(20 puntos)**: $N \leq 1000$, $F, C \leq 10^5$
- **(18 puntos)**: $N \leq 10^5$, $F, C \leq 10^5$, $E = 1$
- **(30 puntos)**: $N \leq 10^5$, $F, C \leq 10^5$
