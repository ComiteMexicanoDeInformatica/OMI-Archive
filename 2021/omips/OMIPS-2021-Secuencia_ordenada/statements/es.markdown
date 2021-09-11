Desde pequeño a Karel le gustaba jugar con números, en particular con _secuencias ordenadas_ de números. Una _secuencia ordenada_ es una lista de números ordenados de chico a grande.

Karel tiene una lista desordenada de $N$ números y quiere ver si puede usarla para construir una _secuencia ordenada_. Para que sea divertido, Karel decide que el único movimiento válido es el siguiente:

- Karel puede tomar el número en el extremo izquierdo o el extremo derecho de su lista, quitarlo y ponerlo al final de la secuencia que está construyendo.

A Karel le interesa saber si la lista que tiene le servirá para construir una _secuencia ordenada_.

# Problema

Ayuda a Karel a determinar si la lista que tiene le servirá para construir una _secuencia ordenada_ y se quede orientado al norte en caso de que sí y orientado al sur en caso de que no.

# Ejemplo

## Entrada

![Entrada 1](entrada1.png)

En este mundo de ejemplo Karel **si puede** formar una secuencia ordenada, en específico la secuencia: $1, 1, 2, 2, 3, 5, 6, 7$, por lo que debe **terminar viendo al NORTE.**

## Entrada

![Entrada 2](entrada2.png)

En este mundo de ejemplo Karel **NO puede** formar una secuencia ordenada, por lo que debe **terminar viendo al SUR.**

# Consideraciones

- Karel empieza en la casilla (1, 1) orientado al norte.
- Karel tiene infinitos zumbadores en la mochila.
- La lista de números está representada por montones de zumbadores en la fila $1$ y empieza en la casilla (1, 1).
- No hay espacios vacíos entre los números.
- Los números de la lista están entre $1$ y $99$.
- Para la evaluación sólo importa la orientación final de Karel.

# Subtareas

- **(57 puntos):** Karel puede avanzar una cantidad ilimitada de veces.
- **(43 puntos):** Karel puede avanzar a lo mas $N$ veces donde $N$ es la cantidad de números en la lista.
