Karel acaba de llegar a la Ciudad de México y entre tanta gente se perdió. Antes de perderse, su guía le dijo en qué puerta se tenían que ver. El guía es un poco despistado, así que puede ser que haya puesto un número de puerta que no existe.

# Problema

Ayuda a Karel a llegar a la puerta en la cual tiene que encontrar a su guía y una vez que llegue, orientarse al norte. Si la puerta no existe, Karel se debe regresar al punto de llegada y orientarse viendo al sur.

# Ejemplos

### Entrada

![Entrada](entrada.png)

### Salida

![Salida](salida.png)

# Consideraciones

* Karel inicia en la casilla (1,1) viendo al norte.
* En la casilla (1,1) está un montón de zumbadores que representa el número de puerta en la que Karel va a encontrarse con su guía.
* El único montón de zumbadores en la fila 1 será el de la casilla (1,1).
* Los números de las puertas van del 1 al 99.
* No habrá más de una puerta con el número que está buscando Karel.
* Las únicas paredes son las que delimitan el mundo.
* No importa cómo queden los zumbadores del mundo al final.
* No importa cómo quede la mochila de Karel al final.
* Se evalúa la posición y orientación final de Karel.
* Los casos de prueba están agrupados en pares. Esto quiere decir que si siempre te apagas en la casilla (1,1) viendo al norte, vas a obtener 0 puntos.

# Subtareas

* En el 72% de los casos Karel no tiene zumbadores en la mochila.
* En el 28% de los casos Karel tiene infinitos zumbadores en la mochila.
