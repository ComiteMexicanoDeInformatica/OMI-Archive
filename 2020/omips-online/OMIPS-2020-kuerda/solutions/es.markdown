# Kuerda - Solución

![1](1.png)

En este problema debemos decir cuál de los 2 equipos suma mayor fuerza o si la fuerza de ambos equipos es la misma. El reto es encontrar cuales son los jugadores que pertenecen a cada equipo para sumar sus fuerzas y compararlas al final.

En este problema puede haber muchos casos especiales, por lo que tenemos que ser cuidadosos de ello.

Podemos explotar las consideraciones que nos dan para poder plantear una solución: dado que el equipo de la izquierda tiene prioridad ante ambigüedades podemos verificar si los primeros <b>n</b> jugadores de izquierda a derecha cumplen con alguna formación (si están formados ascendente o descendentemente). Si cumplen con esto entonces el equipo de la izquierda será el equipo más grande (en número de jugadores), de lo contrario el equipo de la derecha será el más grande.

Cuando sabemos cual es el equipo más grande podemos encontrar al último jugador de izquierda a derecha que pertenece al equipo de la izquierda y así sumar las fuerzas de su equipo. Después de esto, el resto de los jugadores que queden pertenecerán al equipo de la derecha.

Haremos comparación de números en más de ocasión, para esto nos apoyaremos de la siguiente función recursiva:

```
define comparar(n) {
    if(!iszero(n) && nextToABeeper) {
        pickbeeper();
        comparar(pred(n));
        putbeeper();
    }
    else if(iszero(n) && nextToABeeper) {
        // Número n es más chico
        while(notFacingNorth)
            turnleft();
    }
    else if(!iszero(n) && notNextToABeeper) {
        // Número junto a Karel es más chico
        return();
    }
    else {
        // Iguales
        while(notFacingSouth)
            turnleft();
    }
}
```

Funciona cuando queremos comparar un número <b>n</b> y se lo pasamos por parámetro a una función. Dicho número se compara con el número sobre el que se encuentra Karel en la casilla.

## Verificar la formación de los primeros <b>n</b> jugadores.

Para realizar esta tarea podemos contar cual es el valor de <b>n</b> al principio (por conveniencia dejamos el valor de <b>n</b> menos uno en la casilla (2,1), esto nos ayudará más adelante), así podremos saber cuándo debería acabarse el primer equipo.

![2](2.png)

Comparamos los <b>n-1</b> primeros pares de jugadores de izquierda a derecha. Si el número de la izquierda es mayor que el número de la derecha entonces dejamos un zumbador sobre el montón de la derecha (en la fila 2). 

Esto podemos lograrlo con el siguiente código.

```
define programN(n) {
    /* Función que ubica a Karel en el último 
     * jugador del equipo izquierdo.
     */
    iterate(pred(n)) {
        contarComparar(0);
        if(facingNorth) {
            move();
            putbeeper();
            turn(2);
            move();
            turn(1);
        }
        else if(facingSouth) {
            // Caso especial: números repetidos
            turn(3);
            move();
            return();
        }
    }
    ...
}

define contarComparar(n) {
    if(nextToABeeper) {
        pickbeeper();
        contarComparar(succ(n));
    }
    else {
        iterate(n)
            putbeeper();
        move();
        comparar(n);
    }
}
```

Luego de ejecutarlo el mundo de Karel se verá como el siguiente:

![3](3.png)

Lo que sigue es verificar si la secuencia de los primeros <b>n</b> jugadores están formados ascendente o descendentemente. 

Si en la segunda fila (desde la columna en la que Karel termina) hay <b>n-1</b> montones de un zumbador entonces se cumple que los primeros <b>n</b> jugadores están formados descendentemente, si hay <b>n-1</b> casillas con cero zumbadores entonces se cumple que los primeros <b>n</b> jugadores están formados ascendentemente.

Si cualquiera de estos 2 casos se cumple entonces el equipo de la izquierda es el mayor, de lo contrario, el equipo de la derecha será el mayor.

Para esto podemos hacer uso de 2 funciones que cuentan la mayor cantidad de casillas contiguas con uno y cero zumbadores.

```
define contar1(n) {
    if(frontIsBlocked) 
        comparar(n);
    else if(nextToABeeper) {
        pickbeeper();
        move();
        contar1(succ(n));
    }
    else {
        move();
        contar0(0);
    }
}

define contar0(n) {
    if(frontIsBlocked) 
        comparar(n);
    else if(nextToABeeper) {
        pickbeeper();
        move();
        contar1(0);
    }
    else {
        move();
        contar0(succ(n));
    }
}
```

Al final de estas funciones comparamos el valor que guardan en su variable con el valor de <b>n-1</b> que se encuentra en la casilla (2,1).

![4](4.png)

Si después de comparar Karel termina viendo hacia el sur entonces se cumplirá que los primeros <b>n</b> jugadores se encuentran formados ascendente o descendentemente, por lo tanto, el equipo de la izquierda será el más grande, de lo contrario, el equipo de la derecha lo será.

Ubicamos a Karel en el último jugador del equipo izquierdo avanzando <b>n</b> veces de izquierda a derecha o de derecha a izquierda según sea el caso.

Esto es posible lograrlo con el siguiente código:

```
define programN(n) {
    /* Función que ubica a Karel en el último 
     * jugador del equipo izquierdo.
     */
    ...
    turn(1);
    move();
    turn(1);
    if(nextToABeeper) 
        contar1(0);
    else 
        contar0(0);
    if(facingSouth) {
        /* El equipo de la izquierda es 
         * más grande
         */
        move();
        turn(1);
        iterate(pred(n))
            move();
        turn(2);
    }
    else {
        /* El equipo de la derecha es
         * más grande
         */
        while(notFacingSouth)
            turnleft();
        move();
        turn(1);
        while(nextToABeeper && frontIsClear)
            move();
        turn(2);
        if(notNextToABeeper) 
            move();
        iterate(n)
            move();
    }
}
```

Luego de ejecutar este código el mundo se verá como el siguiente:

![5](5.png)

En este punto Karel se encuentra sobre el último jugador del equipo izquierdo mirando hacia el oeste.

## Sumatoria de fuerzas.

Una vez que sabemos dónde termina el equipo izquierdo, sumamos las fuerzas de cada uno de los equipos y comparamos por última vez.

Podemos sumar la fuerza de un equipo utilizando recursividad como en la siguiente función:

```
define sumaFuerzas(n) {
    if(notNextToABeeper) {
        // Caso base de la recursión
        if(facingWest) {
            /* Fuerza del equipo de
             * la izquierda
             */
            iterate(n)
                putbeeper();
        }
        else {
            /* Equipo derecha suma más 
             * fuerza.
             */
            turn(2);
            while(frontIsClear) 
                move();
            // Comparamos las fuerzas
            comparar(n);
            if(facingSouth) {
                // Empate
                turn(2);
            }
            else if(facingNorth) {
                /* Equipo izquierdo suma más 
                 * fuerza.
                 */
                turn(1);
            }
            else {
                /* Equipo derecho suma más 
                 * fuerza.
                 */
                turn(2);
            }
        }
    }
    else if(nextToABeeper) {
        pickbeeper();
        if(nextToABeeper) 
            sumaFuerzas(succ(n));
        else {
            if(frontIsClear)
                move();
            sumaFuerzas(succ(n));
        }
    }
}
```

Dicha función la utilizamos 2 veces, una para sumar las fuerzas de cada equipo. El caso base de la función cambia cuado sumamos la fuerza de cada equipo.

Este es el mundo luego de que Karel suma la fuerza del equipo de la izquierda:

![6](6.png)

Código del program:

```
define contar(n) {
    if(nextToABeeper) {
        pickbeeper();
        contar(succ(n));
    }
    else {
        iterate(pred(n))
            putbeeper();
        turn(2);
        move();
        turn(1);
        programN(n);
    }
}

program () {
    move();
    contar(0);
    /* Sumar fuerzas del equipo
     * de la izquierda
     */
    sumaFuerzas(0);
    turn(2);
    move();
    while(notNextToABeeper)
        move();
    /* Sumar fuerzas del equipo
     * de la izquierda
     */
    sumaFuerzas(0);
    turnoff();
}
```

## Casos especiales.

Debemos ser cuidadosos de algunos mundos como los siguientes:

![7](7.png)

![8](8.png)

En la linea 14 de la función programN(n) nos encargamos de mundos como el primero de estos.
