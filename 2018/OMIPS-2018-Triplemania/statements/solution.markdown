Para resolver este problema simularemos lo que nos pide la redacción. Para cada columna buscamos el menor montón de zumbadores y eliminamos los demás. Si el menor de una columna no es único, entonces debemos pasar a la siguiente columna y repetir el proceso con los montones que quedaron. Si sólo quedó un montón de zumbadores, significa que hemos encontrado el ganador.

El siguiente código busca el menor en una columna y elimina las filas restantes. Llevamos un parámetro que le indica a Karel cuál es el menor montón de zumbadores que ha encontrado hasta el momento. Para cada montón compara con $n$, si es menor actualiza el valor de $n$ y elimina las filas necesarias; de lo contrario elimina toda la fila de ese zumbador para no considerarla en futuras comparaciones.

```
    define-nueva-instruccion encuentra-menor(n) como inicio
    	si junto-a-zumbador entonces inicio
        	compara(n);
            si orientado-al-sur entonces inicio        
            	limpia-fila;
                norte;
                si frente-libre entonces inicio
                	avanza;
                    encuentra-menor(n);
                fin;
            fin sino inicio
            	si frente-libre entonces inicio
                	cuenta(0);
                fin;
            fin;
        fin sino inicio
        	si frente-libre entonces inicio
            	avanza;
                encuentra-menor(n);
            fin;
        fin;
    fin;
```

Este código simula el proceso de encontrar la fila ganadora. Para cada columna encuentra el menor montón de zumbadores utilizando el método que describimos arriba. Si el menor fue único, entonces hemos terminado; de lo contrario debemos repetir el proceso en la siguiente columna.

```
    define-nueva-instruccion menor-lexicografico como inicio
    	encuentra-menor(100);
        sur;
        avanza-zumbador;
        si frente-libre entonces inicio
        	avanza;
            avanza-zumbador;
            si no-junto-a-zumbador entonces inicio
            	norte;
                avanza-zumbador;
                sur;
            fin sino inicio
            	avanza-pared;
                este;
                avanza;
                norte;
            fin;
        fin;
    fin;
```
