Para la solución de 56 puntos, podemos probar todos los rangos posibles (1,2),(1,3)....(1,N),(2,3),(2,4)....(2,N).

Esta solución tiene una complejidad $O(N^2)$. Como $N$ es igual a $10^3$, esto resultaría en $10^6$ operaciones.

Para los 100 puntos, esta solución no entraría en tiempo. Con una observación nos podemos dar cuenta que solo
tenemos que recorrer el arreglo una sola vez. Al ser consecutivos los rangos, solo nos importa si el número actual
es estrictamnete menor al anterior. Podemos llevar un contador de cuántas veces va cumpliendose esa condición,
y al encontrar un número que no sea estrictamente menor al anterior detener el contador y ver si es la secuencia más grande.
