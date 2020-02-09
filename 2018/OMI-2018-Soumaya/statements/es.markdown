En tu viaje a la Ciudad de México visitaste el museo Soumaya y tu vena artística volvió a la vida.

Al buscar tus herramientas de pintura, encontraste lienzos de cuando ibas a clases de pintura.
Te diste cuenta que las figuras en estos lienzos estaban sin terminar y no las quieres dejar así.

Una figura está compuesta por casillas contiguas pintadas.
Dos casillas son contiguas si comparten un lado entre ellas.
Se considera que una figura está terminada si su forma es rectangular
(un cuadrado también es un rectángulo).

Se considera que el lienzo está terminado cuando contiene únicamente figuras terminadas no contiguas.

Aquí se muestran dos lienzos iniciales, el primero con una sola figura, y el segundo con dos figuras.

![ejemplo entrada](Figura1.png)

Aquí se muestra cómo ven las figuras terminadas.

![ejemplo salida](Figura2.png)

# Problema

Escribe un programa que se asegure que tu lienzo contiene sólo figuras terminadas utilizando
la menor cantidad de pintura posible.
Tu programa recibirá puntos dependiendo de la cantidad de pintura que uses
(revisa la sección de Evaluación para tener más detalle).

# Entrada

Dos enteros $N$ y $M$ que representan el número de filas y columnas respectivamente;
seguidos de $N$ líneas con $M$ caracteres. Cada casilla tiene un $1$ si ya está pintada o un $0$ si está vacía.

# Salida

Una matriz de $N \times M$ que sea la representación del lienzo que
contenga únicamente figuras terminadas.

# Ejemplo

||input
4 6
000100
011110
000010
000000
||output
011110
011110
011110
000000
||input
4 6
001000
011010
000011
000000
||output
011000
011011
000011
000000
||input
5 9
111100000
100000000
100011101
000010000
010010000
||output
111111100
111111100
111111101
111111100
111111100
||end

# Evaluación

Tu programa obtendrá puntos dependiendo de cuánta pintura utilizaste para pintar el lienzo.
Si utilizaste la mínima cantidad de pintura necesaria, obtendrás todos los puntos para ese caso.
De lo contrario, obtendrás una cantidad parcial de puntos.

Si el lienzo contiene figuras no terminadas,
o despintaste algún cuadrito que inicialmente estaba pintado, obtendrás 0 puntos para ese caso.

# Límites

* $1 \leq N,M \leq 1500$
* $1 \leq NM \leq 10^6$
* Cada lienzo puede contener desde 1 hasta 400 figuras.

# Subtareas

* En el 14% de los casos, se cumple que $1 \leq N,M \leq 25$.
* En el 20% de los casos, se cumple que $1 \leq N,M \leq 50$.
* En el 36% de los casos, se cumple que $1 \leq NM \leq 10^4$.
* Para 30% restante de los casos no hay consideraciones adicionales.
