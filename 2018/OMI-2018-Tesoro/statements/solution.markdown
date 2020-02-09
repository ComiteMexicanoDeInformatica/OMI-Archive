En este problema, la tarea es escribir la función `BuscaTesoro`, donde conocemos las dimensiones
de la cuadrícula $n$ y $m$, así como la cantidad de tesoros que podemos encontrar, $k$.

La función `Preguntar(i,j)` nos dirá la cantidad de tesoros entre la $(1,1)$ y la $(i,j)$.
Sin embargo, con esta información no sabemos si hay tesoro en la posición $(i,j)$,
a menos que sea la $(1,1)$. Pero podemos usar información de casillas adyacentes para conocerlo.
Si conocemos lo siguiente:

$T_1$ = `Preguntar(i,j)`,   
$T_2$ = `Preguntar(i-1,j)`,  
$T_3$ = `Preguntar(i,j-1)`,

el valor de $T_1$ - $T_2$ - $T_3$, nos dice todo lo que hay de $(1,1)$,
y le estamos quitando lo que hay hasta la columna anterior, y también lo que hay hasta la fila anterior.
El problema está en que estamos quitando 2 veces lo que hay entre la $(1,1)$ y la $(i-1,j-1)$,
por lo tanto, si conocemos

$T_4$ = `Preguntar(i-1,j-1)`,

ya sabemos que $T_1 - T_2 - T_3 + T_4$ nos dará $1$ si hay un tesoro en la posición $(i,j)$, o $0$ en caso contrario.

Así, podemos lanzar 2 iteraciones anidadas, las cuales van recorriendo cada posición, entonces podemos
hacer lo descrito anteriormente para saber la solución, en cada posición mandando a llamar a `Preguntar`
$4nm$ veces. Cabe mencionar que esto nos dará 0 puntos, pero podemos dar el siguiente paso:
Si cuando queremos saber lo de $(i,j)$, ya tenemos calculada la respuesta para
$(i,j-1)$, $(i-1,j)$ y $(i-1,j-1)$, para obtenerlas tuvimos que conocer la cantidad de tesoros entre
$(1,1)$ y la $(i,j-1)$, la $(i-1,j)$ y la $(i-1,j-1)$, por lo que si guardamos estos valores, ya no es
necesario hacer llamadas extra, haciendo solo $nm$ preguntas, lo cual recibirá algunos puntos.

Pero ahora podemos dar otro paso:
Si existe una fila $c$, tal que `Preguntar(n,c)`, regresa uno más que `Preguntar(n,c-1)`,
es porque en la columna $c$ efectivamente hay un tesoro, por lo que podemos recorrerla para
saber en qué fila está en ese tesoro. Así, ya no preguntaremos $n$ veces en columnas vacías, y en
cada columna, podemos dejar de preguntar una vez que encontramos el tesoro, reduciendo la cantidad de
preguntas realizadas. Además, si ya sabemos que en una columna no hay tesoros, podemos conocer por
nuestra cuenta lo que regresará `Preguntar(i,j)`, ya que será lo mismo que `Preguntar(i,j-1)`, lo cual,
conocimos de esta misma forma, o porque buscamos la posición de un tesoro y tuvimos que preguntarlo,
teniendo $nm$ preguntas en el peor de los casos, pero puede crecer la cantidad de puntos. 

Ahora, dentro de una columna de la cual ya sabemos que hay un tesoro, en lugar de ir uno por uno,
podemos cambiarlo por una búsqueda binaria donde ahora, si conocemos la cantidad de tesoros de la posición
$(1,c)$ a la $(f,c)$, tendremos $1$ si estás en la fila donde está el tesoro, o en una fila después,
y si da 0, es que es una fila antes. Y para obtener ese valor, podemos hacer `Preguntar(i,j)` - `Preguntar(i,j-1)`.
Y ya dijimos que si lo hacemos en orden, cuando estemos en $(i,j)$, lo de $(i,j-1)$ ya lo sabemos.
Entonces hacemos una búsqueda binaria para saber la fila del tesoro. Eso nos permite hacer $\log_2(n)$
preguntas en cada fila, dando $m\log_2(n)$ total. Y aprovechando esta misma propiedad que nos permite
hacer búsqueda binaria, la ocupamos para determinar lo que regresará `Preguntar` en toda esa columna.

Pero eso no es todo, podemos hacer la misma idea para encontrar la siguiente columna con tesoro.
Si ya tenemos que en la columna $c$ hay tesoro, llamando `Preguntar(n,d)`, con $d > c$, si es mayor
que `Preguntar(n,c)`, es porque ya estamos en la primer columna con tesoro después de c, o en una columna
después. Si resulta ser igual, es porque estamos en una columna antes. Entonces podemos hacer la
binaria buscando la primera fila $d$ que cumpla lo establecido, haciendo $\log_2(m)$ preguntas.

Y sabemos que en total hay $k$ tesoros, entonces $k$ veces tenemos que buscar la siguiente columna con
tesoro (que nos toma $\log_2(m)$ preguntas), y dentro de esa columna, buscar la fila que lo tiene
(que nos toma $\log_2(n)$ preguntas). Una vez encontrado el $k$ésimo tesoro, nos detenemos.

Así, realizamos en total la siguiente cantidad de preguntas: $k(\log_2(m) + \log_2(n))$,
y ya, finalmente, aseguramos los 100 puntos de esta forma. Obviamente, una vez que sabemos
que en una posición $(i,j)$ hay un tesoro, hay que llamar a $Cavar(i,j)$.
