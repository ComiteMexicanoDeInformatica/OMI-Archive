# Bits - Solución

## Subtarea 1 $(N \le 5)$

Para resolver esta subtarea es posible iterar sobre todos los pares posibles de números y contar cuántos pares de números fallan la estrategia. Como $N \le 5$, solo existen 31 números posibles y 961 pares.
Sin embargo, es necesario saber cuántos bits encendidos tiene cada uno de los números para solo considerar pares válidos, con $A$ bits y $B$ bits. Al tener limites tan pequeños, es posible precalcular esto a mano, o hacerlo en código. Existen varias maneras para hacer esto, como usar operaciones de bits, checar la paridad del bit mas pequeño e ir dividendo el número, o incluso usar funciones preexistentes como `__builtin_popcount`.
La complejidad será $O(2^N*2^N)$ con algunas constantes, dependiendo de cómo se obtenga la cantidad de bits de cada número.

## Subtarea 2 $(N \le 16)$

Para resolver esta subtarea, todavía es posible generar todos los $2^N$ números. Sin embargo, comparar todos los pares ya no es suficiente para obtener los puntos, pues esto dará TLE. Para mejorar esta solución, es importante la siguiente observación:
Si tenemos un número $num$ con $A$ bits encendidos, y $A > B$, todos los números mayores a $num$ que tengan exactamente $B$ bits encendidos serán los que causaran el error. De una manera similar, si tenemos un número $num$ con $A$ bits encendidos, y $A < B$, todos los números menores a $num$ con exactamente $B$ bits encendidos causaran un error. Para resolver estos dos casos, se puede generar un arreglo de prefijos $pref[i]$ que represente cuántos números desde 1 hasta $i$ tienen exactamente $B$ bits encendidos, y un arreglo de sufijos $suf[i]$ que represente cuántos números desde $i$ hasta $N$ tienen exactamente $B$ bits encendidos. Ahora, se recorre la lista, y cuando se encuentra un número con exactamente $A$ bits encendidos, podemos agregar a la respuesta $pref[i - 1]$ si $A < B$ o $suf[i + 1]$ si $A > B$. El caso $A = B$, necesitamos sumar $pref[i - 1]$ y $suf[i + 1]$, pues ambos lados causaran un error, pues el único número que no es diferente es $i$. Esto tiene una complejidad de \$O(2^N\*N) con algunas constantes, dependiendo de cómo se obtenga la cantidad de bits de cada número.

Otras posible solución es crear dos arreglos, uno con todos los números con $A$ bits, y otro con todos los números con $B$ bits, y usar búsqueda binaria o dos punteros para obtener lo equivalente a los cálculos que teníamos en prefijos / sufijos.

## Subtarea 4 $(N \le 200)$

En esta subtarea ya no es posible generar los números como un entero, pues exceden los límites incluso de un long long. Esto quiere decir que la solución involucra ver los números en su representación binaria y buscar alguna propiedad que nos ayude.

La primera propiedad importante es que si dos números son iguales, su representación binaria será la misma.
La propiedad clave es: En caso de que dos números sean diferentes, el primer bit que difiere (de más significativo a menos significativo) es el que determina cuál numero es mayor. Al menos un bit tiene que ser diferente, pues si todos son iguales, son el mismo número.

Prueba: Asumamos que el bit más significativo que difiere es $i$. Todos los bits $> i$ son iguales, pues si alguno más significativo difiere, $i$ no sería el bit más significativo diferente. Como sabemos que $i$ difiere, $num1$ tiene el bit encendido, y $num2$ tiene el bit apagado. Aún si todos los siguientes bits son encendidos en $num2$ y nada se enciende en $num1$ (que es el peor caso), $num1$ seguirá siendo mayor, pues $2^i > 2^{i - 1} + 2^{i - 2} + ... + 2^0$.

Sabiendo esto, se puede ir construyendo la respuesta bit por bit, de más significativo a menos significativo, siempre manteniendo información de en que bit vamos, cuantos bits están prendidos en $num1$, cuántos en $num2$. En cada bit tenemos 4 opciones , $(0,0)$ , $(0,1)$, $(1,0)$ o $1,1$. Simular esto toma $4^N$, o equivalentemente $2^N*2^N$, la misma complejidad que la subtarea 1. Sin embargo, se puede ver ver que el problema cada vez se hace más pequeño (de tener $i$ bits a $i-1$ cada vez que determinamos uno). Además, muchos de estos subproblemas coinciden. Es decir, es posible reusar información y ahorrar operaciones.

Sabiendo esto, se puede el problema con programación dinámica. Se define $dp[i][a][b]$ como el número de errores que existen en todos los números con $i$ bits, en dónde $num1$ tiene $a$ bits encendidos, $num2$ tiene $b$ bits encendidos.

La respuesta estará en $dp[N][A][B]$. En cada caso podemos prender ambos o no prender ninguno. Si en algún momento difiere, podemos usar n sobre k para calcular cuántas maneras fallarán a partir de ahí. Es importante siempre ir a estados válidos.

Las transiciones son las siguientes:

$dp[i][a][b]$ = Suma de:

Encender solo en $num1$: $dp[i - 1][a - 1][b]$

Encender solo en $num2$: $dp[i - 1][a][b - 1]$

Encender en ambos: $dp[i - 1][a - 1][b - 1]$

No encender en ninguno: $dp[i - 1][a][b]$

Esta dp tiene $N^3$ estados y 4 transiciones por lo que la complejidad final es $O(N^3)$, lo cual es suficiente para obtener los puntos de esta subtarea.

## Subtarea 4 \$(N \le 5000)

La solución con programación dinámica no es suficiente para obtener los puntos de esta subtarea. Sin embargo, la observación que hicimos en la subtarea anterior es vital para llegar a la solución completa. Sabemos que la diferencia esta determinada únicamente por un bit, por lo que podemos fijar este bit, y calcular cuántas posibilidades fallan con este bit como el primer bit que marca la diferencia. Si fijamos $i$ como el primer bit que difiere, sabemos que todos los bits anteriores son iguales, por lo que podemos fijar cuántos bits encendidos habrá antes, y con combinatoria calcular cuántas posibilidades de fallo existen. Si tenemos $N$ posibles puntos de diferencia, y para cada uno $N$ opciones para bits encendidos antes, tenemos un total de $N^2$ posibilidades, pues los bits de después están determinados por los que ya use. Precalculando factoriales e inversos factoriales debido al módulo, y usando combinatoria, se puede llegar a la solución con una complejidad de $O(N^2)$
