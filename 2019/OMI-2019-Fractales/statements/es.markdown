Un nuevo villano ha surgido, el Dr. Alberthanos. El Dr. tiene en su poder el guantelete del infinito, y planea usarlo para eliminar una gran cantidad de la población del mundo T.R.E.S! 
El mundo T.R.E.S. puede ser visto como una cuadrícula de lados de tamaño $3^{16}$ donde en cada casilla habita un ciudadano. El Dr. Alberthanos que es un gran fánatico de los fractales desea que la manera en que se elimine a la población se pueda ver como un fractal. El Algoritmo que usará es el siguiente.

1. Se divide el cuadro en 9 cuadros iguales
2. El cuadro de en medio y el cuadro de inferior derecho quedan intactos, mientras que todos los habitantes de los demas cuadros son eliminados
3. Se repite este proceso en los 7 cuadros restantes, hasta que los cuadros tengan lados de tamaño $1$. 

# Problema

Dada una casilla $(X, Y)$ del mundo inicial, se quiere saber cuantos habitantes fueron eliminados en el rectangulo con esquina superior izquierda en la casilla $(1, 1)$ y con esquina inferior derecha en la casilla $(X, Y)$.

# Entrada

Una única linea con dos enteros, $X, Y$ respectivamente.

# Salida

Una única línea con un entero, representando cuantos habitantes fueron eliminados.

# Ejemplo

||input
3 3
||output
7
||description
En el rectangulo con esquinas 1,1 y 3,3, hay 7 habitantes eliminados:
111
101
110
||end

# Límites

* $1 \leq X, Y \leq 15000000$.

# Subtareas

* Subtarea 1 (13 puntos):
  * $X = Y$.
  * $X, Y$ es potencia de 3.
* Subtarea 2 (21 puntos):
  * $max(X, Y) \leq 1000$.
* Subtarea 3 (48 puntos):
  * $X, Y \leq 1000000$.
* Subtarea 4 (18 puntos):
  * No hay restricciones adicionales.
