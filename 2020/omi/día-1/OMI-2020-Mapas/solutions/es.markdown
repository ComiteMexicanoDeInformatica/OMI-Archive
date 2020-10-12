# Mapas - Solución

## Subtarea 1

Esta subtarea no necesita ninguna observación, consiste solo de implementación. Cómo se asegura que no ocurrió ninguna transformación en el mapa, solo se tiene que checar que los dos mapas sean exactamente iguales.

<details><summary>Solución para la Subtarea 1 (25 puntos)</summary>

{{25.cpp}}

</details>

## Subtarea 2

En esta subtarea, una observación similar es importante. Hacer dos inversiones verticales lleva a la misma matriz del inicio. Lo mismo ocurre con las inversiones horizontales. Sabiendo esto, se puede ver que solo existen 4 configuraciones: Sin inversiones, invertido verticalmente, invertido horizontalmente o invertido verticalmente y horizontalmente.
Con esta observación, se pueden implementar funciones para invertir la matriz horizontalmente o verticalmente, probar las 4 configuraciones posibles, y comprobar si alguna coincide con el mapa original.

<details><summary>Solución para la Subtarea 2 (50 puntos)</summary>

{{50Inv.cpp}}

</details>

## Subtarea 3

Para solucionar esta subtarea, es importante darse cuenta que solo existen 4 posibles configuraciones para el mapa. Estas son: rotar 0º grados, rotar 90º grados, rotar 180º grados o rotar 270º grados. Si en algún momento el mapa se rota más de 270º, se llega a una configuración repetida, pues cada 360º el mapa regresa a su estado original.  
Sabiendo esto, solo se tiene que implementar una función que gire la matriz. Teniendo esto, se pueden probar las 4 configuraciones posibles, y comparar cada una con el mapa original. Si alguna coincide con el mapa, son iguales. Si se prueban las 4 y ninguna coincide, son diferentes, pues se asegura que solo ocurrieron rotaciones.

<details><summary>Solución para la Subtarea 3 (50 puntos)</summary>

{{50Giro.cpp}}

</details>

## Subtarea 4

Con las observaciones de las Subtasks 2 y 3, se puede llegar a la observación siguiente. Si sólo existen 4 configuraciones de giro, y 4 configuraciones de inversiones, se pueden probar todas estas configuraciones entre sí, lo cual representa un total de 16 configuraciones posibles. Teniendo las funciones para girar y invertir, se comprueba cada configuración y se compara con el mapa original, checando si alguna. Esto es suficiente para todos los puntos, aunque una pequeña optimización es posible, pues de estas 16 configuraciones, varias llevan al mismo resultado. En total solo existen 8 configuraciones diferentes, dado que existen movimientos equivalentes, como rotar 90 grados, o rotar 270 grados e invertir vertical y horizontalmente.

<details><summary>Solución para la Subtarea 4 (100 puntos)</summary>

{{solution.cpp}}

</details>

[Aquí puedes encontrar un video explicando la solución.](https://www.youtube.com/watch?v=YxSLPX1zKX4)
