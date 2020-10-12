# Kuadtri - Solución

La dificultad principal de este problema está en saber a qué casilla debemos ir. Primero podemos
medir el mundo para determinar su tamaño, y la potencia de $2$ con la que estamos trabajando. Sea $2^n$
el tamaño del mundo.

La primera observación que podemos hacer es que el número $x$ de la casilla $(1,1)$ necesariamente
va a ser igual a $4^0 + 4^1 + \ldots + 4^n + k$, con $0 \leq k < 4^n$. Esta suma corresponde precisamente
a los números que se utilizaron en las regiones del mundo que son más grandes que una casilla.

Adicionalmente, podemos ver que $k$ es todo lo que necesitamos para saber a dónde dirigirnos. Si escribimos
a $k$ en base $4$, tenemos $k = a_{n-1} 4^{n-1} + a_{n-2} 4^{n-2} + \ldots + a_0 4^0$. Por cómo se asignaron
los números de las regiones, podemos observar que las $a_i$ nos están diciendo las direcciones a seguir para
llegar a la región donde vive Kuadtri.

Para resolver el problema, entonces, necesitamos calcular $n$, restar las potencias de $4$ que no necesitamos,
y finalmente ir calculando los coeficientes $a_i$ uno por uno, para así recursivamente ir siguiendo las
instrucciones para llegar a la casilla deseada.

[Aquí puedes encontrar un video explicando la solución.](https://www.youtube.com/watch?v=5K3bqaRNjy4)
