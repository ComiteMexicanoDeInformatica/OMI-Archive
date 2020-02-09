# Solución - Líneas

Calculemos la paridad de un montón de beepers sin hacer movimientos.

El código es este:

```  
void checkParity() {
    	if (nextToABeeper) {
        	pickbeeper();
            if (nextToABeeper) {
            	pickbeeper();
                checkParity();
                putbeeper();
            } else {
            	east();
            }
            putbeeper();
        } else {
        	west();
        }
    }
```

Observemos que para dibujar $N$ puntos en a lo más $2N$ movimientos, solo podemos recorrer el mundo a lo mas dos veces. Consideremos solo los montones de tamaño impar en la primer corrida del mundo (de izquierda a derecha).

Consideremos el primer montón de beepers (solo consideramos los de tamaño impar por el momento). Al dibujar esta línea, podemos encontrarnos con otro montón de beepers (solo consideramos tamaños impares). Su línea correspondiente comparte cierta cantidad de posiciones con la que estamos pintando actualmente. Pintemos la que termina mas a la derecha (esto es fácil si vemos cuantos beepers del nuevo montón hacen falta considerar).

Para dibujar las líneas, basta con usar una función recursiva con un parámetro que nos sirva como contador.

El código es este:
```  
void extendOddLine(x) {
    	if(nextToABeeper) {
        	pickbeeper();
            extendOddLine(succ(x));
        } else {
        	oddLine(x);
        }
    }

    void oddLine(x) {
    	if (nextToABeeper) {
        	checkParity();
            if (facingEast) {
            	// Impar
                iterate(x) if(nextToABeeper) pickbeeper();
                extendOddLine(x);
            } else {
            	east();
                if(frontIsClear) {
                	move();
                    if(!iszero(x)) oddLine(pred(x));
                    else oddLine(x);
                }
            }
        } else {
        	if (frontIsClear) {
            	if(!iszero(x)) {
                    putbeeper();
                    move();
                    oddLine(pred(x));
                } else {
                    move();
                    oddLine(x);
                }
            } else if(!iszero(x)) putbeeper();
        }
    }
```  

Al terminar de pintar las líneas de tamaño impar, estamos en el extremo derecho del mundo y ahora el problema es pintar las líneas de tamaño par en una corrida de derecha z izquierda. Observemos que es casi el mismo problema que acabamos de resolver, solo basta con considerar únicamente montones de tamaño par.

El código es este:

```  
 void oddLine(x) {
    	if (nextToABeeper) {
        	checkParity();
            if (facingEast) {
            	// Impar
                iterate(x) if(nextToABeeper) pickbeeper();
                extendOddLine(x);
            } else {
            	east();
                if(frontIsClear) {
                	move();
                    if(!iszero(x)) oddLine(pred(x));
                    else oddLine(x);
                }
            }
        } else {
        	if (frontIsClear) {
            	if(!iszero(x)) {
                    putbeeper();
                    move();
                    oddLine(pred(x));
                } else {
                    move();
                    oddLine(x);
                }
            } else if(!iszero(x)) putbeeper();
        }
    }

    void extendEvenLine(x) {
    	if(nextToABeeper) {
        	pickbeeper();
            extendEvenLine(succ(x));
        } else {
        	evenLine(x);
        }
    }

    void evenLine(x) {
    	if (nextToABeeper) {
        	checkParity();
            if (facingWest) {
            	// Par
                iterate(x) if(nextToABeeper) pickbeeper();
                extendEvenLine(x);
            } else {
            	west();
                if(frontIsClear) {
                	move();
                    if(!iszero(x)) evenLine(pred(x));
                    else evenLine(x);
                }
            }
        } else {
            if (frontIsClear) {
            	if(!iszero(x)) {
                    putbeeper();
                    move();
                    evenLine(pred(x));
                } else {
                    move();
                    evenLine(x);
                }
            } else if(!iszero(x)) putbeeper();
        }
    }
```
