![Ilustracion](karel-skate.jpeg)

Karel se ha vuelto un experto en patineta con el objetivo de representar a México en los juegos olímpicos en esta disciplina. Está tan acostumbrado a la patineta que ahora es su único medio de transporte. Sin embargo, la patineta de Karel es especial, ya que es capaz de _saltar_ y _flotar_.

En específico, si Karel quiere transportarse de un lugar a otro en su patineta puede hacerlo de la siguiente forma:

- **Avanzar:** Si la patineta está sobre piso, es decir, tiene pared en el lado sur, la patineta sólo puede avanzar hacia el este. **_Avanzar_ NO cuesta energía.**
- Si la patineta está sobre aire, es decir, no tiene pared en el lado sur, Karel puede decidir entre alguno de los siguientes movimientos:
  - **Saltar:** Mueve a Karel una casilla al norte. **_Saltar_ tiene costo de energía 1.**
  - **Flotar:** Mueve a Karel una casilla al este. **_Flotar_ tiene costo de energía 1.**
  - **Caer:** Mueve a Karel una casilla al sur. **_Caer_ NO cuesta energía.**

En cualquiera de los tres casos: _saltar_, _flotar_ o _caer_, Karel sólo puede llevarlos a cabo si no existe una pared que le impida dicho movimiento.

Observa las siguientes figuras para entender los movimientos posibles del monopatín de Karel.

![Avanza](ejemplo1.png)

En esta imagen la patineta de Karel está sobre el piso, por lo que Karel tiene que avanzar hacia el este.

![Opciones](ejemplo2.png)

En esta imagen la patineta de Karel está en el airepor lo que puede decidir _saltar_ (con costo), _flotar (con costo) o \_caer_ (de forma gratuita).

El mundo de Karel representa una serie de pisos por los que Karel puede avanzar y entre los cuales puede _saltar_, _flotar_ o _caer_. Además, en la columna este del mundo hay un montón de zumbadores que indican la posición a la que Karel desea llegar. Haz un programa que lleve a Karel a la posición deseada y deje en esa posición un montón de zumbadores que indique el mínimo de energía que tiene que usar para llegar hasta esa posición.

# Problema

Escribe un programa que lleve a Karel de su posición de inicio a la posición en la columna este marcada con un montón de 1 zumbador y deje ahí un montón de zumbadores igual al costo mínimo de energía que tuvo que gastar para llegar ahí.

# Ejemplos

## Entrada

![Mundo de entrada](karel-skate.in.png)

## Salida

![Mundo de salida](karel-skate.out.png)

## Descripción

En este mundo Karel tiene muchas formas para moverse de su posición inicial a la posición deseada. En el ejemplo de salida se muestran 3 posibles.

- En el camino **rojo**, cada vez que Karel quedó sin piso decidió _flotar_ para avanzar hacia el este. En total Karel tiene que _flotar_ 5 veces por lo tanto el costo de energía del camino **rojo** es 5.
- En el camino **azul**, Karel decide primero _caer_, posteriormente _flotar_ y finalmente _saltar_ y _flotar_ un último espacio. El costo total de energía del camino azul es de 8.
- En el camino **verde**, Karel decide primero _saltar_ un par de posiciónes y _flotar_ para alcanzar el piso. Finalmente Karel simplemente se deja _caer_ sobre la posición deeseada. El costo total de energía del camino verde es 3 y es el mínimo que se puede lograr, por lo tanto, la respuesta es 3.

# Consideraciones

- Karel inicia en alguna posición orientado al este.
- Karel lleva infinitos zumbadores en la mochila.
- El único zumbador del mundo indica la posición deseada.
- Se asegura que siempre será posible para Karel llegar a la posición deseada.
- **Para obtener los puntos, tu programa deberá en la posición desada, un montón de zumbadore que indique la energía mínima que se tiene que consumir para llegar de la posición inicial al punto deseado.**

# Subtareas

En este problema, los casos de cada subtarea se encuentran agrupados. Para obtener el puntaje de una subtarea deberás resolver correctamente todos los casos del grupo.

- (7 puntos): Se te asegura que la solución mínima sólo requiere el movimiento _flotar_.
- (17 puntos): Se te asegura que la solución mínima sólo requiere usar los movimientos _flotar_ y _caer_.
- (12 puntos): Además de las paredes que rodean el mundo sólo existe una pared de _piso_ en el mundo.
- (22 puntos): Además de las paredes que rodean el mundo, por cada columna del mismo habrá, a lo más una pared.
- (42 puntos): Sin restricciones adicionales.
