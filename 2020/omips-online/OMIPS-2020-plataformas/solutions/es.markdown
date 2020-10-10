# Plataformas -  Solución.

![1](1.png)

En este problema nos piden alinear plataformas verticales que se encuentran sobre cada una de las filas del mundo utilizando la menor cantidad de movimientos. Un movimiento consiste en trasladar una plataforma una casilla a la izquierda o a la derecha sin que se salga de los limites del mundo.

El enfoque clave para el problema es: ¿cuántos movimientos hacen falta para trasladar cada plataforma hacia una columna específica?

De esta forma podemos hacer de este problema 2 sub-problemas: calcula la cantidad de movimientos necesarios para mover todas las plataformas a cada una de las columnas y después encuentra la columna con menos movimientos.


## Contar movimientos.

Para esta parte contaremos cuántos movimientos necesita cada plataforma para llegar a cada columna, al final sumaremos todos los movimientos para tener el total de cada columna.

Hacen falta 0 movimientos para que una plataforma se encuentre sobre las columnas que abarca al principio, luego hace falta un movimiento por cada cada columna a la izquierda y a la derecha de la plataforma, por lo que debemos empezar a contar a partir de la izquierda y derecha sobre cada plataforma y para esto utilizaremos recursión.

El siguiente código se encarga de contar los movimientos sobre una columna.

```
define cuenta_plataforma() {
    while(notNextToABeeper) 
        move();
    cuenta(1);
    cuenta(1);
}

define cuenta(n) {
    if(notNextToABeeper) {
        iterate(succ(n))
            putbeeper();
        if(frontIsClear) {
            move();
            cuenta(succ(n));
        }
        else
            turn(2);
    }
    else {
        if(frontIsClear) {
            move();
            cuenta(n);
        }
        else
            turn(2);
    }
}

```

Luego de ejecutar la función cuenta_plataforma() sobre la primer plataforma el mundo se verá como el siguiente:

![2](2.png)

Tenemos que ejecutar la función sobre cada una de las filas del mundo.

```
program () {
    while(notFacingEast) 
        turnleft();
    while(leftIsClear) {
        cuenta_plataforma();
        turn(1);
        move();
        turn(3);
    }
    cuenta_plataforma();
    ...
}
```

Al final del conteo el mundo queda así:
![3](3.png)

Ahora debemos sumar el total de movimientos sobre cada columna, y como tenemos un zumbador de más por cada fila debemos restar al total de cada columna el número de filas que hay, para esto utilizaremos recursión.

```
define agrupaZumbadores(n) {
    if(nextToABeeper) {
        pickbeeper();
        agrupaZumbadores(succ(n));
    }
    else {
        if(frontIsClear) {
            move();
            agrupaZumbadores(n);
            pickbeeper();
        }
        else {
            iterate(n)
                putbeeper();
        }
    }
}
```

Este es el mundo luego de ejecutar la función sobre la primer coumna.

![4](4.png)

Debemos de ejecutar la misma función sobre cada una de las columnas.

```
program () {
    ...
    turn(3);
    while(leftIsClear) {
        agrupaZumbadores(0);
        pickbeeper();
        turn(1);
        move();
        turn(1);
        while(frontIsClear)
            move();
        turn(2);
    }
    agrupaZumbadores(0);
    pickbeeper();
    ...
}
```

Al final de este sub problema el mundo se verá como el siguiente:

![5](5.png)


En este punto tenemos en la primer fila sobre cada columna el total de movimientos necesarios para mover todas las plataformas a cada columna, ahora basta con encontrar cual es el menor de estos números y dejarlo en la casilla (1,1).

## Encuentra el menor montón de zumbadores.

![6](6.png)

Este es un problema muy común en problemas de Karel, para resolverlo debemos comparar los números en pares e ir dejando siempre el número menor encontrado hasta el momento.

El siguiente código compara solo 2 números contiguos y deja en la casilla de enfrente el número menor.

```
define encuentraMenor(n) {
    if(nextToABeeper) {
        pickbeeper();
        encuentraMenor(succ(n));
    }
    else {
        move();
        iterate(n) {
            if(nextToABeeper) 
                pickbeeper();
            else {
                turn(1);
                iterate(pred(n))
                    putbeeper();
            }
        }
        if(facingWest) {
            while(nextToABeeper) 
                pickbeeper();
            iterate(n)
                putbeeper();
        }
        else 
            turn(3);
    }
}
```

![7](7.png)

Debemos ejecutar esta función sobre cada número en la primer fila, esto se logra con el siguiente código:

```
program () {
    ...
    turn(3);
    while(frontIsClear) 
        encuentraMenor(0);
    turnoff();
}
```
