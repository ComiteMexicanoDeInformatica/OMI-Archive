Karel quiere llegar saltando hasta la parte superior del mundo y quiere saber cuál es la cantidad mínima de saltos que debe dar.

En cada columna del mundo hay trampolines representados por montones de zumbadores. Estos trampolines le permiten a Karel brincar en línea recta (es decir, subiendo en esa columna).
El número de cada montón le indica cuántas casillas al norte puede avanzar al brincar en ese trampolín.

Si la distancia del trampolín al techo es menor a la cantidad de zumbadores del trampolín, Karel no choca con el techo.

Si al dar un brinco Karel no llega exactamente a un nuevo trampolín, Karel cae hacia el sur hasta llegar de nuevo a algún trampolín. Observa que si Karel cae al mismo trampolín del que saltó, significa que no puede llegar al techo usando los trampolines de esa columna.

Para llegar al techo, Karel puede usar los trampolines de la columna que prefiera.

# Problema

Ayuda a Karel a calcular cuál es el número mínimo de saltos que debe dar para llegar al techo y a dejar ese número en la casilla $(1,1)$.

# Ejemplo

## Entrada

![Ejemplo de Entrada](sample.in.png)

## Salida

![Ejemplo de Salida](salida.in.png)

En la columna 2 la cantidad mínima de brincos es 2.
En este ejemplo todas las columnas llegan al techo; esto no es cierto en todos los casos.

# Consideraciones

- Karel empieza en la casilla $(1,1)$ viendo al Norte.
- No hay paredes internas.
- Karel no tiene zumbadores en la mochila.
- Karel siempre brinca en línea recta hacia el Norte.
- Todos los trampolines empiezan en la segunda fila.
- Puede haber columnas que no tienen suficientes trampolines para llegar al techo.
- Solo se evalúan los zumbadores finales de la casilla $(1,1)$.
- Un trampolín puede ser de tamaño 1 a 99.

# Subtareas

- Para el 48% de los casos los trampolines nunca te harán regresar.
- Para el 52% adicional no hay restricciones adicionales.
