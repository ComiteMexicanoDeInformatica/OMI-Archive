Karelópolis tiene muchos apagones y el gobernador solo tiene un generador para darle electricidad a una columna o una fila de la ciudad.

El número de zumbadores en cada casilla representa las personas que viven en una casa.

# Problema

Ayuda a Karel a saber en qué fila o columna del mundo debería poner el generador para darle electricidad al máximo de personas posibles.

Debes dejar el número máximo de personas a las que les puede dar electricidad en la casilla $(1, 1)$.

# Ejemplos

### Entrada

![Entrada](sample.in.png)

### Salida

![Salida](sample.out.png)

En este caso la fila 5 es la que mas personas tiene ($2 + 3 + 4 + 3 +4 + 999 = 1015$) por eso Karel tiene que dejar 1015 zumbadores en la casilla $(1, 1)$

# Consideraciones

- Karel inicia en la casilla $(1, 1)$.
- Karel inicia viendo al norte.
- La casilla $(1, 1)$ siempre está vacía.
- Karel tiene infinitos zumbadores en la mochila.
- La altura del mundo puede ser entre 1 y 99.
- El ancho del mundo puede ser entre 2 y 99.
- El mundo siempre es rectangular.
- No hay paredes internas en el mundo.
- Los montones de zumbadores pueden ser entre 1 y 1000.
- Sólo se evalúa cuántos zumbadores deja Karel en la casilla $(1, 1)$ al final.

# Subtareas

- En el 36% de los casos no hay zumbadores en la primer fila ni en la primer columna.
- En el 64% de los casos no hay consideraciones adicionales.
