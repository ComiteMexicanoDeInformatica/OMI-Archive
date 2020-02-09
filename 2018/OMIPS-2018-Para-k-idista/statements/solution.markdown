Debemos darnos cuenta de que no importa el orden en que Karel hace los movimientos,
solo importa cuántas veces se movió a la izquierda o a la derecha.

Por ejemplo, si Karel se encuentra inicialmente en la fila 7, significa que Karel deberá
bajar 6 filas para llegar a la pista. De tal manera que puede moverse hasta 6 columnas a
la izquierda o a la derecha de la columna en la que inicia. 

Por lo tanto, para saber si Karel puede caer en un zumbador, debemos medir la distancia de
Karel a la pista; llamemos a esta distancia $d$. Si hay algún zumbador que se encuentra a
una distancia menor o igual a $d$ (a la izquierda o a la derecha) de la columna inicial de
Karel, significa que Karel puede llegar a un trampolín. Si lo anterior no pasa sabemos que
no hay manera de que Karel llegue a un trampolín.
