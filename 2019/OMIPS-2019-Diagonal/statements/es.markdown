Karel está en un mundo cuadrado que tiene exactamente un zumbador en cada columna.

Karel quiere dejar los zumbadores en la diagonal que atraviesa el cuadrado de la esquina superior izquierda a la esquina inferior derecha, por lo que en cada columna debe mover el zumbador hacia arriba, hacia abajo o dejarlo dónde está.

# Problema

Ayuda a Karel contar cuántas casillas debe mover cada zumbador para dejarlo en la diagonal y dejar la cantidad que contó sobre la diagonal. **Además de las cantidades que dejes en la diagonal, no debes dejar ningún otro zumbador.**

Si no fue necesario mover un zumbador, entonces deberás dejar 0 zumbadores en esa columna.

# Ejemplos

### Entrada

![Entrada1](sample.in.png)

### Salida

![Salida1](sample.out.png)

### Explicación

En la primer columna Karel tiene que mover el zumbador 3 casillas hacia arriba para dejarlo en la diagonal, entonces deja 3 zumbadores en la posición final (1,5). En la segunda columna, el zumbador ya está dentro de la diagonal, por lo que la cantidad de movimientos es 0. En la tercer columna Karel tiene que mover el zumbador 2 casillas hacia arriba; en la cuarta columna 3 casillas hacia abajo; en la quinta columna 0 casillas.

# Consideraciones

* Karel inicia en la casilla (1,1) viendo al norte.
* Karel tiene infinitos zumbadores en la mochila.
* Las únicas paredes en el mundo son las que lo delimitan.
* El mundo es cuadrado. Es decir, el alto y el ancho son del mismo tamaño.
* Hay exactamente un zumbador en cada columna del mundo.
* Se evalúan todos los zumbadores del mundo.
