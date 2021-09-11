En un tablero de $N$ filas por $M$ columnas se colocan al azar fichas de $N$ colores distintos, $M$ fichas de cada color, todas en casillas distintas, de modo que el tablero queda completamente ocupado.

Un movimiento válido consta de elegir cualesquiera dos fichas de una misma fila e intercambiarlas de lugar. Nota que luego de un movimiento válido ambas fichas siguen en su fila original.

Una _columna completa_ es aquella que tiene fichas de los $N$ colores distintos.

Un jugador puede realizar tantos movimientos como quiera antes de terminar el juego. Una vez terminado el juego el jugador recibirá un punto por cada _columna completa_ que haya logrado.

# Problema

Dadas las dimensiones $N$ y $M$ del tablero y la colocación inicial de las fichas, realiza movimientos válidos para obtener un tablero final que te dé el mayor puntaje posible.

# Entrada

- La primera línea contiene dos números $N$ y $M$ las filas y columnas del tablero.
- Las siguientes $N$ líneas contienen $M$ enteros en el rango $[1, N]$ cada una que indica el color de la ficha en la casilla correspondiente del tablero.

# Salida

- Escribe $N$ líneas, cada una con $M$ enteros en el rango $[1, N]$ que indiquen el estado final del tablero luego de los movimientos que hayas realizado.

# Límites

- $2 \leq N \leq 50$
- $2 \leq M \leq 10,000$

# Evaluación

- Si el tablero final que entregues no se puede construir usando movimientos válidos, obtendrás $0$ puntos.
- Si tu tablero es válido el número de puntos que obtengas para cada caso dependerá de la cantidad de _columnas completas_ que tenga tu solución.

# Ejemplo

||input
3 3
1 2 3
1 2 3
1 2 3
||output
1 2 3
2 3 1
3 1 2
||description
La primera fila se deja sin cambios.

La segunda fila se intercambian la primera ficha con la segunda y luego la segunda con la tercera.

La tercera fila se intercambian la tercera ficha con la segunda y luego la segunda con la primera.

El tablero que se obtiene tiene $3$ _columnas completas_ y obtendría el 100% de los puntos.
||end

# Experimentación

Este es un problema mixto: puedes enviar tu código normalmente o subir las salidas como un problema de sólo salida.

Si quieres subir sólo las salidas, debes crear un zip que contenga los archivos de salida. Los archivos de salida deben ser un `.out` que tenga el mismo nombre que el archivo de entrada `.in` al que corresponde la salida.

En caso de que envíes tu código, será evaluado con estos mismos casos de prueba.

Puedes descargar los casos de prueba de este problema aquí:

{{output-only:download}}

# Limites por caso

En total existen 20 casos, cada uno con valor de 5pts. Los límites de cada uno son:

- Caso 1: N = 3, M = 6
- Caso 2: N = 5, M = 10
- Caso 3: N = 10, M = 20
- Caso 4: N = 12, M = 30
- Caso 5: N = 15, M = 50
- Caso 6: N = 2, M = 10000
- Caso 7: N = 3, M = 10000
- Caso 8: N = 5, M = 10000
- Caso 9: N = 8, M = 10000
- Caso 10: N = 10, M = 10000
- Caso 11: N = 12, M = 1000
- Caso 12: N = 15, M = 1000
- Caso 13: N = 17, M = 1000
- Caso 14: N = 19, M = 1000
- Caso 15: N = 21, M = 1000
- Caso 16: N = 20, M = 10000
- Caso 17: N = 25, M = 10000
- Caso 18: N = 35, M = 10000
- Caso 19: N = 40, M = 10000
- Caso 20: N = 50, M = 10000
