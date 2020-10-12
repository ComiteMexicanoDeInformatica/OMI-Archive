# Circuito - Solución

La observación clave para resolver este problema es la siguiente: imagina que recorres el circuito en dirección de las manecillas del reloj (tal como se muestra en la figura de abajo). Notemos que para toda casilla rodeada por el circuito, las flechas que trazamos dejan a la casilla de lado derecho de la flecha. Por el contrario, para toda casilla fuera del circuito cumple que todas las flechas dejan la casilla de lado izquierdo de la flecha.

![recorrido](recorrido.png)

Esta es una propiedad muy interesante de los polígonos en general y podemos aprovechar esta propiedad para saber si estamos dentro o fuera del polígono; es decir, rodeado o no por el circuito.

Si hacemos que Karel avance desde la posición donde empieza hasta topar con el primer zumbador (si no hay zumbador significa que estamos fuera), giramos izquierda y hacemos que Karel recorra el circuito en ese sentido podemos notar que **Karel recorrerá el circuito en sentido de las manecillas del reloj si empieza fuera y en sentido contrario a las manecillas del reloj si empieza dentro**.

Por lo tanto, el problema se reduce a saber en qué sentido recorre Karel el circuito. Para esto, podrían haber varias alternativas. Vamos a explicar una de ellas:

1. Vamos a recorrer el circuito y quitar algunos zumbadores que sean esquinas; es decir, aquellos zumbadores que para continuar el circuito se necesite girar. Particularmente, vamos a quitar todas las esquinas en las cuales, al recorrer el circuito y llegar a esa esquina, Karel estaba viendo al norte.

2. Vamos a la casilla $(1, 1)$, para asegurar estar en una posición fuera del polígono.

3. Vamos hacer un recorrido vertical columna por columna, de sur a norte, hasta encontrar el primer zumbador. Notar que si hacemos esto, terminaremos en una parte vertical del circuito y además orientados para un recorrido en sentido de las manecillas del reloj.

4. Procedemos a avanzar hasta encontrar la esquina de la parte vertical donde estamos.

5. Si no hay zumbador en esa esquina significa que empezamos fuera del polígono, pues en el recorrido que hicimos inicialmente sí quitó el zumbador de la esquina acorde a un recorrido en sentido de las manecillas del reloj. En caso contrario significa que comenzamos fuera. Por lo tanto, orientamos a Karel acorde a la respuesta y terminamos ejecución.

[Aquí puedes encontrar un video explicando la solución.](https://www.youtube.com/watch?v=N34Wkr9UJbg)
