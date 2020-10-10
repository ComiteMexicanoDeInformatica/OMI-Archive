# Kuartos - Solución

Se puede partir esta solución en 3 pasos:

1. Contar el tamaño del primer cuarto
1. Comparar el primer cuarto con el segundo
1. Regresar al zumbador y orientarte hacia el cuarto mas grande

Lo primero que vamos a hacer es una función que siempre nos lleve a la siguiente casilla del pasillo sin importar las paredes. A esta función la llamaremos `super-avanza`. Esta función nos va a servir en todos los pasos siguientes.

```
	define-nueva-instrucción super-avanza como inicio
        si frente-bloqueado entonces inicio
            si izquierda-libre entonces inicio
                gira-izquierda;
            fin sino si derecha-libre entonces inicio
                repetir 3 veces gira-izquierda;
            fin;
        fin;

        avanza;
    fin;
```

Para contar el tamaño del primer cuarto vamos a usar recursión llevando en la variable `n` el tamaño actual. La recursión se va a detener cuando estemos junto a un zumbador. Nota como usar `super-avanza` hace muy fácil de entender lo que va a hacer Karel.

```
    define-nueva-instrucción cuenta(n) como inicio
    	si junto-a-zumbador entonces inicio
        	compara(n);
        fin sino inicio
        	super-avanza;
            cuenta(sucede(n));
        fin;
    fin;
```

Para comparar lo que vamos a hacer es intentar llamar `n` veces `super-avanza` y si en algún momento no podemos, significa que el primer cuarto es más grande que el segundo.

```
    define-nueva-instruccion compara(n) como inicio
    	si si-es-cero(n) entonces inicio
        	{el primer cuarto es mas chico que el segundo}
            regresa;
            gira-izquierda;
            gira-izquierda;
        fin sino si frente-bloqueado e izquierda-bloqueada y derecha-bloqueada entonces inicio
            {el primer cuarto es mas chico que el segundo}
        	regresa;
            super-avanza;
            gira-izquierda;
            gira-izquierda;
            avanza;
            gira-izquierda;
            gira-izquierda;
        fin sino inicio
        	super-avanza;
        	compara(precede(n));
        fin;
    fin;
```

Para regresar hacemos es una función sencilla que llama `super-avanza` hasta encontrar de nuevo el zumbador.

```
    define-nueva-instruccion regresa como inicio
    	gira-izquierda;
        gira-izquierda;
        mientras no-junto-a-zumbador hacer inicio
        	super-avanza;
        fin;
    fin;
```

La otra observación importante es que puede que cuando regreses termines viendo hacia una pared, en ese caso lo que hicimos en la función `compara` fue super-avanzar una casilla más y después regresar para asegurarnos que Karel siempre termina orientado hacia un cuarto y no hacia una pared.
