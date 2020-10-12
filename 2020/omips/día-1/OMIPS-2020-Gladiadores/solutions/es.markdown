# Gladiadores - Solución

Lo primero que hay que notar es que en cada batalla (en cada línea) gana el equipo que la suma de todos sus gladiadores sea la mayor.

Sabiendo esto, la tarea se convierte en comparar las sumas de cada equipo en cada una de las líneas y dejar la respuesta en la casilla central.

Para la comparación final, solo se debe contar cuántas batallas ganó el este y el oeste y volver a comparar. Para hacer esto más sencillo podemos dejar un zumbador del lado de cada equipo ganador y al final sumarlos en la primera fila.

Con esto volvemos a usar la función de comparación en la fila 1 y sabremos el ganador, ya después solo es cuestión de dejar el número correcto en la casilla $(1, 1)$

Esta solución es un poco larga de implementar porque usa la mochila para comparar y tienes que tener cuidado de asegurarte que tienes zumbadores en la mochila antes de intentar dejarlos.

Hay otras formas de implementar la comparación en cada línea como ir recogiendo un zumbador de cada lado hasta que uno se acabe.

Otra forma aún más sencilla de implementarlo es usando recursión. Este es un buen problema para aprender a usar la variable de la recursión para contar y comparar.

El siguiente código es la implementación sin recursión

```
	iniciar-programa

    define-nueva-instruccion gira(n) como inicio
        repetir n veces gira-izquierda;
    fin;

    define-nueva-instruccion pared como inicio
        mientras frente-libre hacer avanza;
    fin;

    define-nueva-instruccion recoge como inicio
        mientras junto-a-zumbador hacer inicio
            coge-zumbador;
            si no-junto-a-zumbador entonces avanza;
        fin;
        mientras algun-zumbador-en-la-mochila hacer deja-zumbador;
    fin;

    define-nueva-instruccion avanza2 como inicio
        avanza;
        avanza;
    fin;

    define-nueva-instruccion recoge-sobrantes como inicio
        pared;
        gira(3);
        mientras frente-libre hacer inicio
            avanza;
            mientras junto-a-zumbador hacer inicio
                coge-zumbador;
            fin;
        fin;
        gira(2);
        pared;

    fin;

    define-nueva-instruccion restar como inicio
        mientras junto-a-zumbador hacer inicio
            coge-zumbador;
            avanza2;
            si junto-a-zumbador entonces inicio
                coge-zumbador;
                gira(2);
                avanza2;
                gira(2);

            fin sino inicio
               {gana el de la derecha}
               gira(2);
               avanza;
               repetir 2 veces inicio
                 si algun-zumbador-en-la-mochila entonces inicio
                   deja-zumbador;
                 fin;
               fin;
               avanza;
               gira(2);
               mientras junto-a-zumbador hacer coge-zumbador;
            fin;
        fin;
    fin;

    define-nueva-instruccion compara-final como inicio
        restar;

        avanza;
        si junto-a-zumbador entonces inicio
            {gana derecha};
            recoge-sobrantes;
            repetir 2 veces deja-zumbador;

        fin sino inicio
          avanza;
          si junto-a-zumbador entonces inicio
              {gano el de la izquierda}
              recoge-sobrantes;
              deja-zumbador;
          fin sino inicio
             {empate}
             recoge-sobrantes;
             repetir 3 veces deja-zumbador;
          fin;
          gira(2);
        fin;
    fin;

    define-nueva-instruccion compara como inicio
        restar;

        avanza;
        si junto-a-zumbador entonces inicio
            gira(2);
            avanza;
            deja-zumbador;
            gira(2);
        fin sino inicio
          avanza;
          si junto-a-zumbador entonces inicio
              {gano el de la izquierda}
              mientras junto-a-zumbador hacer coge-zumbador;
              deja-zumbador;
              gira(2);
              avanza;
              deja-zumbador;
          fin sino inicio
             {empate}
             gira(2);
             avanza;
             deja-zumbador;
             deja-zumbador;
             deja-zumbador;
          fin;
          gira(2);
        fin;

        pared;
        mientras algun-zumbador-en-la-mochila hacer deja-zumbador;
    fin;

    define-nueva-instruccion suma-fila como inicio
        avanza;
        gira(3);
        recoge;
        pared;
        gira(2);
        recoge;
        compara;
        pared;
        gira(3);
    fin;

    define-nueva-instruccion suma como inicio
        mientras frente-libre hacer inicio
            mientras junto-a-zumbador hacer coge-zumbador;
            avanza;
        fin;

        mientras algun-zumbador-en-la-mochila hacer deja-zumbador;
    fin;


    inicia-ejecucion
        mientras frente-libre hacer inicio
            suma-fila;
        fin;

        gira(3);
        avanza;
        mientras  no-junto-a-zumbador hacer avanza;
        coge-zumbador;
        si no-junto-a-zumbador entonces inicio
            deja-zumbador;
            avanza;
        fin sino inicio
            deja-zumbador;
        fin;
        avanza;
        gira(3);
        suma;
        gira(2);
        pared;
        gira(1);
        avanza2;
        gira(1);
        suma;

        gira(1);
        avanza2;
        gira(2);

        compara-final;


        apagate;
    termina-ejecucion
finalizar-programa
```

[Aquí puedes encontrar un video explicando la solución.](https://www.youtube.com/watch?v=y5BcQM1-AYQ)
