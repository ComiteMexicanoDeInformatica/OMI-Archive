# Comprimiendo - Solución

Otra manera de definir el problema es que empezando por la primer fila, cada dos posiciones en una columna deberán ser comprimidas tal que la suma de sus zumbadores queda en la casilla correspondiente en el granero.

Para resolver este problema recorreremos cada columna de abajo hacia arriba, tomando los zumbadores recursivamente. Sabemos que la altura de la granja es de tamaño par así que podemos tomar dos montones, uno tras otro, y dejar pendiente dejar los zumbadores de esas dos casillas más avanzar una sola casilla.

Entonces, una columna la recorreremos de abajo hacia arriba dejando pendiente dejar los montones de zumbadores comprimidos, tal que cuando las instrucciones pendientes se saquen de la pila de la recursión dejaremos los montones de zumbadores como quedarían en el granero, empezando por el montón que queda más arriba y terminando por el que queda más abajo.

Ya que sabemos como resolver el problema para una sola columna, podemos repetir este proceso para todas las columnas empezando de izquierda a derecha. Cada vez que terminamos de recoger los montones de una columna, dejamos pendiente re-acomodar a Karel tal que siempre deja los montones de zumbadores como corresponden, y luego se re-acomoda para empezar a dejar los montones de la siguiente columna.

Si recorremos las columnas de abajo hacia arriba, y todas las columnas de izquierda a derecha, la primera vez que lleguemos a un montón sin zumbadores sabremos que llegamos al granero, en cuyo caso acomodamos a Karel en la esquina superior derecha para que los instrucciones pendientes se saquen de la pila de la recursión y dejen los zumbadores donde corresponden.

```
iniciar-programa
    define-prototipo-instruccion siguiente;

    define-nueva-instruccion gira(n) como inicio
        repetir n veces gira-izquierda;
    fin;

    define-nueva-instruccion pared como inicio
        mientras frente-libre hacer avanza;
    fin;

    define-nueva-instruccion recuerda2(n) como inicio
        si junto-a-zumbador entonces inicio
            coge-zumbador;
            recuerda2(sucede(n));
            deja-zumbador;
        fin sino inicio
            siguiente;
        fin;
    fin;

    define-nueva-instruccion recuerda1(n) como inicio
        si junto-a-zumbador entonces inicio
            coge-zumbador;
            recuerda1(sucede(n));
            deja-zumbador;
        fin sino inicio
            avanza;
            recuerda2(0);
        fin;
    fin;

    define-nueva-instruccion siguiente como inicio
        si frente-libre entonces inicio
            avanza;
            si junto-a-zumbador entonces inicio
                recuerda1(0);
                avanza;
            fin sino inicio
                pared;
                gira(2);
            fin;
        fin sino inicio
            gira(2);
            pared;
            gira(1);
            avanza;
            gira(1);
            recuerda1(0);
            gira(2);
            pared;
            gira(1);
            avanza;
            gira(1);
        fin;
    fin;

    inicia-ejecucion
        recuerda1(0);
        apagate;
    termina-ejecucion
finalizar-programa
```
