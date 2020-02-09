En los primeros 77 puntos no tenías que preocuparte por si había zumbadores que intervinieran en las casillas de la respuesta (las filas 1 y 2), 
por lo que podías recorrer el mundo y por cada vez que encontrabas un barco, usando parámetros y la pila recursiva, obtenías su fila (contando espacios hacía abajo)
y columna (contando espacios a su izquierda) correspondiente. Al final contabas el id del barco y colocabas la respuesta en la columna correspodiente 
y volvías a recorrer buscando otro barco si hubiera.

Saltar de esta idea a la de 100 puntos era fácil observando que en los últimos casos podían haber casillas que intervinieran al momento de colocar respuestas, 
entonces tienes que usar la pila recursiva guardando el id también. Así se puede recorrer todo el mundo guardando fila, columna y id del barco y al finalizar el
recorrido, el mundo queda sin zumbadores, para poner las coordenadas usando los regresos recursivos en sus casillas correspondientes.

