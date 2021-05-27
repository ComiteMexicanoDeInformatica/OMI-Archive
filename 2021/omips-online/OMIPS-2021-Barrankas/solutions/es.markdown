## Primera subtarea, no hay _hermosuras_ negativas. (35 puntos)

El problema te pide que trabajes con diferencias de alturas entre barrancas contiguas. El primer paso para facilitar la solución es sustituir las alturas por las diferencias.

En la primera subtarea te indican que las alturas de las montañas están en orden ascendente, por lo que no hay que preocuparse por negativos. Un posible pseudocódigo para obtener las diferencias es:

```
   Mueve a Karel hasta la penúltima montaña (este)
   Hacia el oeste, aprende las alturas recursivamente dejando el montón con su valor original
   Regresa recursivamente quitando a cada montaña la altura de la previa
```

Con las diferencias, puedes utilizar una técnica conocida como **suma de prefijos** o **acumulado de prefijos** para resolver el problema.

### Suma de prefijos

Si tienes una lista de valores (como en este problema) se le llama _prefijo_ a una lista de menor o igual tamaño formada con los primeros elementos de la lista inicial.

Por ejemplo, si tu lista inicial es: $ \left\lbrace 1, 3, 6, 4, 5, 7 \right\rbrace$ la lista $ \left\lbrace1, 3 \right\rbrace$ sería un prefijo. Pero por ejemplo la lista $ \left\lbrace1, 6 \right\rbrace$ no lo es porque _eliminó_ el $3$, o la lista $ \left\lbrace3, 1 \right\rbrace$ no es prefijo porque cambia el orden original.

La lista completa de prefijos para la lista anterior es: $ \left\lbrace1 \right\rbrace, \left\lbrace1, 3 \right\rbrace, \left\lbrace1, 3, 6 \right\rbrace, \left\lbrace1, 3, 6, 4 \right\rbrace, \left\lbrace1, 3, 6, 4, 5 \right\rbrace, \left\lbrace1, 3, 6, 4, 5, 7 \right\rbrace$

La técnica de _suma de prefijos_ es calcular el valor de la suma de los elementos de cada prefijo. Esta técnica es muy usada en programación competitiva y se usa de la siguiente manera.

Supón que tienes una lista de valores $A =  \left\lbrace a_1, a_2, a_3, ..., a_n \right\rbrace$ y calculas los valores de _suma de prefijos_ en otra lista $PREF =  \left\lbrace pref_1, pref_2, pref_3, ..., pref_n \right\rbrace$ de modo que:

<center>$pref_1 = a_1$: La suma de los valores del primer prefijo, en este caso sólo $a_1$</center>

<center>$pref_2 = a_1 + a_2$: La suma de los valores del segundo prefijo</center>

<center>$pref_3 = a_1 + a_2 + a_3$</center>

En general

<center>$pref_i = a_1 + a_2 + a_3 + ... + a_i$</center>

E imagina que quieres contestar de forma eficiente la siguiente pregunta: _¿Cuánto vale la suma de todos los valores desde la posición $i$ hasta la posición $j$? donde $i < j$._ Es decir, la pregunta te está pidiendo calcular la suma $a_i + a_{i+1} + a_{i+2} + ... + a_{j-1} + a_j$.

Usando la suma de prefijos la respuesta es: $pref_j - pref_{i - 1}$

Para convencerte que es cierto recuerda que:

<center>$pref_j = a_1 + a_2 + ... + a_j$</center>

<center>$pref_{i-1} = a_1 + a_2 + ... + a_{i-1}$</center>

de modo que

<center>$pref_j - pref_{i-1} = (a_1 + a_2 + ... + a_j) - (a_1 + a_2 + ... + a_{i - 1})$</center>

Puedes ver que todos los términos desde $a_1$ hasta $a_{i-1}$ se _cancelan_, quedando únicamente la suma de $a_i + a_{i + 1} + ... + a_j$ que es lo que querías.

El beneficio de la **suma de prefijos** es que nos permitió tener la suma de un rango de valores, sin importar el largo del mismo, mediante una única resta.

Calcular la **suma de prefijos** en este problema es muy sencillo. Un posible pseudocódigo para hacerlo es:

```
   Cuenta la cantidad de montañas
   Sube al renglón dónde están las diferencias
   repetir precede(n) veces
      cuenta montón
	  avanza
	  deja lo que contaste
```

### Solución primera tarea

Ahora queda resolver el problema usando la **suma de prefijos**. Con ella puedes saber fácilmente la suma de un rango mediante una resta, entonces lo que puedes hacer es memorizar las primeras $N - K + 1$ sumas de prefijos y restarlas de las últimas $N - K + 1$ y quedarte con esos resultados. El máximo de esos resultados es la solución al problema. Un posible pseudocódigo para resovlerlo es:

```
   resta N - K y guárdalo en la variable
   en el renglón de las sumas de prefijos aprende las primeras N - K + 1 sumas recursivamente
   ve al final del renglón de las sumas de prefijos y resta recursivamente los valores que aprendiste
   obten el mayor de las restas
```

## Segunda subtarea. Hay negativos, no hay limite de movimientos (35 puntos)

La solución a la segunda subtarea es similar a la primera, pero requieres encontrar una forma de manejar números negativos.

Una posible forma de hacerlo es utilizar un renglon para los números positivos y otro para los negativos. Con la idea de la primera subtarea, al momento de obtener las diferencias, si la diferencia es positiva la dejas en un renglón (por ejemplo el renglón 2) y si la diferencia es negativa dejas el valor absoluto en otro renglón (por ejemplo el renglón 3). Luego repites las **sumas de prefijos** en el renglón de positivos y de negativos por separado. Finalmente la _hermosura_ de la foto se calcula restando la suma de un rango de prefijos negativos del mismo rango de prefijos positivos. **OJO** esto podría darte como resultado un negativo, pero el problema te dice que la respuesta es mayor o igual a 0, por lo tanto si una resta es negativa puedes ignorarla y dejar 0.

## Tercera subtarea. Límite de movimientos (30 puntos)

Una forma de resolver el problema con movimientos limitados es utilizar la observación de una **suma telescópica**.

### Suma telescópica

Una suma telescópica es una serie de sumas en las que algunos términos se cancelan dejando al final un número fijo de términos sin importar la cantidad de sumandos originales.

En el caso específico de este problema requieres la suma de un rango de diferencias. A su vez cada diferencia se obtiene de una resta de alturas contiguas. Entonces supón que:

$m_i$ es la altura de la montaña en la posición $i-ésima$

$d_i$ es la diferencia de alturas de las montañas $i$ e $i + 1$, es decir $d_i = m_{i+1} - m_i$

y el resultado se obtiene del máximo de sumar $K$ diferencias contiguas. ¿Cómo calculas de forma sencilla el resultado de la suma $d_i + d_{i+1} + d_{i+2} + ... + d_{i+K-1}$?

Substituye cada $d_i$ por las alturas que se usan para obtenerlo:

$d_i + d_{i+1} + ... + d_{i+K-1} = S = (a_{i+1} - a_i) + (a_{i + 2} - a_{i + 1}) + ... + (a_{i + K} - a_{i + K - 1})$

reordenando los términos puedes ver que:

$S = (-a_{i}) + (a_{i+1} - a_{i+1}) + (a_{i+2} - a_{i+2}) + ... + (a_{i+K-1} - a_{i+K-1}) + a_{i+K}$

puedes ver que los términos se cancelan y te quedas únicamente con:

$S = a_{i+K} - a_{i}$

### Solución tercer subtarea

Por lo que para obtener los 100 puntos en este problema basta con restarle a cada montaña la altura de la montaña $K$ posiciones al oeste de ella y quedarse con el máximo de los resultados.

**NOTA INTERESANTE:** Si observas la solución de 100 puntos puedes ver que es la última parte de la solución de la primer subtarea. De hecho, si fuiste observador, habrás notado que la **suma de prefijos** es exactamente igual a la lista de alturas originales. Esto podía haberte dado una pista para resolver el problema aún sin conocer el concepto de la **suma telescópica**
