Si durante esta OMI te encuentras con algún ex-olímpico, aprovecha para preguntarle sobre sus técnicas de entrenamiento. Algunos te darán un consejo breve, otros, como Juan, te podrán dar consejos durante toda la tarde. Sin embargo, si le preguntas a Sebas, te dirá que sólo comparte sus métodos con aquellos que sean capaces de resolver el siguiente problema:

- Sebas piensa en una secuencia numérica estrictamente creciente. Es decir, cada número siempre es **mayor** que el número anterior. Sebas **NO te dice** la secuencia.
- Luego _rota a la derecha_ esa secuencia una cantidad de veces que él decide. _Rotar a la derecha_ una secuencia significa que tomas el último número de la misma y lo pasas al inicio. Por ejemplo, si la secuencia original era $1, 2, 4, 5, 6$ y la _rotas a la derecha_ te queda $6, 1, 2, 4, 5$. Si la vuelves a _rotar_ te queda $5, 6, 1, 2, 4$ y así la cantidad de veces que quieras _rotarla_.
- Finalmente, Sebas elige un número de la secuencia y te dice cuál es. Llamaremos a este número $X$.

Tu tarea es descubrir en qué posición de la secuencia está el número $X$. Para lograrlo podrás preguntarle a Sebastián un máximo de $K$ preguntas del tipo: _"¿Qué valor hay en la posición $i$ de la secuencia?"_ Para cada pregunta Sebastián te contestará el valor en esa posición de la secuencia.

Si eres capaz de encontrar la posición de $X$, en $K$ o menos preguntas, Sebastián compartirá contigo su secreto para llegar a la IOI.

# Problema

Este es un problema interactivo, deberás utilizar las funciones descritas en la sección **Implementación** para encontrar la posición de $X$ en la secuencia.

# Implementación

Deberás implementar la función `void encuentra(int N, int X, int K)` en la que:

- $N$ representa la longitud de la secuncia que pensó Sebastián.
- $K$ representa el número máximo de preguntas que puedes hacerle.
- $X$ representa el número que estás buscando.

Para hacerle preguntas a Sebastián deberás invocar la función `int pregunta(int pos)` en la que:

- $pos$ representa la posición de la que quieres saber el valor.
- La función te devolverá como resultado el valor en la posición $pos$ dentro de la secuencia de Sebastián.

**Recuerda que como máximo podrás invocar la función `pregunta` $K$ veces.**

Cuando sepas la posición del valor $X$ deberás invocar la función `void posicion(int pos)` donde:

- $pos$ representa la posición del valor $X$ en la secuencia.

**Sólo puedes invocar la función `posicion` una vez.**

# Ejemplo

Supón que la secuencia original que pensó Sebastián es $1, 2, 4, 5, 6$, decidió _rotarla_ dos veces con lo que obtuvo la secuencia $5, 6, 1, 2, 4$ Y te pidió que buscaras el valor $X = 4$. El número máximo de preguntas, $K$, que te permite hacer es de $20$. La siguiente es una posible interacción de tu programa.

||input
Función llamada
||output
Valor devuelto
||description
Descripción
||input
`encuentra(5, 4, 20)`
||output

- ||description
  El evaluador invoca tu código diciéndole que hay $N = 5$ números en la secuencia. Que tienes $K = 20$ preguntas que puedes hacer y que debes encontrar la posición del número $X = 4$.
  ||input
  `pregunta(1)`
  ||output
  5
  ||description
  Tu programa pregunta por el valor en la posición $1$, el evaluador devuelve el valor $5$ indicando que el primer número de la secuencia es $5$.
  ||input
  `pregunta(5)`
  ||output
  4
  ||description
  Tu programa pregunta por el valor en la posición $5$, el evaluador devuelve el valor $4$.
  ||input
  `posicion(5)`
  ||output
- ||description
  Tu programa encontró el número $4$, por lo tanto no tiene que seguir preguntando. Invoca la función `posicion` para dar el resultado y terminar.
  ||end

# Límites

- $1 \leq N \leq 10^6$ La cantidad de valores en la secuencia que pensó Sebastián.
- $20 \le K$ La cantidad máxima de preguntas que puedes hacer.
- $1 \leq a_i \leq 10^9$ Los valores en la secuencia que piensa Sebastián.

# Subtareas

- (15 puntos): $K = N$. Se te permite hacer $N$ preguntas.
- (17 puntos): La secuencia original que piensa Sebastián son los números del $1$ al $N$.
- (18 puntos): Sebastián no _rota_ la secuencia después de haberla pensado.
- (20 puntos): $K = 21$. Se te permiten a lo más 21 preguntas.
- (30 puntos): $K = 20$. Se te permiten a lo más 20 preguntas.

# Instrucciones para compilar en HuronOS

- Descarga la plantilla para **Sistema operativo: Linux** y **Lenguaje: C++**.
- Haz clic sobre el archivo descargado para descomprimirlo. Esto creará una carpeta dentro del folder `Downloads` con el nombre del problema.
- Si utilizas CodeBlocks, debes hacer lo siguiente:
  - Abre CodeBlocks, en el menú elige `File` -> `Open` y navega al folder `Downloads/omi-2023-encuentra-x_unix_cpp/encuentrax`.
  - Elige el archivo `encuentrax.cbp`.
  - El archivo que debes completar es `encuentrax.cpp` y estará dentro de `sources` en tu proyecto.
  - Puedes trabajar con CodeBlocks como lo haces normalmente.
- Si utilizas Visual Studio Code, debes hacer lo siguiente:
  - Abre VisualStudio, en el menú elige `File` -> `Open Folder` y navega al folder `Downloads/omi-2023-encuentra-x_unix_cpp/encuentrax`.
  - Debes trabajar sobre el archivo `encuentrax.cpp`.
  - Abre una _Terminal_, en el menú elige `Terminal` -> `New Terminal`.
  - **Para compilar tu código** debes escribir en la terminal: `make run`.

{{libinteractive:download}}
