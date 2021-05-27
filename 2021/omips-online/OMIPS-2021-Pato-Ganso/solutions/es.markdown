# Pato Ganso - Solución

Antes de resolver el problema hay que entender lo que se nos pide.

Debemos convertir toda la orilla del mundo de patos (casillas sin zumbador) a gansos (casillas con zumbador)

Debemos convertirlos en un orden especifico: saltarnos un pato y cuando lleguemos al siguiente pato convertirlo en ganso.

Veamos el caso de ejemplo:

![Entrada de ejemplo](ejemplo.png)

El primer pato que Karel se salta es el de la casilla $(5, 3)$ por lo que el primer ganso sera el de la casilla $(5, 4)$. Debemos seguir convirtiendo gansos de la misma manera hasta que ya no haya patos.

Hay que entender muy bien lo que pasa despues de dar la primer vuelta. Observa la siguiente imagen:

![Primera vuelta](vuelta.png)

En este punto, Karel acaba de convertir el noveno ganso. ¿Dónde debe poner el decimo?. De nuevo el primer pato que se encuentra es el $(5, 3)$ y se lo debe saltar pero la siguiente casilla ya es un ganso, por lo que esa ya no se puede convertir, el siguiente pato disponible es el de la casilla $(5, 5)$

Este es el orden en que pondría todos los zumbadores:

![Explicación ejemplo](../statements/explicacion.png)

Una vez entendiendo esto la última observación importante es saber cuándo debemos de terminar. La redacción nos dice que Karel tiene exactamente el número de zumbadores en la mochila para convertir a todos. Lo único que tenemos que hacer es repetir el proceso hasta que ya no tengamos zumbadores en la mochila.

Una técnica importante que debes aprender cuando programes en Karel es poder hacer una función que te lleve a la siguiente casilla que te interesa. A esta función es comun llamarla `súper-avanza`, ya que no solo avanza si no que tiene la lógica y validaciones necesarias para llevarte al siguiente pato.

```
  define-nueva-instrucción súper-avanza como inicio
    si frente-bloqueado entonces gira-izquierda;
    avanza;
    si junto-a-zumbador entonces súper-avanza;
  fin;
```

Esta función hace 3 cosas, primero valida que si está en una esquina debe girar a la izquierda, después avanza una casilla y válida que esté vacía, si no está vacía vuelve a llamar `super-avanza` para volver a hacer las mismas validaciones en la siguiente casilla.

Teniendo está función lo único que tenemos que hacer es mandarla llamar 2 veces y después poner un zumbador. Repitiendo lo mismo hasta que ya no tengamos zumbadores en la mochila.

```
  inicia-ejecución
    mientras algún-zumbador-en-la-mochila hacer inicio
      súper-avanza;
      súper-avanza;
      deja-zumbador;
    fin;
    apágate;
  termina-ejecución
```
