# Distancia - Solución

En este documento veremos las soluciones para cada subtarea posible.

## Subtarea 1: 20 puntos

Los límites en esta subtarea son:

- $1\leq N, Q\leq100$
- $0 \leq x, y \leq 100$

Para esta subtarea la solución esperada es simular lo que nos pide el problema, en otras palabras hacer una [BFS](https://es.wikipedia.org/wiki/B%C3%BAsqueda_en_anchura) por cada query desde cada posición inicial hacia las ovejas, el primer momento en el que estemos posicionados en una oveja es la respuesta a esa query.

Sea $\textbf{maxÁrea}$ igual a la máxima área posible, en este caso sería a la máxima longitud por el máximo ancho, que es $ 101 \times 101$. Entonces $\textbf{maxÁrea} = 10201$

Complejidad en memoria de $O(\textbf{maxÁrea})$  
Complejidad en tiempo de $O(\textbf{maxÁrea} \times Q)$

<details><summary>Solución para la Subtarea 1 (20 puntos)</summary>

{{parcialA.cpp}}

</details>

## Subtarea 2: 35 puntos

Los límites en esta subtarea son:

- $1 \leq N, Q \leq 1000$
- $0 \leq x, y \leq 1000$

En esta subtarea nos haremos una pregunta, ¿cuántos pasos nos toma ir de una posición $(x_1, y_1)$ a una posición $(x_2, y_2)$?

Esto se puede calcular con la siguiente fórmula:
$\text{pasos} = \max\left(\left| x_1 - x_2 \right|, \left| y_1 - y_2 \right|\right)$

Basándonos en esta fórmula podemos hacer lo siguiente: por cada query que nos hagan calcular el mínimo entre los pasos de la posición inicial y todas las ovejas.

Esto nos deja con las siguientes complejidades:  
Complejidad en memoria de $O(N)$  
Complejidad en tiempo de $O(N \times Q)$

<details><summary>Solución para la Subtarea 2 (55 puntos)</summary>

{{parcialB.cpp}}

</details>

## Subtarea 3: 45 puntos

Para resolver el problema completamente se tiene que tomar en cuenta que los límites son muy grandes para poder hacer algo por cada query.  
La solución esperada para los 100 puntos es la siguiente:  
Hacer una [BFS](https://es.wikipedia.org/wiki/B%C3%BAsqueda_en_anchura) con punto de inicio en cada oveja hacia todas las direcciones, de esta manera podremos saber la cantidad mínima de pasos para cualquier punto $x, y$, contestando cada query en $O(1)$.

El precálculo en este caso la complejidad tanto en espacio de memoria como complejidad en tiempo es la mayor área posible que es $1001 \times 1001$, esto debido a que la [BFS](https://es.wikipedia.org/wiki/B%C3%BAsqueda_en_anchura) se va a expandir hasta cualquier posición posible que pregunten.

Nótese que cada query se contestará en $O(1)$ por lo que se hacen $Q$ operaciones también, entonces:  
Complejidad en memoria de $O(\textbf{maxÁrea})$  
Complejidad en tiempo de $O(\textbf{maxÁrea} + Q)$

<details><summary>Solución para la Subtarea 3 (100 puntos)</summary>

{{solution.cpp}}

</details>

[Aquí puedes encontrar un video explicando la solución.](https://www.youtube.com/watch?v=mmbnd8zZ0gU)
