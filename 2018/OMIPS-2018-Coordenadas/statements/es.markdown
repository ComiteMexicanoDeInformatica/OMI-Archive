La Cuasi Organización Marítima Internacional le pidió a Karel que reportara todos los barcos que están situados en el Pacífico. Para esto, Karel cuenta con un tablero donde se pueden localizar todos los barcos, cada uno representado con una clave distinta.

# Problema

Tu tarea es ayudar a Karel a hacer el reporte de las coordenadas de todos los barcos del Pacífico.

El tablero está representado en el mundo de Karel como un rectángulo y cada coordenada es vista como una casilla del mundo. Un montón de zumbadores en la columna $i$ y fila $j$ simbolizan la clave única de un barco situado en la coordenada $(i,j)$. 

Si un barco con clave $c$ está localizado en la coordenada $(x,y)$, Karel debe escribir en la primera fila de la columna $c$ la componente $x$ de la coordenada y en la segunda fila, de la misma columna, la componente $y$.

# Ejemplo

### Entrada

![Ejemplo de entrada](entrada.png)

### Salida

![Ejemplo de salida](salida.png)

# Consideraciones

* Karel inicia en la casilla (1,1) viendo al norte.
* Karel tiene infinitos zumbadores en la mochila.
* Se garantiza que las dimensiones del mundo serán lo suficientemente grandes para reportar todos los barcos.
* Las únicas paredes son las que delimitan el mundo.
* No importan la posición ni orientación final de Karel.
* Solo se evaluarán las casillas de las dos primeras filas.
* Ningún barco tiene la misma clave.

# Subtareas

* En el 77% de los casos no habrá zumbadores en las primeras dos filas inicialmente.
