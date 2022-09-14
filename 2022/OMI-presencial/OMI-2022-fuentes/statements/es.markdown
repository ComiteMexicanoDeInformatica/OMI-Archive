Un amigo tuyo diseña jardines con fuentes de agua y te ha pedido ayuda.

Un jardín se representa como una cuadrícula de $N$ filas por $M$ columnas en donde cada cuadro puede estar ocupado o libre. Tu amigo quiere **llenar de agua todos los cuadros libres del jardín**, para eso el va a colocar _fuentes de agua_ en **algunos de los cuadros libres**. Una vez que coloque y encienda las _fuentes_ pasará lo siguiente:

- Cada segundo, si hay un cuadro libre tal que dos de sus $4$ cuadros _adyacentes ortogonalmete_ (ver glosario) tengan agua, este cuadro se llenará de agua también. Dos cuadros se consideran _adyacentes ortogonalmente_ si comparten una _pared_ en la cuadrícula.

Tu amigo quiere saber dónde poner fuentes de modo que eventualmente todas las casillas libres se llenen de agua y se utilice el menor número de fuentes posible.

**Este es un problema de sólo salida.**  Esto quiere decir que podrás descargar los archivos de evaluación y deberás mandar un ".zip" con los archivos de salida correspondientes a cada uno de ellos.

# Problema

A partir de los mapas de los jardines que tu amigo está diseñando, devuelve como resultado el mismo mapa indicando las posiciones dónde se deben colocar las fuentes.

# Entrada

Este es un programa de **sólo salida**, esto quiere decir que tu puedes descargar los mapas de los jardines, procesarlos en tu máquina de la forma que desees y deberás devolver los mapas indicando los lugares con fuentes. El archivo del mapa del jardín tiene la siguiente estructura:

- En la primera línea, los números $N$ y $M$, el número de filas y de columnas del jardín respectivamente.
- En las siguientes $N$ líneas habrá una cadena con $M$ caracteres representando el mapa. Un carácter '.' representa un cuadro vacío y un carácter '#' representa un cuadro ocupado.
- **El contorno del jardín siempre está formado por cuadros ocupados.**

# Salida

Para cada mapa de entrada deberás enviar un mapa con fuentes colocadas con la siguiente estructura:

- En la primera línea los números $N$ y $M$, el número de filas y de columnas del jardín respectivamente.
- En las siguientes $N$ líneas debe haber una cadena con $M$ caracteres representando el mapa. Un carácter '.' representa un cuadro vacío, un caracter '#' representa un cuadro ocupado y un carácter 'F' representa una fuente.

# Evaluación

Obtendrás $0$ puntos en un caso si:
- Tu mapa de respuesta no cumple la estructura especificada o usa caractéres inválidos.
- Tu mapa de respuesta es de distinto tamaño del mapa de entrada.
- Tu mapa de respuesta puso fuentes en cuadros que originalmente estaban ocupados.
- Tu mapa de respuesta marca como ocupados cuadros que originalmente estaban libres o viceversa.

Para asignarle puntos a tu mapa, el evaluador realizará el siguiente proceso:
- Simulará el _encendido_ de las fuentes hasta llenar todos los cuadros posibles con tu configuración de respuesta.
- Contará el número de cuadros libres que **quedaron sin llenar** y asignará ese número a la variable $L$.
- Contará el número de fuentes que se usaron y asignará ese número a la variable $F$.
- El puntaje que obtenga tu mapa será mayor mientras el valor $F + (2 \times L)$ sea menor.  Es decir, mientras menos fuentes uses y menos cuadros sin llenar dejes obtendrás mejor puntaje.

# Ejemplo

||input
7 7
#######
#..#..#
#..#..#
####..#
#.....#
#.....#
#######
||output
#######
#F.#F.#
#.F#.F#
####F.#
#.F.F.#
#F.F.F#
#######
||description
El mapa de salida coloca 10 fuentes (para este mapa existen soluciones con menos fuentes). Con esas 10 fuentes, al cabo de suficiente tiempo, todos los cuadros libres del mapa quedarán llenos de agua.
||end

# Envío de respuestas

Para subir las salidas, debes crear un zip que contenga los archivos de salida. Los archivos de salida deben tener extensión ".out" y deben tener el mismo nombre que el archivo de entrada ".in" al que corresponden.

Puedes descargar los casos de prueba de este problema aquí:

{{output-only:download}}

# Límites por caso

- Caso 1 (6 puntos): $N, M = 3$.
- Caso 2 (6 puntos): $N, M = 100$. No hay cuadros libres adyacentes en el jardín.
- Caso 3 (6 puntos): $N = 3$, $M = 1000$
- Caso 4 (6 puntos): $N, M = 999$. Los únicos cuadros ocupados son los del contorno.
- Caso 5 (6 puntos): $N = 1000$, $M = 500$. Los únicos cuadros ocupados son los del contorno.
- Caso 6 (6 puntos): $N, M = 1000$. Los cuadros libres forman _áreas_ rectangulares.
- Caso 7 (8 puntos): $N, M = 1000$. Los cuadros libres forman una _cruz_ en el centro.
- Caso 8 (8 puntos): $N, M = 1000$. Los cuadros libres forman una _X_ en el centro.
- Caso 9 (12 puntos): $N, M = 1000$. Aleatorio.
- Caso 10 (12 puntos): $N, M = 1000$. Aleatorio.
- Caso 11 (12 puntos): $N, M = 1000$. Aleatorio.
- Caso 12 (12 puntos): $N, M = 1000$. Aleatorio.