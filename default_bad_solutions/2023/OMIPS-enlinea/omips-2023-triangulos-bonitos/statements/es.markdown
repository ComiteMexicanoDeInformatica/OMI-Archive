![Ilustracion](ilustracion_doritos.jpeg)

Karel fue contratado como gerente de operaciones en la fabrica de Doritos. Él recibe cierta cantidad de masa, que es correspondiente al área que debe tener el dorito. Para posteriormente darle forma triangular.

Para que un dorito se apruebe, tiene que cumplir ciertas características.

- La masa no puede ser desperdiciada, es decir, toda debe ser utilizada.
- El dorito debe ser triangular.
- La diferencia entre la base y la altura del triángulo debe ser la menor posible.

Karel está agotado, así que te pidió que le hagas un programa que calcule qué medidas de la base y la altura debe tener para que se apruebe el dorito.

## Problema

Dada el área del dorito, Karel debe dejar dos montones de zumbadores en las primeras dos posiciones de la fila $1$ que representan la medida de la base y la altura para que el dorito sea aprobado.

## Ejemplo

![ejemplo_entrada](ejemplo1.jpeg)

![ejemplo_salida](salida.jpeg)

### Consideraciones

- Karel inicia en la posición (1,1) viendo al norte.
- Karel tiene zumbadores infinitos en la mochila.
- El montón de zumbadores con el área estará en la casilla (1,1).
- El montón de zumbadores iniciales no será mayor a 400.
- La altura y la base del triángulo deben estar en las dos primeras casillas de la fila $1$. No importa el orden.
- No importa la orientación ni posición final de karel.

### Subtareas

- (25 puntos): La diferencia entre base y altura no será tomada en cuenta, obtendrás los puntos si tu programa escribe una base y altura que formen un triángulo del área especificada.
- (25 puntos): Se te asegura que el área del triángulo es un número primo, es decir, sólo puede dividirse de manera exacta entre $1$ y él mismo.
- (25 puntos): El área del triángulo es la mitad de un número cuadrado, es decir, que tiene raíz cuadrada exacta como 4, 9, 16, 25, etc.
- (25 puntos): No hay consideraciones adicionales.
