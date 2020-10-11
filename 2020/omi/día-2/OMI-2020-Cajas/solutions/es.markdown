# Cajas - Solución

## Subtarea 2 $(N \le 100)$ $O(N^2)$

En este problema lo más importante es notar que una estrategia greedy nos da una respuesta correcta. Pero no el primer acercamiento que podemos tener de ir poniendo las cajas de la más fuerte a la más débil en orden y haciendo una nueva torre cada que ya no puedas poner una caja encima. Sino, ir poniendo las cajas de las más débiles a las más fuertes, poniendo las cajas hasta abajo de la torre que tenga la menor cantidad de cajas.

Notemos que esto nos da una solución correcta, supongamos que hemos acomodado las primeras $m$ cajas (Primero notemos que cualquier acomodo que hagamos, se puede reordenar para que las torres esten ordenadas de la caja más fuerte a la más débil). Entonces al poner la $m+1$-ésima caja, habrá 2 opciones. O es posible ponerlo abajo de alguna de las torres(lo que no afectara la cantidad de torres). O si no se puede, creamos una nueva torre. Notemos que esto sería necesario, ya que esas $m+1$ cajas tendrían que ser puestas, y cualquier caja que pongamos al final tendría que estar en una nueva torre, ya que la más fuerte de esas no pudo estar con la cantidad de torres actual. Aqui podemos ver un pseudocódigo de la implementación:

<details><summary>Solución para las subtareas 1 y 2 (61 puntos)</summary>

{{61exp.cpp}}

</details>

## Subtarea 3 $(N \le 100000)$ $O(N)$

Para optimizar la solución anterior, usamos la técnica de guardar nuestros datos en [cubetas para ordenar](https://es.wikipedia.org/wiki/Ordenamiento_por_casilleros). Entonces al ordenar nuestras cajas y checarlas, tenemos complejidad $O(N)$. Para elegir en qué torre poner una caja, hacemos una técnica parecida al bucket donde guardamos en `torres[i]` la cantidad de torres de tamaño $i$, en cada momento guardamos el tamaño de la torre más pequeña y al poner una caja, ahí hacemos `torres[i]--; torres[i+1]++;` para actualizar su tamaño. Esta solución solo realiza una operación por caja, así que tenemos el pseudocódigo:

<details><summary>Solución para todas las subtareas (100 puntos)</summary>

{{solutionB.cpp}}

</details>
