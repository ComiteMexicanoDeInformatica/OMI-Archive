Acaban de descubrir una nueva pirámide en Karelotitlán y han pedido tu ayuda para restaurarla.

En la primera fase de trabajo se va a restaurar la escalera principal de la pirámide. La escalera tiene $N$ escalones (numerados de $1$ a $N$), pero muchos de ellos se encuentran dañados. A algunos de ellos les faltan pedazos y están a menor altura de la que deberían y a otros les han caído piedras encima y son más altos de lo que deberían.

Hay $K$ escalones que se conservan en perfectas condiciones y tienen bellos relieves grabados. Durante la restauración, debes mantener los $K$ escalones tal como están y restaurar **algunos** de los escalones restantes para asegurar que toda la escalera sea ascendente, es decir, que la altura del escalón $i$ sea menor que la altura del escalón $i + 1$. Al restaurar un escalon puedes aumentar o disminuir su altura en cualquier cantidad. **La altura final del escalón debe ser entera y mayor o igual que cero.**

Restaurar cada escalón cuesta, por lo que se busca restaurar el menor número de escalones posible.

La empresa te ha dado una lista de $N$ números que representan las alturas actuales de los escalones y te ha dado las posiciones de los $K$ escalones que se desea conservar.

# Problema

Escribe un programa que dadas las alturas de los $N$ escalones y la lista de los $K$ escalones que se desean conservar, proponga una posible configuración final para la escalera restaurada. La configuración debe conservar los $K$ escalones deseados y puede modificar los valores de altura del resto.

La calificación que obtenga tu programa será mejor mientras menos escalones modifique.

# Entrada

- En la primera línea los números $N$ y $K$, el número de escalones y la cantidad de ellos que se desea conservar.
- En la segunda línea habrá $N$ números separados por espacio que representan las alturas de los escalones del $1$ al $N$.
- En la tercera línea habrá $K$ números distintos separados por espacio que representan las posiciones de los escalones que se desea conservar.

# Salida

- Una línea con $N$ enteros que representan las alturas finales de los escalones en la escalera restaurada.

**En caso de que sea imposible construir una escalera ascendente tu programa deberá imprimir -1.**

# Ejemplo

||input
10 2
4 3 5 4 8 16 15 18 19 3
7 3
||output
2 3 5 6 8 14 15 18 19 20
||description
Los escalones que se desea conservar son el $3$ (con altura $5$) y el $7$ (con altura $15$).

Una opción de restauración (**hay otras distintas**) sería: **2** 3 5 **6** 8 **14** 15 18 19 **20** donde los números en negrita representan los escalones que se restauraron.

Para esta pirámide, no es posible restaurar la escalera modificando menos de $4$ escalones, por lo que esta solución obtendría el $100%$ de los puntos.
||input
5 2
1 2 4 3 5
3 4
||output
-1
||description
La escalera del ejemplo es imposible de restaurar ya que se desea conservar los escalones $3$ y $4$ pero sus alturas no cumplen con la regla de ser una escalera ascendente.  
||end

# Límites

- $2 \leq N \leq 10^5$
- $0 \leq K \leq N$
- $0 \leq h_i \leq 10^9$ Los valores de altura en el arreglo inicial.

# Evaluación

Para cada subtarea tu programa será evaluado de la siguiente forma:

- Si tu programa escribe un escalera inválida, obtendrá $0$ puntos. Una escalera inválida es aquella que:
  - Tiene más o menos de $N$ escalones.
  - Modifica alguno de los $K$ escalones que se debían dejar intactos.
  - No es ascendente.
- Si tu programa escribe $-1$ cuando sí era posible construir una escalera, obtendrá $0$ puntos.
- Si tu programa escribe una escalera **válida** que modifica $N - K$ escalones, es decir, todos los escalones que se pueden modificar, obtendrá **10% de los puntos**.
- Si tu programa escribe una escalera **válida** que modifica el número mínimo de escalones, obtendrá **100% de los puntos**.
- Si tu programa escribe una escalera **válida** que modifica entre $N - K$ y el número mínimo de escalones, obtendrá un puntaje intermedio entre **10% y 100% de los puntos**.

# Subtareas

- **(23 puntos)**: $N \leq 20$ y no hay ninguna escalera que no se pueda restaurar.
- **(37 puntos)**: $N \leq 1000$
- **(40 puntos)**: Sin restricciones adicionales
