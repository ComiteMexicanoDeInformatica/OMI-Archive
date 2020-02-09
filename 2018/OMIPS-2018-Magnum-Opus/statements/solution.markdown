El problema da un cuadrado de $N*N$ y podemos separarlo en recuadros de lados $1, 3, 5,\cdots , N$. En cada recuadro había que ver si había al menos un montón de zumbadores y había que llenar el recuadro completa con montones iguales. Si estaba vacío, llenarlo con montones de un zumbador. 
Para el recuadro del centro, que viene siendo de $1x1$, si no había zumbadores, había que dejar uno para rellenarlo, en el caso contrario, no había que hacer nada, pues ya estaba lleno ese recuadro. 
A partir del recuadro de lado $3$, tenemos que posicionarnos a una posición que pertenezca a ese recuadro, para después ir a buscar un montón de zumbadores, y este valor, copiarlo por todo el recuadro. Este debe repetirse en cada recuadro.
Podemos observar que se vuelve sencillo si elegimos las esquinas superiores de la derecha de cada recuadro, ya que podemos reducir al siguiente problema : Dada una línea de tamaño $L+1$ , verifica si hay algún montón de zumbadores y lleva esa cantidad al final de la línea. Esto se puede resolver copiando el número sobre el que estamos, a la siguiente posición de la línea : 
```
define-nueva-instruccion copia(n) como inicio
    si junto-a-zumbador entonces inicio
        coge-zumbador;
        copia(sucede(n)),
    fin sino inicio
        repetir n veces inicio
            deja-zumbador;
        fin;
        avanza;
        si no-junto-a-zumbador entonces inicio
            deja-zumbador;
        fin;
    fin;
fin;
```
Así, para la línea de tamaño $L+1$, repetirlo $L$ veces, que además de dejarlo al final, deja el rastro del número desde su primera aparición.
Ahora que ya sabemos como resolverlo para una línea, podemos resolver el recuadro porque solo es repetir la función 4 veces, dando una vuelta entre cada solución de línea. De esta forma conseguimos llevar el montón de zumbadores a la esquina inicial. 
```
define-nueva-instruccion coloreaMarco(L) como inicio
    repetir 4 veces inicio
        repetir L veces inicio
            copia(0);
        fin;
        gira-izquierda;
    fin;
fin;
 ```
En caso de no estar sobre un montón, es porque el recuadro se quedó vacio, por lo que hay que dejar un zumbador. Ahora sí, si volvemos a ejecutar los pasos anteriores, podemos llenar todo el recuadro, ya que con lo que llevamos hasta el momento, las posciones antes de la primer apareción de un montón están vacias. 
```
define-nueva-instruccion marco(L) como inicio
    coloreaMarco(L);
    si no-junto-a-zumbador entonces inicio
        deja-zumbador;
    fin;
    coloreaMarco(L);
fin;
```
Finalmente, ya que sabemos resolver cada recuadro, hay que estar llamando un función que sepa el valor L de cada recuadro y se vaya moviendo en las esquinas mencionadas. Una vez terminado el recuadro, si no hemos llegado al borde, nos movemos a la siguiente esquina y llamamos recursivamente a la función pero ahora con el valor L+2 : 
```
define-nueva-instruccion marco(L) como inicio
    coloreaMarco(L);
    si no-junto-a-zumbador entonces inicio
        deja-zumbador;
    fin;
    coloreaMarco(L);

    si derecha-libre entonces inicio
        mientras no-orientado-al-norte hacer inicio
            gira-izquierda;
        fin;
        avanza;
        mientras no-orientado-al-este hacer inicio
            gira-izquierda;
        fin;
        avanza;
        mientras no-orientado-al-oeste hacer inicio
            gira-izquierda;
        fin;
        marco(sucede(sucede(L)));
    fin;
fin;

```
