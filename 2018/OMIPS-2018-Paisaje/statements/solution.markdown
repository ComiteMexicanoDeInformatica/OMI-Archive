# Paisaje - Solución

Para facilitar la resolución de este problema podemos dividir la solución en dos partes. En la primera parte sólo dibujamos el contorno de la montaña, mientras que en la segunda parte coloreamos todas las casillas del color correspondiente.

Para dibujar el contorno de la montaña hacemos lo siguiente: Si Karel está bajando, entonces lo movemos una casilla al este y una al sur mientras no esté junto a un zumbador, y cuando llegue a un zumbador deberá empezar a subir. Si Karel está subiendo, lo movemos una casilla al este y una al norte mientras no esté junto a un zumbador, y cuando llegue a un zumbador deberá a empezar a bajar.

El código para pasar de una cima a un valle se ve algo así:

```
    define-nueva-instruccion baja como inicio
        avanza;
        sur;
        avanza;
        este;
    fin;
    
    define-nueva-instruccion avanza-a-valle como inicio
    	si frente-libre entonces 
        	baja;
        mientras no-junto-a-zumbador y frente-libre hacer inicio
        	deja-zumbador;
            baja;
        fin;
    fin; 
```

El código para pasar de un valle a un cima es bastante parecido. Para dibujar todo el contorno de la montaña simplemente debemos alternar entre avanzar a valle y avanzar a cima hasta que choquemos con una pared.

Después de haber coloreado el contorno, el mapa lucirá parecido a este:

![contorno](contorno.png)

Una vez que hemos marcado el contorno de la montaña debemos colorear las casillas que faltan. Para esto, debemos darnos cuenta que una vez que marcamos el contorno de la montaña, en cada columna del mapa hay sólo un montón de 1 zumbador, y para cada columna debajo de ese 1 deben haber sólo montones de 1 zumbador (que representa la parte de la montaña), y arriba de ese 1 sólo debe haber montones de 2 zumbadores (que representan el cielo). 

Así que para terminar de pintar el mundo debemos ir avanzando columna por columna. Para cada columna ponemos montones de 1 zumbador hasta llegar al montón que pusimos en la parte anterior de la solución, y arriba de ese montón ponemos montones de 2 zumbadores hasta llegar a la pared.

El código para pintar una columna se ve así:

```
    define-nueva-instruccion pinta-linea como inicio
    	norte;
        mientras no-junto-a-zumbador hacer inicio
        	deja-zumbador;
            avanza;
        fin;
        mientras frente-libre hacer inicio
        	avanza;
            deja-zumbador;
            deja-zumbador;
        fin;
        
        sur;
        mientras frente-libre hacer avanza;
    fin;   
```

Hay que repetir este proceso en todas las columnas del mapa.