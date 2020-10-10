Karel está explorando la plaza principal del centro de Karelópolis y quiere saber cuáles caminos puede seguir para regresar a su casa.

En cada casilla se encuentra un montón de zumbadores entre 1 y 4, que le indica a Karel hacia dónde tiene que dar el siguiente paso.

Si en la casilla hay 1 zumbador, Karel debe avanzar hacia el norte.
Si en la casilla hay 2 zumbadores, Karel debe avanzar hacia el oeste.
Si en la casilla hay 3 zumbadores, Karel debe avanzar hacia el sur.
Si en la casilla hay 4 zumbadores, Karel debe avanzar hacia el este.

Un camino lleva a Karel a su casa si al seguirlo sale de la plaza principal.

Para no confundirse, Karel va a borrar los caminos que no le sirvan para volver a casa.

# Problema

Ayuda a Karel a borrar todos los caminos que no lo lleven a casa y a dejar intactos todos los que sí.

# Ejemplo

## Entrada

![entrada](sample.in.png)

## Salida

![salida](sample.out.png)

Explicación:

Cuando Karel llega a la casilla $(2,4)$ tiene que ir al sur, pero la casilla $(1,4)$ lo manda de regreso al norte. Entonces este camino no lleva a Karel a casa, porque no lo hace salir de la plaza.

# Consideraciones

- Karel inicia en la casilla $(1,1)$.
- Karel inicia viendo al norte.
- Karel tiene infinitos zumbadores en la mochila.
- Todos los montones de zumbadores son instrucciones válidas. Es decir, todas las casillas del mundo tienen entre 1 y 4 zumbadores.
- La plaza principal tiene forma rectangular y no tiene paredes intermedias.
- Si Karel está en una casilla junto a un montón de zumbadores que lo haría chocar con una pared. Significa que saldría de la plaza y se iría a su casa.
- Se evalúan todas las casillas del mundo.
- No importa la posición ni orientación final de Karel.
