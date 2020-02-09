# Chocolate - Solución

Este problema se parte en dos partes: recoger todos los zumbadores y repartirlos en las filas inferiores hasta que se acaben.

Para recogerlos solo hay que hacer una ciclo mientras estemos junto a un zumbador, cuidando las validaciones de no chochar con la pared.

Para dejarlos debemos hacer otro ciclo mientras tengamos zumbadores en nuestra mochila

```
iniciar-programa
    inicia-ejecucion
        mientras junto-a-zumbador hacer inicio
            coge-zumbador;
            si frente-libre entonces avanza;
        fin;

        gira-izquierda;
        mientras frente-libre hacer avanza;
        gira-izquierda;
        mientras frente-libre hacer avanza;
        gira-izquierda;

        mientras algun-zumbador-en-la-mochila hacer inicio
            deja-zumbador;
            si frente-libre entonces inicio
                avanza;
            fin sino inicio
                gira-izquierda;
                si frente-libre entonces inicio
                    avanza;
                    gira-izquierda;
                    mientras frente-libre hacer avanza;
                    gira-izquierda;
                    gira-izquierda;
                fin;

            fin;
        fin;
        apagate;
    termina-ejecucion
finalizar-programa
```
