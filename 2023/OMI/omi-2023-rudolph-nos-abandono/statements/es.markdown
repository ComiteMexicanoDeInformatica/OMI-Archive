Los chicos del PES (Programadores En Serio) se encuentran entrenando en CDMX, están por tomar un viaje en el metro. Desafortunadamente Rudolph, el encargado de este grupo de chicos, los abandonó. Es bien sabido que de vez en cuando Rudolph pone este tipo de pruebas a los chicos del PES, por lo que siempre previsores, los chicos del PES le pusieron un chip de rastreo.

La contraseña del chip es una permutación $P$ de tamaño $N$.

Una permutación de tamaño $N$ es un arreglo en el que cada entero de $1$ a $N$ aparece **exactamente una vez**. Por ejemplo $[1, 2, 3, 4]$ y $[3, 1, 2, 4]$ son permutaciones de tamaño $4$.

Aunque los chicos del PES fueron muy previsores en ponerle el chip de rastreo a Rudolph, olvidaron la permutación $P$ que usaron como contraseña. Por suerte, el rastreador permite que hagas preguntas del siguiente tipo para tratar de adivinar la contraseña.

- Se escribe en el rastreador un arreglo $A$ de $N$ enteros positivos, el rastreador responde cuantas posiciones $i$ hay tales que $P_i = A_i$. Es decir, en cuantas posiciones coinciden el arreglo y la permutación de contraseña.

Si el chip recibe muchas preguntas se bloqueará y será imposible encontrar a Rudolph. Por lo que debes encontrar la contraseña correcta en el menor número de preguntas.

# Problema

Este es un problema interactivo, tu código deberá encontrar la permutación $P$ invocando la función `similitud(A)` la menor cantidad de veces.

# Implementación

Deberás implementar la función `void Rudolph(int N)`.

Para obtener información debes invocar la función `int similitud(int A[])` que devolverá la cantidad de posiciones $i$ tales que $P_i = A_i$. **Recuerda que el arreglo $A$ debe contener exactamente $N$ enteros y el valor de los números debe estar en el rango entre 1 y N. En $A$ puedes, si lo deseas, mandar números repetidos (revisa el ejemplo para que te quede más claro)**.

Una vez que hayas descifrado la permutación $P$, deberás invocar la funcion `void localizacion(int P[])`. **Sólo puedes invocar la función `localizacion` una vez**

# Ejemplo

En este caso $P = [1,2,4,3]$

||input
Rudolph(4)
||output

- ||description
  Inicialmente se invoca la función `Rudolph` indicando que la permutación $P$ es de tamaño $4$.
  ||input
  similitud({1,2,3,4})
  ||output
  2
  ||description
  La función devuelve $2$ ya que la primera y segunda posición de $P$ y del arreglo $A$ que se probó coinciden.
  ||input
  similitud({1,2,3,3})
  ||output
  3
  ||description
  El resultado es $3$ ya que coinciden las posiciones $1$, $2$ y $4$ entre $P$ y el arreglo $A$.
  ||input
  localizacion({1,2,4,3})
  ||output
- ||description
  Una vez que sabes cuál es la permutación $P$ puedes invocar `localizacion`.
  ||end

# Evaluación

Tu puntaje dependerá de la cantidad de veces que invoques la función `similitud`. En algunas subtareas basta con que la cantidad de invocaciones sea menor que un límite para obtener los puntos. En la última subtarea tu puntaje dependerá de qué tanto te acerques al número de invocaciones de la solución oficial.

En cualquiera de los siguientes casos:

- Si al invocar la funcion `similitud(A)` tu arreglo no cumple con las características antes mencionadas,
- Si **no** invocas a la funcion `localizacion(P)` exactamente una vez,
- Si excedes la cantidad máxima de invocaciones a `similitud(A)` para esa subtarea o
- Si tu respuesta $P$ no es correcta

Obtendrás **0** puntos.

# Límites

- $1 \leq N \leq 4096$

# Subtareas

- **(5 puntos):** Puedes invocar `similitud` a lo más $N^2$ veces.
- **(8 puntos):** Puedes invocar `similitud` a lo más $N + Nlog_2 (N)$ veces.
- **(15 puntos)** Puedes invocar `similitud` a lo más $Nlog_2 (N)$ veces.
- **(72 puntos):**
  - Si invocas `similitud` más de $Nlog_2 (N)$ veces obtendrás $0$ puntos.
  - Si invocas `similitud` a lo más el número de veces que lo hace la solución oficial obtendrás el $100$% de los puntos.
  - Si invocas `similitud` entre $Nlog_2 (N)$ y número de la solución oficial obtendrás una cantidad parcial de los puntos.

# Instrucciones para compilar en HuronOS

- Descarga la plantilla para **Sistema operativo: Linux** y **Lenguaje: C++**.
- Haz clic sobre el archivo descargado para descomprimirlo. Esto creará una carpeta dentro del folder `Downloads` con el nombre del problema.
- Si utilizas CodeBlocks, debes hacer lo siguiente:
  - Abre CodeBlocks, en el menú elige `File` -> `Open` y navega al folder `Downloads/omi-2023-prueba-rudolph_unix_cpp/rudolph`.
  - Elige el archivo `rudolph.cbp`.
  - El archivo que debes completar es `rudolph.cpp` y estará dentro de `sources` en tu proyecto.
  - Puedes trabajar con CodeBlocks como lo haces normalmente.
- Si utilizas Visual Studio Code, debes hacer lo siguiente:
  - Abre VisualStudio, en el menú elige `File` -> `Open Folder` y navega al folder `Downloads/omi-2023-prueba-rudolph_unix_cpp/rudolph`.
  - Debes trabajar sobre el archivo `rudolph.cpp`.
  - Abre una _Terminal_, en el menú elige `Terminal` -> `New Terminal`.
  - **Para compilar tu código** debes escribir en la terminal: `make run`.

{{libinteractive:download}}
