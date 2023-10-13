Adolfo de la Huerta fue un presidente de México poco conocido. Fue exiliado por levantarse en armas contra Álvaro Obregón en 1923. Una vez exiliado, se estableció en Los Ángeles, donde puso una escuela de ópera. Cobró fama internacional por enseñarle a cantar a las estrellas de Hollywood del momento.

Para ejercitar el oído de sus alumnos, Adolfo realizaba el siguiente ejercicio:

- Primero les daba a sus alumnos una secuencia de notas. Llamemos a esta secuencia $A$.
- Luego, Adolfo cantaba una secuencia distinta de notas, la cual los alumnos tenían que escuchar. Llamemos a esta secuencia $B$.
- Finalmente, los alumnos debían contestar si **todas** las notas de $A$ aparecían en $B$ en el mismo orden, sin importar si había notas intermedias entre ellas.

Por ejemplo, supongamos que se usan letras para representar notas. Si $A = abcad$ y $B = baaacbcaad$, la respuesta sería **Sí** ya que las notas de $A$ aparecen en $B$ en el mismo orden. Sin embargo, si $A = abc$ y $B = cba$ o $B = abbbbb$, la respuesta sería **No** ya que las notas de $A$ no aparecen en $B$ en el mismo orden.

Por el 100 aniversario de la rebelión de la Huertista se retomaron estudios sobre Adolfo. Estudiando sus notas de clase, descubrieron que además de la música, Adolfo era un pionero de lo que serían las ciencias computacionales. Resulta que para el ejercicio descrito, Adolfo usaba una representación de _árbol_, es decir, un diagrama de $N$ vértices conectados por $N - 1$ aristas de modo que para cada par de vértices $u$ y $v$ hay un camino para llegar desde $u$ a $v$ pasando por una secuencia de aristas.

Durante el ejercicio Adolfo les daba a sus alumnos la secuencia $A$ y elegía al azar dos vértices $u$ y $v$ de su _árbol_ y cantaba las notas en el camino desde $u$ hasta $v$ para la secuencia $B$.

En conmemoración de nuestro presidente más musical, deberás convertirte en uno de sus alumnos y resolver este ejercicio.

# Problema

En este problema recibirás como entrada el _árbol_ que usaba Adolfo en sus ejercicios. Cada vértice tiene asignada una letra minúscula que representa una nota musical. Tu programa deberá ser capaz de contestar $Q$ preguntas. Cada pregunta consiste de dos vértices $u$ y $v$ y una cadena $A$ que representan los vértices elegidos por Adolfo y la secuencia $A$ que deben identificar los alumnos.

Por cada pregunta tu programa deberá escribir "SI" (sin las comillas) en caso de que la cadena $A$ aparezca, en el mismo orden en el camino entre $u$ y $v$ o "NO" en caso contrario.

# Entrada

Tu programa deberá leer de la entrada estándar los siguientes datos:

- La primera línea de la entrada consiste de los enteros $N$ y $Q$.
- La segunda línea, consiste de una cadena con $N$ caracteres. El $i$-ésimo caracter de la cadena dada se le asigna al vértice $i$. Los vértices se numeran del $1$ al $N$.
- Las siguientes $N - 1$ líneas, consisten de dos enteros $u$ y $v$ e indican que existe una arista entre los dichos vértices.
- Las últimas $Q$ líneas, consisten de dos enteros, $u$, $v$, y una cadena $A$. Representan la información de cada pregunta.

# Salida

Tu programa deberá escribir $Q$ líneas, una por cada pregunta, la línea debe contener **SI** en caso de que la respuesta a la pregunta sea afirmativa, y **NO** en caso contrario.

# Ejemplo

||input
10 3
canserbero
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
1 10 casero
2 9 ser
9 3 amar
||output
SI
SI
NO
||description

En la primera pregunta, la cadena formada por el camino entre los vértices $1$ y $10$ es "canserbero".
La cadena "casero" aparece como subsecuencia si excluyes los caracteres de los vértices $3, 5, 6, 7$.

En la segunda pregunta, La cadena formada por el camino entre los vértices $2$ y $9$ es "anserber".
La cadena "ser" aparece como subsecuencia si excluyes los caracteres de los vértices $2, 3, 5, 6, 7$.

En la última pregunta, la cadena formada por el camino entre los vértices $3$ y $9$ es "rebresn".
La cadena "amar" no aparece en ninguna subsecuencia pues la letra "m" nunca aparece en la cadena "rebresn".

||end

# Límites

Sea $A_i$ la cantidad de caracteres de la cadena en la pregunta $i$. Sea $A$ la suma de todos los $A_i$.
Para todos los casos se cumple que:

- $2 \le N, Q \le 3 \cdot 10^5$
- $Q \le A \le 3\cdot 10^5 + Q$. La suma del largo de todas las cadenas en las preguntas.

# Subtareas

- Subtarea 0 (10 puntos): $N, Q \le 10^5$. El árbol es una línea, En particular, las aristas son de la forma $(i, i + 1)$. Además $u = 1$ y todas las cadenas de las preguntas tienen longitud igual a 1.
- Subtarea 1 (20 puntos): $N, Q \le 1000$, $A \le 2000$.
- Subtarea 2 (20 puntos): $N, Q \le 10^5$, $A \le 2 \cdot 10^5$. Los vértices $u$ y $v$ son los mismos en todas las preguntas.
- Subtarea 3 (20 puntos): $N, Q \le 10^5$, $A \le 2 \cdot 10^5$. El árbol es una línea. En particular, las aristas son de la forma $(i, i + 1)$.
- Subtarea 4 (30 puntos): Sin restricciones adicionales.
