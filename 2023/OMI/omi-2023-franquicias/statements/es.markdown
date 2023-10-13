Es sabido que los programadores gustan de la comida de franquicia. Normalmente piden su comida mediante apps, sin embargo, motivados por una vida sana, en tu calle los programadores prefieren ir caminando a la sucursal más cercana.

Tu calle tiene $M$ edificios, todos del mismo tamaño, en las posiciones de la $1$ a la $M$. En $F$ de ellos hay una sucursal de alguna franquicia. Por regla de la colonia, sólo puede haber una franquicia por edificio. Además, en $P$ de estos edificios hay oficinas con programadores.

Los programadores quieren hacer ejercicio, pero no demasiado, ellos siempre van a la sucursal que les queda más cerca de su oficina (puede ser incluso en el mismo edificio).

Una cadena quiere abrir sucursales en tu calle. Como cualquier negocio, su objetivo es ganar la mayor cantidad de dinero. La cadena está dispuesta a abrir **hasta** $N$ sucursales (puede abrir menos si lo considera convieniente). Sabiendo la regla que no permite más de una franquicia por edificio, los dueños de la cadena inventaron una modalidad _carrito_ que permite poner la sucursal entre cualesquiera dos edificios. Por lo tanto, las $N$ sucursales se pueden colocar en:

- Un edificio que aun no tenga franquicia.
- Un _carrito_ entre dos edificios.

**Si una oficina está a la misma distancia de una nueva sucursal que de uno de los $F$ restaurantes previos, los programadores irán al restaurante previo, ya que no les gusta cambiar.**

Cada programador gasta $B$ pesos en comida al mes. Mantener una sucursal funcionado tiene un costo de $C$ pesos al mes.

La cadena quiere que le digas ¿cuál es el máximo ingreso que puede conseguir si ubica hasta $N$ (o menos) sucursales de forma óptima?

# Problema

Escribe un programa que dada la localización de las $F$ franquicias actuales, la ubicación de las $P$ oficinas de programadores con la cantidad de programadores en cada una, el gasto mensual de cada programador, el costo mensual de mantener una sucursal y el número máximo $N$ de sucursales que quiere abrir la nueva cadena, determine el ingreso máximo mensual que se puede obtener ubicando las sucursales de manera óptima.

# Entrada

Tu programa deberá leer de la entrada estándar los siguientes datos:

- En la primera línea los enteros $N$, $M$, $F$ y $P$. El número de sucursales, el largo de la calle, la cantidad de franquicias actuales y el número de oficinas.
- En la segunda línea los enteros $B$ y $C$. El gasto mensual de cada programador y el costo mensual de mantener una sucursal.
- En la tercera línea habrá $F$ enteros separados por espacio, el $i$-ésimo de estos enteros representa la ubicación de la $i$-ésima franquicia establecida.
- En las siguientes $P$ líneas habrá dos enteros separados por espacio $pos_j$, $programadores_j$ que representan la ubicación de la $j$-ésima oficina y el número de programadores que hay en ella.

**Tanto las franquicias como las oficinas vendrán ordenadas de acuerdo a su ubicación.**

# Salida

Tu programa deberá escribir en la salida estándar un número indicando el ingreso máximo mensual que se puede obtener.

# Ejemplo

||input

3 20 6 8
2 5
1 5 6 8 12 16
1 1
3 1
4 2
7 1
10 5
11 1
14 2
19 2

||output

8

||description

Se abren las siguientes sucursales:

- Una sucursal de _carrito_ entre los edificios en las posiciones $10$ y $11$: A esta sucursal van los programadores de los edificios $10$ y $11$, en total seis programadores. Dado que $B = 2$ la venta total es $6 \times 2 = 12$. A esta venta hay que quitarle el costo $C = 5$ con lo que queda un ingreso total de $12 - 5 = 7$ unidades mensuales.

- Una sucursal en el edificio en la posición $4$: A esta sucursal van los programadores de los edificios $3$ y $4$. Haciendo el ejercicio de ingreso tenemos que el ingreso total (venta menos costo) de esa surusal sería $2 \times 3 - 5 = 1$.

Aunque se puede abrir una sucursal más, en cualquier lugar que se abra tendría pérdida, por lo que no hay beneficio en abrirla.

El ingreso total que puede tener la nueva cadena es por tanto de $8$ unidades al mes.

||end

# Límites

- $1 \le N, F, P \le 10^5$
- $N \le M \le 10^6$
- $1 \le f_i, pos_j \le M$
- $0 \le B, C, prog_j \le 10^6$

# Subtareas

- **(12 puntos)**: $N = 1$, $M = 1000$, $C = 0$ Solo se piensa abrir una sucursal, la calle tiene a lo más $1000$ edificios y no hay costo por mantener una sucursal.
- **(13 puntos)**: $N = 1$
- **(25 puntos)**: $N = 2F$, $C = 0$
- **(20 puntos)**: $N = 2F$
- **(30 puntos)**: Sin restricciones adicionales.
