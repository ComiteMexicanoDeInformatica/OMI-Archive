Para resolver este problema necesitamos una manera de guardar el montón de zumbadores que debemos buscar, y una vez hecho esto necesitamos poder identificar si un montón de zumbadores es igual al que estamos buscando.

Para esto podemos guardar el montón de zumbadores a buscar en un parámetro. Después debemos recorrer el mapa buscando montones de zumbadores. Cada vez que encontremos uno comparamos el montón de zumbadores con el que llevamos en parámetro. Para hacer esto último intentamos quitar una cantidad de zumbadores igual a la que llevamos en el parámetro, si después de hacer esto no quedan zumbadores, significa que hemos encontrado el montón que estábamos buscando. 

El siguiente código implementa el proceso que describimos arriba.

```
    define-nueva-instruccion busca(x) como inicio
        mientras orientado-al-norte hacer inicio
            si junto-a-zumbador entonces inicio
                repetir x veces
                    si junto-a-zumbador entonces inicio
                        coge-zumbador;
                    fin sino inicio
                        sur;
                    fin;
                si orientado-al-sur entonces inicio
                    norte;
                fin sino inicio
                    si no-junto-a-zumbador entonces inicio
                        sur;
                    fin;
                fin;
            fin;            
            si orientado-al-norte entonces
                siguiente;
        fin;
        si orientado-al-sur entonces inicio
            norte;
        fin sino inicio
            oeste;
            corre;
            sur;
        fin;
    fin;
```