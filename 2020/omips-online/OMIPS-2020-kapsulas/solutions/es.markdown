Consideremos el caso en el que solamente hay un montón de $x$ zumbadores en la casilla $(i,j)$. Para este caso la esquina superior izquierda del cuadrado la podemos encontrar moviendo a Karel $x$ veces al norte y $x$ veces al oeste (desde la casilla $(i,j)$).

Supongamos que tenemos a Karel en la esquina superior izquierda del cuadrado orientado al sur.
A partir de aquí se puede repetir $x$ veces lo siguiente:

- Llenar una línea de longitud $x$ al este con $1$ zumbador (regresar y orientarse al sur nuevamente).
- Avanzar.

Y esto pintaría el cuadrado que nos pide el problema, solo **hay que tener cuidado con el ultimo avanza**, pues Karel podría chocar con alguna pared.

Ahora, si hay más de un zumbador y de alguna manera podemos hacer lo anterior para cada montón, entonces al final solo habría que limpiar (dejar con $0$ zumbadores) aquellas casillas con más de $1$ zumbador.

Notemos que este problema **no** se puede resolver encontrando el primer montón y hacer el cuadrado, encontrar el segundo y hacer su cuadrado, y asi hasta acabar, pues uno de los no podemos saber cuando un montón con $1$ zumbador era parte del mundo original (es decir, hay que hacer su cuadrado de 3x3) o si pertenece a algún cuadrado que pintamos anteriormente.

Para resolver este problema podemos recorrer el mundo con una función recursiva. Esta función debe ser capaz de recordar en que casillas había un montón de zumbadores y cuantos había; si podemos lograr hacer esto entonces ya solo es aplicar las ideas anteriores.

Una manera de hacer esto es con una función con parametros y recorriendo el mundo de izquierda a derecha y de abajo a arriba.

El siguiente código implementa la solución anterior.

```
class program {

    void turn( y ){
    	iterate( y ) turnleft();
    }

    void fn( x ){
    	if( nextToABeeper() ){
        	pickbeeper();
            fn( succ( x ) );
        }else{
        	if( frontIsClear() ){
            	move();
                fn( 0 );
                move();
            }else{
            	turn( 3 );
                if( frontIsClear() ){
                	move();

                    turn( 3 );
                    while( frontIsClear() ) move();
                    turn( 2 );

                    fn( 0 );

                    turn( 3 );
               		if( frontIsClear() ){
                		move();

                    	turn( 3 );
                    	while( frontIsClear() ) move();
                    	turn( 2 );
                    }
                }else{
                	turn( 3 );
                }
            }

            if( iszero( x ) ) return();

            turn( 2 );
            iterate( x ) move();
            turn( 1 );
            iterate( x ) move();
            turn( 1 );

            iterate( 2 )
            iterate( pred( x ) ){
            	turn( 1 );

                iterate( 2 ){

                    iterate( pred( x ) ){
                       putbeeper();
                       move();
                    }

                }

                putbeeper();
                move();
                putbeeper();
                move();
                putbeeper();

                turn( 2 );
                iterate( 2 ) iterate( pred( x ) ) move();
             	move();
                move();

                turn( 1 );
                move();
            }

            iterate( 2 ){
            	turn( 1 );

                iterate( 2 ){

                    iterate( pred( x ) ){
                       putbeeper();
                       move();
                    }

                }

                putbeeper();
                move();
                putbeeper();
                move();
                putbeeper();

                turn( 2 );
                iterate( 2 ) iterate( pred( x ) ) move();
             	move(); move();

                turn( 1 );
                move();
            }

            turn( 1 );

                iterate( 2 ){

                    iterate( pred( x ) ){
                       putbeeper();
                       move();
                    }

                }

                putbeeper();
                move();
                putbeeper();
                move();
                putbeeper();

                turn( 2 );
                iterate( 2 ) iterate( pred( x ) ) move();
             	move();
                move();

                turn( 3 );
                iterate( x ) move();
                turn( 3 );
                iterate( x ) move();
                turn( 3 );
        }
    }

    void arregla(){
    	if( nextToABeeper() ){
        	pickbeeper();
            if( nextToABeeper() ){
            	while( nextToABeeper() ) pickbeeper();
            }else{
            	putbeeper();
            }
        }
        if( frontIsClear() ){
        	move();
            arregla();
        }
    }

    program () {


        fn( 0 );
        turn( 2 );

        while( rightIsClear() ){
        	arregla();
            turn( 3 );
            move();
            turn( 3 );
            while( frontIsClear() ) move();
            turn( 2 );
        }

        arregla();

        turnoff();
    }
}
```
