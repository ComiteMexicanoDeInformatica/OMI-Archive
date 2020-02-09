Observemos que podemos interpretar la información que se nos da acerca de las puertas como un grafo dirigido.

Notemos que la única condición que tiene que cumplir una puerta para que no se pueda cerrar
es que pertenezca a algún ciclo de nuestro grafo.
Esto ya que si al abrir una puerta X, después de abrir otras puertas, se vuelve a abrir X,
entonces ese proceso se repetirá infinitamente, sin que lleguemos a lograr cerrar X.

De este modo, el problema se reduce a verificar por cada una de las puertas que nos dan como pregunta,
si alguna de ellas genera o pertenece a un ciclo (el ciclo no necesariamente tiene que incluir a la puerta
que estamos evaluando).

Para encontrar si un nodo pertenece a un ciclo, basta con ver que ninguno de sus hijos pertenezca a un ciclo.
Notemos que esto satisface las propiedades de una función recursiva, puesto que estamos resolviendo el mismo problema,
pero con diferente información cada vez.

Así pues, definimos una función recursiva como sigue.

	dfs(nodo){
		si nodo no tiene hijos, entonces no genera ningun ciclo, por lo tanto, regresamos 1, que indica que el nodo actual no genera ciclo.
		si ya visitamos anteriormente a nodo, verificar si ya concluimos si el nodo no genera un ciclo. Si lo genera o no hemos calculado con anterioridad si lo genera, regresamos 0, indicando que genera un ciclo, en caso contrario regresamos 1.
		Por cada uno de los hijos de nodo haz: {
			suma=suma+dfs(hijo_actual_de_nodo);
		}
		Si la suma es igual a la cantidad de hijos, significa que ninguno de sus hijos genera un ciclo. Por lo tanto, regresamos 1, indicando que nodo no genera algún ciclo.
		En caso contrario, regresamos 0.
	}
	
Por cada pregunta, basta con ver si alguna de las puertas que nos dan como entrada nos regresó 0 en algún momento en la función dfs. Si esto sucede, entonces imprimimos N. En caso contrario S.
