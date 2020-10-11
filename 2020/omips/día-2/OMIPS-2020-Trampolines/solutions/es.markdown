# Trampolines - Solución

Se puede partir esta solución en 2 pasos:

1. Recorrer cada columna del mundo para contar cuántos saltos se necesitan en esa columna para llegar al techo y dejar ese número en la fila 1 de esa columna.
2. Comparar todos los resultados que dejamos en la fila 1 y llevar el menor a la casilla $(1,1)$.

Para saber cuántos saltos se necesitan en cada columna:

- Lo primero es avanzar una casilla y revisar si ahí hay zumbadores, si no hay quiere decir que en esa columna no hay trampolines.
- En caso de que sí haya zumbadores, vas a intentar avanzar ese número de casillas (puede que en menos pasos ya hayas llegado al techo). Si después de avanzar llegas a una casilla que no está junto al techo y hay zumbadores, ya estás en el trampolín y repites este paso. Si llegas a una casilla que no está junto al techo y no hay zumbadores, debes regresar en esa columna para ver si hay algún otro trampolín que puedas usar y cuando lo encuentres, repetir este paso.

Si al "caer" el número de casillas que subiste en tu último salto, no encuentras ningún trampolín, quiere decir que en esa columna no podrás llegar al techo.

Si esto sucede, dejamos el número de saltos que teníamos guardados en la casilla más alta de la columna.

Cuando ya hicimos esto para cada columna, llevamos a Karel a la fila 1 para que busque el montón más pequeño de la fila y poner esa misma cantidad de zumbadores en la casilla $(1,1)$.
