# Solución oficial para Karel y las monedas del Abuelo (OMIPS 2022)

## Observación principal

Para cumplir los requisitos del Abuelo, se requiere que si tomas una cantidad par de monedas desde cualquiera de los extremos de la fila, la cantidad de _águilas_ y _soles_ sea la misma.

Analiza primero uno de los casos, digamos el extremo izquierdo. Supón que la condición del Abuelo se cumple hasta una cierta posición, llamemos a esta posición $L$. Es decir, si partiendo del extremo izquierdo tomas las primeras $2$ monedas o las primeras $4$, $6$, $8$, ... hasta las primeras $L$, en todos los casos el número de _águilas_ es igual al número de _soles_.

¿Qué pasa con el siguiente par? Hay 3 opciones posibles:

- Que haya $2$ _águilas_: En este caso será necesario voltear una de las dos monedas.
- Que haya $2$ _soles_: En este caso igualmente será necesario voltear una de las dos monedas.
- Que haya $1$ _águila_ y $1$ _sol_: En este caso no es necesario hacer ningún cambio.

Observa que no es necesario fijarse en las monedas previas, ya que todos los pares anteriores cumplen. Basta fijarse en el último par. Y al dejar ese par listo, no será necesario volver a fijarse en él.

Finalmente observa que como el número total de monedas es par, puedes empezar por el extremo que quieras izquierdo o derecho y las parejas nunca se van a traslapar.

Por lo tanto, para resolver el problema basta con ir dejando acomodado de par en par y para cada par de monedas, se requiere a lo más $1$ cambio.

A continuación se muestran posibles ideas para resolver cada una de las subtareas.

<details><summary>Subtarea 1 (10 puntos): Dejar una fila que cumpla con los requerimientos del abuelo.
Para obtener estos 10 puntos basta con dejar una fila ${1, 2, 1, 2, ...}$
</summary>

{{sol_sub_10pts.kp}}

</details>

<details><summary>Subtarea 2 (50 puntos): Hacer el mínimo número de cambios, pero sin llevar la cuenta.
Para obtener 50 puntos es necesario ir revisando cada par de monedas y cambiando una de ellas en el caso en que sean $2$ _águilas_ o $2$ _soles_
</summary>

{{sol_sub_50pts.kp}}

</details>

<details><summary>Subtarea 3 (100 puntos): Minimizar los cambios y contar cuántos fueron.
Para obtener 100 puntos requieres ir revisando cada par de monedas, haciendo cambio si es necesario y contando (recursivamente o mediante alguna marca) los lugares en que cambiaste monedas.
</summary>

{{solution.kp}}

</details>
