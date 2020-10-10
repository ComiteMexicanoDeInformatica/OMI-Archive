# Kanikas

Para la subtarea de 89 puntos la soluci�n es simplemente simular la repartici�n de canicas. Primero recogemos todos los zumbadores de la fila y despu�s llenamos las casillas en orden con 1 zumbador. Si al final no terminamos de llenar todas las casillas nos orientamos al sur, sino al norte.

El problema cuando tenemos infinitos zumbadores en la mochila es que nos obliga a guardar de alguna manera n�mero de zumbadores que recogimos.

Entonces, para los 100 puntos necesitamos hacer uso de la recursi�n. Con ayuda de la recursi�n podemos mantener el n�mero exacto de zumbadores que tomamos, ya sea con un par�metro o sin �l.

El c�digo con par�metros se ver�a asi:

    void fn(x){
    	if(nextToABeeper()){
        	pickbeeper();
            fn(succ(x));
        }
        else{
        	if(frontIsClear()){
            	move();
                fn(x);
            }else{
            	iterate (2) turnleft();
                iterate (x){
                	putbeeper();
                    if(frontIsClear())
                    	move();
                }
            }
        }
    }

Est� funci�n hace todo el recorrido a la fila, aumentando en uno el par�metro $x$ cada que recoge un zumbador. Por lo tanto al final $x$ ser� igual al n�mero de zumbadores que tom� y a partir de ah� podemos usar el mismo algoritmo que la subtarea, llenar las $x$ casillas y verificar si terminamos de llenar toda la fila o no.
