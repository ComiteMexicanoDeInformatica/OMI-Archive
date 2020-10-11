Mario, el famoso fontanero rojo, se ha encontrado con un nuevo nivel. Este nivel tiene una forma rectangular de $N \times M$ casillas. Cada casilla puede o no tener una moneda (representado por un zumbador en el mundo de Karel), y cada que Mario llega a una casilla recoge una moneda si le es posible. Mario puede avanzar de una casilla a otra adyacente de un salto.

Cada que Mario salta las casillas que tenían una moneda ahora no la tendrán, y viceversa, las casillas que no tenían una moneda, ahora la tendrán.

Una vez que Mario recoge una moneda ya no aparecen nuevas monedas en esa casilla.

# Problema

Mario quiere recoger todas las monedas posibles, así que le ha pedido ayuda a su amigo Karel para que le diga cuál es la mayor cantidad de monedas que puede obtener y dejar la cantidad de monedas en la casilla $(1, 1)$.

# Ejemplo

## Entrada

![Ejemplo de Entrada](sample.in.png)

## Salida

![Ejemplo de Salida](sample.out.png)

En este ejemplo Mario puede recoger 3 monedas en la fila 1, 5 monedas en la fila 2 y 4 en la fila 3 por lo que Karel debe dejar 12 zumbadores en la casilla $(1, 1)$.

# Consideraciones

- Karel empieza en la casilla $(1,1)$ orientado al Norte.
- Karel tiene zumbadores infinitos en la mochila.
- No hay paredes internas en el mundo.
- El mundo representa la configuración inicial. Es decir, los zumbadores realmente no cambian cada que Karel avanza.
- Karel debe dejar en la posición $(1,1)$ la máxima cantidad de monedas que puede obtener Mario.
- No importa la orientación ni la posición final de Karel.
- Solo se evalúan los zumbadores que Karel deja en la casilla $(1,1)$.
