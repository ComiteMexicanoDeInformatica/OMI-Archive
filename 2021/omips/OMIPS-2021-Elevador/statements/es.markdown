Karel se encuentra formado en la fila del elevador del edificio dónde trabaja. Por cuestiones de pandemia, en el elevador sólo pueden entrar $N$ personas a la vez. Las gente de la fila viene en _grupos_ que no quieren separarse, por ejemplo, si hay un _grupo_ de $4$ personas y al elevador sólo le quedan $3$ espacios, el _grupo_ de $4$ personas dejará ir el elevador y esperará a que llegue nuevamente para subirse.

Para pasar el tiempo mientras espera, a Karel se le ocurrió calcular ¿cuántas vueltas tendrá que dar el elevador para que toda la gente actualmente en la fila se haya subido?

El mundo de Karel es un rectángulo sin paredes internas con $N$ filas, **esto quiere decir que la altura del mundo representa la cantidad máxima de personas que pueden usar el elevador a la vez.**

Los _grupos_ de personas en la fila se representan por montones de zumbadores en la fila $1$ del mundo. La cantidad de zumbadores en el montón representa el tamaño del _grupo_.

**Cuando el elevador regresa al piso donde está Karel, siempre llega vacío y se pueden ocupar todos los lugares.**

# Problema

Escribe un programa que permita a Karel contar cuántas vueltas tendrá que dar el elevador para que todas las personas de la fila se hayan subido y deje un montón de zumbadores igual a ese número en la posición $(1, 1)$.

# Ejemplo

## Entrada

![Entrada 1](entrada1.png)

## Salida

![Salida 1](salida1.png)

La siguiente imagen muestra cómo subieron los _grupos_ de personas al elevador:

![Explicacion 1](explicacion1.png)

- El alto del mundo es $8$, eso significa que al elevador le caben $8$ personas.
- En la primera vuelta suben _grupos_ de $2 + 5 = 7$ personas. El siguiente _grupo_ de $3$ personas no cabe porque se pasarían del cupo límite de $8$ personas.
- En la segunda vuelta suben _grupos_ de $3 + 3 + 2 = 8$ personas.
- En la tercera vuelta sube el _grupo_ de $4$ personas. El siguiente _grupo_ de $5$ ya no cabe.
- En la cuarta y última vuelta suben los _grupos_ de $5 + 1 + 1 = 7$ personas.
- **En total el elevador tuvo que dar $4$ vueltas para que todos subieran, por lo que el resultado es $4$.**

# Consideraciones

- Karel inicia en la casilla (1, 1) orientado al norte.
- Karel **tiene $0$ zumbadores** en la mochila.
- El mundo de Karel será de $N$ filas por $100$ columnas.
- No habrá ningún grupo que sea mayor que la capacidad del elevador.
- No hay espacios vacíos entre los montones que representan los grupos.
- Para la evaluación, sólo importa el montón de zumbadores que tu programa deje en la casilla (1, 1).

# Evaluación

- **Para un conjunto de casos con valor de 25 puntos:** Todos los grupos serán de $1$ persona.
- **Para otro conjunto de casos con valor de 25 puntos:** Tu programa debe ejecutar la instrucción _avanza/move_ máximo $2(N + G)$ veces donde $G$ es la cantidad de _grupos_ de personas en la fila.
- **Para el resto de los casos:** No hay restricciones adicionales.
