Karel estaba corriendo una carrera en la que corrió tan rápido que salió girando del circuito. Como dio muchas vueltas, ahora no sabe dónde está. Karel te pide que vayas por él para llevarlo a su casa. Para saber a dónde pasar por él, necesitas saber si está rodeado por el circuito de la carrera o fuera de él.

El circuito donde fue la carrera es un ciclo simple con montones de $1$ zumbador, en el cual sin importar el lugar donde empieces, si caminas sobre el circuito, volverás al lugar donde empezaste sin pasar por ninguna pared. El circuito mide una casilla de ancho y además está por lo menos a una casilla de distancia de las paredes del mundo.

Este es un circuito **válido**:

![circuito válido](sample.in.png)

Estos son circuitos **inválidos**:

![circuito inválido 1](invalid1.in.png)

Este circuito **inválido** tiene zumbadores con más de $2$ zumbadores adyacentes.

![circuito inválido 2](invalid2.in.png)

Este circuito **inválido** no tiene espacio entre los zumbadores y la pared del sur.

# Problema

Si Karel está por fuera del circuito, debe apagarse orientado al norte. Si está rodeado por el circuito, debe apagarse orientado al sur.

# Ejemplo

## Entrada

![Ejemplo de Entrada](sample.in.png)

## Salida

![Ejemplo de Salida](sample.out.png)

# Consideraciones

- Karel empieza en una orientación y casilla arbitrarias.
- No hay zumbadores en la posición inicial de Karel.
- No hay paredes en el mundo.
- El mundo nunca excede $50 \times 50$.
- No hay zumbadores en la orilla del mundo.
- Los únicos zumbadores en el mundo son los que forman parte del circuito.
- Sólo se evalúa la orientación final de Karel.
- Los casos están agrupados en pares.

# Subtareas

- **(37 puntos)**: Karel tiene infinitos zumbadores en la mochila.
- **(63 puntos)**: Karel no tiene zumbadores en la mochila.
