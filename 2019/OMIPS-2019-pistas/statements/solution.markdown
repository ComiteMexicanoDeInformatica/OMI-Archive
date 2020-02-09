# Pistas- Solución

Para solucionar este problema aprovecharemos que iniciamos con la mochila vacía.

Lo primero que haremos es encontrar el montón de zumbadores  en la primer fila.

Después, cada vez que lleguemos a un montón de zumbadores los tomaremos todos, dejaremos uno, subiremos a la siguiente fila, y a partir de la primer columna, avanzaremos al este mientras tengamos zumbadores, dejando un zumbador antes de dar cada paso.

Así, cada vez que lleguemos a un nuevo montón de zumbadores tendremos la mochila vacía, y podremos repetir el proceso hasta que lleguemos a una casilla sin zumbadores, donde deberemos apagar a Karel.
```
iniciar-programa
	define-nueva-instruccion gira(n) como inicio
    	repetir n veces gira-izquierda;
    fin;

    define-nueva-instruccion sigue-pista como inicio
    	mientras junto-a-zumbador hacer coge-zumbador;
        deja-zumbador;
        gira(1);
        avanza;
        gira(1);
        mientras frente-libre hacer avanza;
        gira(2);
        mientras algun-zumbador-en-la-mochila hacer inicio
        	deja-zumbador;
            avanza;
        fin;
    fin;

    inicia-ejecucion
        gira(3);
        mientras no-junto-a-zumbador hacer avanza;

        mientras junto-a-zumbador hacer inicio
        	sigue-pista;
        fin;

        apagate;
    termina-ejecucion
finalizar-programa
```