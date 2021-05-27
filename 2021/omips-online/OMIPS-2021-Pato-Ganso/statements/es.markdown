Karel está jugando _Pato Ganso_. Todos sus amigos se paran en la orilla del mundo, formando un rectángulo.
Todos comienzan siendo patos (casillas vacías) y una vez que Karel les da un zumbador, se convierten en gansos.

Karel empieza en algún lugar de la orilla del mundo y el primer pato que revisa es el que está adelante de él.
Karel empieza a avanzar hacia donde está viendo inicialmente y sigue recorriendo la orilla del mundo, hasta que todos los patos sean gansos.

Para poder convertir un pato a ganso, Karel debe saltarse un pato (una casilla sin zumbador) y convertir en ganso al siguiente pato que se encuentre.

El juego termina cuando Karel convierte a todos en gansos (cuando toda la orilla del mundo tiene un zumbador).

# Problema

Karel debe jugar Pato Ganso y apagarse en la casilla donde convirtió al último pato en ganso.

# Ejemplo

## Entrada

![Ejemplo de Entrada](sample.in.png)

## Explicación

![Expliación ejemplo](explicacion.png)

En este caso karel tiene 18 zumbadores en la mochila, esto quiere decir que hay 18 jugadores. En la imagen puedes ver el orden que siguió Karel para convertir a todos los patos en gansos.

## Salida

![Ejemplo de Salida](sample.out.png)

La última casilla fue $(4, 6)$

# Consideraciones

- Karel empieza pegado a la pared de la orilla del mundo con la derecha bloqueada y el frente libre.
- Karel tiene en su mochila los zumbadores exactos para poner un zumbador en cada una de las casillas de la orilla del mundo.
- La altura del mundo puede ser entre 2 y 100.
- El ancho del mundo puede ser entre 2 y 100.
- El mundo siempre es rectangular.
- No hay paredes internas en el mundo.
- No hay zumbadores en el mundo.
- Solo se evalúa la posición final de Karel.
