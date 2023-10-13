Luego de su compentencia, Martín el robot decidió quedarse a trabajar como bartender en Alemania. El concepto futurista de un robot sirviéndote bebidas ha tenido tanto éxito que Martín está sobrepasado por su clientela y necesita tu ayuda para saber la mejor forma de atender a sus clientes.

En una noche cualquiera Martín tiene $N$ clientes que se colocan a lo largo de la barra en las posiciones $1, 2, 3, ..., N$. Cada cliente ordena su bebida preferida. En específico, el cliente en la posición $i$ ordena una bebida que le cuesta a Martín $a_i$ energía preparar.

Martín es ordenado y tiene **todo** su material de trabajo en **una única** posición de la barra. Llamemos a esta posición la posición $j$. Cuando Martín atiende al cliente $i$ gasta energía en prepara la bebida y en transportarse desde la posición $j$ hasta la posición $i$. En específico el costo total de energía de antender al cliente $i$ se calcula de la siguiente forma: $costo(i) = a_i + |j - i|$.

Los $N$ clientes de hoy ya llegaron y cada uno ha ordenado su bebida. El día de hoy Martín va a atender únicamente a $K$ clientes (Martín se da a desear). Por supuesto, quiere gastar la menor energía posible. Martín te ha pedido ayuda para que le digas cuánto gastará de energía en atender a $K$ clientes si pone su material de trabajo en cada una de las $N$ posiciones de la barra.

**Observa que los $K$ clientes que atienda pueden ser cualesquiera $K$. Es posible que los clientes que le convenga atender si su material está en cierta posición sean distintos de los que le conviene atender si su material está en una posición distinta.**

# Problema

Deberás escribir un programa que dado el número de clientes en el bar y el costo de preparación de la bebida que cada uno ordena, le diga a Martín cuál es la mínima energía que necesitará para atender a $K$ clientes teniendo su material de trabajo en cada una de las $N$ posiciones de la barra.

# Entrada

Tu programa deberá leer de la entrada estándar los siguientes datos:

- En la primera línea los números $N$ y $K$, la cantidad de clientes en el bar y el número de clientes que Martín va a atender.
- En la segunda línea habra $N$ números, el $i$-ésimo de estos números representa el costo de prepara la bebida del $i$-ésimo cliente.

# Salida

Tu programa deberá escribir en la salida estándar $N$ líneas cada una con un número. El número de la $i$-ésima línea indica el costo mínimo de energía que Martín debe gastar para atender $K$ clientes si tiene su material en la posición $i$.

# Ejemplo

||input
7 3
3 2 4 1 4 5 1
||output
10 9 9 9 9 10 11
||description
Si Martín tiene su material en la posición $1$ le conviene atender a los clientes en las posiciones $1$, $2$ y $4$. Los costos de atenderlos son:

- Cliente en posición $1$. $costo = a_1 + |1 - 1| = 3 + 0 = 3$
- Cliente en posición $2$. $costo = a_2 + |1 - 2| = 2 + 1 = 3$
- Cliente en posición $4$. $costo = a_4 + |1 - 4| = 1 + 3 = 4$
- Costo total de atender a $K = 3$ clientes es $3 + 3 + 4 = 10$

Si Martín tiene su material en la posición $5$ le conviene atender a los clientes en las posiciones $4$, $5$ y $7$ con costos respectivos de:

- Cliente posición $4$. $costo = a_4 + |5 - 4| = 1 + 1 = 2$
- Cliente posición $5$. $costo = a_5 + |5 - 5| = 4 + 0 = 4$
- Cliente posición $7$. $costo = a_7 + |5 - 7| = 1 + 2 = 3$
- Costo total de atender $K = 3$ clientes es $2 + 4 + 3 = 9$

Se puede realizar un ejercicio similar para todas las posiciones.
||end

# Límites

- $1 \leq N \leq 10^5$. El número de clientes en el bar.
- $1 \leq K \leq N$. El número de clientes que va a atender Martín.
- $1 \leq a_i \leq 10^5$. El costo de preparar la bebida del $i$-ésimo cliente.

# Subtareas

- (16 puntos): $a_i = a_j$, es decir, todos los clientes piden la misma bebida.
- (14 puntos): $K = N$.
- (21 puntos): $K = 1$.
- (10 puntos): $1 \leq N \leq 1000$.
- (39 puntos): Sin restricciones adicionales.
