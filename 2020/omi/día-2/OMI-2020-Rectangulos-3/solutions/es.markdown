# Ciudad Rectángulos - Solución

Por la naturaleza de este problema, hay muchas formas de llegar a una solución correcta. En este documento nos vamos a enfocar en cómo se puede ir mejorando una solución hasta llegar a la correcta. Usaremos Karel para visualizar los mapas.

Si analizamos la fórmula que nos piden maximizar $$(\text{número de zumbadores totales} - \text{número de rectángulos de tamaño repetido}) \times (\text{número de tamaños distintos})$$,

Se nos pide que busquemos un balance entre rectángulos de mayor área y la cantidad de rectángulos de distintos tamaños. Podemos empezar con una construcción muy básica de rellenar todo el mundo para hacer 1 solo rectángulo del área máxima. Es intuitivo ver que no hay otra construcción de 1 rectángulo que dé más puntos que esta.

![1 solo rectángulo](1-rect.png)

<details><summary>Solución con un sólo rectángulo (~4 puntos)</summary>

{{one_rect.cpp}}

</details>

Lo siguiente que podemos intentar es partir este rectángulo en 2, esto deberia de darnos mas puntos que la anterior excepto si al partir el rectángulo queden 2 del mismo tamaño. La manera mas fácil de hacer esto es simplemente hacer un rectángulo de 1 de ancho y el otro del resto.

![2 rectángulos](2-rect.png)

<details><summary>Solución con dos rectángulos (~8 puntos)</summary>

{{two_rects.cpp}}

</details>

Siguiendo esta idea podemos mejorar la construcción si hacemos rectángulos de 1 ancho, de 2 de ancho, de 3 de ancho y así hasta llegar a la pared

![n rectángulos](n-rect.png)

<details><summary>Solución con $n$s rectángulos (~16 puntos)</summary>

{{columns.cpp}}

</details>

Si tomamos en cuenta las consideraciones:

- Un rectángulo de tamaño $AxB$ se considera diferente de un rectángulo de tamaño $BxA$.
- Un cuadrado es un rectángulo.

Podemos hacer el proceso anterior en las columnas y en las filas y esto construirá todos los rectángulos desde 1x1 hasta nxn.
Esta construcción es la mejor para un mundo cuadrado. Si intentamos partir cualquier rectángulo obtendríamos uno repetido y si intentamos hacer mas grande cualquier rectángulo nos cabrían menos rectángulos.

![nxn rectángulos](nxn-rect.png)

Esta construcción solo es óptima en los mundos cuadrados donde los cortes sean exactos. Para mundos rectangulares o con cortes no exactos hay que considerar las siguentes observaciones:

- Conviene más no hacer el último corte para maximizar el área y no tener repetidos.
- El area sobrante se puede dividir en 2 rectángulos.
- En estos rectángulos se puede continuar haciendo cortes partiendo del último tamaño que se hizo completo.

La solución oficial construye un rectángulo de la siguiente forma.

![solución oficial](full-score.png)

<details><summary>Solución oficial</summary>

{{solution.cpp}}

</details>
