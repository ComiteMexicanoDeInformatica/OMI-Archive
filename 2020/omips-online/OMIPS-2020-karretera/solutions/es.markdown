Este problema se puede partir en dos partes: Recoger zumbadores y pintar las líneas.

Para pintar la linea primero tenemos que recoger los zumbadores necesarios. Esto lo podemos lograr primero contando el ancho del mundo.

Karel puede contar usando recursión: mientras tengas el frente libre avanzas y llamas la función incrementando el parámetro.

```
define-nueva-instrucción cuenta-ancho(n) como inicio
    si frente-libre entonces inicio
        avanza;
        cuenta-ancho(sucede(n));
    fin sino inicio
        pintura(n);
    fin;
fin;
```

Cuando llega a la pared podemos llamar otra función que se encargue de recoger los zumbadores recibiendo $n$ como el ancho del mundo.
Hay varias formas de hacer divisiones con Karel, pero en esta ocasión podemos aprovecharnos de que se tiene que dividir entre 4 usando la orientacion para llevar la cuenta. despues solo hay que hacer un ciclo de $n$ repeticiones donde recoja un zumbador y gire. El único momento en que no vamos a recoger es cuando estemos viendo al norte, de esta manera vamos a recoger 3 y saltarnos uno.

```
define-nueva-instrucción pintura(n) como inicio
    repetir n veces inicio
        si no-orientado-al-norte entonces inicio
            coge-zumbador;
        fin;
        gira-izquierda;
    fin;
fin;
```

Con esto ya tenemos la pintura en la mochila, lo único que falta es ir ala fila 3 y pintar siguiendo el patron que se pide.
Podemos usar de nuevo una variable para llevar un conteo de las casillas que faltan por pintar y cada que la variable sea 0 solo avanzar y regresar la variable a 3

```
define-nueva-instrucción pintar(n) como inicio
    si algún-zumbador-en-la-mochila entonces inicio
        si no si-es-cero(n) entonces inicio
            deja-zumbador;
            si frente-libre entonces avanza;
            pintar(precede(n));
        fin sino inicio
            avanza;
            pintar(3);
        fin;
    fin;
fin;
```
