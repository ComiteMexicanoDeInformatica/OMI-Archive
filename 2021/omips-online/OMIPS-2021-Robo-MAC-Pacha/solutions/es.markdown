## Solución parcial

En este problema se nos pide quitar todas las cámaras que pueden ser vistas por otras cámaras. Las cámaras pueden ver todos los zumbadores que estén a su derecha y arriba.

Para las subtareas donde no importa el número de instrucciones `avanza` podemos marcar con un zumbador todas las casillas que pueden ser vistas por una cámara.

Para hacer esto podemos primero partir el problema en un caso más sencillo. Si solo hubiera una columna, debemos buscar el zumbador más al sur, agregarle un zumbador y después marcar todas las casillas del norte con un zumbador.

Si repetimos este proceso para todas las columnas de un mundo, quedan marcadas las cámaras más al sur con 2 zumbadores y todas las demás con 1 zumbador.

![todas las columnas marcadas](columnas.png)

El segundo paso es repetir el mismo proceso en todas las filas para que queden marcadas con 3 zumbadores todas las cámaras que no son vistas y las demás casillas con 1 o 2 zumbadores.

![todas las filas marcadas](filas.png)

El último paso es solamente volver a recorrer el mundo quitando 2 zumbadores de todas las casillas.

![Salida](../examples/sample.out.png)

## Solución completa

Para poder solucionarlo con el menor número de instrucciones `avanza`, solo podemos recorrer cada columna una vez.

La observación más importante es que una vez que encontramos un zumbador en la altura $Y$, ya no es necesario ningún zumbador con altura mayor o igual a $Y$ en las columnas subsecuentes.

Podemos crear una función `busca(altura)` que haga lo siguiente:

- Avanzar máximo `altura` veces o hasta que encuentre o un zumbador o una pared.
- Si encontró un zumbador borrar los zumbadores más al norte y regresar.
- Usar recursión para contar la nueva altura y mandar llamar recursivamente la función con la nueva altura.

Al principio de la ejecución invocamos `busca(101)` para asegurar que llegaremos hasta la pared del norte.

<details><summary>Implementación de 100 puntos:</summary>

{{100B.kp}}

</details>
