# Solución oficial para Karel y el Ciclismo (OMIPS 2022)

## Observación principal

Observa que si no existe límite en la capacidad de la batería la energía en la batería cuando Karel está a una altura $h$ siempre es la misma.

Para darte cuenta de que esto es cierto supón que Karel está en una altura $h$ y tiene $e$ rayitas de energía en su batería. Adelante de el hay una bajada de $M$ metros seguida de una subida igual de $M$ metros. Analicemos qué sucede:

- Karel baja $M$ metros. Su batería cargó $M$ rayitas (una por cada metro) por lo que tiene $e + M$ rayitas y su altura es $h - M$ metros.
- Después Karel sube $M$ metros. Su batería consume $M$ rayitas (una por cada metro que sube), ahora su batería tiene $(e + M) - M = e$ rayitas y su altura es $(h - M) + M = h$ metros.
- Observa que al haber bajado y subido $M$ metros Karel tiene la misma energía y la misma altura en la que empezó.

¿Qué sucede si hay varias subidas y bajadas de distintas alturas (no ambas de $M$ como en este caso)? Observa que cada metro que se baja la energía aumenta en $1$ y la altura disminuye en $1$, de igual forma cada metro que se sube consume $1$ rayita de energía y aumenta la altura en $1$. De modo que sin límte de capacidad el orden de las subidas y las bajadas no importa ya que cada vez que Karel vuelva a la altura de inicio va a tener la energía inicial.

Usando la observación previa puedes darte cuenta que el punto donde Karel tendrá menos energía es el punto más alto de todos. Si Karel puede llegar a este punto, entonces podrá hacer todo el recorrido.

La solución para las primeras subtareas (en las que te aseguran que Karel puede terminar) es encontrar el punto máximo del mundo, restarlo de la altura inicial y esa es la energía que necesitas cargar en la batería de Karel.

A continuación se muestran posibles ideas para resolver las subtareas.

<details><summary>Subtarea 1 (5 puntos): La altura inicial de Karel es la mayor de todo el trayecto.
En esta subtarea no es necesario que Karel cargue energía, basta con que se apague viendo al norte luego de recoger los zumbadores.
</summary>

{{sol_sub1.kp}}

</details>

<details><summary>Subtareas 2, 3 y 4 (45 puntos): Se te asegura que Karel puede terminar.
Como se vio en la observación, para resolver este problema se requiere saber la altura máxima del mundo, restarle la altura inicial y al resultado restarle la energía inicial de la batería.
</summary>

{{sol_sub_50pts.kp}}

</details>

<details><summary>Subtarea 3 (100 puntos): Minimizar los cambios y contar cuántos fueron.
Para obtener 100 puntos requieres ir revisando cada par de monedas, haciendo cambio si es necesario y contando (recursivamente o mediante alguna marca) los lugares en que cambiaste monedas.
</summary>

{{solution.kp}}

</details>
