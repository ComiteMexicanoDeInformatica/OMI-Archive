El primo Korel está de visita en la ciudad y Karel quiere llevarlo a conocer el Ángel de la independencia.
Solo hay un problema: Korel se mueve de manera diferente a Karel.

# Problema

Los dos parten de la casa de Karel y quieren llegar al Ángel, el cual está representado como el único zumbador en el mundo.

Korel solo puede caminar en diagonal, incluso entre paredes. Es decir, de la casilla $(f,c)$ en un paso puede ir a la casilla $(f+1,c+1)$ o $(f+1,c-1)$ o $(f-1,c+1)$ o $(f-1,c-1)$. Sin importar si hay paredes entre las dos casillas.

Escribe un programa que lleve a Karel al zumbador y se oriente al norte si Korel va a poder llegar o al sur si no. Puedes obtener más puntos si en la casilla donde está el Ángel, dejas el número mínimo de pasos de Korel (no Karel) que necesita para llegar.

# Ejemplo

### Entrada

![Ejemplo de entrada](entrada.png)

### Salida

![Ejemplo de salida](salida.png)

### Explicación

Karel se apaga sobre el zumbador y se orienta al norte porque el primo Korel sí puede llegar.

# Consideraciones

* La posición y la orientación inicial de Karel son desconocidas.
* La posición inicial de Karel es su casa.
* Korel inicia desde la misma casilla que Karel.
* Korel puede atravesar paredes, incluso las que delimitan al mundo.
* Karel tiene infinitos zumbadores en la mochila.
* En el mundo puede haber paredes internas, incluyendo islas.
* Solo existe un zumbador en el mundo.
* Si Korel no puede llegar al zumbador, se considera que el número mínimo de pasos es cero.
* Se asegura que Karel siempre va a poder llegar al zumbador.
* No importa cómo queden los zumbadores del mundo al final, salvo el de la casilla del Ángel.
* Se evalúa la posición y orientación final de Karel.

# Subtareas

* En el 70% de los casos solamente se evalúa la posición y orientación final de Karel.
* En el 30% restante se evalúa además la cantidad de zumbadores que quedan al final en la casilla del Ángel.
