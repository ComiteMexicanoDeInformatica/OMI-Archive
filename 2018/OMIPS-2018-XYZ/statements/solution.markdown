# XYZ

Para resolver este problema, despreocupémonos por el momento de que existen figuras inválidas y consideremos solo la $x$, $y$ y $z$. 

La clave esta en identificar una casilla (o varias) a las que pueda llegar y me permitan diferenciar entre estas tres. Proponemos la casilla más abajo de la figura.

En esta casilla, orientados al norte, nos damos cuenta que si hay paredes a la izquierda y a la derecha, entonces nos encontramos encerrados o en una $x$ o en una $y$. Caso contrario estamos encerrados en una $z$. 

Ahora bien, para distinguir entre $x$ y $y$ podemos avanzar a la casilla del norte y aplicar el mismo criterio que antes. Si seguimos bloqueados a la izquierda y derecha, entonces corresponde una $y$; de otra forma podemos decir que estamos en una $x$.

Una vez obtenido nuestro único posible candidato a figura, lo que nos queda es verificar si en efecto nos encontramos dentro de una $x$, $y$ o $z$ (Nótese que en este punto ya sabríamos que figura es si se tratara de una figura válida). Para esto, no nos queda más que checar casilla por casilla. En el momento que una casilla no coincida con la cantidad y posición de las paredes que contiene esa celda en la figura que estamos checando, podemos afirmar que la figura es inválida. Si al final no encontramos diferencia alguna, nuestro inicial candidato es la figura correcta.