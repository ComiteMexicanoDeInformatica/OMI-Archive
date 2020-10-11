# Instrusos - Soluci�n

Sabemos que:

- Todos los montones de una columna son diferentes
- Habr� un mont�n que cambia al menos una vez

Con esta informaci�n, podemos saber que todos los montones que no cambian aparecer�n en el mundo una cantidad de veces igual al n�mero de columnas. Tambi�n sabemos que habr�n dos o m�s montones que aparecer�n en el mundo una cantidad de veces menor al n�mero de columnas.

Ahora podemos resolver el problema si podemos identificar a los montones que aparecen una cantidad de veces igual al n�mero de columnas, ya que estos son los que tenemos que sumar.

Dado que tenemos la columna 1 vac�a y ning�n mont�n tendr� m�s de 100 zumbadores, por cada mont�n podemos dejar un zumbador en la columna 1 y en la fila del tama�o del mont�n.

Cuando hayamos hecho esto con todas las columnas, tendremos marcado cuantas veces aparece cada mont�n y sabremos cuantas columnas hay.

Ahora solo tenemos que intentar quitar uno menos que el n�mero de columnas en cada posici�n de la columna 1, y los montones que queden indicar�n los n�meros que tenemos que sumar. Por cada marca, dejamos una cantidad de zumbadores igual al n�mero de la fila en la posici�n (1,1).

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
