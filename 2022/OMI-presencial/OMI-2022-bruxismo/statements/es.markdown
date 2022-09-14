Fernanda tiene bruxismo, una condición que le hace apretar muy fuerte los dientes mientras duerme.

Su dentista está preocupado por el daño que sufren sus dientes. El $i$-ésimo diente de Fernanda tiene una dureza $D_i$, si en una noche Fernanda aprieta los dientes con una fuerza **mayor a $D_i$** el $i$-ésimo diente **aumentará** su _daño total_ en $A_i$ unidades, por el contrario, si Fernanda aprieta los dientes con una fuerza **menor o igual a $D_i$** el diente se recuperará y su _daño total_ **disminuirá** $B_i$ unidades. **El daño total de cada diente se va acumulando a lo largo de las noches. Además nunca puede tener menos de $0$ puntos de daño.**

Si en algún momento el **_daño total_ del $i$-ésimo diente es mayor o igual que su valor máximo $M_i$** entonces el diente se caerá.

**Observa que el valor máximo, la dureza, el daño acumulable y el daño que se recupera son específicos de cada diente.**

Fernanda hizo un programa que predice la fuerza con la que apretará sus dientes en cada uno de las siguientes $T$ noches. Fernanda quiere saber qué dientes se le van a caer en las siguientes $T$ noches si considera que el _daño total_ inicial en todos sus dientes es igual a $0$.

Tu programa debe imprimir un arreglo de tamaño $N$, si el diente $i$ se va a caer debe imprimir un $1$ en esa posición, en caso contrario debe imprimir un $0$.

# Problema

Escribe un programa que para cada diente reciba su dureza, el daño que acumula, el daño que recupera y el máximo daño que soporta y un arreglo con la fuerza con la que Fernanda apretará los dientes las siguientes $T$ noches y determine qué dientes se caerán y qué dientes permanecerán.

# Entrada

Tu programa debe leer de la entrada estándar:

- En la primera línea los números $N$ y $T$, la cantidad de dientes que tiene Fernanda y la cantidad de noches a evaluar.
- En las siguientes $N$ líneas cuatro enteros $D_i$, $A_i$, $B_i$ y $M_i$, la dureza, el daño que se acumula, el daño que recupera y el _daño total_ máximo del $i$-ésimo diente.
- En la última línea habrá $T$ números separados por entero que representan la fuerza con la que Fernanda apretará los dientes en cada una de las siguientes $T$ noches.

# Salida

Tu programa deberá escribir a la salida estándar una línea con $N$ números separados por un espacio, uno por cada diente, el número debe ser $0$ si el diente permance al cabo de los $T$ días y un $1$ si el diente se cayó en algún momento de las $T$ noches.

# Ejemplo

||input
3 5
1 2 3 15
5 10 5 10
3 3 4 5
4 2 8 3 4
||output
0 1 0
||description

- El diente uno tiene dureza $D_1 = 1$ de modo que todas las noches acumula daño. Cada noche acumula $2$ unidades de daño, al cabo de las $5$ noches tendrá un total de $10$ puntos de daño. Como el daño máximo que soporta $M_1 = 15$, no ha llegado a su máximo y el diente permanece en la boca de Fernanda.
- El diente dos tiene dureza $D_2 = 5$. Las noches uno y dos no recibe daño, como el _daño total_ no puede disminuir de $0$, se mantiene en ese número. La tercera noche la fuerza es de $8$, excede su dureza y el diente acumula $10$ unidades de daño, con lo cual llega a su máximo $M_2 = 10$ y por lo tanto se cae.
- El diente tres tiene dureza $D_3 = 3$. La primera noche acumula daño y su _daño total_ queda en $3$, la segunda noche se recupera con lo cual su _daño total_ disminuye a $0$ (observa que no puede ser menor que cero), en la tercera vuelve a acumular daño, la cuarta recupera (la fuerza es menor o igual a su dureza), la quinta acumula y termina con _daño total_ igual a $3$ por lo que nunca llega a su máximo y el diente permanece.
||end

# Límites

- $1 \leq N \leq 10^5$ El número de dientes de Fernanda.
- $1 \leq T \leq 10^4$ El número de días para los que se conoce la fuerza con que apretará Fernanda.
- $1 \leq A_i, B_i \leq 20$ El daño y la recuperación diaria de el $i-ésimo$ diente.
- $1 \leq D_i \leq 10^9$ La dureza del $i-ésimo$ diente.
- $1 \leq M_i \leq 10^6$ El daño máximo que soporta el $i-ésimo$ diente.
- $1 \leq F_j \leq 10^9$ La fuerza con la que Fernanda aprieta la $j-ésima$ noche.

# Subtareas

- (18 puntos): $N, T \leq 1000$
- (24 puntos): $D_i = D_j$, $A_i = A_j$ y $B_i = B_j$ Todos los dientes tienen la misma dureza, sufren el mismo daño diario y tienen la misma recuperación.
- (27 puntos): $A_i = B_i$ Para todos los dientes el daño diario es igual a su recuperación.
- (31 puntos): Sin restricciones adicionales.
