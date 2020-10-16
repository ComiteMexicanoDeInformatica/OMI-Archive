# Mensajería - Solución

La solución de este problema es un greedy. Si la ruta de $i$ a $i+1$ tiene un costo menor a $K$, entonces pon esa ruta. Si en cambio ese costo ($a_i$) es mayor o igual a $K$ mejor pon una central de envío.

Si todas las rutas de envío tienen costo menor a $K$, entonces quita la ruta más cara y remplaza por una central de envío.

## Justificación

Una manera de justificar el algorimo anterior es la siguiente. Imagina un grafo con $N+1$ nodos inicialmente desconectados. Los $N$ primeros nodos son los cuarteles y el otro nodo es la central de envío.

El objetivo es entonces conectar todos estos nodos con el menor costo, donde las aristas posibles son las que van desde el nodo "central de envío" a todos cualquier $N$ cuartel con costo $K$ y además las que conectan los cuarteles $i$ con $i+1$ con costo $a_i$.

Este problema entonces se reduce al Minimum Spanning Tree (MST) que demuestra que nuestro greedy propuesto da la solución correcta, pues nuestro greedy es una versión muy simple del algoritmo de Kruskal.
