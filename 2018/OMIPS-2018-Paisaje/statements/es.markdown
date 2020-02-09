En su visita a la Ciudad de México, Karel visitó el museo de Frida Kahlo.
Esa visita lo inspiró, por lo que ahora quiere dedicarse a pintar paisajes.

Como es su primera vez pintando, decidió mejor sólo esbozar su paisaje
y dejarte a ti que lo completes.

Ayuda a Karel a terminar su pintura.

# Problema

El paisaje de Karel es muy sencillo: sólo tiene montañas y cielo.

Karel marcó para ti los puntos con las cimas y valles de sus montañas.
Tu tarea es rellenar el resto del lienzo, usando montones de un zumbador
para pintar las montañas, y montones de dos zumbadores para pintar el cielo.

Karel siempre puede visitar todas las cimas y valles una por una
si empieza desde la que está más a la izquierda. Estando sobre un
zumbador, para llegar al siguiente, Karel debe avanzar una casilla al
este, una al norte, y repetir esto varias veces si está subiendo las montañas,
o una casilla al este, una al sur, y repetir si está bajando las montañas.

# Ejemplo

### Entrada

![Entrada](entrada.png)

### Salida

![Salida](salida.png)

### Explicación

Las cimas y valles de las montañas están marcadas por grupos de un zumbador.

Al visitar los zumbadores uno por uno y dibujar el camino,
quedan divididas las montañas del cielo.

# Consideraciones

* El mundo de Karel es rectangular, de tamaño desconocido.
* Karel inicia sobre el zumbador más a la izquierda de todos, viendo al este.
* Karel siempre inicia sobre una cima.
* Solamente hay montones de un zumbador en el mundo, representando las cimas y valles del boceto de Karel.
* Siempre hay un valle después de una cima y siempre hay una cima después de un valle.
* Siempre hay un zumbador en la primera y la última columna del mundo.
* Karel tiene infinitos zumbadores en la mochila.
* Las únicas paredes son las que delimitan el mundo.
* Se evalúa cómo quedan todos los zumbadores del mundo al final.
* No importa cómo quede la mochila de Karel al final.
* No importa la posición y orientación final de Karel.

# Subtareas

* En el 13% de los casos el boceto de Karel solo tiene dos zumbadores.
* En el 87% de los casos no hay restricciones adicionales.
