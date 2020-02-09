# Historia

Prowler capturó a Karel Araña y lo encerró en un mundo de  $1 \times N$. Sin embargo, Prowler descubrió que Karel Araña es su sobrino, por lo tanto no lo quiere matar. A cambio de su libertad, Karel Araña tendrá que dibujar líneas justo como Prowler quiera.

# Problema

Si hay $x$ zumbadores en la casilla $(1,i)$ significa una de las siguientes cosas:

* Si $x$ es impar, Karel tiene que dibujar una línea de longitud $x$ hacia la derecha.
* Si $x$ es par, Karel tiene que dibujar una línea de longitud $x$ hacia la izquierda.

Dibujar una línea de longitud $x$ hacia la derecha a partir de la posición $(1,i)$ es dejar exactamente un zumbador en las casillas $(1,i),(1,i+1),...,(1,i+x-1)$, y de la misma manera para una línea hacia la izquierda.

Prowler quiere deshacerse rápido de Karel para tomar el metro antes de la hora pico, así que Karel solo puede avanzar $2N$ veces.

# Ejemplo

### Entrada

![Entrada1](Entrada.png)

### Salida

![Salida1](Salida.png)

Explicacion:
* El 5 dibuja desde el 2 hasta el 6.
* El 2 dibuja del 3 al 2 pero como ya estan pintandos nada cambia.
* El 3 dibuja del 4 al 6 pero pero como ya estan pintandos no cambia nada.
* El 1 pinta la casilla 6 que ya está pintada.
* El 3 pinta del 13 al 15.
* El 4 pinta del 14 al 11.

# Consideraciones

* Karel inicia en la casilla $(1,1)$ orientado al este.
* Karel no lleva zumbadores en la mochila.

* Se asegura que Karel nunca tendrá que hacer una línea que se salga del mundo.
* Karel solo puede avanzar $2N$ veces.
* No importa la posición ni orientación final de Karel.
* Para un conjunto de casos de prueba con valor de 24 puntos, no se restringe el número de veces que Karel puede avanzar.
* Para un conjunto de casos de prueba con valor de 32 puntos, sólo hay montones de zumbadores impares.
