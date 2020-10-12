# Primo - Solución

En este problema se nos pide que encontremos el número primo que falta de una lista ordenada de números primos.

Para saber cuál es el número primo que falta primero necesitamos calcular todos los números primos menores a $n$.
Podemos armar la lista en tiempo $O(n)$ usando la [criba de Erastótenes](https://es.wikipedia.org/wiki/Criba_de_Erat%C3%B3stenes).

![Criba](criba.gif)

Para encontrar el número que falta, solo debemos comparar el resultado de `primo(posicion)` con nuestra lista en la misma posición. Si el resultado es igual significa que el número perdido está adelante; si no significa que está atrás.

Para minimizar el número de llamadas podemos hacer una [búsqueda binaria](https://es.wikipedia.org/wiki/B%C3%BAsqueda_binaria). Esto nos asegura que siempre podemos encontrar el número perdido en a lo más $\log_{2} n$ llamadas.

<details><summary>Solución para la Subtarea 2 (100 puntos)</summary>

{{solution.cpp}}

</details>

[Aquí puedes encontrar un video explicando la solución.](https://www.youtube.com/watch?v=y2zK_tt8VSY)
