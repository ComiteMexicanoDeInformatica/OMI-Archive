# Vecinos - Solución

La solución esperada para este problema es la siguiente: vamos a sumar a cada casa el número de distintos tipos de vecinos que tiene. Es decir, un número entre 1 y 4.

Para esto, vamos a ver cómo hacer para sumar los vecinos inferiores. Como se aprecia en la figura de abajo, todos los zumbadores tienen un vecino inferior excepto si es la primera casa de abajo a arriba en la columna.

![Vecinos inferiores](inferiores.png)

Entonces, podemos para cada columna un recorrido de abajo a arriba. Nos saltamos al primer zumbador y a los demás de la columna le sumamos un zumbador.

Análogamente hacemos lo mismo para los vecinos superiores, izquierdos y derechos. Para los vecinos superiores los que no se les sumarían serían los primeros de cada columna de arriba a abajo. Para los derechos e izquierdos los que no se les sumarían serían los primeros de cada fila de izquierda a derecha y los primeros de cada fila de derecha a izquierda, respectivamente. Si programamos funciones que no dependan de la orientación podríamos reusar el mismo código que ocupamos para los inferiores.

Finalmente, basta con contar aquellas casillas que terminaron con 5 zumbadores (la casa inicial y los cuatro vecinos que se le sumaron en el proceso) y dejarlo en la $(1, 1)$.

[Aquí puedes encontrar un video explicando la solución.](https://www.youtube.com/watch?v=RIleigayBhg)
