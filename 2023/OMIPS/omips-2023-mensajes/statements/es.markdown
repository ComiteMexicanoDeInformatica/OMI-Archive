![Ilustracion](mensajes.jpeg)

Karel aprendió a leer desde muy pequeño gracias al método de su maestra de preescolar, el cual se describe a continuación.

- Al iniciar el día, la maestra le pintaba a cada niño una letra en cada mano.
- Luego la maestra escribía una palabra en el pizarrón.
- Finalmente algunos de los niños debían acomodarse en una línea y formar la misma palabra usando las letras en sus manos.

Había algunas restricciones que tomar en cuenta:

- Cada niño tenía que usar las letras de ambas manos. La maestra siempre escribía palabras de longitud par.
- Las dos letras de cada niño tenían que usarse juntas, es decir, el primer niño de la fila aporta las letras 1 y 2, el segundo las letras 3 y 4, etc.
- Cada niño podía utilizar sus dos letras en cualquier orden, es decir, si el niño tenía las letras "O" y "M" en sus manos el niño pude ponerlas de modo que formen "OM" o de modo que formen "MO".
- Un niño sólo puede participar una vez por palabra, sin embargo, el mismo niño puede participar varias veces en la clase, en distintas palabras.

La maestra de Karel necesita tu ayuda. Ella ha decidido una lista de palabras que quiere usar en la clase de hoy, pero necesita saber cuál es el mínimo número de niños que requiere haber en la clase para que sea posible formar todas las palabras.

En el mundo de Karel se representan la lista de palabras de la maestra. Cada palabra se representa en una fila como una lista de zumbadores en la cual cada montón representa una letra. Las palabras se listan a partir de la primera fila y hacia arriba. Todas las palabras serán de una longitud par.

**Algo importante que debes saber es que en el lenguaje de Karel sólo existen 9 letras diferentes. Estas letras se representan con montones de zumbadores del 1 al 9.**

# Problema

Escribe un programa que dada la lista de las palabras de la maestra determine el número mínimo de niños que debe haber en la clase para que sea posible crear todas las palabras. Tu programa deberá dejar un montón de zumbadores en la posición (1, 1) indicando esa cantidad.

# Ejemplos

## Entrada

![Mundo de entrada](mensajes.in.png)

## Salida

![Mundo de salida](mensajes.out.png)

## Descripción

La lista de la maestra tiene 3 palabras.

- Para la primera palabra "12345678" se requieren 4 niños, al primero de ellos se le pintarán las letras "1" y "2", al segundo las letras "3" y "4", etc.
- Para la segunda palabra "1221" se requieren 2 niños, pero es posible _reutilizar_ al niño con la pareja "1", "2" de la primera palabra y pintar las letras "2", "1" a uno nuevo. De modo que hasta este momento se requieren 5 niños.
- La última palabra "118721" requiere 3 niños, sin embargo, tanto para el "87" como para el "21" podemos _reutilizar_ niños que ya se tienen, por lo que sólo se requiere un nuevo niño para el "11".

Por lo tanto el mínimo de alumnos que se requiere en la clase es de 6.

# Consideraciones

- Karel inicia en la posición (1, 1) orientado al norte.
- Karel lleva infinitos zumbadores en la mochila.
- El mundo de Karel siempre será de tamaño $100 \times 100$.
- Comenzando de la fila 1 y hacia arriba, hay una palabra por fila hasta junta la lista completa. Cada palabra es una lista de montones de zumbadores entre $1$ y $9$ sin espacios intermedios. Cada palabra tiene una longitud par de letras.
- **Para obtener los puntos, tu programa deberá dejar en la posición (1, 1) un montón de zumbadores indicando la cantidad mínima de niños que se requiere en la clase para poder escribir todas las palabras.**

# Subtareas

En este problema, los casos de cada subtarea se encuentran agrupados. Para obtener el puntaje de una subtarea deberás resolver correctamente todos los casos del grupo.

- (15 puntos): La única letra que se usa es la letra "1".
- (30 puntos): En las posiciones impares de todas las palabras siempre se usará la letra "1" y en las posiciones pares las letras de la "2" a la "9".
- (23 puntos): Se te asegura que si divides las palabras en _parejas de letras_, todas las parejas entre todas las palabras son diferentes.
- (32 puntos): Sin restricciones adicionales.
