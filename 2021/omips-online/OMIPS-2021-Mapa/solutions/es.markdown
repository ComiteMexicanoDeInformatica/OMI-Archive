Este es un problema ideal para aprender [recursión](https://omegaup.com/course/introduccion_a_algoritmos/assignment/algoritmos_recursivos_lectura/#problems).

El problema se trata de convertir instrucciones definidas por montones de zumbadores por instrucciones avanza o gira.

Por ejemplo, si vemos el caso:

```
3 4
1 4
```

Karel debe avanzar 4 casillas al norte y 4 casillas al sur.

Podemos replantear que para girar a una orientación siempre empezamos viendo al este y después giramos el número de zumbadores. Podemos decir que para llegar la solución se necesitan las siguentes instrucciones:

- Girar al este
- Girar 1 vez a la izquierda
- Avanzar 4 veces
- Girar al este
- Girar 3 veces a la izquierda
- Avanzar 4 veces

Ahora solo necesitamos una forma de recoger los zumbadores y convertirlos en las instrucciones necesarias.

La recursión es cuando una función se manda a llamar a si misma.
Podemos construir una función que recoja zumbadores de manera recursiva:

```
define-nueva-instruccion recoger como inicio
    si junto-a-zumbador entonces inicio
        coge-zumbador;
        recoger;
    fin;
fin;
```

Cada que una función manda a llamar a otra función se lleva un registro de todas las funciones que se han llamado en una pila. En Karel puedes ver la pila de ejecución en la pantalla.

Al recoger el cuarto zumbador la pila se ve así:

![Pila Karel](pila.png)

Podemos ver que hay 4 funciones encoladas. Cuando termine cada una va a regresar la ejecución a la última función que la mandó llamar.

Podemos aprovechar esto para agregar instrucciones al regresar de la recursión. Analiza la siguiente función:

```
define-nueva-instruccion recoger-y-avanzar como inicio
    si junto-a-zumbador entonces inicio
        coge-zumbador;
        recoger-y-avanzar;
        avanza;
    fin;
fin;
```

La función va a recoger todos los zumbadores y después va a avanzar el mismo número de casillas. Tienes que entender muy bien este concepto para poder construir soluciones más complejas a partir de esta idea. Te recomendamos que copies la función en Karel.js y la ejecutes paso a paso hasta que no tengas dudas de su funcionamiento.

Una cosa muy importante a la hora de hacer funciones recursivas es que tienes que tener muy claro en qué momento vas a dejar de llamar a la función. Si no, te puedes quedar ciclado para siempre.

En este caso nuestra condición para seguir llamando a la función es que estemos junto a un zumbador, pero esto depende de cada problema.

Con todas estas ideas podemos armar 2 funciones: una que recoja y avance, y otra que recoja y gire. Después podemos hacer que una llame a la otra hasta tener todas las instrucciones en la pila.

La única observación final que hay que hacer es que las instrucciones se ejecutan en el orden contrario en las que se metieron, por lo que debemos empezar a recoger los zumbadores desde arriba, para que se ejecuten en el orden que queremos.

<details><summary>El siguiente código es la solución oficial:</summary>

{{100B.kp}}

</details>

Alternativa no recursiva:

Otra manera de resolver el problema sin recursión es sumar todas las instrucciones de la misma dirección, y después restar las instrucciones sur y oeste a las instrucciones norte y este, respectivamente. Esto nos dejaría las dos coordenadas a las que nos debemos de mover.
