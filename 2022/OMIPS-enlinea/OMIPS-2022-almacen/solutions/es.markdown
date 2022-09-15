# Solución oficial para Karel y el Almacén (OMIPS 2022)

Para resolver este problema ayuda conceptualizarlo de una forma diferente a la que se plantea en el texto. En la programación competitiva, ser capaz de abstraer la historia planteada en algún modelo matemático con propiedades que conozcas es una de las herramientas más poderosas que puedes adquirir, es muy recomendable que lo practiques.

Las restricciones del problema te piden que sea cual sea el acomodo que hagas, se debe poder llegar de cualquier casilla libre a cualquier otra casilla libre del almacén. Digamos que dos casillas libres adyacentes están _conectadas_ si no hay pared entre ellas. Además, digamos que dos casillas libres $A$ y $B$ **NO adyacentes** están _conectadas_ si existe un camino de casillas libres adyacentes _conectadas_ por el que se puede llegar desde $A$ hasta $B$.

La siguiente figura ilustra el concepto de casilla _conectada_. En la figura de la izquierda se observa las casillas adyacentes _conectadas_, en la figura de la derecha, cada círculo azul representa una casilla y cada línea muestra las casillas adyacentes a las que está _conectada_. Observa que si inicias desde cualquier casilla con círculo azul puedes encontrar un camino de líneas azules que te lleve a cualquier otro círculo azul del mundo.

![Casillas _conectadas_](figura1.png)

Si eliminas el mundo de Karel y te quedas únicamente con el diagrama de casillas _conectadas_ (en programación competitiva un diagrama de este tipo se conoce como **grafo**) verás que en ese diagrama existen 2 tipos de estructuras básicas, líneas y ciclos. La siguiente figura muestra el **grafo** conectado del mundo y un ejemplo de línea y ciclo. Observa que en el caso de una línea, si Karel coloca una caja en una de las casillas intermedias de la línea, entonces desconecta las casillas en ambos extremos de la línea. Esto no pasa en los ciclos, en un ciclo, Karel puede colocar una caja en cualquier lugar del ciclo y todas las demás casillas permanecen _conectadas_. Observa también que si pones una caja en un ciclo, _rompes_ ese ciclo y lo conviertes en una línea.

![Grafo](figura2.png)

Para que el almacén esté siempre conectado se requiere entonces que en caso de que haya _líneas_ en el grafo de conexión, Karel siempre ponga las cajas en los extremos de las líneas y cuando ya no existan _líneas_ entonces Karel ponga la caja en el ciclo de modo que cree una nueva _línea._

Este proceso puede sonar complicado de llevar a cabo, sin embargo existe una herramienta muy común en programación para hacer que se llama [búsqueda en profundidad](https://es.wikipedia.org/wiki/B%C3%BAsqueda_en_profundidad) y casualmente es justo lo que Karel sabe hacer mejor :)

Haciendo una búsqueda en profundidad Karel puede ir recorriendo el almacén y buscando los extremos de las líneas para ir acomodando cajas.

Uno de los detalles importantes es cómo llevar la cuenta de cuántas cajas le faltan por acomodar a Karel, ya que Karel no puede _regresar_ valores en la recursión. Una forma sencilla y que normalmente se puede utilizar para devolver valores en el regreso de la _recursión_ es utilizar la casilla del mundo en la que está Karel. Ese es el método que usa la solución oficial.

<details><summary>Solución oficial. Búsqueda en profundidad (DFS).
</summary>

{{solution.kp}}

</details>
