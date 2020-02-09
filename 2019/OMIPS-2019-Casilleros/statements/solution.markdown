# Solución - Interruptores

La observación crucial a este problema es darse cuenta que las casillas que al final estarán prendidas son las que corresponden a los cuadrados perfectos (enumerando desde cero la primera casilla). Para notar lo anterior basta con tener en cuenta que cada interruptor va a ser cambiado de estado únicamente por sus divisores. Después de esto, sabemos que permanecerá prendido si y solo si es cambiado un número impar de veces. Por lo tanto, los interruptores que tienen un número impar de divisores serán los que terminarán encendidos. Estos son los números cuadrados.

Ahora bien, la idea de solución consiste en pasar de un número cuadrado perfecto al siguiente solamente avanzando hacia la derecha. Encontraremos ahora una forma de llegar al siguiente cuadrado sin regresar.

Imaginemos que estamos en el $n$-ésimo cuadrado y queremos llegar al $(n+1)$-ésimo. Esto quiere decir que nos encontramos en el interruptor número $n^2$ y queremos llegar al interruptor $(n+1)^2$. Para hacer eso necesitamos avanzar exactamente $(n+1)^2 - n^2 = 2n + 1$ pasos. Notemos que $2n + 1$ es la secuencia de números impares. Es decir, para llegar a la casilla uno debemos avanzar 1, para llegar de la casilla uno a la cuatro nos movemos 3, de la cuatro a la nueve nos movemos 5 y así sucesivamente.

Con todo lo anterior, podemos programar una funcion que nos diga en un parámetro la cantidad de pasos que debemos movernos para llegar al siguiente interruptor que debemos prender y volver a llamar esta función con el nuevo número de pasos que necesitamos (el siguiente número impar).

El código se ve así:

```  
  define-nueva-instruccion prendeInterruptores(pasos) como inicio
  	 avanzaNpasosPonZumbador(pasos);
     prendeInterruptores(sucede(sucede(pasos)));
  fin;
```
