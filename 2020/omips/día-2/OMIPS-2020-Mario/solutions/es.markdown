# Mario - Solución

**Observación 1.** El estado mundo será igual para todo tiempo par y será el mismo invertido para todo tiempo impar.

Es muy intuitivo ver que esto es cierto si dibujamos el mundo en los primeros segundos. Para demostrarlo notar que si una casilla está en cierto estado (0 o 1 zumbador) al tiempo $i$ estará en el mismo estado al tiempo $i+2$. Por lo que estará en el mismo estado en los tiempos $t = 0, 2, 4, ...$ y estará en el estado opuesto en los tiempos $t = 1, 3, 5, ...$.

De esta observación obtenemos que **solo importa entonces la paridad con la que podemos llegar a una casilla**.

**Observación 2.** La paridad con la que podemos llegar a una casilla es única.

Es un poco más complicado notar esto si no está uno acostumbrado a trabajar con paridades. Para demostrarlo pintemos el mundo como un tablero de ajedrez:

![Tablero de Ajedrez](ajedrez.png)

Intentemos llegar de la casilla inferior izquierda (negra) a cualquier otra casilla negra. No importa el camino que tomemos, estará dado por _negra -> blanca -> negra -> blanca -> negra_ que siempre será de tamaño par. Análogo, a cualquier casilla blanca llegaremos en tiempo impar sin importar el camino elegido.

Así, **no importa el camino que elijamos, siempre tendremos el mismo estado en la casilla**. También vemos que entonces nos conviene pasar por todas las casillas del mundo para ver cuáles monedas podríamos recoger.

Por lo tanto, la solución es sencilla. Hacer un recorrido en zigzag en el mundo, donde si estamos en una casilla negra y hay un zumbador, contamos una moneda y si estamos en una casilla blanca y no hay zumbador, también lo contamos (porque habríamos llegado en un tiempo impar, que cambiaría el estado de esa casilla).

[Aquí puedes encontrar un video explicando la solución.](https://www.youtube.com/watch?v=0o8iIHCDHhE)
