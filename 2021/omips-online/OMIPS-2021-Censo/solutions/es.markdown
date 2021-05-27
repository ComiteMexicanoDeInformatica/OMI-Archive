Para resolver este problema necesitaremos [recursión](https://omegaup.com/course/introduccion_a_algoritmos/assignment/algoritmos_recursivos_lectura/#problems).

El problema se trata de mover todos los montones de zumbadores de cada renglón a la primera columna del mundo.

Veamos el caso de ejemplo:

![Ejemplo de Entrada](../statements/sample.in.png)

![Ejemplo de Salida](../statements/sample.out.png)

En total en el renglón 1 hay 2 zumbadores, en el 2 hay 2 zumbadores, en el 3 hay 4 zumbadores, en el 4 hay 0 zumbadores y en el 5 hay 99 zumbadores.

Ya que no sabemos donde está Karel al inicio, lo mejor es asegurarnos que esté en la casilla $1,1$. Como solo hay paredes verticales en el mundo, lo podemos hacer con un algoritmo como el siguiente:

```
while (!facingSouth) turnleft();
while (frontIsClear) move();
iterate (2) turnleft();
while (frontIsClear && !leftIsClear) move();
while (leftIsClear) {
    if (leftIsClear) turnleft();
    move();
    turnleft();
    while (frontIsClear) move();
    iterate (2) turnleft();
    while (frontIsClear && !leftIsClear) move();
}
iterate (2) turnleft();
while (frontIsClear) move();
iterate (2) turnleft();
```

Con ello nos direccionamos al sur, llegamos hasta abajo y nos volteamos al norte. Después revisamos la pared de la izquierda para saber si es el borde del mundo o si hay una salida. Repetimos hasta encontrar el último renglón (el primero del mundo) y nos posicionamos en la parte de abajo viendo al norte.

Ahora podemos hacer una función que recoja los zumbadores y para después dejarlos en orden inverso (recordemos que cuando se deshace la pila de instrucciones, se ejecutan en orden inverso).

```
void recoger() {
    if (nextToABeeper) {
      pickbeeper();
      recoger();
      putbeeper();
    }
}
```

Ya que podemos recoger los zumbadores, tenemos que movernos a cada una de las casillas, pero debemos hacerlo antes de dejar los zumbadores, así que lo haremos en el $else$.

```
void recorre() {
    if (nextToABeeper) {
      pickbeeper();
      recorre();
      putbeeper();
    } else if (frontIsClear) {
      move();
      recorre();
      move();
    }
}
```

Con esto ya podemos recoger los zumbadores y movernos hasta que se acabe la columna y movernos y dejar los zumbadores en el orden inverso.

Finalmente tenemos que agregar un $else$ para cuando se acabe la columna y nos podamos mover, ya sea a la siguiente columna o regresemos a la casilla $1,1$ para poder dejar los zumbadores.

```
void recorre() {
    if (nextToABeeper) {
      pickbeeper();
      recorre();
      putbeeper();
    } else if (frontIsClear) {
      move();
      recorre();
      move();
    } else {
      iterate (2) turnleft();
      while (leftIsBlocked && frontIsClear) move();
      if (leftIsClear) {
        turnleft();
        move();
        iterate (3) turnleft();
        while (frontIsClear) move();
        iterate (2) turnleft();
        recorre();
      } else {
        llegaEsquina();
      }
    }
}
```

Nos damos la vuelta y avanzamos buscando una salida a la izquierda. Si la encontramos, significa que hay otra columna, entonces nos movemos a ella, nos posicionamos en la parte de abajo viendo al norte y volvemos a llamar a la función. Si no encontramos la izquierda libre, significa que llegamos a la última columna y podemos regresar al inicio de la misma forma como hicimos antes de empezar.

Cuando se deshace la pila y nos empezamos a mover vamos a llegar al borde y es necesario regresar a Karel a la parte de abajo para que no choque y deje los zumbadores en el orden correcto.

```
void recorre() {
    if (nextToABeeper) {
      pickbeeper();
      recorre();
      putbeeper();
    } else if (frontIsClear) {
      move();
      recorre();
      move();
    } else {
      iterate (2) turnleft();
      while (leftIsBlocked && frontIsClear) move();
      if (leftIsClear) {
        turnleft();
        move();
        iterate (3) turnleft();
        while (frontIsClear) move();
        iterate (2) turnleft();
        recorre();
      } else {
        llegaEsquina();
      }
      iterate (2) turnleft();
      while (frontIsClear) move();
      iterate (2) turnleft();
    }
}
```

Así por cada columna que recorramos nos regresaremos una vez a la parte de abajo; en cada columna nos movemos la altura del mundo y regresaremos la misma cantidad de veces; y en cada casilla pondremos la misma cantidad de zumbadores que recogimos.

<details><summary>El siguiente código es la solución oficial:</summary>

{{solution.kj}}

</details>
