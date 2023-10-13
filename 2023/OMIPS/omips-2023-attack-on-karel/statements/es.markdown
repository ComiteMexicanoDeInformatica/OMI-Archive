![Ilustracion](Ilustracion.jpeg)

El _estruendo_ ha empezado y los _titanes_ vienen a atacar Karelotitlán.

Los _titanes_ son gigantes hechos de zumbadores que avanzan en fila aplastando todo a su paso. Un _titán_ se representa como un montón de zumbadores, el número de zumbadores en el montón representa su altura.

Por suerte, Levi Karelman el campeón de Karelotitlán, está entre los defensores. Levi puede derrotar a cualquier _titán_. Pero tiene una limitante, sólo puede derrotar _titanes_ cuya altura sea mayor al punto dónde él se encuentra. Para derrotar a un _titán_, Levi debe subir hasta su cabeza. Los titanes vienen en fila y Levi no tiene espacio para bajar cada que derrota a un _titán_, por lo tanto, Levi decidió seguir el siguiente algoritmo:

- Levi derrotará al primer _titán_ de la fila.
- A partir de ese momento, Levi derrotará al siguiente _titán_ en la fila que sea más alto que el último _titán_ que haya derrotado.

Escribe un programa que dada la fila de de _titanes_ y sus alturas cuente ¿a cuántos _titanes_ derrotará Levi?

En la primera fila del mundo, a partir de la segunda columna, habrá montones de zumbadores que representan la fila de _titanes_. El número en cada montón representa la altura del _titán_.

# Problema

Escribe un programa que dada la fila de _titanes_ deje en la posición (1, 1) un montón de zumbadores igual al número de titanes a los que derrotará Levi siguiente el algoritmo descrito.

# Ejemplos

## Entrada

![Mundo de entrada](entrada.png)

## Salida

![Mundo de salida](attack-out.png)

## Descripción

Al derrotar al primer _titán_, Levi queda a una altura de $3$, ahora sólo puede derrotar _titanes_ más altos que eso. El siguiente _titán_ más alto mide $5$, luego hay uno de $6$ y finalmente uno de $7$.

Por lo tanto, Levi derrotó a $4$ _titanes_.

# Consideraciones

- Karel inicia en la posición (1, 1) orientado al norte.
- Karel lleva $0$ zumbadores en la mochila.
- El mundo de Karel es de $100 \times 100$.
- Sólo habrá zumbadores en la fila 1 del mundo.
- Los montones de la fila 1 pueden tener entre $1$ y $99$ zumbadores.
- No hay espacios vacíos entre los montones de zumbadores.
- **Para obtener los puntos, tu programa deberá dejar en la posición (1, 1) un montón igual a la cantidad de _titanes_ eliminados.**

# Subtareas

En este problema, los casos de cada subtarea se encuentran agrupados. Para obtener el puntaje de una subtarea deberás resolver correctamente todos los casos del grupo.

- (10 puntos): La altura de los _titanes_ es estríctamente creciente, cada _titán_ en la fila es más alto que el anterior.
- (20 puntos): Sólo hay $2$ _titanes_ en la fila.
- (28 puntos): La altura de los _titanes_ no decrece, es decir, cada _titán_ en la fila es mayor o igual en altura al anterior.
- (42 puntos): Sin restricciones adicionales.
