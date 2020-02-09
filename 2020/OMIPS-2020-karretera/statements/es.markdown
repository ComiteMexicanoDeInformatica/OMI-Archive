Karel ha conseguido un nuevo trabajo pintando líneas en la karretera de Karelópolis.

Karel está en un mundo de $5$ de alto por $N$ de ancho representando la karretera. En la casilla $(1, 1)$ hay infinitos zumbadores que representan un bote de pintura.

Como Karel desconoce el largo de la karretera, debe usar su mochila para transportar la pintura y recibirá un premio si usa la menor cantidad posible.

# Problema

Escribe un programa que ayude a Karel a pintar segmentos de línea de $3$ casillas de largo en la fila $3$. Cada línea debe estar separada por una casilla en blanco. (Revisa el caso de ejemplo.)

En caso de que la línea que estás pintando no pueda medir $3$ casillas porque hay una pared, pinta $1$ o $2$ casillas dependiendo del espacio que tengas.

# Ejemplos

### Entrada

![Entrada1](sample.in.png)

### Salida

![Salida1](sample.out.png)

# Consideraciones

* Karel inicia en la casilla $(1,1)$ viendo al norte.
* Karel tiene 0 zumbadores en la mochila.
* El alto del mundo siempre es 5.
* El ancho del mundo puede ser de 1 hasta 100.
* No importa la posición ni orientación final de Karel.

# Evaluación

Para cada caso de prueba se evaluará que las líneas queden pintadas correctamente en la fila $3$.
Adicionalmente, para obtener todos los puntos en este problema debes evitar las siguientes penalizaciones:

* Tienes una penalización de $7\%$ si avanzas $3N$ veces o más.
* Tienes una penalización de $8\%$ si al final quedan zumbadores en alguna otra línea aparte de la cubeta.
* Tienes una penalización de $12\%$ si al final tienes zumbadores en la mochila.
* Tienes una penalización de $13\%$ si ejecutas la instrucción `coge-zumbador` o `pickbeeper` mas veces de las necesarias para pintar la línea.
