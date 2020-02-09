# Antena - Solución

Una forma para encontrar el edificio más alto dentro del mundo, es llevar a Karel a la parte más alta del mundo y luego recorrerlo hacia abajo, mientras no encuentre una pared.

Sabemos que no hay edificios en la columna 1, que es donde empieza Karel. Con esta información podemos llevar a Karel hasta la pared que delimita al mundo por arriba simplemente caminando mientras el frente esté libre. Una vez que lleguemos a este punto, podemos hacer un recorrido horizontal hacia el este, en caso de que en alguno de los pasos Karel tenga una pared a su derecha, quiere decir que está sobre un edificio; el problema nos dice que solamente hay un edificio más alto, por lo que sabemos que aquí es donde debemos dejar el zumbador. En caso de llegar a tener una pared de frente, quiere decir que llegamos al extremo derecho del mundo. Para continuar nuestro recorrido, bajamos una fila y caminamos esta vez hacia el oeste, y si en alguna casilla tenemos una pared de lado izquierdo, este es el lugar para dejar el zumbador. Se repite este recorrido en zig zag hasta encontrar una pared ya sea de lado izquierdo o derecho, dependiendo de hacia dónde vaya caminando Karel.

El siguiente código implemente la solución anterior.

```
iniciar-programa
    define-nueva-instruccion salta como inicio
        mientras no-orientado-al-sur hacer
            gira-izquierda;
        si frente-libre entonces
        inicio
            avanza;
            gira-izquierda;
            si frente-bloqueado entonces
            inicio
                gira-izquierda;
                gira-izquierda;
            fin;
        fin;
    fin;

    define-nueva-instruccion busca como inicio
        mientras algun-zumbador-en-la-mochila hacer
        inicio
            si orientado-al-este y derecha-bloqueada entonces
            inicio
                deja-zumbador;
                apagate;
            fin;
            si orientado-al-oeste y izquierda-bloqueada entonces
            inicio
                deja-zumbador;
                apagate;
            fin;
            si frente-libre entonces
                avanza
            sino salta;
        fin;
    fin;

    inicia-ejecucion
        mientras frente-libre hacer
            avanza;
        gira-izquierda;
        gira-izquierda;
        gira-izquierda;
        busca;
        apagate;
    termina-ejecucion
finalizar-programa
```
