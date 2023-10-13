Martín Terreneitor es un robot **con forma cuadrada** que puede caminar en cualquier terreno. Este año participará en una competencia de robots, y tiene que recorrer una casa llena de paredes y obstáculos. El objetivo de la competencia es que Martín se desplace desde el punto $A$ al punto $B$.
Los creadores de Martin están preocupados por el tamaño de éste, ya que no saben si va a caber en los espacios apretados de la casa. Es bien sabido que entre más pequeño un robot, más difícil es diseñarlo y compactarlo.

Es por eso que debes decir cuál es el tamaño máximo que Martin puede tener de tal manera que le sea posible llegar de punto $A$ a punto $B$.

Martín puede moverse en 4 direcciones: adelante, atrás, izquierda o derecha. **No puede moverse en diagonal**. Se considera que Martín inicia en el punto $A$ si cualquier parte de su _cuerpo_ está tocando la casilla $A$, igualmente se considera que llegó al punto $B$ si cualquier parte de su _cuerpo_ está tocando la casilla $B$.

![Ejemplo_Simulacion](ejemplo_simulacion2.gif)

En este caso, Martin tiene un tamaño de 4x4, se mueve hacia arriba y luego a la derecha. Las casillas rojas representan las casillas en las que Martin estuvo. Es decir, todas las rojas pueden llegar a todas las rojas si el robot tiene tamaño 4x4.

La competencia consta de $Q$ pruebas cada una con su propio punto de inicio $A_i$ y su punto de destino $B_i$, para cada una de las $Q$ pruebas tu programa debe validar si es posible realizar el recorrido y en caso de que sea posible, calcular el tamaño máximo que puede tener Martin.

# Problema

Dadas las $Q$ pruebas, tu programa debe responder el tamaño máximo que Martin puede tener para ir de punto $A$ a punto $B$.

# Entrada

Tu programa deberá leer de la entrada estándar los siguientes datos:

- En la primera línea los números $N$ y $M$, el tamaño de la casa, indica que la casa tiene $N$ filas y $M$ columnas.
- En las siguientes $N$ líneas hay $M$ caractéres que representan el mapa de la casa. `#` indica una pared y `.` indica un espacio libre.
- La siguiente línea contiene el entero $Q$, la cantidad de pruebas del concurso.
- Las últimas $Q$ líneas describen una prueba, cada una tiene los enteros, $A_{fila}$, $A_{columna}$, $B_{fila}$ y $B_{columna}$.

# Salida

Tu programa debe escribir a la salida estándar $Q$ líneas con un entero cada una.

- En caso de que el recorrido de la prueba sea imposible, la línea debe tener $-1$.
- Si el recorrido es posible, el número debe indicar el tamaño máximo que Martín puede tener.

**Recuerda que se considera llegar al punto $B$ si algun punto de Martín está encima de esa casilla.**

# Ejemplo

|| input
6 6
#.....
......
...###
##....

######

..#...
3
3 1 1 6
2 4 4 5
6 1 6 6

|| output
2
1
-1
|| end

# Límites

- 1 <= N,M <= 500
- 1 <= Q <= 30000

# Subtareas

- **(10 puntos):** 1<=N,M,Q<=20
- **(34 puntos):** Q = 1
- **(15 puntos):** 1<=N,M<=100
- **(41 puntos):** Sin reestricciones adicionales.
