![Ilustracion](killer-queen.jpeg)

En el ajedrez la reina tiene la capacidad de desplazarse en cualquier dirección: horizontal, vertical o en cualquiera de las diagonales. Se dice que la reina está _atacando_ a una pieza si desde su posición puede desplazarse haciendo un moviento horizontal, vertical o diagonal hasta dónde está la otra pieza y además no existe ninguna pieza intermedia entre las dos.

En la versión especial de ajedrez que juega Karel la _reina asesina_ (o killer-queen) puede _saltar_ piezas. Es decir, la _reina asesina_ puede atacar a cualquier pieza que esté en una posición a la que se pueda mover sin importar si hay o no piezas intermedias.

Karel es novato en ajedrez y está aprendiendo a usar la _reina asesina_, dado un tablero de ajedrez determina ¿a cuántas piezas está atancando la reina?

El mundo de Karel representa el tablero de ajedrez, las piezas se representan con montones de 1 zumbador, Karel inicia en la posición de la _reina asesina_.

**La _reina asesina_ no se ataca a sí misma.**

# Problema

Escribe un programa que dado el tablero de ajedrez y la posición de la _reina asesina_ calcule ¿cuántas piezas están siendo atacadas por la _reina asesina_?.

Tu programa deberá dejar en la posición inicial de Karel un montón de zumbadores con la cantidad total de piezas atacadas por la reina.

# Ejemplos

## Entrada

![Mundo de entrada](killer-queen.in.png)

## Salida

![Mundo de salida](killer-queen.out.png)

## Descripción

- En su fila (movimiento horizontal), la _reina asesina_ ataca a 2 piezas.
- En su columna (movimiento vertical), la _reina asesina_ ataca a 3 piezas.
- En sus diagonales, la _reina asesina_ ataca a 4 piezas, 2 en una diagonal y 2 en la otra.

En total la _reina asesina_ ataca $2 + 3 + 4 = 9$ piezas.

**Observa que la _reina_ también aparece como pieza en el tablero, pero no se ataca a ella misma.**

# Consideraciones

- Karel inicia en una posición desconocida con orientación desconocida.
- Dependiendo del grupo de casos de prueba Karel llevará $0$ o $1$ zumbador en la mochila.
- El mundo de Karel es cuadrado, pero la longitud de su lado puede ser distinto en cada caso de prueba.
- Todos los montones son de $1$ zumbador.
- **Para obtener los puntos, tu programa deberá dejar en la posición inicial de Karel un montón igual a la cantidad de piezas atacadas por la _reina asesina_.**

# Subtareas

En este problema, los casos de cada subtarea se encuentran agrupados. Para obtener el puntaje de una subtarea deberás resolver correctamente todos los casos del grupo.

- (25 puntos): Todas las piezas están en la columna o la fila de la _reina asesina_. **Karel lleva 1 zumbador.**.
- (30 puntos): **Karel lleva 1 zumbador.**
- (25 puntos): Por cada dirección de las ocho que puede tomar la reina, a lo más hay una pieza contraria. **Karel lleva 0 zumbadores**
- (20 puntos): **Karel lleva 0 zumbadores.**
