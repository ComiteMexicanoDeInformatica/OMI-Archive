![Ilustracion](karel-jones_ilustracion.jpeg)

Tras años de investigación, el arqueólogo Karel Jones descubrió los restos de Karelotitlán, una antigua ciudad en la ubicación de la actual CDMX. Karelotitlán fue famosa por su _gran puente_, el cual cruzaba de una lado al otro de la ciudad pasando sobre varias formaciones de agua.

Desgraciadamente, el _gran puente_ se encuentra destruido y Karel Jones desea reconstruirlo en base a las descripciones que existen del mismo.

El _gran puente_ unía los extremos este y oeste de Karelotitlán. El puente tenía muchas columnas y entre cada par de columnas había un _arco_ formado por una escalera en diagonal que subía, llegaba a un punto máximo y luego bajaba en diagonal hasta apoyarse en la siguiente columna. Por cuestiones arquitectónicas, las columnas eran de distintas alturas.

![Gran Puente](gran_puente.png)

La figura anterior muestra cómo se veía el _gran puente_ de Karelotitlán.

Aun existen las columnas del puente, pero todos los _arcos_ se han caído. Ayuda a Karel Jones a reconstruir el _gran puente_ de Karelotitlán reconstruyendo con zumbadores los _arcos_ del mismo.

El mundo de Karel representa Karelotitlán. Las columnas del _gran puente_ están delimitadas por paredes y todas son de ancho 1. Karel inicia en la primera columna del puente orientado al norte. La última columna del puente está junto de la pared este del mundo.

# Problema

Escribe un programa que reconstruya los _arcos_ del _gran puente_ utilizando zumbadores.

# Ejemplos

## Entrada

![Mundo de entrada](puente.in.png)

## Salida

![Mundo de salida](puente.out.png)

## Descripción

El mundo del ejemplo corresponde al de la figura en la descripción del problema. Los _arcos_ han sido destruidos y Karel debe reconstruirlos usando montones de 1 zumbador.

# Consideraciones

- Karel inicia sobre la primera columna del puente orientado al norte.
- Karel lleva infinitos zumbadores en la mochila.
- Todas las columnas del _gran puente_ tienen ancho 1 y al menos 1 casilla de altura.
- La última columna del _gran puente_ se encuentra pegada a la pared este del mundo.
- Se te asegura que siempre es posible construir un _arco_ entre cada par de columnas.
- Se te asegura que los _arcos_ nunca van a llegar hasta la pared norte del mundo.
- **Para obtener los puntos, tu programa deberá reconstruir los _arcos_ del puente y no dejar zumbadores en ningún otro lugar del mundo. La posición y orientación final de Karel no importan.**

# Subtareas

En este problema, los casos de cada subtarea se encuentran agrupados. Para obtener el puntaje de una subtarea deberás resolver correctamente todos los casos del grupo.

- (20 puntos): Todas las columnas del puente tienen la misma altura.
- (21 puntos): Las columnas tendrán alturas crecientes, es decir, para cada columna del puente su altura será mayor que la columna anterior.
- (22 puntos): Las columnas tendrán alturas decrecientes, es decir, para cada columna del puente su altura será menor que la columna anterior.
- (23 puntos): El puente sólo tiene dos columnas, la columna donde inicia Karel y la última.
- (14 puntos): Sin restricciones adicionales.
