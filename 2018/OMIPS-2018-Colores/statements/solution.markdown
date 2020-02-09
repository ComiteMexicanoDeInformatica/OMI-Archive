# Colores - Solución

Hay varias maneras de resolver este problema. 

Como nos piden contar la cantidad de colores diferentes, y los colores están representados por montones desde 1 hasta 99 zumbadores, podemos ir buscando cada color por separado. Es decir, recorremos el mapa para verificar si hay algún montón de 1 zumbador, si eso pasa, aumentamos 1 al valor de la casilla (1, 1); luego recorremos el mapa para buscar montones de 2 zumbadores, si existe alguno, aumentamos en 1 el valor de la casilla (1, 1); y así sucesivamente hasta llegar a 99. Cuando terminemos habremos contado la cantidad de colores diferentes.

Hay otra alternativa que hace algo parecido a lo anterior. Para llegar a esta solución debemos darnos cuenta de una propiedad: si le quitamos un zumbador a todos los montones del mundo, la cantidad de colores diferentes no se altera. Aprovechando esto podemos hacer lo siguiente: haremos varios recorridos en el mapa, en cada recorrido restaremos un zumbador en cada posición del mapa que aún tenga zumbadores (excepto la (1, 1)). Vemos que todos los montones del mismo color se volverán casillas vacías en el mismo recorrido (todos los montones de 3 zumbadores se vacían en el tercer recorrido, y en general todos los montones de n zumbadores se vacían en el n-ésimo recorrido), por lo que si en algún momento de un recorrido encontramos que una casilla se quedó sin zumbadores, significa que hemos encontrado un nuevo color, y al terminar el recorrido aumentamos 1 al valor de la casilla (1, 1). Si en un recorrido ninguna casilla se vació, el número de colores no cambia. Además, sabemos que hemos terminado cuando todo el mapa queda vacío. 

El siguiente fragmento de código implementa la solución que acabamos de describir:

```
    define-nueva-instruccion siguiente como inicio
        si frente-libre entonces inicio
            avanza;
        fin sino si derecha-libre entonces inicio
            gira-izquierda;
            gira-izquierda;
            pared;
            gira-izquierda;
            avanza;
            gira-izquierda;
        fin;
    fin;

    define-nueva-instruccion recorre(n) como inicio
        {*
          n = 0 no se agarro ningun zumbador
          n = 1 se agarro almenos 1 zumbador
          n = 2 se vacio una casilla
        *}
        si frente-bloqueado y derecha-bloqueada entonces inicio
            si si-es-cero(n) y no-junto-a-zumbador entonces inicio
                apagate;
            fin sino inicio
                si junto-a-zumbador entonces inicio
                    coge-zumbador;
                    si no-junto-a-zumbador entonces inicio
                        regresa(2);
                    fin sino inicio
                        regresa(n);
                    fin;
                fin sino inicio
                    regresa(n);
                fin;
            fin;
        fin sino inicio
            si junto-a-zumbador entonces inicio
                coge-zumbador;
                si no-junto-a-zumbador entonces inicio
                    siguiente;
                    recorre(2);
                fin sino inicio
                    siguiente;
                    si si-es-cero(n) entonces inicio
                        recorre(1);
                    fin sino inicio
                        recorre(n);
                    fin;
                fin;
            fin sino inicio
                siguiente;
                recorre(n);
            fin;
        fin;
    fin;   
```

Nota como el parámetro del método 'recorre' sirve para comprobar si alguna casilla quedó vacía, o si no se pasó por ninguna casilla con zumbadores. El método 'regresa' sirve para volver a la casilla (1, 1) y dejar un zumbador en caso de que alguna casilla se haya vaciado.

```
    define-nueva-instruccion regresa(n) como inicio
        mientras no-orientado-al-oeste hacer gira-izquierda;
        pared;
        gira-izquierda;
        pared;
        gira-izquierda;
        gira-izquierda;
        si si-es-cero(precede(precede(n))) entonces inicio
            deja-zumbador;
        fin;
    fin;   
```

Una tercer alternativa es ir buscando montones de zumbadores, cuando se encuentre uno eliminamos del mapa todos los montones del mismo color y aumentamos en 1 el valor de la casilla (1, 1), repetimos este proceso mientras siga habiendo montones de zumbadores en el mundo.