# Diana - Solución

Una primera observación para resolver este problema es el hecho de que la casilla central no tiene zumbadores, por lo que si Karel inicia sobre un zumbador, inmediatamente sabemos que no está en el centro de la Diana.

Falta ver que ocurre cuando Karel no inicia sobre un zumbador. Podemos darnos cuenta de que la casilla central cumple la propiedad de que hay zumbadores en las cuatro casillas que están junto a ella (al norte, sur, este y oeste), y que además ninguna otra casilla libre de zumbadores cumple esta propiedad.

La solución verifica primero si Karel está junto a un zumbador, si esto ocurre sabemos que Karel no está en el centro, así que lo orientamos al sur. Si Karel no se encuentra junto a un zumbador, entonces comprueba si hay zumbadores en sus cuatro casillas adyacentes, si esto ocurre entonces Karel está en el centro del mapa y se orienta al norte; en caso contrario se orienta al sur.

```
iniciar-programa
        define-nueva-instruccion sur como
    inicio
        mientras no-orientado-al-sur hacer
                gira-izquierda;
    fin;

    define-nueva-instruccion norte como
    inicio
        mientras no-orientado-al-norte hacer
                gira-izquierda;
    fin;

    define-nueva-instruccion cruz como
    inicio
        repetir 4 veces
        inicio
                si frente-libre entonces
            inicio
                        avanza;
                si junto-a-zumbador entonces
                    inicio
                            gira-izquierda;
                        gira-izquierda;
                            avanza;
                        gira-izquierda;
                fin
                    sino
                inicio
                        sur;
                    apagate;
                    fin;
           fin;
        fin;
        norte;
    fin;

    inicia-ejecucion
       si junto-a-zumbador entonces
       inicio
        sur;
        apagate;
       fin
       sino
       inicio
        cruz;
       fin;

       apagate;
    termina-ejecucion
finalizar-programa
```
