�Has notado lo grande que se ven las cosas bajo una lupa? Puedes ver letras peque�as de un texto o los detalles de una fotograf�a o un mapa.

# Problema

Para este problema la utilizaremos para ver n�meros. Tu tarea es mostrar la cantidad de zumbadores que tienes en la mochila al verla bajo la lupa. Cada d�gito bajo la lupa se representa de la siguiente manera:

<center>![N�meros](num.png)</center>

# Ejemplo

### Entrada

![Ejemplo de entrada](entrada.png)

### Salida

![Ejemplo de salida](salida.png)

# Consideraciones

- Karel se encuentra en un mundo de 9 columnas y 6 filas.
- Karel est� inicialmente en la casilla (1,1) con orientaci�n desconocida.
- Karel tiene en la mochila la cantidad de zumbadores a representar (sin ceros a la izquierda).
- En la casilla (9,6) se encuentra una cantidad infinita de zumbadores en caso de no tener suficientes para representar el n�mero requerido.
- En las casillas con fila $1 \leq i \leq 5$ y columna $7 \leq j \leq 9$ se debe colocar el d�gito de las unidades.
- En las casillas con fila $1 \leq i \leq 5$ y columna $4 \leq j \leq 6$ se debe colocar el d�gito de las decenas.
- En las casillas con fila $1 \leq i \leq 5$ y columna $1 \leq j \leq 3$ se debe colocar el d�gito de las centenas.
- �nicamente se evaluar�n la cantidad de zumbadores de cada casilla con fila $1 \leq i \leq 5$ y columna $1 \leq j \leq 9$.

# Evaluaci�n

- En el 20% de los casos Karel tiene en la mochila de 0 a 9 zumbadores.
- En el 30% de los casos Karel tiene en la mochila de 10 a 99 zumbadores.
- En el 50% de los casos Karel tiene en la mochila de 100 a 999 zumbadores
