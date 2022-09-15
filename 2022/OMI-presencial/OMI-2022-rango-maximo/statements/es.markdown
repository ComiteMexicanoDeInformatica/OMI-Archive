Luego de consagrarse como beta-tester de codeforces, Juan quiere crear una plataforma de programación competitiva con concursos diarios. Juan tiene $N$ amigos que serán sus usuarios iniciales, cada amigo tiene un puntaje asignado según su capacidad. Juan quiere que los concursos sean _equilibrados_, esto quiere decir que si un concurso está calibrado para gente con puntaje $X$, entonces en ese concurso sólo deben poder participar aquellos usuarios cuyo puntaje esté en el rango $[X - d, X + d]$. Donde $d$ es un parámetro de la plataforma.

Juan no tiene mucho presupuesto y le preocupa la cantidad de servidores que necesitará. El número de servidores depende de la cantidad de usuarios que pueden presentar un examen al mismo tiempo. Juan te compartirá el puntaje de todos sus amigos y el parámetro $d$ y quiere que le ayudes a calcular cuál es el máximo número de usuarios que pueden presentar un examen al mismo tiempo. **Considera que Juan no ha hecho los exámenes y no sabe para qué puntaje $X$ quedarán calibrados, así que tu programa debe contemplar todos los posibles puntajes $X$ para un examen.**

**Noticia de último momento:** Juan ya inauguró su plataforma y tuvo sus primeros exámenes. Luego de cada examen hay cambios en los puntajes de sus amigos, algunos suben su puntaje y otros lo bajan. Para cada examen que haga, Juan te dará los cambios de puntaje y luego de recibirlos deberás volver a decirle ¿cuál es el máximo de usuarios que pueden presentar un examen de forma simultánea?

# Problema

Escribe un programa que reciba el listado de puntajes y el valor de $d$ y responda el número máximo de usuarios que pueden participar en un examen de forma simultánea.

**Para las últimas subtareas de este problema además tu programa debe recibir los cambios de puntaje luego de cada examen y responder nuevamente la cantidad de usuarios que pueden presentar un examen de forma simultánea.**

# Entrada

Tu programa debe leer de la entrada estándar:

- En la primera línea los números $N$ y $d$, el número de usuarios y el parámetro de la plataforma.
- En la segunda línea habrá $N$ números separados por un espacio que representan los puntajes de cada usuario de la plataforma. **Los puntajes estarán ordenados de menor a mayor.**
- En la tercera línea el número $E$ la cantidad de exámenes que ha hecho Juan. **Para las primeras subtareas del problema este número será igual a $0$.**
- Por cada examen que se ha llevado a cabo en la plataforma debes leer el siguiente bloque de líneas:
  - En la primer línea del bloque el número $C$, la cantidad de usuarios que cambio de puntaje.
  - En las siguientes $C$ líneas dos números enteros $i$ y $P_i$ que representan que el $i$-ésimo usuario cambió su puntaje a $P_i$ puntos.
  - **Para la línea anterior considera que los usuarios están numerados de 1 a N.**

# Salida

Tu programa deberá escribir a la salida estándar una línea con el número máximo de usuarios que puede participar en examen de forma simultánea tomando en cuenta los puntajes iniciales.

Si en la plataforma se han llevado a cabo exámenes, tu programa deberá escribir, por cada examen, una línea con el número máximo de usuarios que pueden participar de forma simultánea tomando en cuenta los nuevos puntajes.

# Ejemplo

||input
10 3
1 2 2 2 3 3 5 6 10 10
0
||output
8
||description
Si por ejemplo el examen está calibrado para un puntaje $X = 4$ entonces, dado que $d = 3$ pueden participar usuarios con puntaje en el rango $[(4 - 3), (4 + 3)] = [1, 7]$. Hay ocho competidores con puntajes en ese rango, por lo tanto, la respuesta es $8$.

En este caso, se realizan cero exámenes extras.
||input
10 3
1 2 2 2 3 3 5 6 10 10
2
2
3 8
4 1
1
5 11
||output
8
7
6
||description

- Para los puntajes iniciales, la respuesta es $8$ ya que es el mismo caso que en el ejemplo anterior.
- Luego del primer examen, los puntajes del usuario $3$ y $4$ cambian. De modo que los nuevos puntajes son $[1, 2, 8, 1, 3, 3, 5, 6, 10, 10]$, para un puntaje $X = 4$ tenemos $7$ posibles usuarios.
- Luego del segundo examen, el puntaje del usuario $5$ cambia. **Observa que los puntajes de los usuarios $3$ y $4$ conservan sus cambios del primer examen.** La nueva lista de puntajes queda $[1, 2, 8, 1, 11, 3, 5, 6, 10, 10]$. Para un puntaje de $X = 4$ ahora hay $6$ competidores, lo mismo que para un puntaje de $X = 8$.
  ||end

# Límites

- $1 \leq N \leq 10^5$ El número de usuarios.
- $0 \leq d \leq 10^9$ El parámetro de la plataforma.
- $1 \leq p_i \leq 10^9$ El puntaje de cada uno de los competidores.
- $0 \leq E \leq 10^5$ La cantidad de exámenes realizados en la plataforma.
- $1 \leq C \leq N$ La cantidad de cambios luego de un examen. **Se te asegura que la cantidad de cambios de puntaje entre todos los exámenes es menor o igual a 10^5.**

# Subtareas

- (5 puntos): $p_i = p_j$, $E = 0$. Todos los usuarios inician con el mismo puntaje.
- (18 puntos): $N, p_i \leq 1000$, $E = 0$.
- (19 puntos): $N \leq 1000$, $E = 0$.
- (19 puntos): $N, E \leq 1000$.
- (20 puntos): $E \leq 10$.
- (19 puntos): Sin restricciones adicionales.
