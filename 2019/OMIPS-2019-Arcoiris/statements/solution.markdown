#Arcoíris - Solución

Observando como luce el arcoíris una vez que se dibuja, podemos darnos cuenta de que en la columna central del mundo aparecen los números del $1$ al $7$ de manera consecutiva, de tal manera que el $7 $ aparece en la celda más al norte de dicha columna. Vemos además que desde la columna central salen escaleras descendientes a la izquierda y a la derecha: del $1$ de la columna central sale una escalera descendiente a la derecha y otra a la izquierda, del $2$ de la columna central sale una escalera descendiente a la derecha y otra a la izquierda, y así consecutivamente.

El problema se reduce entonces a encontrar la columna central (para esto basta ver que la columna central es igual a la altura del mundo) y posteriormente bajar a la posición donde debe ir el $1$ de esta columna, dibujar sus dos escaleras para después subir a la posición del $2$ de la columna central y dibujar sus escaleras y así consecutivamente.

A continuación se muestra una forma de encontrar la columna central.

```  
   define-nueva-instruccion centro como inicio
    	si frente-libre entonces inicio
        	avanza;
            centro;
            avanza;
        fin sino inicio
        	este;
        fin;
    fin;
```

Y esta es la implementación para dibujar una de las escaleras del arcoíris. Nota que usamos recursividad para volver a la columna central.

```  
   define-nueva-instruccion escalera-izq(n) como inicio
    	si izquierda-libre entonces inicio
        	avanza;
            sur;
            avanza;
            oeste;
            deja(n);
            escalera-izq(n);
            norte;
            avanza;
            este;
            avanza;
        fin;
    fin;
```
