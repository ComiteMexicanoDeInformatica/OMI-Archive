# Electricidad - Solución

En este problema se nos pide obtener el mayor número de zumbadores que existe en una fila o columna en la cual Karel pondría el generador.

La idea de solución es realizar un recorrido por cada fila y columna que exista, durante dicho recorrido se obtendrán todos los zumbadores para llevarlos a la casilla <b>(1, 1)</b> y de esta manera ir actualizando el número máximo de zumbadores que se recolecta en cada uno de los recorridos, manteniendo siempre el mayor.

## Recorrido en filas

Primero lo que vamos a hacer es realizar la búsqueda en cada una de las filas que existen en el mundo, y por cada casilla que recorramos vamos a ir tomando los zumbadores que nos encontremos e ir llevando la cuenta de cada uno de ellos y en la casilla en la cual se encuentran, esto lo logramos con recursividad. para esto nos apoyaremos de las siguientes funciones:

```
    void go(n){
        if (nextToABeeper){
            pickbeeper();
            go(succ(n));
            putbeeper();
        } else{
            if (frontIsClear){
                move();
                go(n);
                back();
            } else{
                bumpWestToUpdate(n);
            }
        }
    }

    void checkRows(){
        while (iszero(0)){
            go(0);
            if (leftIsBlocked){
                return();
            } else {
                north();
                move();
                west();
                bump();
                east();
            }
        }
    }
```


Cuando terminemos de recorrer toda la fila y de obtener todos los zumbadores, debemos retornar a la casilla <b>(1, 1)</b> la cual siempre se ubicará en la izquierda inferior del mundo, es decir, al Suroeste del mundo, para esto, las siguientes funciones nos ayudaran a regresar:

```
    void bumpSouthToUpdate(n){
        if (!facingSouth){
            turnleft();
            bumpSouthToUpdate(n);
            turnright();
        } else if (!frontIsBlocked){
            move();
            bumpSouthToUpdate(n);
            back();
        } else {
            updateMax(n);
        }
    }

    void bumpWestToUpdate(n){
        if (!facingWest){
            turnleft();
            bumpWestToUpdate(n);
            turnright();
        } else if (!frontIsBlocked){
            move();
            bumpWestToUpdate(n);
            back();
        } else {
            bumpSouthToUpdate(n);
        }
    }
```

### Actualizar el número máximo de zumbadores obtenidos en una fila

Una vez situándonos en la casilla <b>(1, 1)</b>, actualizaremos el número máximo de zumbadores que hemos encontrado en el recorrido de cada fila, la idea es que cuando el número de zumbadores <b>B</b> recolectados en el último recorrido sea mayor al número máximo de zumbadores <b>A</b> que se encuentra en la casilla <b>(B > A)</b>, obtengamos la diferencia de <b>B-A</b> y de esta manera sumarlo al número de zumbadores actuales en la casilla. Esto lo lograremos con recursividad a través de la siguiente función:

```
    void updateMax(n){
        if (iszero(n))
            return();

        if (nextToABeeper){
            pickbeeper();
            updateMax(pred(n));
            putbeeper();
        } else {
            iterate (n)
                putbeeper();
        }
    }
```


### Regresar cada zumbador a su respectiva casilla

Después de haber hecho lo anterior, necesitaremos regresar a la última casilla en donde recolectamos el último grupo de zumbadores, la siguiente función nos ayudará a hacerlo:

```
    void back(){
        turnleft();
        turnleft();
        move();
        turnleft();
        turnleft();
    }
```

Al finalizar cada recursión de la función <b>go()</b>, volveremos a poner cada uno de los zumbadores recolectados anteriormente en su respectiva casilla y nos moveremos a la siguiente fila que se encuentra al norte del mundo para situarnos en la primera casilla del oeste y realizar la misma dinámica. Esto lo haremos en cada una de las filas hasta que ya no exista otra fila que podamos recorrer.

## Recorrido en columnas

posteriormente, realizaremos la misma dinámica pero ahora en cada columna, empezando por la primera columna al Oeste del mundo y recorriendolas de sur a norte.

Para desplazarnos y recolectar todos los zumbadores utilizaremos la funcion:

```
    void checkColumns(){
        while (iszero(0)){
            go(0);
            if (rightIsBlocked){
                return();
            } else {
                east();
                move();
                south();
                bump();
                north();
            }
        }
    }
```

y de nueva cuenta la funcion <b>go()</b>.

nuevamente para regresar a la casilla <b>(1, 1)</b> utilizaremos las funciones <b>bumpWestToUpdate()</b> y <b>bumpSouthToUpdate()</b>.

actualizaremos el maximo de zumbadores recolectados con la funcion <b>updateMax()</b>.

Y nuevamente retornaremos a la última columna recorrida para colocar cada uno de los zumbadores en su respectiva casilla con la función <b>back()</b>.

Al final de cumplir dicha secuencia, obtendremos que en la casilla </b>(1, 1)</b> se encontrará el número máximo de zumbadores que Karel pudo recolectar en una fila o columna.

En necesario que tambien contemplemos el siguiente codigo implementado en la funcion principal del programa para ejecutar el algoritmo anterior.

```
    void turnright(){
        turnleft();
        turnleft();
        turnleft();
    }

    void west(){
        while (notFacingWest)
            turnleft();
    }

    void north(){
        while (notFacingNorth)
            turnleft();
    }

    void east(){
        while (notFacingEast)
            turnleft();
    }

    void south(){
        while (notFacingSouth)
            turnleft();
    }

    void bump(){
        while (frontIsClear)
            move();
    }

    program (){
        turnright();

        if (frontIsClear) {
            move();
            checkRows();
        }

        south();
        bump();
        west();
        bump();

        north();

        if (frontIsClear) {
            move();
            checkColumns();
        }
    }

```