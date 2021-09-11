Contrataron a Karel para probar un nuevo video juego de peleas.

En este juego cada jugador elige uno de entre múltiples personajes con diferentes _niveles de poder_. Los personajes se enfrentan en _rondas_. En cada ronda el juego sortea parejas entre los jugadores que continúan _vivos_ y todas las parejas se enfrentan en simultáneo. Si el número de jugadores _vivos_ es impar un jugador al azar pasa a la siguiente ronda en automático.

En un enfrentamiento siempre gana el personaje con mayor _nivel de poder_, el otro es eliminado. En caso de que el _nivel de poder_ de ambos sea el mismo, ambos continúan a la siguiente ronda.

El juego termina cuando sólo queda $1$ personaje o cuando es imposible eliminar a más personajes. Los personajes que quedan al final son considerados _ganadores_.

En la primera fila del mundo hay montones de zumbadores que representan personajes, la cantidad de zumbadores en cada montón indica su nivel de poder.

Karel quiere saber ¿qué personajes son _ganadores_?

# Problema

Ayuda a Karel a determinar ¿qué personajes son _ganadores_? escribiendo un programa que deje $1$ zumbador en la posición de dichos personajes y $0$ zumbadores en las posiciones de todos los demás personajes.

# Ejemplo

## Entrada

![Entrada 1](entrada1.png)

## Salida

![Salida 1](salida1.png)

# Consideraciones

- Karel empieza en la casilla (1, 1) orientado al norte.
- Karel tiene infinitos zumbadores en la mochila.
- La lista de personajes está representada por montones de zumbadores en la fila $1$ y empieza en la casilla (1, 1).
- No hay espacios vacíos entre los personajes.
- Los _niveles de poder_ de los personajes están entre $1$ y $99$.
- Para la evaluación importan los zumbadores en las posiciones de los personajes.

# Subtareas

- **(28 puntos):** Los _niveles de poder_ de los personajes son todos distintos.
- **(22 puntos):** Karel puede avanzar a lo más $2 * N$ veces, donde $N$ es la cantidad de personajes. Los _niveles de poder_ de los personajes son todos distintos.
- **(28 puntos):** Puede haber _niveles de poder_ repetidos.
- **(22 puntos):** Karel puede avanzar a lo más $2 * N$ veces, donde $N$ es la cantidad de personajes. Puede haber _niveles de poder_ repetidos.
