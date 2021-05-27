Enola le pide ayuda a Karel para descifrar un mensaje secreto. Enola tiene un diccionario y un mensaje escrito en clave, para poder descifrarlo, debes utilizar el diccionario.

El diccionario son varios montones de zumbadores en la fila $1$, empiezan en la casilla $(1,1)$ y termina justo antes de la única pared dentro del mundo. El mensaje secreto empieza a la derecha de donde termina el diccionario.

Cada letra del diccionario está en la columna con el número que reemplaza a esa letra en el mensaje secreto. Por ejemplo, si en la columna $1$ hay $5$ zumbadores, entonces todos los montones de $5$ zumbadores del mensaje secreto se deben cambiar por montones de $1$ zumbador, si en la columna $3$ hay $4$ zumbadores, todos los montones de $4$ zumbadores se deben cambiar por montones de $3$ zumbadores.

**Te recomendamos que veas la explicación del ejemplo para que te quede mas claro**

El mensaje puede tener letras que no están en el diccionario, eso significa que son un espacio y debes dejar esa casilla vacía.

# Problema

Ayuda a Karel a usar el diccionario para reemplazar el mensaje secreto con el mensaje descifrado.

# Ejemplo

## Entrada

![Ejemplo de Entrada](sample.2x13.in.png)

## Salida

![Ejemplo de Salida](salida1.png)

## Explicación

En este ejemplo el diccionario es `5,3,2,4,1`. Esto quiere decir que en el mensaje secreto tienes que cambiar los montones de $5$ zumbadores por montones de $1$ zumbador, porque el $5$ esta en la columna $1$, los montones de $3$ zumbadores por montones de $2$ zumbadores, los montones de $2$ zumbadores por montones de $3$, los montones de $4$ zumbadores se quedan igual y los montones de $1$ zumbador se cambian por montones de $5$ zumbadores.

## Entrada 2

![Ejemplo de Entrada 2](sample1.2x10.in.png)

## Salida 2

![Ejemplo de Salida 2](salida2.png)

## Explicación

Este ejemplo usa el mismo diccionario que el ejemplo anterior pero en este mensaje hay un $6$ que no está en el diccionario, por eso la salida es `1 0 5 5`.

# Consideraciones

- Karel empieza en la casilla $(1,1)$ viendo al norte.
- Karel tiene zumbadores infinitos en la mochila.
- El mundo siempre es de $100 \times 100$.
- Solo hay una pared de 1 de alto que indica la separación entre el diccionario y el mensaje secreto.
- Solo se evalúan las casillas donde esta el mensaje secreto.
- No importa la orientación ni la posición final de Karel.
- No hay casillas vacías en la llave.
- No hay casillas vacías en medio de la palabra.

# Subtareas

- **(23 puntos)**: El diccionario solo tiene 2 letras.
- **(60 puntos)**: El diccionario tiene a lo más 10 letras diferentes.
- **(17 puntos)**: El mensaje secreto tiene letras que no están en el diccionario (espacios).
