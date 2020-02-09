#Cubesort - Solución.

Para resolver este problema es necesario implementar un algoritmo de ordenamiento, por lo que el ordenamiento de burbuja encaja perfectamente en esta ocasión.

El ordenamiento burbuja hace $n$ recorridos a lo largo de la lista. Comparando los números adyacentes e intercambia los que no están en orden. Cada recorrido a lo largo de la lista ubica el siguiente valor más grande en su lugar apropiado. En esencia, cada numero sube como una burbuja hasta el lugar al que pertenece.

Para implementar esta solución se debe dividir el problema en sub-problemas, puesto que es necesario primero tener una forma de comparar objetos.

# Comparación.

Los objetos a comparar son ternas $x, y, z$. El criterio que siguen es que un objeto $A$ es mayor que  un objeto $B$ si $A_x > B_x$, en caso de que sean iguales entonces tiene que cumplirse que $A_y > B_y$, en caso de que $A_x = B_x$ y $A_y = B_y$ tiene que cumplirse que $A_z > B_z$.

Es necesario comparar 2 números individuales. Para esto podemos hacerlo de la siguiente manera donde Karel inicia viendo hacia el este sobre el número de la izquierda.

```
define contar(n) {
    if(nextToABeeper) {
        pickbeeper();
        contar(succ(n));
    }
    else {
        iterate(n)
            putbeeper();
        move();
        comparar(n);
    }
}
define comparar(n) {
    if(!iszero(n) && nextToABeeper) {
        pickbeeper();
        comparar(pred(n));
        putbeeper();
    }
    else if(iszero(n) && nextToABeeper)     // Número derecho es mayor.
        turnright();
    else if(!iszero(n) && notNextToABeeper) // Número izquierdo es mayor.
        backturn();
    else                                    // Números iguales.
        turnleft();
}
```

Karel terminará viendo hacia el norte si ambos números son iguales, hacia el sur si el número de la derecha es mayor o hacia el oeste si el número de la izquierda es mayor.

A partir de la orientación nosotros podemos tomar la próxima decisión.

```
define compararColumna() {
    iterate(3) {
        if(facingEast)
            contar(0);
        if(facingNorth) {
            move();
            turnleft();
            move();
            backturn();
        }
    }
    if(facingWest) { // Columna izquierda es mayor
        turnleft();
        while(frontIsClear)
            move();
        turnright();
        iterate(3) {
            intercambiaNumeros();
            backturn();
            move();
            turnleft();
            move();
            turnleft();
        }
        turnleft();
        while(frontIsClear)
            move();
    }
    else { // Columna derecha es mayor
        while(frontIsClear)
            move();
    }
    turnleft();
}
```

Tras comparar 2 columnas adyacentes, en la derecha quedará la columna mayor y en la izquierda la columna menor. Karel siempre terminará hasta abajo en la columna de la derecha mirando hacia el este.

El intercambio de 2 números adyacentes se logra con recursividad de la siguiente manera.

```
define intercambiaNumeros() {
    if(nextToABeeper) {
        pickbeeper();
        intercambiaNumeros();
        putbeeper();
    }
    else {
        move();
        backturn();
        intercambia();
        backturn();
        move();
    }
}
define intercambia() {
    if(nextToABeeper) {
        pickbeeper();
        intercambia();
        putbeeper();
    }
    else
        move();
}
```

# Ordenamiento.

El ordenamiento es una tarea más sencilla que la de comparar. Es necesario saber primero cuántos números se ordenarán, por lo que se debe medir la distancia de la lista.

Para esto, Karel inicia en la esquina inferior izquierda mirando hacia el este.

```
define medir(n) {
    if(nextToABeeper && frontIsClear) {
        move();
        medir(succ(n));
    }
    else {
        if(frontIsBlocked) {
            backturn();
            while(frontIsClear)
                move();
            backturn();
            ordenar(succ(n));
        }
        else {
            backturn();
            while(frontIsClear)
                move();
            backturn();
            ordenar(n);
        }
    }
}
define ordenar(n) {
    if(!iszero(n)) {
        iterate(pred(n))
            compararColumna();
        backturn();
        while(frontIsClear)
            move();
        backturn();
        ordenar(pred(n));
    }
}
```

El valor $n$ en la instrucción ```ordenar``` indica la cantidad de números menos 1 a ordenar en este recorrido, ya que al término del $i$-ésimo recorrido los $i$ objetos más grandes ya se encontrarán ordenados. Es por esto que podemos parar de ordenar cuando el valor $n$ de la instrucción es 0. Karel debe recorrer la lista de izquierda a derecha, por lo que debe regresar al inicio de la lista al término de cada recorrido.
