Karel fue a visitar las Barrancas del Cobre, donde podía observar muchas montañas juntas. Karel quiere tomar la foto más hermosa de las Barrancas del Cobre. La hermosura de una foto se calcula sumando las diferencias de alturas de cada par de montañas juntas que salen en la foto.

Es importante que sepas que no siempre caben todas las montañas en la foto de Karel.

# Problema

Ayuda a Karel a calcular la hermosura máxima que se puede obtener al fotografiar $K$ montañas juntas.

# Entrada

- En la casilla $(1,1)$ hay $N$ zumbadores que representan la cantidad de montañas que hay.
- En la casilla $(2,1)$ hay $K$ zumbadores que representan la cantidad de montañas que caben en la foto de Karel.
- En la segunda fila, empezando en la columna $1$, hay $N$ montones que indican la altura de las $N$ montañas.

# Salida

Karel debe dejar en la casilla $(3,1)$ un único número que representa la máxima hermosura que puede conseguir Karel en una foto.

# Ejemplo

## Entrada

![Ejemplo de Entrada](sample.3x7.in.png)

## Salida

![Ejemplo de Salida](sample.3x7.out.png)

En este caso, Karel debe escoger 4 montañas. Si escogemos las primeras 4, la hermosura se calcula como sigue:

- De la primera montaña a la segunda la diferencia es $-1$ porque $1 - 2 = -1$.

- La diferencia entre la segunda y la tercera montaña es $2$ porque $3 - 1 = 2$. La hermosura hasta el momento es de $1$ ya que $-1 + 2 = 1$.

- Finalmente de la tercera a la cuarta la diferencia es $-1$ porque $2 - 3 = 1$ y la hermosura total es $0$ porque $-1 + 1 = 0$.

Las operaciones para calcular la hermosura de $4$ montañas empezando en la montaña $1$ es:

$(1 - 2) + (3 - 1) + (2 – 3) = -1 + 2 + -1 = 0$

Si se inicia en la segunda montaña, la hermosura total se calcula como sigue:

$(3 - 1) + (2 - 3) + (6 - 2) = 2 + -1 + 4 = 5$

Revisa con cuidado el cálculo anterior con el ejemplo hasta que entiendas cómo se hizo.

Por último si se inicia en la tercera montaña, la hermosura total se calcula:

$(2 – 3) + (6 – 2) + (2 – 6) = -1 + 4 – 4 = -1$

No es posible empezar en la cuarta, quinta o sexta montañas ya que sería imposible fotografiar 4 montañas.

**La respuesta del problema es la hermosura máxima de todas las hermosuras posibles, la cual se obtiene iniciando en la segunda montaña y su total es 5**.

# Consideraciones

- No hay paredes internas en el mundo.
- Karel empieza en la casilla $(1,1)$ viendo al norte.
- Karel tiene infinitos zumbadores en la mochila.
- El número de montañas puede ser entre $2$ y $100$.
- El número de montañas que caben en la foto puede ser entre $2$ y $100$.
- Las alturas de las montañas pueden ser entre $1$ y $100$ inclusive.
- Puede haber alturas repetidas.
- Solo se evaluan los zumbadores en la casilla $(3, 1)$.
- Se asegura que la respuesta siempre será mayor o igual a $0$.

# Subtareas

- **(35 puntos)**: Las alturas de las montañas están ordenadas ascendentemente. (No hay hermosuras negativas)
- **(35 puntos)**: No hay restricciones adicionales.
- **(30 puntos)**: Solo puedes usar la instrucción avanza a lo más $8N$ veces.
