Al gobernador de Karelópolis nuevamente se le ha zafado un tornillo y ahora tiene una gran obsesión por los rectángulos. Esta obsesión lo llevó a pedirle a Karel construir una ciudad rectangular. Lamentablemente, Karel ahora mismo trabaja de constructor y no de arquitecto, por lo que te ha pedido ayuda a ti para diseñar los planos de la ciudad y cumplir con las exigencias del gobernador.

La ciudad consiste en una cuadrícula de $H$ filas (numeradas de $1$ a $H$) y $W$ columnas (numeradas de $1$ a $W$), en la cual se construirán los diferentes bloques que conformarán la ciudad.

A pesar de la obsesión del gobernador, aún se preocupa por los ciudadanos de Karelópolis y el diseño de la ciudad. Para él, un buen diseño es **tener una gran variedad de rectángulos**, así que ha puesto ciertas reglas para el diseño de la ciudad:

- Que esté formada por bloques rectangulares.
- Los rectángulos no deben intersecarse entre sí.
- No se debe construir fuera de los límites de la ciudad.
- Cada rectángulo debe estar separado por al menos una casilla de los otros rectángulos en todas las direcciones (también en diagonal).
- Mientras más rectángulos, mejor.
- Mientras más tamaños distintos de rectángulos, mejor.
- Las esquinas de los rectángulos deben estar en posiciones enteras de la cuadrícula.

Cualquier diseño que cumpla estás reglas es válido, pero para obtener 100 puntos debes maximizar la cantidad de rectángulos y minimizar la cantidad de rectángulos con tamaño repetido.

# Problema

Dadas las medidas, $H$ y $W$, debes diseñar una ciudad que cumpla las reglas que ha puesto el gobernador.

Este es un problema de solo salida, por lo que no necesariamente tienes que enviar tu código, sino que también puedes enviar un zip con tus salidas.

## Entrada

Una línea con dos enteros, $H$ y $W$, que representan las dimensiones de la ciudad.

## Salida

En la primera línea un entero, $R$: la cantidad de rectángulos en el diseño.

En cada una de las siguientes $R$ líneas, 4 enteros separados por un espacio: $h_1, w_1, h_2, w_2$. $(h_1, w_1)$ representan la fila y columna de la esquina inferior izquierda del rectángulo, y $(h_2, w_2)$ representan la fila y columna de la esquina superior derecha del rectángulo.

Además, se debe de cumplir que $1 \le h_1 \le h_2 \le H$ y $1 \le w_1 \le w_2 \le W$.

No importa el orden en el que se impriman los rectángulos, siempre y cuando se cumplan todas las restricciones.

# Límites

- $ 5 \leq H,W \leq 2500$

# Evaluación

- Si no cumples con las reglas del gobernador, obtendrás 0 puntos.
- Un rectángulo de tamaño $A \times B$ se considera diferente de un rectángulo de tamaño $B \times A$.
- Un cuadrado es un rectángulo.
- Tu mundo se evalúa usando la siguiente fórmula:
  $$(\text{área total de los rectángulos} - \text{número de rectángulos de tamaño repetido}) \times (\text{número de tamaños distintos})$$
  Obtendrás más puntos por tu solución entre más alto sea el valor de esa fórmula.
- Esta fórmula implica que las soluciones con más rectángulos de tamaño distinto y de áreas más grandes sacan más puntos.

# Ejemplos

Si tuviéramos un caso con $H = 5$ y $W = 7$, algunos diseños posibles serían:

## Diseño 1

![Ejemplo 1](ejemplo1.png)

En este caso, Karel construyó 3 rectángulos. Lo que tu programa debería de imprimir para esta construcción es:

```
3
2 2 2 2
4 1 5 3
2 5 4 6
```

Al evaluar la fórmula obtendríamos $(13 - 0) * 3 = 39$. Recuerda que el rectángulo de 2x3 se considera diferente al rectángulo de 3x2.

## Diseño 2

![Ejemplo 2](ejemplo2.png)

En este caso, Karel construyó un único rectángulo. Lo que tu programa debería de imprimir para esta construcción es:

```
1
1 5 5 7
```

Al evaluar la fórmula obtendríamos $(15 - 0) * 1 = 15$. En este caso, el diseño 1 obtendría más puntos que el diseño 2, pues el valor de la fórmula es mayor.

## Diseños Inválidos

![Invalido 1](invalido1.png)

Cada rectángulo debe estar separado por al menos una casilla de los otros rectángulos en todas las direcciones. Al no estar separados, este diseño se considera inválido.

![Invalido 2](invalido2.png)

Los rectángulos deben de estar separados también en diagonal, por lo que este diseño también es inválido.

Ambos casos recibirían 0 puntos.

# Experimentación

Este problema es mixto: puedes enviar tu código normalmente, o subir las salidas como un problema de solo salida.

Si quieres subir solo las salidas, debes crear un zip que contenga los archivos de salida. Los archivos de salida deben ser un `.out` que tenga el mismo nombre que el archivo de entrada `.in` al que corresponde la salida.

En caso de que envíes tu código, será evaluado con estos mismos casos de prueba.

Puedes descargar los casos de prueba de este problema aquí:

{{output-only:download}}
