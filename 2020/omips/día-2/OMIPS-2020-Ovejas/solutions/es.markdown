# Ovejas - Solución

La idea para resolver este problema consiste en ir expandiendo un zumbador en el mundo de acuerdo a la distancia Manhattan:

![Estado inicial](no_expandido.png)

![Estado final](expandido.png)

La estrategia es hacer esto para cada zumbador en el mundo. Sin embargo, en vez de dejar tal cual la distancia manhattan como en la figura de arriba, vamos a dejar el máximo entre ese número y lo que había. Así, cada casilla contendrá la máxima distancia manhattan a algún zumbador.

Para trabajar con el problema de no confundirnos con los zumbadores iniciales, podemos guardar en un recorrido la posición de cada uno de ellos; y con ayuda de la pila ir expandiendo uno por uno, conscientes de dónde se encontraba inicialmente.

Finalmente, solo elegimos la casilla con la menor cantidad de zumbadores y nos apagamos allí. Recordar que si hay empates tiene que ser la más al oeste y más al sur.

[Aquí puedes encontrar un video explicando la solución.](https://www.youtube.com/watch?v=SQ7rOzu_c_M)
