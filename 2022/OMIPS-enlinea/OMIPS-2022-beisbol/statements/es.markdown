Karel se ha aficionado al beísbol y quiere que le ayudes a preparar un campo de juego en un terreno cercano a su casa.

Si nunca has jugado antes, un campo de beísbol tiene cuatro bases en forma de cuadrado y un montículo de pitcheo justo en el centro del mismo.

![Campo de béisbol](img/diamante-beisbol.webp)

Karel ya colocó las cuatro bases en forma de cuadrado, pero está teniendo problemas para ubicar el punto exacto dónde debe ir el montículo de pitcher. Es decir, el centro exacto del cuadrado. Ayuda a Karel a encontrar el lugar.

El mundo de Karel es un rectángulo sin paredes internas que representa el terreno. Las cuatro bases se representan con montones de 1 zumbador y están colocadas formando un cuadrado. El cuadrado de las bases puede estar paralelo a los lados del terreno (forma de cuadrado) o inclinado 45 grados (forma de rombo). Para que sea más claro observa los dos mundos de ejemplo.

# Problema

Escribe un programa que dadas las posiciones de las bases encuentre el centro del cuadrado y haga que Karel se apague justo en esa casilla.

# Ejemplos

## Entrada

Ejemplo de bases en forma de cuadrado

![Mundo de entrada](sample.in.png)

## Salida

![Mundo de salida](sample.out.png)

## Explicación

Karel debe apagarse en la casilla (5, 5) ya que este es el centro del cuadrado de las bases.

## Entrada

Ejemplo de bases en forma de rombo

![Mundo de entrada](sample_rombo.in.png)

## Salida

![Mundo de salida](sample_rombo.out.png)

## Explicación

Karel debe apagarse en el centro de las bases.

# Consideraciones

- Karel empieza en la casilla (1, 1) orientado al norte.
- En algunos casos de prueba Karel no tiene zumbadores en la mochila.
- Las cuatro bases pueden estar en cualquier lugar del mundo y siempre forman un cuadrado.
- Se asegura que siempre habrá una casilla que es el centro exacto del cuadrado.
- **No importa la orientación final de Karel**.
- **No importan los zumbadores que dejes en el mundo**.
- **Solo importa la posición final de Karel**

# Subtareas

**Nota:** Recuerda que _fila 1_ se refiere al renglón inferior del mundo.

- (30 puntos): Karel tiene **infinitos** zumbadores, al menos una de las bases está en la fila 1 y las bases están en forma de _cuadrado_.
- (10 puntos): Karel tiene **infinitos** zumbadores, las bases pueden estar en cualquier lugar y están en forma de _cuadrado_.
- (30 puntos): Karel tiene **infinitos** zumbadores, una de las bases está en la fila 1 y las bases están en forma de _rombo_.
- (15 puntos): Karel tiene **infinitos** zumbadores, las bases pueden estar en cualquier lugar y están en forma de _rombo_.
- (15 puntos): Karel **no tiene** zumbadores, las bases están en forma de _cuadrado_ o _rombo_.
