![Ilustracion](Kalcetines_ilustracion.jpeg)

El cajón de los calcetines de Karel es un desastre, todos los calcetines están desordenados.

Karel necesita urgentemente encontrar un par de calcetines lo más parecidos posible, si se puede iguales, aun mejor.

En la primera fila del mundo, a partir de la segunda columna, hay montones de zumbadores. Cada montón representa un calcetín y el número de zumbadores en el montón representa el color. El parecido entre dos colores se determina mediante la diferencia de los números de ambos. Por ejemplo un calcetín de color $4$ se parece más a un calcetín de color $6$ (la diferencia entre ambos colores es $2$) que a un calcetín de color $1$ (la diferencia entre ambos colores es $3$).

Ayuda a Karel a encontrar el par de calcetines cuyo color sea el más parecido posible. Si hay múltiples opciones que tengan el mismo parecido, cualquiera de ellas que escojas será correcta.

Tu programa deberá dejar, en las dos primeras posiciones de la primera fila del mundo los calcetines elegidos.

# Problema

Escribe un programa que dado el cajón de calcetines con sus colores respctivos, deje en las primeras dos posiciones de la fila uno la pareja de calcetines más parecidos en color.

# Ejemplos

## Entrada

![Mundo de entrada](kalcetines.in.png)

## Salida

![Mundo de salida](kalcetines.out.png)

## Descripción

Hay dos parejas de calcetines con diferencia de color $0$, es decir, iguales. Las parejas son de color $3$ o de color $5$.

Cualquiera de ellas que pongas se considera correcta.

# Consideraciones

- Karel inicia en la posición (1, 1) orientado al norte.
- Karel lleva infinitos zumbadores en la mochila.
- El mundo de Karel es de $100 \times 100$.
- Sólo habrá zumbadores en la fila 1 del mundo.
- Los zumbadores de la fila 1 empiezan en la segunda columna.
- Los montones de la fila 1 pueden tener entre $1$ y $100$ zumbadores.
- No hay espacios vacíos entre los montones de zumbadores.
- **Para obtener los puntos, tu programa deberá dejar en las primeras dos posiciones de la fila 1 del mundo los calcetines elegidos.**

# Subtareas

En este problema, los casos de cada subtarea se encuentran agrupados. Para obtener el puntaje de una subtarea deberás resolver correctamente todos los casos del grupo.

- (25 puntos): Siempre hay al menos una pareja de calcetines del mismo color.
- (23 puntos): Los calcetines están ordenados de menor a mayor según su color.
- (26 puntos): Los calcetines de la solución tienen diferencia de color igual a $1$.
- (26 puntos): Sin restricciones adicionales.
