# Problema

Spider-man se ha teletransportado al planeta Möbius. En éste planeta existe una calle que corre por todo su ecuador. Esta calle tiene $N$ casas y cada casa está identificada con un número entero.

Spider-man apareció en esta calle y se encuentra desorientado. Spider-man ha empezado a columpiarse en la calle y ha visto que los números de las casas están ordenados, es decir, siempre van creciendo o decreciendo (aunque los números de las casas no necesariamente avanzan de 1 en 1).

De alguna manera, Spider-man pudo comunicarse contigo. Tú, como buen olímpico, sabes que puedes teletransportar a Spider-man de regreso si llega a la casa identificada con el número $destino$. El problema es que Spider-man tiene una cantidad limitada de telaraña y solo podrá columpiarse un número limitado de veces.

Tu labor, será guiar a Spider-man hasta la casa identificada con el número $destino$ antes de que se le acabe la telaraña.

# Evaluación

Éste es un problema interactivo.

Debes implementar la función `encuentraCasa(long long origen, long long destino)`.
`origen` es el número que identifica la casa en la que Spider-man se encuentra en este momento y `destino` es el número que identifica la casa a la que Spider-man debe de llegar para ser teletransportado de regreso. La casa identificada con el número `destino` siempre es distinta de la casa identificada con el número `origen`.

Para guiar a Spider-man hacia su destino debes llamar a la función `long long avanza(long long casas)`, esta función le dice a Spider-man que se mueva un número de casas igual al valor de la variable `casas` en alguna dirección.  Si el parámetro `casas` es positivo, Spider-man se mueve hacia el este sobre el ecuador y si es negativo, Spider-man se mueve hacia el oeste. Como resultado recibirás el número que identifica la casa en la que terminó Spider-man tras haberse movido. 

Toma en cuenta que como la calle da la vuelta al mundo por el ecuador, si Spider-man está en la casa con el mayor número de la calle y se mueve una casa en la dirección en la que crece la numeración, pasará a la casa con el menor número de todas. De la misma forma, si esta en la casa identificada con el menor número de la calle y se mueve una casa en la dirección en la que disminuye la numeración terminará en la casa con el mayor número de todas.

Debido a que estás en la Tierra, tú no sabes si la numeración de la calle crece hacia el este o hacia el oeste.

Cada que llames la función `avanza` Spider-man gastará su teleraña por lo que tienes un límite de llamadas de $L$, después de eso Spider-man quedará sin opción de retorno.

Si después de llamar `avanza` Spider-man termina en la casa `destino`, en ese momento el evaluador terminará la ejecución de tu programa para este caso, y tomará en cuenta, para calificarte, la cantidad de veces que hayas llamado a`avanza` hasta este momento

# Rutina de Ejemplo
|| input
Función llamada
|| output
Valor devuelto
|| description
Descripción
|| input
encuentraCasa(1,120)
|| output
-
|| description
Esta será la llamada inicial a tu procedimiento `encuentraCasa`.
|| input
avanza(1)
|| output
10
|| description
avanzas una casa, la nueva casa tiene número 10.
|| input
avanza(5)
|| output
130
|| description
avanzas cinco casas, la nueva casa tiene número 130.
|| input
avanza(-1)
|| output
120
|| description
regresas una casa, y llegas a la casa destino. En este momento el evaluador se detiene.
|| end

# Experimentación

{{libinteractive:download}}

# Límites

* Puedes avanzar desde $-2^{63}$ hasta $2^{63}-1$ `casas`.
* El número que identifica cada casa será mayor igual que $-2^{63}$ y menor igual que $2^{63} - 1$.

# Subtareas

* **Subtarea (14 puntos):**
  * `origen` siempre será $1$ y esa será la casa identificada con el menor número en la calle.
  * $1 < N < 2^{15}$
  * $L = N$
* **Subtarea (25 puntos):**
  * no hay restricción de `origen`
  * $1 < N < 2^{31}$
  * $L < \frac{N}{2}$
* **Subtarea (61 puntos):**
  * $1 < N < 2^{63}$
  * $L \le 2 \times \lceil\log(N)\rceil$
  * 43 de estos puntos están agrupados
