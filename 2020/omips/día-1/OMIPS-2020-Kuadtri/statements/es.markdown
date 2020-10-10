Karel fue a visitar a su primo Kuadtri. En la ciudad de su primo, numeran las casillas de manera distinta.

La ciudad de Kuadtri siempre es un cuadrado donde sus lados miden alguna potencia de 2.

Toda la ciudad se considera como la región 0 y se divide a la mitad horizontal y verticalmente dejando 4 nuevas regiones cuadradas.

A cada región se le asigna un número consecutivo, empezando por el número siguiente al último asignado.

El orden de asignación es el siguiente:

1.  Región inferior izquierda.
2.  Región inferior derecha.
3.  Región superior izquierda.
4.  Región superior derecha.

Este proceso se repite en todas las regiones en el mismo orden hasta que todas las regiones sean de 1 casilla.

![Ejemplo de Entrada](explanation.png)

En la imagen anterior se muestra una ciudad de $4 \times 4$ y cómo se ve la numeración en cada división.

# Problema

Ayuda a Karel a encontrar dónde vive su primo Kuadtri, dado el número de su región.

Karel debe leer de la casilla $(1, 1)$ el número de la casa de Kuadtri y apagarse en la casilla correspondiente, siguiendo la númeración definida.

# Ejemplo

## Entrada

![Ejemplo de Entrada](sample.in.png)

## Salida

![Ejemplo de Salida](sample.out.png)

# Consideraciones

- Karel empieza en al casilla $(1,1)$ orientado al norte.
- Solo hay zumbadores en la casilla $(1,1)$.
- Se asegura que el montón de zumbadores en la $(1,1)$ siempre representará una región válida.
- Karel tiene infinitos zumbadores en la mochila.
- El mundo siempre será un cuadrado de lado $2^n$, para algún entero $n$.
- No hay paredes internas en el mundo.
- El ancho y alto del mundo es mínimo 2 máximo 100.
- No importa la orientación final de karel.
- Solo se evalúa la posición final de Karel.

# Subtareas

# Subtareas

- **(33 puntos)**: El mundo es de $8 \times 8$ y conoces los zumbadores que habrán en la casilla $(1, 1)$ de 5 casos de prueba:
  - 35
  - 44
  - 56
  - 62
  - 71
- **(67 puntos)**: No hay consideraciones adicionales.
