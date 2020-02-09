La primera posible observación era una idea greedy: para cada figura determinar el
rectángulo de menor área tal que la cubre. Esta idea desafortunadamente no funciona,
ya que los rectángulos que resulten de esto puede que se toquen.

Sin embargo, se puede arreglar esto repitiendo el mismo proceso mientras que en cada
iteración se pinte al menos una casilla que antes no lo estaba.

Para determinar el rectángulo de menor área que cubre una figura se puede hacer una DFS
(búsqueda en profundidad) desde alguna de sus casillas y guardar "la más a la izquierda",
"la más abajo", "la más a la derecha" y "la más arriba" de entre todas las que se
alcanzaron y pintar el rectángulo delimitado por estos valores.

Está solución tiene complejidad $O(2 \cdot N \cdot M \cdot K)$ que con
algunas podas podría entrar en tiempo.

Sin embargo, una solución más eficiente para estos limites es trabajar sobre la
cantidad de figuras.

Si guardamos los cuatro valores antes mencionados para cada una de las $K$ figuras,
checar si cualesquiera dos de ellas chocan es trivial considerando unos pocos casos.
Como recomendación podrías en su lugar checar si no chocan.

Entonces, si para cada figura iteramos contra todas las demás y las "unimos" en caso
de que choquen, y mientras se hayan "unido" al menos un par de figuras seguir haciéndolo
nos genera un algoritmo de complejidad $O(K^3)$ que entra más cómodamente.
Al final seria solo pintar los rectángulos que te quedaron sin unir.
