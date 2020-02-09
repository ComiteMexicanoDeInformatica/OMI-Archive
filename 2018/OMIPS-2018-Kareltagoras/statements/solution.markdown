# Kareltágoras - Solución

Podemos dividir la solución de este problema en dos partes.

En la primera parte debemos calcular el valor de $c^2$. Para esto debemos idear una manera de medir el valor de $a$ y elevarlo al cuadrado, para después hacer lo mismo con $b$. Elevar un número al cuadrado es un problema que podemos resolver utilizando recursividad con parámetros. Hacer una método que mida $a$ y deje el valor en la casilla (1, 1) es sencillo: llevamos un parámetro $n$ que aumenta cada vez Karel avanza; cuando ya no puede avanzar movemos a Karel a la casilla (1, 1) y dejamos $n$ zumbadores. El código se vería algo así:

```
    define-nueva-instruccion mide(n) como inicio
        si frente-libre entonces inicio
            avanza;
            mide(sucede(n));
        fin sino inicio
            gira(2);
            corre;
            repetir sucede(n) veces 
            	deja-zumbador;
        fin;
    fin;
```
Si además queremos calcular el valor de $a^2$, en lugar de sólo dejar $n$ zumbadores, podemos repetir $n$ veces ese paso y tenemos el valor de $a^2$:

```
    define-nueva-instruccion cuadrados(n) como inicio
        si frente-libre entonces inicio
            avanza;
            cuadrados(sucede(n));
        fin sino inicio
            gira(2);
            corre;
            repetir sucede(n) veces
                repetir sucede(n) veces 
                    deja-zumbador;
        fin;
    fin;
```

Repetimos este proceso para calcular $b^2$ y habremos obtenido el valor de $c^2$.

Para la segunda parte de la solución debemos comprobar si $c$ es un entero.

Para esto observemos que $c$ es entero si existe algún entero $x$ tal que $x*x = c$. Por ejemplo, si $c^2 = 81$, $c$ es entero porque $9 * 9 = 81$; por otro lado, si $c^2 = 90$, $c$ no es entero porque no existe ningún entero que multiplicado por sí mismo de como resultado $90$.

Aprovechando esta propiedad, una forma para ver si $c$ es entero es ir probando enteros uno por uno, multiplicarlos por sí mismos y comprobar si el resultado es igual a $c$. Por ejemplo, si $c^2 = 16$ y queremos ver si c es entero, probamos con $1 * 1 = 1$; como el resultado es diferente de $16$ probamos con $2 * 2 = 4$; luego con $3 * 3 = 9$ y finalmente con $4 * 4 = 16$. Hemos encontrado un entero que multiplicado por sí mismo da $16$. Por otro lado, si tuviéramos que $c^2 = 18$, haríamos las mismas pruebas. Como $4 * 4 = 16$ que es diferente de $18$, necesitaríamos probar con el siguiente entero: $5 * 5 = 25$, como $25 > 17$ nos damos cuenta de que no es necesario probar con enteros más grandes, y concluimos que $c$ no es entero.

Este es un código que verifica si $c$ es entero utilizando el procedimiento que acabamos de describir:

```
    define-nueva-instruccion entero(x) como inicio
        repetir x veces
            repetir x veces inicio
                si junto-a-zumbador entonces inicio
                    coge-zumbador;
                fin sino inicio
                    si no-orientado-al-sur entonces
                        gira(2);
                fin;
            fin;
        si junto-a-zumbador entonces inicio
            repetir x veces
                repetir x veces
                    deja-zumbador;
            entero(sucede(x));
        fin;
    fin;
```