# Historia

Spider-Karel aprecia el vasto universo, tridimensional para nuestros ojos. En particular, admira las estrellas que hay en él. Una noche como cualquier otra, Spider-Karel sube a la azotea a presenciar las constelaciones del cielo estrellado.

Fascinado por la agrupación de estrellas, Spider-Karel anotó en su libreta la posición de cada una de ellas. Desafortunadamente, él anotó las coordenadas de cada estrella en desorden y ahora tiene que ordenarlas para registrarlas en su base de datos arácnida.

# Problema

Spider-Karel quiere ordenar en su libreta las estrellas por su posición. Cada estrella se localiza por coordenadas enteras $(X, Y, Z)$. Para saber si una estrella va antes que otra, simplemente comparamos componente a componente. Es decir, si tenemos dos estrellas identificadas por las coordenadas $(X_1, Y_1, Z_1)$ y $(X_2, Y_2, Z_2)$, entonces la estrella 1 va antes que la estrella 2 si y solo si ocurre uno de los siguientes casos:

* $X_1 < X_2$
* $X_1 = X_2$ y $Y_1 < Y_2$
* $X_1 = X_2$, $Y_1 = Y_2$ y $Z_1 < Z_2$

Ayuda a Spider-Karel a ordenar las estrellas de su libreta (considera que la libreta es el mundo de Karel). Inicialmente, Spider-Karel anotó en las primeras columnas, sin dejar espacios, las coordenadas de las estrellas. En la fila $1$ se encuentran las componentes $X$ de cada estrella; en la fila $2$, las componentes $Y$; por último, en la fila $3$, las componentes $Z$ (Véase ejemplo).


# Ejemplos

### Entrada

![Entrada1](entrada1.png)

### Salida

![Salida1](salida1.png)

### Explicación

Hay 5 estrellas con coordenadas (2, 1, 4), (3, 1, 1), (1, 1, 1), (2, 1, 3) y (3, 2, 4).

### Entrada

![Entrada2](entrada2.png)

### Salida

![Salida2](salida2.png)

### Explicación

Como las 3 estrellas tienen la misma posición $X$ y $Y$, el orden se da por la componente $Z$.

# Consideraciones

* Karel inicia en la casilla 1,1 viendo al norte.
* Karel inicia sobre la $X$ del primer punto a ordenar.
* Karel tiene infinitos zumbadores en la mochila.
* El mundo no tiene paredes internas.
* El alto y ancho del mundo siempre es 100.
* En la columna $i$, fila $1$, está la componente $X$ de la $i-ésima$ estrella. En la columna $i$, fila $2$, está su componente $Y$. Y en la columna $i$, fila $3$, su componente $Z$.
* No hay 2 estrellas con la misma coordenada $(X, Y, Z)$.
* Se evalúan todos los zumbadores del mundo. No debe haber otros montones de zumbadores aparte de los que representan la respuesta.
* Todas las $X$, $Y$, $Z$ son mayores o iguales a 1 y menores o iguales a 100.
* A lo más habrá 90 estrellas.

# Subtareas

* Para el 17% de los casos todos los puntos del mundo cumplen con $X = Y = Z$.
* Para el 24% de los casos todos los puntos del mundo tienen la misma $Z$.
* Para el 59% restante no hay consideraciones adicionales.
