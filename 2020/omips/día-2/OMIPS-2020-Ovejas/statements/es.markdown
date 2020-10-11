Recientemente Karel se hizo un pastor, y como buen pastor debe cuidar de todo su rebaño. Sin embargo, las ovejas son muy traviesas y por ello Karel debe vigilarlas a todas estando lo más cerca posible de cada una de ellas. Karel ha pedido tu ayuda para encontrar la posición tal que la oveja más lejana esté los más cerca posible a Karel.

La distancia entre una oveja y Karel se define como la cantidad de “avanza” o “move” necesarios para llegar a dicha oveja (ver el caso de ejemplo).

Karel está en un rectángulo delimitado por paredes el cual representa la cerca de su rebaño. En el rectángulo hay algunos montones de 1 zumbador que representan a sus ovejas. Karel debe apagarse en una posición que cumpla que la distancia a la oveja más lejana sea la menor posible.

En caso de que hayan varias posiciones que cumplan esto, deben elegir la posición más al oeste. Si aun hay empate entonces la más al sur.

# Ejemplo

## Entrada

![Ejemplo de Entrada](sample.in.png)

## Salida

![Ejemplo de Salida](output.in.png)

## Explicación

Aquí por ejemplo, la distancia a la oveja en $(5,5)$ es 2, y la máxima distancia a una oveja es 3. No hay otra posición que haga menor este número.

# Consideraciones

- Karel empieza en la casilla $(1,1)$ viendo al norte.
- No hay paredes internas en el mundo.
- Karel tiene infinitos zumbadores en la mochila.
- Solo se evalúa la posición final de Karel.

## Subtareas

- **(18 puntos)**: el mundo es de 1 de alto.
- **(31 puntos)**: hay a lo más $2$ zumbadores en el mundo.
- **(51 puntos)**: no hay consideraciones adicionales.
