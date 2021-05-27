Un día, Karel y sus amigos estaban muy aburridos. Tras pasar un rato pensando en un nuevo juego, sus amigos tuvieron una idea. En el mundo esconderían un tesoro y después le dejarían instrucciones a Karel sobre el camino que debe seguir para encontrarlo.

Karel empieza en la casilla $(1, 1)$ del mundo. Las instrucciones están ubicadas en las primeras 2 columnas y Karel debe seguirlas en orden de abajo hacia arriba. Las instrucciones dependen de la cantidad de zumbadores que hay en un renglón: en la primera columna está la dirección hacia la que Karel debe avanzar y en la segunda columna está la cantidad de pasos que debe dar. **Por ejemplo**, en la casilla $(1, 1)$ está la primera dirección en la que debe moverse Karel y en la casilla $(2, 1)$ está la cantidad de pasos que debe avanzar en esa dirección.

La dirección depende del número de zumbadores en las casillas de la primer columna:

- `1` zumbador: Karel debe moverse hacia el norte.
- `2` zumbadores: Karel debe moverse hacia el oeste.
- `3` zumbadores: Karel debe moverse hacia el sur.
- `4` zumbadores: Karel debe moverse hacia el este.

# Problema

Ayuda a que Karel siga todas las instrucciones y se apague en la posición del tesoro.

# Ejemplo

## Entrada

![Ejemplo de Entrada](sample.in.png)

## Salida

![Ejemplo de Salida](sample.out.png)

## Explicación

Este es el camino que recorrió Karel siguiendo las instrucciones para llegar al tesoro.

![Camino](CaminoKarel.jpeg)

# Consideraciones

- Karel empieza en la casilla $(1, 1)$ viendo hacia el norte.
- Karel no tiene zumbadores en la mochila.
- La altura del mundo puede ser entre $2$ y $100$.
- El ancho del mundo puede ser entre $2$ y $100$.
- Las únicas paredes son las que delimitan al mundo.
- Las instrucciones nunca te harán chocar con una pared.
- No hay renglones vacíos entre instrucciones.
- La cantidad de instrucciones siempre es menor a la altura del mundo.
- Solo se evalúa la posición final de Karel.

# Subtareas

- $15$ puntos: Los montones en la segunda columna (la cantidad de pasos) son de $1$ zumbador.
- $15$ puntos: Hay a lo más un renglón de cada orientación.
- $70$ puntos: No hay consideraciones adicionales.
