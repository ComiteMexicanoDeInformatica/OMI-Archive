Karel quiere comprar un nuevo videojuego y para juntar dinero consiguió trabajo pintando pasillos. 

El pasillo que Karel va a pintar es de 1 casilla de ancho y puede tener vueltas. El principio del pasillo ya está pintando y Karel debe repetir el mismo patrón de colores hasta que todo el pasillo esté pintado. Cada color está representado por un monton de zumbadores.

# Problema

Ayuda a Karel a terminar de pintar todo el pasillo copiando el patrón inicial.

# Ejemplos

### Entrada

![Entrada1](sample.in.png)

### Salida

![Salida1](sample.out.png)

### Explicación

El patrón a repetir es [1, 2, 3, 4]

# Consideraciones

* Karel tiene infinitos zumbadores en la mochila
* Karel comienza en el inicio del pasillo orientado hacia donde este se dirige.
* El pasillo nunca se bifurcará.
* Los únicos zumbadores que hay en el pasillo son los del patrón.
* No importa la posición ni orientación final de karel.
* Karel debe pintar el pasillo completo, si el patrón no cabe un número exacto de veces, el último tramo deberá quedar pintado hasta llegar a la pared final.

# Subtareas
 * En el 67% de los puntos puedes usar la instruccion `avanza()` todas las veces que quieras.
 * En el 33% de los puntos restantes puedes usar la instrucción `avanza()` a lo mas $4N$ veces donde $N$ es la longitud del pasillo.
