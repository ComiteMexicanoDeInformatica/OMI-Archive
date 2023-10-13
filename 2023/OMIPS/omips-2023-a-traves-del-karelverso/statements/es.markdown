![Ilustracion](ilustracion_karelverso.jpeg)

Karel estaba a punto de iniciar el examen de la OMIPS cuando súbitamente fue teletransportado a un universo distinto. En este nuevo universo Karel tiene varios poderes, sin embargo, el está dispuesto a renunciar a ellos con tal de poder regresar a tiempo para su examen.

Para regresar a su universo, Karel debe moverse hacia el _portal._ El _portal_ es el único montón de 2 zumbadores que hay en el mundo.

Las cosas, por supuesto, son más difíciles de lo que parecen ya que en su nuevo universo Karel se mueve de forma distinta. En específico:

- Cada que Karel da un _paso_, se mueve una cantidad $K$ de casillas.
- Los $K$ movimientos puede hacerlos en cualquier dirección, no necesariamente la misma. Por ejemplo, si $K = 5$ entonces Karel podría moverse "Norte" -> "Este" -> "Este" -> "Sur" -> "Oeste". Y así en cualquier dirección y orden que él decida.
- Además, dado que Karel sólo existe _parcialmente_ en este universo, él puede atravesar paredes.

Karel necesita tu ayuda para saber si podrá llegar al _portal_ y para saber el número mínimo de _pasos_ que tiene que dar para lograrlo.

El mundo de Karel es un rectángulo con paredes intermedias arbitrarias y representa el universo al que Karel fue teletransportado. El _portal_ se representa como un montón de 2 zumbadores. Se te asegura que hay un camino sin paredes intermedias que permite llegar de la posición inicial de Karel al _portal_. En la posición inicial de Karel habrá un montón de zumbadores que representa el número $K$.

# Problema

Escribe un programa que dado $K$ y el mapa del universo actual determine si Karel puede llegar al _portal_ y la cantidad mínima de _pasos_ en la que puede hacerlo.

- Tu programa deberá dejar a Karel orientado al **NORTE si es posible llegar al _portal_**.
- Tu programa deberá dejar a Karel orientado al **SUR si NO esposible llegar al _portal_**.
- Tu programa deberá dejar en la posición del _portal_ un montón de zumbadores indicando el número mínimo de _pasos_ que se tienen que dar para llegar al portal en caso de que sea posible hacerlo.

**En este problema el 50% de los puntos se obtienen por determinar si es posible llegar al portal y el otro 50% por determinar la cantidad mínima de pasos para hacerlo.**

# Ejemplos

## Entrada

![Mundo de entrada](karelverso.in.png)

## Salida

![Mundo de salida](karelverso.out.png)

## Descripción

- En el primer _paso_, Karel se mueve tres veces al este.
- En el segundo _paso_, Karel se mueve dos veces al este y una vez al norte.
- En el tercer _paso_, Karel se mueve dos veces al norte y una vez al sur.

Observa que esta no es la única forma de llegar en 3 pasos, existen múltiples formas de hacerlo que varían tanto en el orden como en los _pasos_ dados.

# Consideraciones

- Karel inicia en alguna posición del mundo con orientación desconocida.
- Karel lleva infinitos zumbadores en la mochila.
- En la posición inicial de Karel hay un montón de zumbadores que representa el número $K$.
- Existe un único zumbador en el mundo que representa el _portal_, además, existe un camino sin paredes que permite llegar de la posición inicial de Karel al _portal_.
- **En este problema el puntaje se divide en dos secciones:**
  - **Si tu programa determina correctamente si es posible o no llegar al _portal_, obtendrá 50% de los puntos. Tu programa debe reportar esto usando la orientación final de Karel.**
  - **Si tu programa determina correctamente el número mínimo de pasos para llegar al _portal_ y deja ese número como un montón de zumbadores en la posición del _portal_, obtendrás el otro 50% de los puntos.**

# Subtareas

En este problema, los casos de cada subtarea se encuentran agrupados. Para obtener el puntaje de una subtarea deberás resolver correctamente todos los casos del grupo.

- (10 puntos): $K$ es un número impar.
- (15 puntos): El mundo es un rectángulo de altura $1$ o de base $1$.
- (10 puntos): El mundo es un rectángulo de altura $2$ o de base $2$ sin paredes internas.
- (10 puntos): El mundo será un rectángulo sin paredes internas.
- (10 puntos): El _portal_ siempre está en la misma columna que la posición inicial de Karel al norte de Karel.
- (10 puntos): El _portal_ siempre estará en el cuadrante superior derecho de donde inicia karel.
- (15 puntos): El _portal_ siempre estará al norte de Karel pero puede estar en distinta columna.
- (20 puntos): Sin consideraciones adicionales.
