Karel va viajar a la Ciudad de México y está muy emocionado ya que visitará Six Arrows, un parque de diversiones donde se pueden encontrar muchos juegos mecánicos y atracciones como “The Super Karelman”, “Mr Kareltastic: The Ride”, y “Recuerda de dónde saliste”, famosas por hacer sentir mucha adrenalina.

La nueva atracción “Para-k-idista”, a la cual Karel desea subirse, consiste en aventarse desde alguna posición en el mundo. En cada segundo, debido a la caída, se mueve una fila hacia abajo. De igual forma, en cada segundo se puede mover horizontalmente a la columna de la izquierda, a la columna de la derecha, o quedarse sobre la misma columna. Es decir, si Karel se encuentra en alguna posición en el mundo, se puede mover a las casillas de color verde mostradas en la siguiente imagen.

![Movimientos](movimientos.png)

# Problema

Karel caerá en una pista representada por la fila $1$. A lo largo de la pista se encuentran trampolines representados por zumbadores. La función de los trampolines es asegurar que la caída sea suave. Debido a que la atracción es nueva, Karel teme  que desde el punto donde va a descender no pueda caer sobre un trampolín.

Ayuda a Karel a saber si podrá tener una caída suave en la atracción. Deberás orientar a Karel al norte si es posible que caiga sobre uno de los trampolines, u orientarlo al sur en caso contrario.

# Ejemplo

### Entrada

![Entrada](in.png)

### Salida

![Salida](out.png)


# Consideraciones

* Karel inicia sobre la posición donde empieza a caer viendo al sur.
* Karel no tiene zumbadores en la mochila.
* Karel nunca inicia en la fila $1$.
* El mundo de Karel tendrá una altura y un ancho desconocidos.
* Las únicas paredes son las que delimitan el mundo.
* Solo importa la orientación final de Karel.
