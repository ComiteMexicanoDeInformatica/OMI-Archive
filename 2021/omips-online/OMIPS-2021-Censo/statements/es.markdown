El conteo de población llegó al mundo de Karel. Debes contar las personas que hay en un edificio.

El mundo de Karel representa un edificio. Cada renglón es un piso y los zumbadores representan personas. Además, el mundo
tiene paredes verticales que dividen los departamentos de ese piso.

# Problema

Escribe un programa que ayude a Karel a contar cuántas personas viven en cada piso del edificio y dejar la respuesta en la primer columna.

# Ejemplo

## Entrada

![Ejemplo de Entrada](sample.in.png)

## Salida

![Ejemplo de Salida](sample.out.png)

## Explicación

En este ejemplo el edificio mide $5 \times 5$. Karel contó a todas las personas de cada piso y puso los resultados en las casillas de la primera columna. Como en el renglón 4 no hay zumbadores, Karel dejó la casilla $(1, 4)$ vacía.

# Consideraciones

- **Desconoces la ubicación y orientación inicial de Karel.**
- La altura del edificio puede ser entre $1$ y $100$.
- El ancho del edificio puede ser entre $1$ y $100$.
- Solo hay paredes **verticales** en el edificio.
- Se asegura que se puede llegar a todas las casillas del edificio.
- Se asegura que en cada piso no viven mas de $99$ personas.
- No importa la posición ni orientación final de Karel.
- Solo se evalúan los zumbadores en la primera columna.

# Subtareas

- **(50 puntos)**: Karel no tiene zumbadores en la mochila.
  - **(10 puntos)**: Todos los montones son a lo más de tamaño 1.
  - **(10 puntos)**: Solo hay un renglón con zumbadores.
  - **(10 puntos)**: A lo más solo hay un montón por renglón.
  - **(20 puntos)**: Ninguna consideración extra.
- **(50 puntos)**: Karel tiene infinitos zumbadores en la mochila.
  - **(10 puntos)**: Todos los montones son a lo más de tamaño 1.
  - **(10 puntos)**: Solo hay un renglón con zumbadores.
  - **(10 puntos)**: A lo más solo hay un montón por renglón.
  - **(20 puntos)**: Ninguna consideración extra.
