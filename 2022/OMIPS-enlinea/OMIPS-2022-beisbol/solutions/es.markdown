# Solución oficial para Karel y el Béisbol (OMIPS 2022)

El problema requiere encontrar el cruce de las diagonales de un cuadrado. El cuadrado en cuestión puede estar colocado con sus lados paralelos a las paredes del mundo de Karel, en _forma de cuadrado_, o inclinado 45 grados con respecto a las paredes del mundo, en _forma de rombo_.

Dos posibles acercamientos para resolver el problema son:

- Trazar las diagonales mediante una línea de zumbadores y apagar a Karel en la posición que tenga dos zumbadores (el cruce).
- Medir la longitud de una de las diagonales (ambas son iguales) y apagar a Karel a la mitad de la distancia.

En cualquiera de los dos acercamientos, es necesario poder avanzar por las diagonales. Observa que la orientación de las diagonales depende de la orientación del campo. Hay dos posibilidades:

- **Campo en _forma de cuadrado_**: Las diagonales están inclinadas. Imagina una letra X.
- **Campo en _forma de rombo_**: Las diagonales están vertical y horizontal. Imagina una cruz.

Es posible determinar la orientación del campo con el siguiente algoritmo:

- Recorriendo de oeste a este, encuentra la base más al sur del campo.
- Verifica si existe una segunda base hacia el este sobre esa fila.
  - Si hay otra base en esa fila, significa que el campo está en _forma de cuadrado_.
  - Si **NO** hay otra base en esa fila, significa que el campo está en _forma de rombo_.

Uniendo las dos observaciones anteriores podemos llegar al siguiente algoritmo para resolver el problema:

- 1. Encuentra el campo.
- 2. Determina si está en _forma de cuadradro_ o en _forma de rombo_.
- 3. Encuentra el cruce de ambas diagonales.
- 4. Apágate.

A continuación se muestran posibles ideas para resolver cada una de las subtareas.

<details><summary>Subtarea 1 (30 puntos): Forma de cuadrado, el campo está en la fila 1.
Esta solución asume que la base está en la fila 1 y que el campo está en forma de cuadrado.  Al encontrar la primera base al este, traza la diagonal, baja al sur y traza la segunda diagonal, cuando llega al cruce se apaga.
</summary>

{{sol_sub1.kp}}

</details>

<details><summary>Subtarea 2 (10 puntos): Forma de cuadrado, el campo está en cualquier lugar.
Esta solución es muy similar a la subtarea 1, simplemente busca la primera base en todas las filas.

Este código resuelve las subtareas 1 y 2.

</summary>

{{sol_sub1_y_2.kp}}

</details>

<details><summary>Subtarea 3 (30 puntos): Forma de rombo, el campo está la fila 1.
Esta solución busca la base en la fila 1 y de ahí comienza a subir, buscando fila por fila dónde encuentra una base, la fila en la que encuentre una base será la fila en dónde cruzan las diagonales.
</summary>

{{sol_sub3.kp}}

</details>

<details><summary>Subtarea 4 (15 puntos): Forma de rombo, el campo está en cualquier fila.
Esta solución es muy similar a la subtarea 3, simplemente busca la primera base en todas las filas.

Este código resuelve las subtareas 3 y 4.

</summary>

{{sol_sub3_y_4.kp}}

</details>

<details><summary>Subtarea 5 (15 puntos): Cualquier forma, cualquier lugar y además Karel no tiene zumbadores para marcar la diagonal.
En esta solución se utiliza el algoritmo descrito arriba. Se busca la primera base, se identifica la forma del campo y se mide la distancia de la diagonal contando recursivamente para luego regresar la mitad de los pasos que se avanzó.
</summary>

{{solutionC.kp}}

</details>
