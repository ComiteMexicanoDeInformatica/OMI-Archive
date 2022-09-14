¡Al fin la ansiada fecha llegó! después de tantos meses de preparación ibamos a ir a la OMI, pero como es en otro estado debiamos de trasladarnos, así que emprendimos un largo viaje. Nos reunimos los de mi delegación y yo en un mismo sitio para poder irnos juntos. Al subir al autobús habia tanta emoción en el ambiente (una emoción que duró poco), ya que después de la primera hora el tiempo se sentía eterno... por suerte después de tanto pensar llegó a mi mente un recuerdo.

Hace años cuando los niños inventaban juegos para entretenerse, mientras viajaba por la carretera tuve la gran idea de crear este juego que se llama _"5-5 feliz encuentro"_. En el juego, los niños deben fijarse en las placas de los demás coches, si en una placa hay dos números (o letras) iguales **juntas**, como **AA** o **55**, el niño que lo ve primero debe gritar "5-5 feliz encuentro" para ganar un punto.
Decidí proponerselo a mis compañeros, ¡pero todos son grandes programadores! así que no quiero perder, necesito que me ayudes creando un programa para que pueda quedarme con la victoria.

En este problema, tu programa recibirá un texto de longitud $T$ y una lista de $Q$ preguntas, cada dentro de un intervalo $[L_i, R_i]$. Para cada pregunta, tu programa deberá contestar con el número de _felices encuentros_ en el intervalo.

**Es importante que tomes en cuenta las siguientes consideraciones:**

- La primera letra del texto se considera la posición $1$.
- Si hay tres letras o números iguales juntos, por ejemplo **AAA** o **555** eso se considera como dos _felices encuentros_ distintos.

# Problema

Escribe un programa que reciba el texto y la lista de intervalos y para cada intervalo conteste la cantidad de _felices encuentros_ que hay en el mismo.

# Entrada

Tu programa debe leer de la entrada estándar:

- En la primera línea los números $T$ y $Q$, la longitud del texto y la cantidad de intervalos a evaluar.
- En la segunda un texto formado por letras mayúsculas y números acerca del cual tu programa debe contestar preguntas.
- En las siguientes $Q$ líneas los enteros $L_i$ y $R_i$, el inicio y el fin del $i-ésimo$ intervalo.

# Salida

Tu programa deberá escribir a la salida estándar una línea por cada pregunta con el número de _felices encuentros_ que hay en el intervalo de la misma.

# Ejemplo

||input
12 4
AAAAB1233533
1 12
1 3
4 8
5 10
||output
5
2
0
1
||end

# Límites

- $1 \leq T \leq 10^5$ El largo máximo del texto.
- $1 \leq Q \leq 10^5$ El número de preguntas que tu programa debe contestar.
- $1 \leq L_i, R_i \leq T$ El inicio y el fin del $i-ésimo$ intervalo.

# Subtareas

- (5 puntos): $T = 10$, $Q = 1$. La respuesta a la pregunta será $1$ o $0$.
- (17 puntos): $T, Q, L_i, R_i \leq 1000$.
- (13 puntos): El texto contendrá únicamente las letras 'A' y 'B'. (Por ejemplo **AAAABABABBBA...\***).
- (26 puntos): $L_i = 1$ para todas las preguntas.
- (15 puntos): Sea $A_i$ la respuesta a la $i-ésima$ pregunta, se te asegura que $100 > (R_i - L_i) - A_i$.
- (24 puntos): Sin restricciones adicionales.

¡Vamos! Si consigo esta victoria podré contarle a mis compañeros sobre el genial programador que eres.
