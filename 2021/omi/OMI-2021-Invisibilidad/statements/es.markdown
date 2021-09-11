Harry anda de turista en la ciudad de Yakarta previo a la IOI 2022.

Yakarta puede representarse como un rectángulo de $F$ filas por $C$ columnas. Harry desea recorrer toda la ciudad. Para eso Harry comienza en algún lugar de la fila $1$ y quiere llegar a la fila $F$. Como cualquier turista, Harry puede desplazarse en 4 direcciones: norte, sur, este u oeste.

Yakarta tiene $N$ zonas peligrosas en las que Harry debe usar su capa de invisibilidad para pasar sin peligro. Sin embargo, sacar la capa es riesgoso (no debe usar artefactos mágicos en presencia de la gente), por lo que Harry quiere minimizar las veces que usa su capa. Además, Harry quiere comprar _recuerditos_ (y con la capa no puede interactuar con la gente), por lo que sólo piensa usar la capa en las zonas peligrosas.

Cuando usa la capa, Harry no requiere respetar las reglas de tránsito, por lo que puede moverse a cualquiera de las 8 casillas circundantes. Además, Harry puede pasar de una zona peligrosa a otra sin quitarse la capa siempre y cuando ambas zonas peligrosas estén contiguas (tengan un lado o una esquina en común).

Las zonas peligrosas se representan como un rectángulo dentro de la ciudad.

# Problema

Escribe un programa que dadas las dimensiones de la ciudad y las ubicaciones de las zonas peligrosas determine ¿cuál es el menor número de veces que Harry debe usar su capa para moverse desde la fila $1$ hasta la fila $F$?

# Entrada

- En la primera línea los números $N$, $F$ y $C$. La cantidad de zonas peligrosas, la cantidad total de filas y la cantidad total de columnas en la ciudad.
- En las siguientes $N$ líneas habrá cuatro enteros $f_{i_1}$, $c_{i_1}$, $f_{i_2}$ y $c_{i_2}$ que corresponden a la fila y columna de la esquina superior-izquierda y la fila y columna de la esquina inferior-derecha de la _i-ésima_ zona peligrosa.

- **Se asegura que no hay zonas peligrosas ni en la fila $1$ ni en la fila $F$.**
- **Se asegura que las zonas peligrosas no se traslapan entre sí.**

# Salida

- Un número que indique la cantidad mínima de veces que Harry debe usar la capa para moverse de la fila $1$ a la fila $F$

# Ejemplo

||input
2 5 5
2 4 3 5
3 1 4 2
||output
0
||description
El mapa de la ciudad se ve así. La letra **X** representa una zona peligrosa

```
.....
...XX
XX.XX
XX...
.....
```

Si Harry se mueve de forma óptima, no es necesario usar la capa.
||input
2 5 5
2 4 3 5
4 1 4 3
||output
1
||description

```
.....
...XX
...XX
XXX..
.....
```

Aunque hay dos zonas peligrosas, Harry puede pasar de una a otra sin quitarse la capa, por lo que sólo tiene que ponérsela $1$ vez.
||input
2 5 1
2 1 2 1
4 1 4 1
||output
2
||description
||input
6 6 3
2 2 2 2
3 1 3 1
3 3 3 3
4 2 4 2
5 1 5 1
5 3 5 3
||output
3
||description
||end

# Límites

- $1 \leq N \leq 2000$
- $1 \leq F, C \leq 10^9$

# Subtareas

- **( puntos)**: $F = 3$, $N = 1$
- **( puntos)**: $F = 3$, $C \leq 1000$
- **( puntos)**: $F = 3$
- **( puntos)**: $C = 1$
- **( puntos)**: $F, C \leq 500$, $N \leq 100$
- **( puntos)**: Sin restricciones adicionales.
