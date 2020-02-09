En la Feria de Chapultepec se encuentra el juego Guacamole, la versión mexicana de Whac-a-mole
y obviamente quieres obtener la mayor cantidad de puntos posible.

El juego es una cuadrícula de tamaño $N \times M$ en la que hay un topo en cada casilla. Los topos están escondidos inicialmente
y en cada segundo salen topos de algunas casillas y se esconden topos de otras casillas. Obtienes puntos
por cada topo que logras golpear.

Para jugar tienes que seguir las siguientes reglas:

* El topo en la posición $(i,j)$ aparecerá por primera vez en el segundo $I_{i,j}$ y volverá a aparecer cada $S_{i,j}$ segundos. Por ejemplo si $I_{i,j}=2$ y $S_{i,j}=3$, aparecerá un topo en la posición $(i,j)$ en los segundos $(2,5,8,11 \ldots )$ y durará un segundo afuera antes de volver a esconderse. El segundo que está afuera el topo es el único momento en que puedes ganar puntos por golpearlo, es decir, si el topo sale en el segundo 2, puedes golpearlo en ese segundo, para el segundo 3, se habrá escondido de nuevo.
* Debes elegir en qué casilla pegar en el segundo 1, no importa si hay o no topo afuera.
* No puedes no golpear. Es decir, en cada segundo debes golpear alguna casilla, sin importar si hay o no un topo afuera.
* Como no eres tan rápido para moverte por las casillas, si golpeas en la casilla $(i,j)$,
tu siguiente golpe (en el siguiente segundo) debe ser en esa misma casilla o en alguna de sus
8 adyacentes. Es decir, si $(i,j)$ es la última casilla que golpeaste, en el siguiente turno puedes golpear las casillas $(i,j)$,$(i-1,j)$,$(i-1,j-1)$,$(i,j-1)$,$(i+1,j)$,$(i+1,j+1)$,$(i,j+1)$,$(i-1,j+1)$ y $(i+1,j-1)$ siempre y cuando estén dentro de la cuadrícula.
* Si golpeas en la posición $(i,j)$ y hay un topo afuera, se suman $P_{i,j}$ puntos a tu total. Si no hay un topo afuera, no se suma nada a tu total.

# Problema

Encuentra la mayor puntuación posible que se puede lograr con las reglas anteriores.

# Entrada

En la primera línea 3 enteros: $N$, $M$ y $T$ que representan el número de filas,
el número de columnas del tablero y los segundos que dura el juego, respectivamente.

Sigue la matriz $I$ de tamaño $N \times M$ que indica en qué segundo sale cada topo por primera vez.

Después una matriz $S$ de tamaño $N \times M$ que indica cuántos segundos tarda cada topo en volver a salir.

Por último una matriz $P$ de tamaño $N \times M$ que indica cuántos puntos obtienes si logras golpear al topo en cada casilla.

# Salida

Un entero que indica el puntaje más alto que se puede obtener en el juego.

# Ejemplo

||input
3 3 5
5 5 1
4 2 1
3 4 3
5 5 2
5 1 1
2 5 5
39 1 8
11 -100 -2
11 -1 23
||output
61
||description
Contando las filas y columnas a partir de 1 y siendo la posición (1,1) la esquina superior izquierda, es posible jugar como sigue:  
Segundo 1: golpeas en (1,2) con puntaje 1, el topo no ha salido por lo que obtienes 0 puntos.  
Segundo 2: golpeas en (2,1), puntaje 11, no hay topo, 0 puntos.  
Segundo 3: golpeas (3,1), puntaje 11, el topo sí está, agregas 11 puntos.  
Segundo 4: golpeas (2,1), el topo sí está, agregas 11 puntos.  
Segundo 5: golpeas (1,1), el topo sí está, agregas 39 puntos.   
Termina el juego, obtuviste 61 puntos.
||input
1 1 5
1
2
1
||output
3
||end

# Límites

* $1 \leq N,M \leq 100$
* $1 \leq T \leq 500$
* $1 \leq S_{i,j}, I_{i,j} \leq T$
* $-10^9 \leq P_{i,j} \leq 10^9$

# Subtareas

 * En el 30% de los casos, para todo $i,j$ 
  * $I_{i,j}=i+j-1$ (con $1 \leq i \leq N$, $1 \leq j \leq M$).
  * $S_{i,j}=T$ 
  * $0\leq P_{i,j}$ 
 * Para el 70% restante no hay consideraciones adicionales.
