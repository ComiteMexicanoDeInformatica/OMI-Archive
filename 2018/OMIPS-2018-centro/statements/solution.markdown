# Centro del Rectángulo

La primera observación para resolver el problema es que sin importar cuántas columnas haya, la fila en la que terminará Karel será la misma. Análogamente pasa lo mismo con la columna final.

Ahora bien, el problema se reduce a poder encontrar la casilla que se encuentra a la mitad de una fila o una columna. Esto se puede resolver con ayuda de zumbadores o recursión para el total de los puntos.

Supongamos que iniciamos al principio de una fila o de una columna; esto es, hasta abajo o hasta la izquierda, respectivamente. A partir de ahí, nuestra función recursiva luce como la siguiente:

        
    void mitad() {
    	if(frontIsClear) {
    		move();
    		move();
    		mitad();
    		move();
    	} else {
    		turnleft();
    		turnleft();
    	}
    }

Esta función recursiva ocupa la idea de que dividir a la mitad puede expresarse como "por cada dos casillas que avancé al final regresaré una". 

Podemos llegar al centro del rectángulo si primero llamamos nuestra función para encontrar la mitad de alguna fila y luego la usamos nuevamente para encontrar la mitad de la columna en la fila en la que nos encontramos.
