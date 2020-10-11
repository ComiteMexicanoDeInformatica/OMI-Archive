# Reflejo

Para poder reflejar el camino que hicimos es necesario guardar cada instrucci�n que hizo Karel. Esto se puede hacer con recursi�n.

Para concebir dicha funci�n recursiva debemos aclarar bien que debe guardar karel en la pila de llamadas. Adem�s, debemos de tener claro que el camino para salir del laberinto es �nico y se podemos alcanzar la salida de la siguiente forma: avanzamos si hay camino libre o giramos donde haya pared. Esto hasta que nos encontremos con la salida (una casilla sin pared izquierda ni derecha).

Por cada casilla que crucemos debemos poner un zumbador. Debemos notar que los giros no nos cambian de casilla, por lo que solo hay que poner zumbador cada que avancemos.

Como la pila cumple que lo ultimo que entra es lo primero que ejecutar�, basta con que nos ubiquemos en la �ltima posici�n del laberinto y literalmente copiar los mismos movimientos que hizo Karel de ida.

Adjunto el c�digo en pascal:

    define-nueva-instruccion refleja como inicio
    	si izquierda-bloqueada o derecha-bloqueada entonces inicio
        	(*Me encuentro todav�a dentro del laberinto*)
            si frente-libre entonces inicio
            	(*Avanzo y en mi reflejo regresar� de donde vine
                y marcar� con un zumbador*)
                avanza;
                refleja;
                avanza;
                deja-zumbador;
            fin sino inicio
            	(*Giro y de regreso simplemente replico el giro*)
                si izquierda-libre entonces inicio
                	gira-izquierda;
                    refleja;
                    gira-izquierda;
                fin sino inicio
                	gira-derecha;
                    refleja;
                    gira-derecha;
                fin;
            fin;
        fin sino inicio
        	(*Estoy fuera del laberinto y
            debo regresar a la �ltima casilla*)
            gira-izquierda;
            gira-izquierda;
            avanza;
            gira-izquierda;
            gira-izquierda;
        fin;
    fin;
