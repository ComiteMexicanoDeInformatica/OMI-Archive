Te interesa ser aceptado en la Organización de Mensajes Indescifrables (OMI). Para ser admitido, la organización te solicitó desarrollar un programa que encuentre _"frases ocultas"_.

Una _frase oculta_ es una palabra que aparece como subsecuencia de un texto. Esto significa que si eliminas algunas letras del texto, las letras que quedan forman la _frase oculta_.
Por ejemplo, en el texto **"Hoy me fui a casa"** está oculta la palabra **omi** eliminando las siguientes letras: **-o- m- --i - ----**. Observa que las letras de la frase **"omi"** no tienen que estar juntas, pero sí deben aparecer en el orden correcto. Debido a esto, la palabra **amo** no es una _frase oculta_ dentro del texto **"Hoy me fui a casa"** a pesar de que sus letras sí aparecen en la secuencia.

Para ser aceptado en la OMI debes hacer un programa que dado un texto formado por letras minúsculas y una lista de $N$ palabras, determine cuáles son _frases ocultas_.

# Problema

Escribe un programa que reciba un texto de longitud $T$ formado por letras minúsculas y una lista con $N$ palabras. Para cada palabra de la lista, tu programa deberá determinar si es una _frase oculta_ dentro de dicho texto.

# Entrada

Tu programa debe leer de la entrada estándar:

- En la primera línea, los números $T$ y $N$, el largo del texto y la cantidad de palabras respectivamente.
- En la segunda línea, un texto de longitud $T$ conformado unicamente por letras minúsculas.
- Para cada una de las últimas $N$ líneas, habrá un número $l_i$ seguido de una palabra conformada unicamente por letras minúsculas. El número $l_i$ indica la longitud de dicha palabra.

**Tanto el texto como las frases estarán formadas exclusivamente por letras minúsculas.**

# Salida

Para cada una de las $N$ líneas, deberás mostrar un $1$ si la palabra recibida es una _frase oculta_ o un $0$ en caso contrario.

# Ejemplo

||input
15 5
erqfaorfemaifmo
3 omi
4 fama
3 oro
5 plata
6 bronce
||output
1
1
1
0
0
||description
Las palabras _omi_, _fama_ y _oro_ se encuentran como _frases ocultas_ en el texto como se muestra a continuación:

- erqfa<b>O</b>rfe<b>M</b>a<b>I</b>fmo
- erq<b>FA</b>orfe<b>MA</b>ifmo
- erqfa<b>OR</b>femaifm<b>O</b>

||end

# Límites

- $1 \leq T \leq 10^6$ El largo del texto.
- $1 \leq N \leq 10^5\ -$ El número de palabras que habrá en la lista.
- La longitud sumada de todas las palabras no excede $10^6$ letras.

# Subtareas

- (5 puntos): Las palabras están formadas por letras iguales, por ejemplo **"aaaa"** o **"ccc"**.
- (15 puntos): Sólo hay una palabra en la lista y siempre será **omi**.
- (22 puntos): $N \leq 10$
- (23 puntos): $T, N \leq 1000$
- (35 puntos): Sin restricciones adicionales.
