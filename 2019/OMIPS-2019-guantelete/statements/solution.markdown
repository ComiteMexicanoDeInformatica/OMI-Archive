# Instrusos - Solución

Sabemos que:

* Todos los montones de una columna son diferentes
* Habrá un montón que cambia al menos una vez

Con esta información, podemos saber que todos los montones que no cambian aparecerán en el mundo una cantidad de veces igual al número de columnas. También sabemos que habrán dos o más montones que aparecerán en el mundo una cantidad de veces menor al número de columnas.

Ahora podemos resolver el problema si podemos identificar a los montones que aparecen una cantidad de veces igual al número de columnas, ya que estos son los que tenemos que sumar.

Dado que tenemos la columna 1 vacía y ningún montón tendrá más de 100 zumbadores, por cada montón podemos dejar un zumbador en la columna 1 y en la fila del tamaño del montón.

Cuando hayamos hecho esto con todas las columnas, tendremos marcado cuantas veces aparece cada montón y sabremos cuantas columnas hay.

Ahora solo tenemos que intentar quitar uno menos que el número de columnas en cada posición de la columna 1, y los montones que queden indicarán los números que tenemos que sumar. Por cada marca, dejamos una cantidad de zumbadores igual al número de la fila en la posición (1,1).

```
iniciar-programa
    define-prototipo-instruccion cuenta(z);

    define-nueva-instruccion gira(n) como inicio
        repetir n veces  gira-izquierda;
    fin;

    define-nueva-instruccion regresa como inicio
        gira(2);
        mientras frente-libre hacer avanza;
        gira(2);
    fin;

    define-nueva-instruccion aumenta-contador como inicio
        si frente-libre entonces inicio
            avanza;
            aumenta-contador;
            avanza;
        fin si-no inicio
            deja-zumbador;
            gira(2);
        fin;
    fin;

    define-nueva-instruccion siguiente como inicio
        si junto-a-zumbador entonces inicio
            cuenta(0);
        fin sino inicio
            si frente-libre entonces inicio
                avanza;
                si junto-a-zumbador entonces inicio
                    cuenta(0);
                fin;
            fin;
        fin;
        regresa;
    fin;

    define-nueva-instruccion cuenta(z) como inicio
        si junto-a-zumbador entonces inicio
            coge-zumbador;
            cuenta(sucede(z));
            si si-es-cero(z) entonces inicio
                gira(1);
                aumenta-contador;
                gira(1);
            fin si-no inicio
                avanza;
            fin;
        fin sino inicio
            siguiente;
        fin;
    fin;

    define-nueva-instruccion quitar-intrusos(n) como inicio
        mientras frente-libre hacer inicio
            si junto-a-zumbador entonces inicio
              repetir precede(precede(n)) veces inicio
                  si junto-a-zumbador entonces coge-zumbador;
              fin;
            fin;
            avanza;
        fin;
    fin;

    define-nueva-instruccion cuenta-columnas(col) como inicio
        si frente-libre entonces inicio
            avanza;
            cuenta-columnas(sucede(col));
        fin si-no inicio
            gira(3);
            quitar-intrusos(col);
        fin;
    fin;

    define-nueva-instruccion avanza-contando(n) como inicio
        si junto-a-zumbador entonces inicio
            coge-zumbador;
            avanza-contando(sucede(n));
            deja-zumbador;
        fin sino inicio
            si frente-libre entonces inicio
                avanza;
                avanza-contando(n);
            fin;
        fin;
    fin;

    define-nueva-instruccion suma-respuesta(n) como inicio
        si junto-a-zumbador entonces inicio
            repetir n veces deja-zumbador;
        fin;
        si frente-libre entonces inicio
            avanza;
            suma-respuesta(sucede(n));
        fin sino inicio
            gira(2);
            avanza-contando(0);
        fin;
    fin;

    inicia-ejecucion
        gira(3);
        avanza;
        mientras junto-a-zumbador hacer inicio
            gira(1);
            siguiente;
            gira(3);
            si frente-libre entonces inicio
                avanza;
            fin;
        fin;
        gira(2);
        cuenta-columnas(0);
        regresa;
        suma-respuesta(0);
        apagate;
    termina-ejecucion
finalizar-programa
```