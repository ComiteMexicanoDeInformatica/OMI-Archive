# Historia

Se han escuchado rumores de que Karel está muerto, pero en la logia de los matemágicos están convencidos de que eso no es verdad.

La realidad es que Roque el filósofo, uno de los maléficos archienemigos de los matemágicos, lo tiene encerrado en una cuadrícula y solo lo deja salir durante la OMI de primaria y secundaria.

Ante esto Karel no se ha rendido y hará todo lo posible por escapar. Roque el filósofo descubrió su plan y decidió abusar de su autoridad intimidándote y exigiéndote que evites que escape y lo castigues encerrándolo en una casilla.

La cuadrícula en la que Karel está encerrado tiene $N$ filas numeradas de 1 a $N$ (de arriba hacia abajo), y $N$ columnas, también numeradas del 1 a $N$ (de izquierda a derecha).

![Cuadricula](cuadricula.jpg)

Inicialmente Karel se encuentra en el centro de la cuadrícula, $N$ siempre será impar, por lo que siempre habrá una única casilla central, además no hay muros inicialmente en la cuadrícula.

En cada segundo Karel se puede mover a cualquiera de las 4 casillas adyacentes (o salir de la cuadrícula si se encuentra en una de las casillas que están en el borde de la misma) siempre y cuando no haya un muro obstruyendo su camino (esta vez Karel tiene prisa y no necesita gastar tiempo girando para empezar a caminar, por lo tanto puedes considerar que Karel puede girar sin consumir tiempo).

En cada segundo puedes agregar un muro en cualquier lugar de la cuadrícula. Tienes la ventaja de que el primer muro que pongas precede al primer movimiento de Karel (es decir, tu pones un muro, luego Karel se mueve una casilla, pones un segundo muro, Karel se mueve a otra casilla, etc.).

# Problema

Escribe un programa que atrape a Karel en una casilla (un rectángulo de 1x1) y evites así ser castigado por Roque el filósofo.

Recuerda que estamos en tiempos de austeridad, así que entre menos muros utilices para atrapar a Karel más puntos obtendrás.

# Entrada y Salida

**Este es un problema interactivo**, por lo que no tendrás que leer la entrada ni imprimir la salida, sino implementar en tu código la función `atrapando` y mandar llamar la función del evaluador `ponMuro` para completar tu tarea.

**Para obtener más información sobre los detalles de implementación de este problema debes revisar el texto del problema en la plataforma _OmegaUp_.**

# Implementación

## Tu función `atrapando()`

C/C++ `void atrapando(int N);`

Pascal `procedure atrapando(var N: LongInt);`

### Descripción

El evaluador buscará en tu código esta función y la llamará con el número $N$ como parámetro. Tu implementación deberá llamar a la función `ponMuro` para poner un muro en una casilla en específico, y esta misma función te dirá hacia dónde se mueve Karel.

### Parámetros

* `N`: Un entero indicando el tamaño de la cuadrícula.

## Función del evaluador `ponMuro()`

C/C++ `int ponMuro(int f, int c, int d);`

Pascal `function ponMuro(var f, c, d: LongInt):LongInt;`

### Descripción

Esta función coloca un muro al lado de la casilla que se encuentra en fila $f$ y columna $c$. El parámetro $d$ indica con un número del 1 al 4, en cual de las 4 aristas (de las que se encuentran alrededor de esa casilla) poner el muro:

![Orientacion de los muros 1:E 2:N 3:O 4:S](muros.jpg)

Luego de poner el muro, Karel se moverá en alguna de las 4 direcciones. La función regresará un entero del 1 al 4 indicando hacia cual de las 4 direcciones se movió:

![Direcciones de movimiento 1:E 2:N 3:O 4:S](direcciones.jpg)

La función regresará 0 en caso de que Karel se encuentre atrapado en la celda.

# Rutina de Ejemplo

A continuación se muestran las primeras llamadas de una rutina de ejemplo.

|| input

Función llamada

|| output

Valor devuelto

|| description

Descripción

|| input

atrapando(21)

|| output

-

|| description

Esta será la llamada inicial a tu procedimiento `atrapando`. El mundo mide $21x21$ y por lo tanto Karel se encuentra en la casilla $(11,11)$

|| input
ponMuro(11,11,2)

|| output

1

|| description

Muro fue colocado al norte de la casilla $(11,11)$. Karel se mueve al este a la casilla $(11,12)$.

|| input

ponMuro(11,12,1)

|| output

4
1
|| description

Muro fue colocado al este de la casilla $(11,12)$. Karel se mueve al sur la casilla $(12,12)$.

|| input

ponMuro(11,12,4)

|| output

1

|| description

Muro fue colocado al sur de la casilla $(12,12)$. Karel se mueve al este a la casilla $(12,13)$.

|| input

ponMuro(12,13,1)

|| output

4

|| description

Muro fue colocado al este de la casilla $(12,13)$. Karel se mueve al sur a la casilla $(13,13)$.

|| end

# Restricciones

$20 < N < 500$

# Consideraciones

* Debes encerrar a Karel en una casilla para atraparlo
* Siempre hay al menos una forma de atrapar a Karel
* Si Karel sale de la cuadricula obtendras 0 puntos en ese caso
* Si mandas llamar más de $100N$ veces la funcion ponMuro obtendrás 0 puntos
* Se garantiza que siempre recibirás una $N$ para la cual será posible atrapar a Karel
* Mientras menos muros pongas obtendrás más puntos
* $N$ siempre será un número impar

{{libinteractive:download}}
