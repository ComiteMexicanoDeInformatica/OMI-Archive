#Edificio - Soluci�n

# Definiendo un subproblema

Tomemos como referencia un caso como el de la imagen:

![sol1](sol1.png)

Para llegar del piso 8 al piso 1, forzosamente habr� que moverse del piso 8 al piso 7. Para llegar al piso 1 desde el piso 7, forzosamente habr� que moverse del piso 7 al piso 6, y as� sucesivamente.

Como no hay paredes dentro de cada piso, entonces una vez que Karel baja al siguiente piso, nunca tiene que volver al piso anterior.

De esta manera, el problema se puede cambiar por encontrar c�mo moverse de cada uno de los pisos al piso que tengan inmediatamente abajo.

Desgraciadamente hay muchos lugares diferentes por donde se puede llegar a un piso (bajando desde el piso de arriba) y empezar a caminar, estos lugares se representan por puntos rojos en la siguiente imagen:

![sol2](sol2.png)

No hay una manera clara de saber por qu� puntos rojos hay que pasar, pero lo que s� sabemos es que una vez que Karel logra llegar a uno de los puntos rojos, lo �nico que importa es en cu�ntos pasos lo logr� (no importa por d�nde haya pasado antes, s�lo el n�mero de pasos).

La idea de la soluci�n es que si ya tuvi�ramos zumbadores indicando cu�ntos pasos le toma a Karel llegar a cada uno de los _puntos rojos_ de uno de los pisos, tenemos que hacer que Karel indique con zumbadores lo mismo, pero en el siguiente piso.

Es decir, el objetivo es, para cada piso, pasar de esto:

![sol3](sol3.png)

...a esto:

![sol4](sol4.png)

# Soluci�n al subproblema

Para resolverlo, para cada mont�n de zumbadores en el piso en cuesti�n: hay que agarrar todos los zumbadores del mont�n y contarlos recursivamente usando el par�metro.

En el c�digo de la soluci�n, la instrucci�n **expande-fila** encuentra los montones y **expande** los cuenta recursivamente:

    define-nueva-instruccion expande-fila como inicio
    	oeste;
        avanza-pared; (*avanza hasta toparse con una pared*)
        este;

        mientras frente-libre hacer inicio
        	si junto-a-zumbador entonces inicio
            	expande(0);
                este;
            fin;
            avanza;
        fin;
        si junto-a-zumbador entonces inicio
        	expande(0);
        fin;
    fin;

Una vez contados los zumbadores hay que moverse recursivamente a hacia la izquierda incrementado el contador y buscando todos los posibles lugares donde Karel podr�a bajar. Este proceso se debe repetir pero movi�ndose recursivamente hacia la derecha.

En el c�digo, **expande**, adem�s de contar los zumbadores en el mont�n inicial, tambi�n manda a llamar el proceso de buscar lugares para bajar con dos instrucciones diferentes, llamadas **expandeIzq** y **expandeDer**.

    define-nueva-instruccion expande(n) como inicio
    	si junto-a-zumbador entonces inicio
        	coge-zumbador;
            expande(sucede(n));
        fin sino inicio
        	oeste;
            expandeIzq(n);
            este;
            expandeDer(n);
        fin;
    fin;

Cada que se encuentre un lugar donde se pueda bajar, hay que dejar un mont�n de zumbadores abajo indicando la longitud del camino encontrado (osea, el n�mero de zumbadores en el mont�n inicial m�s los pasos horizontales dados para llegar hasta ah�).

En el c�digo esto se puede apreciar en **expandeIzq**, que manda a llamar a **baja** cada que encuentra un lugar para bajar.

    define-nueva-instruccion expandeIzq(n) como inicio
    	si frente-libre entonces inicio
        	si izquierda-libre entonces inicio
            	baja(n);
                oeste;
            fin;
            avanza;
            expandeIzq(sucede(n));
            avanza;
        fin sino inicio
        	si izquierda-libre entonces inicio
            	baja(n);
            fin;
            este;
        fin;
    fin;

Tambi�n hay que tomar en cuenta el caso en el que ya hayas encontrado otro camino antes y ya haya un mont�n ah�, en cuyo caso hay que comparar si el camino encontrado es menor o mayor.

baja toma en cuenta ambos casos, utiliza la instrucci�n compara para actualizar el n�mero de zumbadores en caso de que el mont�n ya exista.

    define-nueva-instruccion baja(n) como inicio
    	sur;
        avanza;
        si no-junto-a-zumbador entonces inicio
        	deja(n);
        fin sino inicio
        	compara(n);
        fin;
        norte;
        avanza;
    fin;

# Integrando el subproblema en la soluci�n general

Una vez resuelto el problema de convertir esto

![sol3](sol3.png)

...en esto:

![sol4](sol4.png)

... lo �nico que resta es saber c�mo iniciar, c�mo terminar y repetirlo en cada piso.

Dado que no hay montones de 0 zumbadores, la manera de iniciar en el piso m�s alto es simplemente dejando un zumbador en el lugar donde inicia Karel (esto har� que el conteo final tenga un zumbador extra, que habr� que restar al final).

Para saber cu�ndo se lleg� al piso de abajo a�n hay un �ltimo truco que aplicar: se trata de buscar un lugar donde sea posible bajar, si no hay un lugar as�, entonces orientarse al sur, y si s� hay, entonces orientarse en otra direcci�n:

    define-nueva-instruccion verifica-fin como inicio
    	oeste;
        avanza-pared;
        este;
        mientras frente-libre y derecha-bloqueada hacer inicio
        	avanza;
        fin;
        si derecha-bloqueada entonces inicio
        	sur;
        fin sino inicio
        	oeste;
            avanza-pared;
            este;
        fin;
    fin;

Al final a�n habr� que contar el n�mero de pasos del �ltimo mont�n hasta la casilla (1, 1).

    define-nueva-instruccion termina como inicio
    	oeste;
        avanza-pared;
        este;
        encuentra-sig;
        mientras junto-a-zumbador y no orientado-al-sur hacer inicio
        	deja-minimo(0);
            este;
            si frente-libre entonces inicio
            	avanza;
                encuentra-sig;
            fin sino inicio
            	sur;
            fin;
        fin;

        oeste;
        avanza-pared;
    fin;

El bloque principal quedar�a algo as�:

    inicia-ejecucion
        deja-zumbador;
        mientras no-orientado-al-sur hacer inicio
        	expande-fila;
            siguiente-fila;
            verifica-fin;
        fin;
        termina;
        coge-zumbador;
        apagate;
    termina-ejecucion

...sin embargo, a�n est� el caso especial de un solo piso, lo cual complica un poco el bloque principal:

    inicia-ejecucion
        deja-zumbador;
        verifica-fin;
        si orientado-al-sur entonces inicio
        	oeste;
            avanza-pared;
            si junto-a-zumbador entonces inicio
            	coge-zumbador;
            fin;
            apagate;
        fin;

        mientras no-orientado-al-sur hacer inicio
        	expande-fila;
            siguiente-fila;
            verifica-fin;
        fin;

        termina;
        coge-zumbador;
        apagate;
    termina-ejecucion
