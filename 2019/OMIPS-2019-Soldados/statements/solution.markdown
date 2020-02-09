#Soldados - Solución.

Las casillas del mundo que inicialmente tengan zumbadores en ellas deberán quedar con la misma cantidad de zumbadores al final del programa, por lo que solo deberemos por preocuparnos por aquellas casillas con 0 zumbadores. Entiéndase por casillas adyacentes aquellas que se encuentran al oeste y al sur de cada casilla.

Para que una casilla $(x,y)$ sea mayor que las casillas adyacentes $(x-1,y)$ y $(x,y-1)$, es suficiente con obtener el valor mayor de ambas casillas y sumarle 1. Formalmente: $f(x,y) = max( f(x-1,y), f(x,y-1) ) + 1 $, donde $f(i,j)$ representa el valor a asignar en la casilla $(i,j)$.

![1](1.png)

Se suma 1 al valor máximo de ambas casillas porque es el número mínimo necesario para que la casilla $(x,y)$ sea mayor que sus 2 casillas adyacentes. Si decidiéramos sumarle un valor $n > 1$ al máximo de ambas casillas, pudiéramos encontrarnos con el siguiente mundo:

![2](2.png)

En donde la única solución es sumarle 1 al máximo de las casillas adyacentes.

<b>¿Qué sucede cuando hay una pared en la casilla $(x-1,y)$ o $(x,y-1)$?</b>

Podemos asumir que si no es posible acceder a las casillas adyacentes, el valor de dichas casillas es 0, entonces solo nos importará sumarle 1 al valor de las casillas a las que sí se puede acceder.

![3](3.png)

El siguiente código asigna el valor a una casilla.

```
void rellenaCasilla() {
        if (notNextToABeeper) {
            turnleft();
            checa();
            turnleft();
            checa();
            backturn();
            putbeeper();
        }
    }
```

La instrucción ```checa``` se encarga de verificar si existe una pared en las casillas adyacentes, de no ser así, entonces copia el valor de dichas casillas, y deja en la casilla $(x,y)$ el valor mayor.

```
void checa() {
        if(frontIsClear) {
            move();
            backturn();
            pasa(0);
            backturn();
        }
    }
```

La instrucción ```pasa``` se encarga de crear una copia del montón de beepers de una casilla adyacente. Finalmente, la instrucción ```rellenaCasilla``` deja un zumbador extra para sumar 1 al valor mayor obtenido.

```
void pasa(x) {
        if (nextToABeeper) {
            pickbeeper();
            pasa(succ(x));
        } else {
            iterate(x)
                putbeeper();
            move();
            iterate(x)
                if(nextToABeeper)
                    pickbeeper();
            iterate(x)
                putbeeper();
        }
    }
```

Para calcular el valor en la casilla $(x,y)$ es necesario primero calcular el valor de las casillas $(x-1,y)$ y $(x,y-1)$, y a su vez, para calcular el valor de la casilla $(x-1,y)$ es necesario calcular primero el valor de las casillas $(x-2,y)$ y $(x-1,y-1)$. Para asegurarnos de que cuando Karel llega a la casilla $(x,y)$ sus casillas adyacentes ya han sido calculadas, podemos comenzar a rellenar las casillas de abajo hacia arriba y de derecha a izquierda, comenzando por la casilla $(1,1)$. 

```
void rellena() {
        rellenaCasilla();
        while(frontIsClear) {
            move();
            rellenaCasilla();
        }
        backturn();
        while(frontIsClear)
            move();
        turnleft();
        if (frontIsClear) {
            move();
            turnleft();
            rellena();
        }
    }
```

La instrucción ```rellena``` se ejecuta por primera vez en el program cuando Karel se encuentra en la casilla $(1,1)$ mirando hacia el norte.

