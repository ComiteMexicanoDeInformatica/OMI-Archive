Tras pelear con los Avengers para conseguir las gemas del infinito, Thanos está agotado. Sin embargo, tiene una última tarea pendiente. Thanos tiene un arreglo de $N$ enteros que debe dejar *perfectamente balanceado*. Un arreglo de números está *perfectamente balanceado* si la diferencia entre un elemento y el siguiente siempre es la misma **para todos** los elementos del arreglo.

la diferencia entre cualquier elemento y el siguiente siempre debe ser constante

Para balancear el arreglo, Thanos sólo puede sumar o restar 1 a cada elemento. Cada vez que Thanos sume o reste un 1 a algún elemento se considera que hizo una *operación*. Solo se puede hacer una operacion por elemento.

# Problema

Thanos ofreció salvarte cuando elimine a la mitad de la población a cambio de tu ayuda. Imprime el menor número de *operaciones* que se necesitan para que el arreglo quede *perfectamente balanceado*, o `-1` si no es posible balancearlo.

# Entrada

En la primer línea el entero $N$. En la segunda línea $N$ enteros separados por un espacio que representan los números del arreglo.

# Salida

Un entero que indica el menor número de *operaciones* necesarias para que el arreglo quede *perfectamente balanceado*, o `-1` si no es posible balancearlo.

# Ejemplo

||input
2
500 500
||output
0
||description
El arreglo ya está *perfectamente balanceado* y no se requiere hacer ninguna *operación*.
||input
5
1 3 6 9 12
||output
1
||description
Si restas 1 al primer elemento para convertirlo en 0, el arreglo queda *perfectamente balanceado* y en total se realizó 1 *operación*.
||input
5
1 3 6 3 6
||output
-1
||description
No hay manera de poder balancer el arreglo
||end

# Límites

* $1 \leq N \leq 100000$.
* $1 \leq n_i \leq 10^9$.

# Subtareas

* Subtarea 1 (17 puntos):
  * Se asegura que siempre se puede balancear usando sólo la operación de suma.
* Subtarea 2 (21 puntos):
  * El primer elemento no necesita que le apliques ninguna operación.
* Subtarea 3 (62 puntos):
  * No hay consideraciones adicionales.
