# Descripción

Antes de desaparecer a la mitad de la población, Thanos practicó su chasquido en muchos simuladores, unos más inusuales que otros. Thanos probó uno cuyo fin es reducir cualquier número entero a un número de un único dígito. El simulador funciona de la siguiente manera:

Dado el número $x$, cada que Thanos chasquea los dedos, $x$ se reduce al número que se obtiene al multiplicar todos sus dígitos entre sí. Se le llama _resistencia_ de $x$ al número de veces que Thanos debe chasquear los dedos para reducir $x$ a un número de un solo dígito. Por ejemplo, el número $333$ tiene resistencia $3$:

 Chasquido 1. $333$: $3 \times 3 \times 3 = 27$

 Chasquido 2. $27$: $2 \times 7 = 14$

 Chasquido 3. $14$: $1 \times 4 = 4$ (Después del tercer chasquido se llega a un número de 1 digito)

# Problema

Ayuda a Thanos a encontrar el número con mayor resistencia. En caso de encontrar más de un número con la misma resistencia, debes elegir el menor.

# Evaluación

Este problema es de _sólo salida_, no es necesario que envíes código. Debes enviar sólo un número, el número que tenga la resistencia más grande que puedas encontrar.

Entre más grande sea la resistencia del número que envíes, más puntos obtendrás. En caso de que encuentres varios números con la misma resistencia, el menor de ellos te dará más puntos.

# Límites

* El numero $X$ debe tener a lo más $1000$ dígitos.
