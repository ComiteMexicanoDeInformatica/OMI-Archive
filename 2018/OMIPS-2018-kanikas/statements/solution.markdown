# Kanikas

Para la subtarea de 89 puntos la solución es simplemente simular la repartición de canicas. Primero recogemos todos los zumbadores de la fila y después llenamos las casillas en orden con 1 zumbador. Si al final no terminamos de llenar todas las casillas nos orientamos al sur, sino al norte.

El problema cuando tenemos infinitos zumbadores en la mochila es que nos obliga a guardar de alguna manera número de zumbadores que recogimos.

Entonces, para los 100 puntos necesitamos hacer uso de la recursión. Con ayuda de la recursión podemos mantener el número exacto de zumbadores que tomamos, ya sea con un parámetro o sin él.

El código con parámetros se vería asi:

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

Está función hace todo el recorrido a la fila, aumentando en uno el parámetro $x$ cada que recoge un zumbador. Por lo tanto al final $x$ será igual al número de zumbadores que tomó y a partir de ahí podemos usar el mismo algoritmo que la subtarea, llenar las $x$ casillas y verificar si terminamos de llenar toda la fila o no.