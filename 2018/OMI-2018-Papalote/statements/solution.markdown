Notemos que cada que aplicamos una operación sobre alguna fila o columna, la suma aumenta al menos por 2.

Vemos que la mínima suma total de la matriz es $-100NM$, mientras que la máxima suma posible es $100NM$.
De este modo, sabemos que llegaremos a la suma máxima total en a lo más $100NM$ operaciones.
Esto ya que siempre la suma es creciente, y aumenta al menos por 2 por cada operación.

Por lo tanto, solo basta invertir los signos de cada fila y cada columna si la suma respectiva de cada fila o columna es menor a cero.
Y por lo anterior, sabemos que esto no nos va a tomar mas de $100NM$ operaciones, y cada inversión nos toma $O(n)$ operaciones. 
Para restaurar la respuesta, solo basta con imprimir las filas y columnas a las cuales les aplicamos una cantidad impar de operaciones.
