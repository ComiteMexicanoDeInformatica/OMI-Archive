Karel se inscribió en un club de ciclismo y hoy está participando en su primer viaje. El itinerario del viaje tiene subidas y bajadas. Karel es principiante, él sabe que no tiene la condición suficiente para resistir todas las subidas por lo que decidió llevar una bici eléctrica para ayudarse en algunos tramos.

En este momento Karel ya agotó por completo sus energías, el resto del trayecto lo hará únicamente con el motor eléctrico de la bici. Sin embargo, Karel no sabe cuánta energía necesitará para el tramo faltante.

La bici de Karel funciona de la siguiente manera:

- La bicicleta tiene una batería cuya carga se mide en _rayitas_ de energía. La batería tiene una carga máxima de $R$ _rayitas_ de energía.
- Por cada metro que Karel **suba** con su bicicleta, se **consume una _rayita_** de energía.
- Por cada metro que Karel **baja** con su bicicleta, la batería se **recarga una _rayita_** de energía.
- Cuando Karel avanza en **terreno plano**, la bicicleta **no consume energía** y la batería no se descarga.

Si la batería de la bicicleta de Karel está en **cero _rayitas_ y debe subir,** Karel no podrá hacerlo y se quedará a la mitad del camino.

En este momento el club se detuvo en una tiendita del camino donde puedes recargar tu bicicleta. Karel conoce la altura del punto en el que está y las alturas de todos los siguientes tramos del trayecto. Ayuda a Karel a determinar ¿cuál es el mínimo número _rayitas_ de energía que debe cargar en su bicicleta para poder terminar el trayecto?

El mundo de Karel es un rectángulo sin paredes internas en el que se representa la siguiente información:

- En la fila 1 del mundo, a partir de la columna 1, hay montones de zumbadores que representan la altura de cada uno de los tramos faltantes del trayecto. Todas las alturas son mayores a cero. Karel y su club se encuentran en el punto representado por la casilla (1, 1).
- En la fila 2 del mundo hay dos valores:
  - En la columna 1 hay un montón de zumbadores que representa el valor $E$, la cantidad de _rayitas_ de energía que tiene la batería en este momento.
  - En la columna 2 hay un montón de zumbadores que representa el valor $R$, la cantidad máxima de _rayitas_ de energía que puede almacenar la batería.

# Problema

Escribe un programa que dado el mapa de las alturas, la energía actual en la batería y la energía máxima que puede almacenar, deje en la casilla (1, 1) un montón de zumbadores igual a la cantidad de _rayitas_ de energía que Karel debe recargar antes de iniciar el trayecto.

Si es posible para Karel terminar el trayecto deberá apagarse viendo al norte (después de dejar la cantidad de energía a cargar en la casilla (1, 1)). De otra forma **si no es posible que Karel termine el trayecto,** deberá apagarse viendo al sur.

# Ejemplos

## Entrada

![Mundo de entrada](sample.in.png)

## Salida

![Mundo de entrada](sample.out.png)

## Descripción

Karel inicia en una altura de 4 con 2 _rayitas_ de energía en la batería.

- Karel debe subir a una altura 6, por lo que consumirá 2 rayitas de energía (si no recargó, tendría 0 rayitas en este momento).
- Karel baja ahora a una altura 3, por lo que recarga 3 rayitas de energía (su batería si no recargó es 3).
- Karel sube a una altura 5, consume 2 rayitas de energía (su batería si no recargó es 1).
- Karel sube a una altura 7, requiere 2 rayitas pero sólo tiene 1. Si no recarga, Karel no podrá avanzar este tramo.

Haciendo pruebas, puedes observar que si Karel recarga $1$ rayita de energía antes de iniciar, podrá terminar el trayecto sin problema.

# Consideraciones

- Karel empieza en la casilla (1, 1) orientado al norte.
- Karel lleva infinitos zumbadores en la mochila.
- El mundo de Karel es de 100 filas y 100 columnas.
- El trayecto termina cuando encuentres la primera posición sin zumbadores en la fila 1 o cuando llegues a la pared.
- **La altura de cada tramo es mayor o igual a 1.**
- El número que representa la altura de cada trayecto puede ser mayor que la altura del mundo.
- Los números que representan los valores $E$ y $R$, la energía actual y la máxima de la batería respectivamente son mayores o iguales a 1 y menores o iguales a 200.
- **No importa la posición final de Karel**.
- **Para obtener los puntos de este problema, Karel debe apagarse viendo al norte o al sur dependiendo de si es posible o no terminar el trayecto.**
- **Para obtener los puntos de este problema, Karel debe dejar en la casilla (1, 1) un montón de zumbadores igual a la cantidad mínima de energía que debe recargar. Si Karel no puede terminar, sólo importa que termine apagado viendo al sur.**

# Subtareas

- (5 puntos): La posición actual del club de Karel tiene la altura máxima de todo lo que resta del trayecto.
- (11 puntos): En lo que resta del trayecto, desde el punto de partida de Karel hay sólo una serie de tramos que suben seguidos de una serie de tramos que bajan. Además se te asegura que Karel siempre puede terminar el trayecto.
- (11 puntos): En lo que resta del trayecto, desde el punto de partida de Karel hay sólo una serie de tramos que bajan seguidos de una serie de tramos que suben. Además se te asegura que Karel siempre puede terminar el trayecto.
- (23 puntos): La posición actual de Karel tiene altura 1, se te asegura que Karel siempre podrá terminar el trayecto.
- (40 puntos): La posición actual de Karel tiene altura 1.
- (10 puntos): Sin ninguna restricción.
