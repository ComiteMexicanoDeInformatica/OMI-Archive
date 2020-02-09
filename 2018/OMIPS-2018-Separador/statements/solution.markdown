# Separador - Solución

Hay varias maneras de resolver este problema.

Para el primer conjunto de casos debemos aprovechar que Karel no tiene zumbadores en la mochila. Podemos recoger primero todos los zumbadores de la casilla (1, 1) y posteriormente pasar a la fila 2, y ahora la cantidad de zumbadores en la mochila nos indica por cuántos libros debemos pasar. Hacemos que Karel avance mientras aún tengas zumbadores en la mochila, y cada vez que encuentre un zumbador deje uno de los que tiene en la mochila. De esta manera, cuando la mochila de Karel está vacía sabemos que ha llegado al libro que queríamos.

El siguiente código muestra como hacer lo que acabamos de describir.

```
	define-nueva-instruccion busca como inicio
        mientras algun-zumbador-en-la-mochila hacer inicio
            si junto-a-zumbador entonces inicio
                deja-zumbador;
            fin;
            si algun-zumbador-en-la-mochila entonces
                avanza;
        fin;        
    fin;
```

Cuando Karel tiene infinitos zumbadores en la mochila, la solución anterior no funciona (Si recogemos los zumbadores de la casilla (1, 1) Karel seguirá teniendo infinitos zumbadores, y la mochila ya no nos indica cuánto debemos avanzar). Pero en este caso podemos aprovechar la recursividad con parámetros: contamos la cantidad de zumbadores en la casilla (1,1) con parámetros y luego pasamos a la fila 2 y sabemos que tenemos que pasar por una cantidad de libros igual al parámetro que llevamos (nota como el parámetro cumple la misma función que cumplía la mochila en la solución anterior).

Este código implementa el procedimiento que acabamos de describir:

```
define-nueva-instruccion busca(x) como inicio
    	si junto-a-zumbador entonces inicio
        	si si-es-cero(x) entonces inicio
            	apagate;
            fin sino inicio
            	avanza;
                busca(precede(x));
            fin;
        fin sino inicio
        	avanza;
            busca(x);
        fin;
    fin;

	define-nueva-instruccion cuenta(x) como inicio
    	si junto-a-zumbador entonces inicio
        	coge-zumbador;
            cuenta(sucede(x));
        fin sino inicio
        	avanza;
            gira(3);
            busca(x);
        fin;
    fin;
```

Hay una solución más que utiliza recursividad sin parámetros. Con un método recursivo recoge todos los zumbadores de la primera fila y aprovecha la recursividad para que por cada zumbador recogido Karel avance hacia el siguiente libro. Una vez recogidos todos los zumbadores mueve a Karel a la fila 2 y deja que la recursividad haga el resto, como se muestra en el siguiente código:

```
	define-nueva-instruccion avanza-zumbadores como inicio
    	si junto-a-zumbador entonces inicio
        	coge-zumbador;
            
            avanza-zumbadores;
            
            mientras no-junto-a-zumbador hacer inicio
            	avanza;
            fin;
            coge-zumbador;
        fin sino inicio
        	avanza;
            gira-izquierda;
            gira-izquierda;
            gira-izquierda;
        fin;
    fin;
```