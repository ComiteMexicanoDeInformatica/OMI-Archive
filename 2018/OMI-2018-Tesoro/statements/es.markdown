La leyenda dice que el tesoro de Moctezuma está enterrado en el Centro Histórico de la Ciudad de México. El Centro Histórico está representado como una cuadrícula de $n$ filas y $m$ columnas. Gracias a la tecnología de la nueva app iFind puedes desenterrarlo por fin.

iFind es una app donde especificas una casilla $(i,j)$ de la cuadrícula y la app responde cuántos
tesoros hay enterrados en el área del rectángulo que abarca de la fila $1$ a la fila $i$
y de la columna $1$ a la columna $j$.

Una vez que sabes la casilla exacta donde hay un tesoro debes cavar en esa posición para desenterrarlo.

Se asegura que cada casilla solo puede tener $0$ o $1$ tesoro y que no hay más de $1$ tesoro en cada columna.

# Problema
Escribe un programa que dados $n$ y $m$, el alto y ancho de la cuadrícula y $k$, el número total de tesoros enterrados, desentierre los $k$ tesoros usando la menor cantidad posible de preguntas a la app.

# Entrada y Salida
**Este problema es interactivo**, por lo que no tendrás que leer la entrada ni imprimir la salida, sino implementar en tu código la función `BuscaTesoros` y mandar llamar las funciones del evaluador `Preguntar` y `Cavar` para completar tu tarea.

Internamente el evaluador llevará el registro de cuántos tesoros quedan. Tu programa no necesitará imprimir ni devolver nada: solo asegurarse de que hayas desenterrado los $k$ tesoros usando la función `Cavar`.

# Implementación
## Tu procedimiento `BuscaTesoros()`
`void BuscaTesoros(int n, int m, int k);`

### Descripción
El evaluador buscará en tu código esta función y la llamará con los parámetros `n`, `m` y `k`. Tu implementación deberá utilizar las funciones `Preguntar` y `Cavar` para desenterrar todos los tesoros. En cada caso de prueba **solo se llamará a esta función una vez**.

### Parámetros
+ `n`: Filas de la cuadrícula.
+ `m`: Columnas de la cuadrícula.
+ `k`: El número de tesoros enterrados.

### Límites
 * $1 \leq n, m \leq 1000$
 * $1 \leq k \leq m$

## Función del evaluador `Preguntar()`
`int Preguntar(int i, int j);`.

### Descripción
Esta función recibe como parámetros las coordenadas (i,j) de la casilla y regresa la cantidad de tesoros que hay en el rectángulo de (1,1) a (i,j).

Si las coordenadas se encuentran fuera de la cuadrícula, la función devolverá `-1`.

### Parámetros
* `i`: La fila máxima del rectángulo.
* `j`: La columna máxima del rectángulo.

## Función del evaluador `Cavar()`
`bool Cavar(int i, int j);`.

### Descripción
Usa esta función cuando quieras desenterrar el tesoro de la casilla (i,j).

Si las coordenadas se encuentran fuera del área de cobertura la función devolverá `false`.
También, si intentas desenterrar en una casilla donde no hay tesoro la función devolverá `false`.
En ambos casos, además obtendrás 0 puntos en ese caso de prueba.

**Nota:** Una vez que desentierres un tesoro, no debes volver a llamar `Cavar` en la misma casilla,
u obtendrás 0 puntos en ese caso de prueba.

### Parámetros
* `i`: La fila de la casilla.
* `j`: La columna de la casilla.

# Rutina de Ejemplo
|| input
Función llamada
|| output
Valor devuelto
|| description
Descripción
|| input
BuscaTesoros(5,5,5)
|| output
-
|| description
Esta será la llamada inicial a tu procedimiento `BuscaTesoros`.
|| input
Preguntar(5,5)
|| output
5
|| description
Consultas el número de tesoros que hay en toda la cuadrícula y verificas que, en efecto, existen 5 tesoros.
|| input
Preguntar(4,4)
|| output
3
|| description
Descubres que hay 2 tesoros de diferencia entre el rectángulo (1,1), (5,5) y el (1,1), (4,4).
|| input
Cavar(5,5)
|| output
false
|| description
Intentas cavar en la casilla (5,5) pero no hay un tesoro ahí.
Tu programa obtiene 0 puntos por cavar en un lugar donde no hay tesoro.
|| input
Cavar(6,4)
|| output
false
|| description
Intentas cavar fuera de la cuadrícula y la función devuelve `false` porque no pudo.
Tu programa obtiene 0 puntos por cavar en un cuadro fuera de la cuadrícula.
|| end

# Experimentación
{{libinteractive:download}}

El evaluador de prueba recibe el archivo `sample.in` con los valores $n$, $m$ en la primera línea. En las siguientes $n$ líneas hay $m$ caracteres indicando 1 si hay tesoro en esa casilla o 0 si no.

Para el caso de ejemplo anterior, `sample.in` se vería de la siguiente manera:

|| input
5 5
01000
10001
00100
00000
00010
|| end

Puedes modificar el contenido de `sample.in` para probar distintos casos con tu solución.

Durante la ejecución, el evaluador de prueba imprimirá algunos mensajes para ayudarte a depurar tu solución. Al finalizar la ejecución de tu función, el evaluador de prueba imprimirá la cantidad de veces que llamaste a la función `Preguntar`, seguido de un mensaje que te dirá si lograste desenterrar todos los tesoros o no.

**IMPORTANTE:** El evaluador de prueba y el evaluador final que se usará para calificar tu solución son diferentes. El evaluador de prueba tiene la intención de facilitar la depuración de tu solución y puede implementar algunas de sus funciones de manera ineficiente. Sin embargo, puedes asumir con seguridad que **el tiempo de ejecución del evaluador final no afectará el tiempo total de tu solución**. 

Tu puntaje se decidirá dependiendo del número de veces que mandaste a llamar la función `Preguntar`. Mientras que hagas una cantidad de preguntas menor o igual a las de la solución oficial, recibirás 100 puntos. En caso que llames a la función `Preguntar` más de $nm$ veces o realices una llamada inválida, recibirás 0 puntos.
