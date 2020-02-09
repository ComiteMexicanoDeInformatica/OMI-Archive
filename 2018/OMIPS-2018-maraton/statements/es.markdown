# Historia

Durante su visita a la Ciudad de México, Karel se enteró que iba a
ser el maratón de la CDMX. Pronto se dio cuenta que al conocer el
mapa de la carrera y la velocidad de cada corredor podía saber quién
será el ganador del maratón antes de que empiece.

# Problema

Karel está dentro del mapa de la carrera. Los corredores empiezan la carrera en la fila 1. Cada columna representa el carril de un corredor.

Cada corredor da pasos de distinto tamaño: en cada punto de partida hay un montón de zumbadores que describe cuántas casillas avanza por paso ese corredor.

Un corredor gana la carrera si:

* Puede llegar en un número exacto de pasos a su meta.
* Este número de pasos es menor a los pasos que necesitan los otros corredores para llegar a cada una de sus metas.

Un corredor choca con la pared y pierde si en el último paso no puede avanzar todas las casillas de su paso sin toparse con la pared de su meta.

Karel se debe apagar en la fila 1 en la columna del ganador de la carrera.

# Ejemplos

### Entrada

![Entrada](entrada.png)

### Salida

![Salida](salida.png)

En este ejemplo, el corredor del carril 1 en cada paso avanza 3 casillas; su carril es de 9 casillas, entonces le toma 3 pasos llegar a su meta.  
El corredor del carril 2 en cada paso avanza 6 casillas, así que sólo puede dar un paso; si quisiera dar un segundo paso, chocaría con la pared.  
El corredor del carril 3 en cada paso avanza 11 casillas, así que en un paso llega a su meta.

El corredor del carril 3 es el ganador.

# Consideraciones

* Karel inicia en la casilla (1,1) orientado al norte.
* Karel tiene infinitos zumbadores en la mochila.
* Las únicas paredes en el mundo son las que lo delimitan.
* Los únicos zumbadores en el mundo son los de la fila 1.
* La velocidad de los corredores puede ser entre 0 y 99.
* La longitud de las pistas puede ser entre 2 y 100 casillas.
* Puede haber hasta 100 corredores.
* Siempre habrá un solo ganador.
* Karel se debe apagar en la fila 1, en la columna del corredor ganador.
* No importa la orientación final de karel.
* No importa cómo queden los zumbadores del mundo al final.

# Subtareas

* Para el 8% de los casos todas las metas son a la misma altura y ningún corredor choca con la pared.
* Para el 9% de los casos todos los corredores corren a la misma velocidad y ningún corredor choca con la pared.
* Para el 24% de los casos ningún corredor choca con la pared.
* Para el 59% restante no hay consideraciones adicionales.
