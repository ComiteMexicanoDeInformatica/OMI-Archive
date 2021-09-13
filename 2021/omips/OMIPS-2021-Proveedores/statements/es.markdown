Tal vez no lo sabías, pero Karel es un exitoso empresario.

La empresa de Karel requiere de $M$ tipos de productos y se los compra a $N$ proveedores distintos. Dependiendo del proveedor, la empresa de Karel puede comprarle desde uno de los tipos de producto hasta los $M$. Si para un tipo de producto Karel tiene sólo un proveedor, le llama _proveedor único_. Es decir, un _proveedor único_ es aquel que le vende un tipo de producto que ningún otro proveedor le vende.

A Karel no le gusta tener _proveedores únicos_ ya que le venden muy caro. Recientemente pidió su _lista de proveedores_ y quiere que le ayudes a revisarla.

El mundo de Karel es un rectángulo sin paredes internas de $N + 1$ filas de alto y $M + 1$ columnas de ancho. La _lista de proveedores_ está representada en el mundo de la siguiente forma:

- Cada fila, a partir de la segunda **(la primera fila está vacía)**, representa un proveedor.
- Cada columna, a partir de la segunda **(la primera columna está vacía)**, representa un producto.
- Un montón de $1$ zumbador indica que el proveedor representado en esa fila, vende el producto representando en esa columna.

# Problema

Ayuda a Karel a contar ¿cuántos _proveedores únicos_ tiene su empresa? y dejar un montón de zumbadores con ese número en la casilla (1, 1).

# Ejemplo

## Entrada

![Entrada 1](entrada1.png)

## Salida

![Salida 1](salida1.png)

Observa que para el segundo, cuarto y sexto producto (ordenando de izquierda a derecha) existe sólo un proveedor.

# Consideraciones

- Karel empieza en la casilla (1, 1) orientado al norte.
- Karel tiene infinitos zumbadores en la mochila.
- El mundo de Karel es de $N + 1$ filas por $M + 1$ columnas.
- No hay paredes internas en el mundo.
- $1 \leq N, M \leq 99$.
- Para la evaluación sólo importa la cantidad de zumbadores que dejes en la casilla (1, 1).
