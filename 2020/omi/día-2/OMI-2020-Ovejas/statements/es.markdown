Recientemente Karel se hizo un pastor, y como buen pastor debe cuidar de todo su rebaño. Sin embargo, las ovejas son muy traviesas y por ello Karel debe vigilarlas a todas estando lo más cerca posible de cada una de ellas. Karel está caminando constantemente en el campo y quiere que le ayudes a saber, si estuviera parado en cierto punto, a qué distancia está la oveja que está más cerca a él en ese momento. La distancia entre dos posiciones es el número de pasos que necesita Karel para llegar de una a otra.

Karel y las ovejas se encuentran en una matriz.

Karel se puede mover en un paso a cualquiera de las 8 casillas adyacentes a la que se encuentra, como un rey de ajedrez.

# Problema

Dadas las posiciones de todas las ovejas ayuda a Karel a responder $Q$ preguntas para saber a qué distancia está la oveja más cercana desde la posición $x_q, y_q$

# Entrada

En la primera línea 2 enteros, $N$ y $Q$, separados por un espacio.
$N$ es el número de ovejas que hay.
$Q$ es el número de veces que Karel te va a preguntar la distancia de la oveja más cercana.

En las siguientes $N$ líneas 2 enteros: $x_i$, $y_i$, que representan las coordenadas de la oveja $i$.

En las siguientes $Q$ líneas 2 enteros: $x_q$, $y_q$, que representan las coordenadas de la posición de Karel al momento de hacer la pregunta $q$.

# Salida

Debes escribir $Q$ líneas con un entero cada una: la distancia de Karel a la oveja más cercana desde $x_q, y_q$.

# Ejemplo

||examplefile
sample
||description
Existen tres ovejas en el rebaño. Están en las coordenadas `(1,5)`, `(4,5)` y `(6,10)`.
Si Karel estuviera en la coordenada `(5,5)`, la oveja más cercana sería la que se encuentra en `(4,5)`, pues Karel solo necesita dar un paso para llegar a esta. Si Karel estuviera en la coordenada `(3,3)`, la oveja más cercana también sería la que se encuentra en `(4,5)` pues solo son necesarios dos pasos para llegar a esta.

||end

# Límites

- $1 \leq N, Q \leq 10^5$
- $0 \leq x, y \leq 1000$

# Subtareas

- **(20 puntos)**
  - $1 \leq N, Q \leq 100$
  - $0 \leq x, y \leq 100$
- **(35 puntos)** $1 \leq N, Q \leq 1000$.
- **(45 puntos)** No hay restricciones adicionales.

# Consideraciones

Todos los casos de cada subtarea están agrupados.
