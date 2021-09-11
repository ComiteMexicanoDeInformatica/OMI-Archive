El señor Burns se levantó de buenas y le dio vacaciones a Homero, tú tendrás que cubrir su puesto en la planta nuclear.

Homero te explicó rápidamente la planta. La planta nuclear de Springfield tiene $N$ reactores numerados del $1$ al $N$ conectados entre sí por $M$ conexiones **unidireccionales**, esto quiere decir que una conexión que va del reactor $a$ al $b$ $(a \rightarrow b)$ no puede usarse en sentido contrario $(a \nleftarrow b)$.

Homero te advierte que la planta es vieja y los reactores pueden fallar de pronto y volverse _inestables_. La advertencia de Homero te preocupa por lo que te pones a investigar y averiguas lo siguiente:

- Si un reactor se vuelve _inestable_, comienza a emitir radiación y pasa una de las siguientes dos cosas:
  - Si el reactor _inestable_ tiene conexión a otros reactores, la radiación hace que todos ellos se vuelvan _inestables_.
  - Si el reactor _inestable_ **no está conectado a ningún reactor, la radiación se emite al medio ambiente**.

Observa que un reactor puede volverse _inestable_ aun sin estar conectado directamente al reactor que falló. Observa la figura.

![Figura 1](figura1.png)

Cuando un reactor es _inestable_ la única forma de volverlo a la normalidad es eliminar la causa de su inestabilidad, por ejemplo, si es _inestable_ porque falló, se requiere reparar la falla; si es _inestable_ porque está recibiendo radiación de otro reactor, se requiere que el reactor que emite la radiación se estabilice y deje de radiar. **Si un reactor tiene más de una causa de _inestabilidad_, todas las causas deben ser eliminadas antes de que pueda volverse estable.**

Hay dos tipos de _inestabilidades_ que son:

- **Simple:** El reactor tiene sólo una causa de _inestabilidad_.
- **Compuesta:** El reactor tiene dos o más causas de _inestabilidad_.

La figura 2 muestra de qué tipo son las _inestabilidades_ en el caso de la figura 1. Observa que el reactor que falla originalmente (el rojo en la figura 1) tiene una _inestabilidad compuesta_ ya que las causas de su _inestabilidad_ son: 1) la falla y 2) la radiación que recibe de un reactor _inestable_.

![Figura 2](figura2.png)

Cuando un reactor falla se dice que la planta entra en _crisis_. Hay tres tipos de _crisis_:

- **Bajo nivel:** En esta _crisis_, si se repara la falla del reactor inicialmente _inestable_, el resto de los reactores vuelve a la normalidad al cabo de un tiempo.
- **Grave:** En esta _crisis_, si se elimina la falla del reactor inicialmente _inestable_, existe un conjunto de reactores que quedan en _inestabilidad simple_.
- **Severa:** Crisis en la que si se elimna la falla del reactor inicialmente inestable, existe un conjunto de reactores que quedan en _inestabilidad compuesta_.

Quieres estar preparado (te gustaría impresionar a Homero) así que piensas escribir un programa que pueda decirte qué pasaría si falla alguno de los reactores.

# Problema

Escribe un programa que dada la configuración de los reactores y un posible reactor de falla sea capaz de contestar tres cosas:

- ¿Qué tipo de _crisis_ se generaría? (Bajo nivel, Grave o Severa)
- ¿Cuántos reactores estarán emitiendo radiación al medio ambiente durante la falla?
- ¿Cuántos reactores continuarán emitiendo radiación al medio ambiente luego de que se corrija la falla?

# Entrada

- La primera línea contiene los números $N$, $M$ y $R$. La cantidad de reactores, la cantidad de conexiones y el número de reactor que falla.
- Las siguientes $M$ líneas contiene dos enteros $a$ y $b$ indicando que la conexión va del reactor $a$ al reactor $b$.

# Salida

- En la primera línea un carácter que indique el tipo de _crisis_. Debes usar **B** para _bajo nivel_, **G** para _grave_ y **S** para _severa_.
- En la segunda línea debe haber dos números que indiquen la cantidad de reactores que emiten radiación al medio ambiente durante la falla y la cantidad de reactores que continúan emitiendo radiación al medio ambiente luego de corregir la falla.

# Ejemplo

||input
10 12 1
1 2
1 3
2 4
3 4
4 5
6 7
7 6
7 1
7 8
8 6
9 10
10 9
||output
B
1 0
||description
La imagen muestra el reactor con falla y los reactores \_inestables.\_Bajo

![Figura 3](figura3.png)

La crisis es de _Bajo nivel_ ya que al corregir la falla en el reactor $1$ los demás reactores vuelven a ser estables.

Durante la falla, el reactor $5$ emite radiación al medio ambiente, al corregirse la falla ningún reactor emite radiación.
||input
10 12 10
1 2
1 3
2 4
3 4
4 5
6 7
7 6
7 1
7 8
8 6
9 10
10 9
||output
G
0 0
||description
![Figura 4](figura4.png)

Aunque se corrija la falla del reactor $10$ este permanece inestable porque sigue recibiendo radiación del reactor $9$.

No hay ningún reactor que emita partículas al medio ambiente ni durante la falla ni luego de que esta se corrija.
||input
10 12 7
1 2
1 3
2 4
3 4
4 5
6 7
7 6
7 1
7 8
8 6
9 10
10 9
||output
S
1 1
||description
![Figura 5](figura5.png)

El reactor $6$ recibe radiación del reactor $7$ y el reactor $8$ por lo que se encuentra en _inestabilidad compuesta_. Al corregir la falla del reactor $7$ este permanece inestable porque está recibiendo radiación del reactor $6$ y el reactor $6$ permence en _inestabilidad compuesta_.

Durante la falla y luego de que esta se corrija, el reactor $5$ emite partículas al medio ambiente.
||input
7 8 1
1 2
2 3
3 4
4 2
1 5
5 4
3 6
5 7
||output
G
2 1
||description
||end

# Límites

- $1 \leq N, M \leq 10^5$
- $1 \leq R \leq N$
- $1 \leq a, b \leq N$

# Evaluación

En este problema se evaluará por separado si tu programa puede detectar el tipo de _crisis_ y si hace correctamente el cálculo de emisiones de partículas.

Si tu programa detecta correctamente el tipo de _crisis_ obtendrás **50%** de los puntos.
Si tu programa calcula correctamente el número de partículas emitidas al medio ambiente obtendrás **50%** de los puntos.

# Subtareas

- **(12 puntos)**: $a < b$ para todas las conexiones. $N \leq 1000$
- **(24 puntos)**: $a < b$ para todas las conexiones.
- **(12 puntos)**: $a < b$ para todas las conexiones menos una. $N \leq 1000$
- **(24 puntos)**: $a < b$ para todas las conexiones menos una.
- **(28 puntos)**: Sin restricciones adicionales.
