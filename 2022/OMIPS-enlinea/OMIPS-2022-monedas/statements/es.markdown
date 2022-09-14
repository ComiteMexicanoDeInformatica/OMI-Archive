El abuelo de Karel tiene una colección de monedas antiguas. Todos los días el abuelo saca **un número par** de sus monedas, las coloca en una fila y se pone a limpiarlas.

El día de hoy, mientras limpiaba sus monedas, tuvo que salir a realizar un mandado. Darel el travieso hermano de Karel, no pudo evitar la tentación de ponerse a jugar con las monedas y desacomodó toda la fila. Darel sabe que el abuelo no tarda en llegar y si las monedas están desacomodadas lo va a regañar. Darel volvió a colocar las monedas en una fila, pero quiere que le ayudes a verificar si el acomodo es correcto y si no lo es, que le ayudes a arreglarlo.

Tú sabes que el abuelo ya no ve bien y lo único que distingue es si la moneda está del lado del _águila_ o del lado del _sol_. También sabes que el abuelo sólo se fija en las siguientes dos condiciones:

- Si el abuelo se fija en una **cantidad par** de monedas empezando **del extremo izquierdo de la fila,** la cantidad de _soles_ y _águilas_ debe ser la misma.
- Si el abuelo se fija en una **cantidad par** de monedas empezando **del extremo derecho de la fila,** la cantidad de _soles_ y _águilas_ debe ser la misma.

El mundo de Karel es un rectángulo sin paredes internas. En la fila 1, a partir de la segunda columna, hay montones de zumbadores que representan la fila de monedas que colocó Darel. Un montón con un zumbador representa un _águila_ y un montón con dos zumbadores representa un _sol_.

# Problema

Escribe un programa que ayude a Darel a determinar si su acomodo es correcto. En caso de que el acomodo no sea correcto, tu programa deberá corregirlo volteando el número mínimo de monedas necesario, además deberá dejar, en la casilla (1, 1) una cantidad de zumbadores igual al número de monedas que volteó.

# Ejemplos

## Entrada

![Mundo de entrada](sample.in.png)

## Salida

![Mundo de salida](sample.out.png)

## Descripción

Darel dejó la fila {_águila_, _águila_, _sol_, _sol_} por lo que el abuelo se dará cuenta de que la desacomodaron. Hay varias formas de acomodarla de nuevo, una forma es dejarla {_águila_, _sol_, _águila_, _sol_} la cual requiere que voltees dos monedas. No existe ninguna forma de arreglar la fila haciendo menos de dos cambios.

# Consideraciones

- Karel empieza en la casilla (1, 1) orientado al norte.
- Karel lleva infinitos zumbadores en la mochila.
- La fila de monedas empieza en la segunda columna y siempre contiene un número par de montones.
- No hay espacios vacíos entre las monedas.
- **La fila de monedas puede llegar hasta la pared este del mundo.**
- **No importa la posición ni la orientación final de Karel**.
- **En cada subtarea obtendrás puntos por las siguientes cosas:**
  - Si dejas la fila acomodada de modo que el abuelo no se de cuenta que la movieron, recibirás el 10% de los puntos de la subtarea.
  - Si dejas la fila acomodada con un número mínimo de cambios, recibirás un 40% extra de puntos de la subtarea.
  - Si además de dejar la fila correcta con un mínimo de cambios, dejas en la casilla (1, 1) el número de cambios que hiciste, recibirás el 50% faltante de los puntos.

# Subtareas

- (50 puntos): El mundo de Karel tiene altura 1.
- (50 puntos): Sin restricciones.
