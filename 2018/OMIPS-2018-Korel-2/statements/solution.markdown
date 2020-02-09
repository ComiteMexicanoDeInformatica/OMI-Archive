La primera observación que debemos hacer es que Korel siempre se puede mover a una casilla que esté a distancia par de la casilla inicial.

Para ver mejor estos movimientos, imaginemos el mundo como un tablero infinito de ajedrez y a Korel que inicia en una casilla negra.
Korel entonces se puede mover únicamente por todas las casillas negras de este tablero.
Además, todas las casillas negras están a distancia par de las demás casillas negra y todas las casillas blancas están
a una distancia impar de las casillas negras (esto se cumple para cualquier camino que tomes).

Por lo tanto, la solución se reduce a saber si la posición donde está el zumbador está a distancia par de la casilla inicial.
Un buen algoritmo para esto es correr una búsqueda con un parámetro que indique si la casilla que estás visitando
está a una distancia par o a una distancia impar, y cambiar el parámetro cada vez que se llame la función recursiva.
