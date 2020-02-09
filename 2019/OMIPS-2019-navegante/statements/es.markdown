# Historia

Karel está planeando sus próximas vacaciones en el mar y quiere saber si puede navegar desde una casilla de origen a una casilla destino.

Karel va a permanecer una cantidad de días en el mar, cada día, el barco se moverá de 2 formas:

* Durante el día, el barco se moverá una casilla en la dirección en la que sopla el viento ese día.
* Durante la noche, Karel decide si deja el barco dónde está o lo mueve **1 casilla** en alguna de las direcciones *norte*, *este*, *sur* u *oeste*.
 
Para asegurarse que todo salga bien, Karel sabe en qué dirección va a soplar el viento todos los días de sus vacaciones.

El mundo de Karel tiene los siguientes datos:

* En la fila 2 está la información de la casilla de origen.  El primer montón de esa fila representa la columna de la casilla origen y el segundo montón representa la fila de la casilla origen.
* En la fila 3 está la información de la casilla destino. El primero monton de esa fila representa la columna de la casilla destino y el segundo montón representa la fila de la casilla destino.
* En la fila 1 se encuentran las direcciones en las que soplará el viento cada día. Un $1$ significa que el viento sopla al *Norte*, un 2 significa que sopla al *Oeste*, un 3 al *Sur* y un 4 al *Este*.

# Problema

Ayuda a Karel a saber si puede iniciar sus vacaciones en la casilla de origen y llegar a la casilla destino el último día de sus vacaciones. Si puede llegar, apágate viendo al norte y si no puede llegar, apágate viendo al sur.

# Ejemplos

### Entrada

![Entrada1](sample.3x6.in.png)

### Salida

![Salida1](sample.3x6.out.png)

### Explicación

Karel inició en la casilla (columna 5, fila 4). El primer día el viento sopló hacia el norte y Karel movió su barco hacia el este, por lo que tras el primer día Karel terminó en la casilla (columna 6, fila 5). El segundo y tercer día Karel movió su barco hacia el este, por lo que luego de 3 días Karel se encontraba en la casilla (columna 8, fila 7). El cuarto día el viento soplaba hacia el oeste y Karel movió su barco hacia el este, por lo que no se movió de lugar. En el quinto día Karel avanzará hacia el norte, terminando en la casilla (columna 8, fila 9), y el último día Karel se dejará llevar por el viento para llegar al destino. No es la única estrategia que Karel pudo haber seguido para llegar al destino.

# Consideraciones

* Karel inicia en la casilla 1,1 viendo al norte.
* Karel tiene infinitos zumbadores en la mochila.
* Las únicas paredes en el mundo son las que lo delimitan.
* El mundo siempre medirá 100x100.
* Las casillas de origen y de destino siempre estarán dentro del mundo de 100x100.
* El número de días que duran tus vacaciones es el número de montones en la fila 1.
* Las vacaciones de Karel pueden durar a lo más 99 días.
* No importa la posición final de Karel.
* No importa el estado final del mundo.
* Solo se evaluará la orientación final de Karel.
* Los casos están agrupados en pares.

# Subtareas

* **(17 puntos)** el viento solo sopla al Norte.
* **(83 puntos)** no hay consideraciones adicionales.
