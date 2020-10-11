# Centro del Rect�ngulo

La primera observaci�n para resolver el problema es que sin importar cu�ntas columnas haya, la fila en la que terminar� Karel ser� la misma. An�logamente pasa lo mismo con la columna final.

Ahora bien, el problema se reduce a poder encontrar la casilla que se encuentra a la mitad de una fila o una columna. Esto se puede resolver con ayuda de zumbadores o recursi�n para el total de los puntos.

Supongamos que iniciamos al principio de una fila o de una columna; esto es, hasta abajo o hasta la izquierda, respectivamente. A partir de ah�, nuestra funci�n recursiva luce como la siguiente:

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

Esta funci�n recursiva ocupa la idea de que dividir a la mitad puede expresarse como "por cada dos casillas que avanc� al final regresar� una".

Podemos llegar al centro del rect�ngulo si primero llamamos nuestra funci�n para encontrar la mitad de alguna fila y luego la usamos nuevamente para encontrar la mitad de la columna en la fila en la que nos encontramos.
