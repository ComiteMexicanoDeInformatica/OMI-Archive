Tapia inventó un nuevo juego de mesa. Tienes un tablero rectangular cuadriculado, fichas blancas y fichas negras. Algunas de las casillas del tablero pueden estar bloqueadas. Para ganar el juego, debes acomodar el mayor número de fichas en las casillas libres del tablero cumpliendo las siguientes condiciones:

- Ninguna ficha negra es adyacente a otra ficha negra.
- Ninguna ficha blanca es adyacente a otra ficha blanca.

# Problema

Dado un tablero de $n$ filas y $m$ columnas, añade la mayor cantidad de fichas que puedas en el tablero.

Este es un problema de solo salida, por lo que no necesariamente tienes que enviar tu código, sino que también puedes enviar un zip con tus salidas.

# Entrada

En la primera línea dos enteros, $n$ y $m$: la cantidad de filas y columnas del tablero, respectivamente.

En las siguientes $n$ líneas vienen $m$ caracteres que representan el tablero inicial. `*` significa casilla bloqueada. `.` significa casilla libre.

# Salida

El tablero final que cumple los requerimientos. 'N' es que pusiste una ficha negra y 'B' es que pusiste una ficha blanca.

# Ejemplo

||examplefile
sample
||end

# Límites

- $1 \leq n, m \leq 1000$.
- Para el 20% de los casos, $1 \leq n, m \leq 10$.

# Evaluación

- Si no cumples con los requerimientos, obtendrás 0 puntos.
- Si la salida cumple con los requerimientos, el puntaje dependerá del número de fichas que pongas.

# Experimentación

Este problema es mixto: puedes enviar tu código normalmente, o subir las salidas como un problema de solo salida.

Si quieres subir solo las salidas, debes crear un zip que contenga los archivos de salida. Los archivos de salida deben ser un `.out` que tenga el mismo nombre que el archivo de entrada `.in` al que corresponde la salida.

En caso de que envíes tu código, será evaluado con estos mismos casos de prueba.

Puedes descargar los casos de prueba de este problema aquí:

{{output-only:download}}
