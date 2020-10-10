Oh, oh, el reloj de Karel ha dejado de funcionar.

# Problema

Sabiendo la hora exacta en la que se detuvo el reloj y los segundos que han transcurrido desde entonces, debes determinar qué hora es.

- La hora en que se detuvo el reloj está en la casilla (2,1).
- El minuto en el que se detuvo el reloj está en la casilla (2,2).
- El segundo en el que se detuvo el reloj está en la casilla (2,3).
- La cantidad de segundos que han transcurrido desde que se detuvo el reloj está en la casilla (1,1).

# Ejemplos

### Entrada

![Entrada](entrada.png)

### Salida

![Salida](salida.png)

# Consideraciones

- Karel inicia en la casilla (1,1) viendo al norte.
- Karel no tiene zumbadores en la mochila.
- En la casilla (3,1) habrá un montón de infinitos zumbadores.
- La cantidad de zumbadores en la casilla de las horas puede ir de 0 a 23.
- La cantidad de zumbadores en la casilla tanto de minutos como de segundos puede ir de 0 a 59.
- La hora en la que se detuvo el reloj es una hora válida. Es decir, las horas, los minutos y los segundos cumplen las dos consideraciones anteriores.
- Los segundos que han transcurrido desde que se detuvo el reloj pueden ir de 1 a 99,999.
- El mundo en el que está Karel siempre es de 3x3.
- No importa la posición ni la orientación final de Karel.

# Subtareas

- En el 15% de los casos la casilla (1,1) será menor a 60 y se asegura que no aumentarán los minutos.
- En el 26% de los casos se asegura que no aumentarán las horas.
- En el 59% restante no hay restricciones adicionales.
