Para llegar a la solución de 100 puntos hay que partir de la idea de fuerza bruta.
Este es simular pegarle a cada topo en el segundo 1 y hacer todos los posibles movimientos. 

Esta idea es fácil de implementar con una función recursiva.

El problema con esto es que la complejidad en tiempo es $O(N \cdot M \cdot 9^T)$.

La transición de esta idea a la óptima utilizando programación dinámica es hacer la función memorizada (top-down).

El estado de la DP es `fila`,`columna` y `tiempo`, que guardará lo siguiente:

***Si golpeo el topo en la casilla `[fila][columna]` cuando han transcurrido `tiempo` segundos, ¿Cuál es la mayor cantidad de puntos que puedo obtener?***

Debido a esto se debe ocupar una matriz de tres dimensiones, `DP[N][M][T]`, para almacenar las respuestas y no volver a calcularlas.

Por lo tanto la respuesta será: $\max( DP[fila][columna][1] )$ de entre todas las filas y columnas.

Esta sencilla modificación baja la complejidad del tiempo a $O(9 \cdot N \cdot M \cdot T)$ con $O(N \cdot M \cdot T)$ de memoria.
