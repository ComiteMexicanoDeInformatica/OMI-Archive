# Historia

Karel tiene muchas canicas y las guarda en cajitas para que no se le pierdan. Algunas cajitas tienen canicas y otras están vacías. Karel quiere saber si tiene suficientes canicas para que no se quede ninguna cajita vacía.

# Problema

Ayuda a Karel orientándolo al norte si las canicas que tiene en sus cajitas son suficientes para reacomodarlas y que ninguna cajita quede vacía o hacia el sur si no son suficientes. 

# Ejemplos

### Entrada 1

![Entrada 1](entrada1.png)

### Salida 1

![Salida 1](salida1.png)

En este ejemplo Karel tiene un total de 16 canicas y 10
cajitas. Como sí alcanzan las canicas, termina orientado al norte.

### Entrada 2

![Entrada 2](entrada2.png)

### Salida 2

![Salida 2](salida2.png)

En este ejemplo Karel tiene un total de 9 canicas y 10
cajitas por lo que sus canicas no son suficientes.
Entonces termina orientado al sur.

# Consideraciones

* Karel inicia en la casilla (1,1) orientado al norte.
* Cada casilla representa una cajita.
* Las cajitas siempre están en la fila 1 como se ve en el ejemplo.
* El conjunto de cajitas está delimitado por paredes.
* Cada cajita puede tener entre 0 y 99 canicas.
* Karel debe terminar orientado al norte si hay suficientes canicas y al sur si no hay suficientes canicas.
* No importa la posición final de Karel.
* No importa cómo queden los zumbadores al final.
* Los casos de prueba están agrupados en pares. Esto quiere decir que si siempre te apagas viendo al norte o siempre te apagas viendo al sur, vas a obtener 0 puntos.

# Subtareas

* Para el 89% de los casos Karel no tiene zumbadores en la mochila.
* Para el 11% de los casos Karel tiene infinitos zumbadores en la mochila.
