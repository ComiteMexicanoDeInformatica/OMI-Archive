La numeración biyectiva es un sistema en que todos los enteros positivos pueden ser representados de exactamente una forma.

La numeración biyectiva base 26 usa el alfabeto para representar 26 dígitos del 1 al 26
(A=1, B=2, C=3, ..., Z=26, AA=27, AB=28, ...). En la numeración biyectiva 26 no se usa
la letra Ñ.

Esta numeración se usa en las hojas de cálculo.

# Problema

Escribe un programa que convierta un entero de sistema decimal a una cadena que representa su valor biyectivo 26 y viceversa.

# Entrada

En la primera línea un entero $T$ que indica el tipo de conversión que vas a hacer (0 = de decimal a cadena, 1 = de cadena a decimal)
En la segunda línea un entero $X$ o una cadena $S$ dependiendo del tipo de conversión.

# Salida

La cadena $S$ que representa a $X$ si la conversión es de tipo 0, o el entero $X$ que representa
a la cadena $S$ si la conversión es de tipo 1.

# Ejemplo

||input
1
AZ
||output
52
||input
0
10487
||output
OMI
||input
1
ABC
||output
731
||end

# Límites

* $1 \leq X < 2^{63}$.
* La longitud de la cadena $S$ es menor que 15.

# Subtareas

* En el 50% de los casos $T=0$.
* En el 50% restante $T=1$.
