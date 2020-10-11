El gobernador de Karelópolis quiere que le ayudes a diseñar una ciudad con las siguientes reglas:

- Que esté formada por bloques rectangulares.
- Que cada rectángulo esté relleno con montones de un zumbador.
- Cada bloque debe estar separado por al menos una casilla sin zumbadores (también en diagonal).
- Mientras más bloques, mejor.
- Mientras más tamaños distintos de bloques, mejor.

# Problema

Ayuda a Karel a diseñar ciudades que cumplan las reglas del gobernador en mundos de distintos tamaños.

Cualquier diseño que cumpla las reglas es válido, pero para obtener 100 puntos debes construir rectángulos de tamaños diferentes intentando cubrir la mayor parte posible del mundo. Puedes repetir tamaños pero se te penaliza el puntaje.

# Ejemplo

Estas son dos salidas posibles para el mismo mundo de entrada. No necesariamente son las mejores.

## Entrada

![Ejemplo de Entrada](sample.in.png)

## Salida 1

![Ejemplo de Salida1](salida1.in.png)

En este ejemplo Karel dibujó 7 rectángulos de 7 distintos tamaños:

- Uno de $3 \times 5$
- Uno de $4 \times 3$
- Uno de $1 \times 2$
- Uno de $2 \times 3$
- Uno de $1 \times 3$
- Uno de $4 \times 2$
- Uno de $3 \times 7$

## Salida 2

![Ejemplo de Salida2](salida2.in.png)

En este ejemplo Karel dibujó 3 rectángulos de 2 distintos tamaños:

- Dos de $4 \times 4$
- Uno de $5 \times 10$

Al ser menos rectángulos y porque hay tamaños repetidos, esta es una respuesta que obtendrá menos puntos que el ejemplo anterior.

## Salidas inválidas

Estos dos ejemplos son salidas inválidas, ya que los rectángulos no están separados por al menos una casilla en blanco.

![Ejemplo de salida inválida 1](invalid1.in.png)
![Ejemplo de salida inválida 2](invalid2.in.png)

# Consideraciones

- Karel empieza en la casilla (1,1) viendo al norte.
- Karel tiene infinitos zumbadores en la mochila.
- No hay paredes internas en el mundo de Karel.
- El mundo siempre será cuadrado de longitud entre $10$ y $100$.
- Lo único que cambia en cada caso de evaluación es el tamaño del mundo.
- No importa la posición ni orientación final de Karel.

# Evaluación

- Cada rectángulo debe estar relleno de montones de $1$ zumbador.
- Los rectángulos deben tener al menos una casilla de separación entre ellos (incluso en diagonal).
- Si no cumples las consideraciones anteriores tendrás 0 puntos.
- Un rectángulo de tamaño $A \times B$ se considera diferente de un rectángulo de tamaño $B \times A$.
- Un cuadrado es un rectángulo
- Tu mundo se evalúa usando la siguiente fórmula:
  $$(\text{número de zumbadores totales} - (\text{número de rectángulos de tamaño repetido} / 2)) \times (\text{número de tamaños distintos})$$
  Obtendrás más puntos por tu solución entre más alto sea el valor de esa fórmula.
- Esta fórmula implica que las soluciones con más rectángulos de tamaño distinto y de áreas más grandes sacan más puntos.

Cuando corres el caso de ejemplo **usando el link a Karel.js hasta arriba de la página** se muestra un mensaje con el resultado de la fórmula.

![Resultado validador](validator.png)

Ya que cargaste el caso de ejemplo, puedes cambiar el ancho y alto del mundo en la parte de arriba para probar con mundos de diferentes tamaños y saber el valor de la fórmula.

![Resultado validador](dimensions.png)
