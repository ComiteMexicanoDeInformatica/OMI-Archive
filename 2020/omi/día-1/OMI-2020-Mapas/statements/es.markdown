El <b>C</b>entro de <b>O</b>rganización de <b>M</b>apas <b>I</b>ntergalácticos diseñó unos mapas futuristas. Los mapas futuristas son como los mapas de ahora, pero están impresos en una superficie transparente. El COMI tiene un archivo de varios mapas de cada una de las galaxias del universo.  
Sebastián y Héctor se dieron cuenta de que existen varios mapas repetidos en el archivo, por lo que desean eliminar cualquier repetición del archivo. Para hacer esto, Sebastian toma un mapa, Héctor toma otro y ambos comparan los mapas para determinar si son iguales. Sin embargo, Héctor estaba distraído pensando en los problemas de la IOI 2020 y algunos mapas se los pasaba en una posición diferente a la original. Ahora Héctor y Sebastian necesitan tu ayuda para comparar los dos mapas y saber si son iguales.

Un mapa está representado por una matriz cuadrada de `X`s y `O`s. Dos mapas son iguales si ambos tienen el mismo carácter en la misma coordenada, para todas las coordenadas.

Para validar que dos mapas son iguales, puedes aplicar cualquiera de las siguientes acciones cero o más veces sobre un mapa que quieras comparar con otro:

- Rotarlo 90º.
- Rotarlo 180º.
- Rotarlo 270º.
- Invertirlo horizontalmente.
- Invertirlo verticalmente.

![Operaciones Posibles en los Mapas](operaciones.png)

# Problema

Sebastian y Héctor te mostrará dos mapas y debes ayudarles a decir si son iguales o diferentes. Si los mapas son iguales, deberás escribir `IGUALES`. Si son diferentes, deberás escribir `DIFERENTES`.

# Entrada

En la primera línea $N$, la longitud del lado de cada mapa.
En las siguientes $N$ líneas una cadena de $N$ caracteres `O` ó `X` que representan el primer mapa.
En las siguientes $N$ líneas una cadena de $N$ caracteres `O` ó `X` que representan el segundo mapa.

# Salida

Debes escribir `IGUALES` si los mapas son iguales después de hacer todas las transformaciones necesarias o `DIFERENTES` en caso contrario.

# Ejemplo

||examplefile
sample
||description
Si el segundo mapa lo giras 90º y además lo inviertes verticalmente, obtienes la misma distribución que el primer mapa.
||examplefile
sample_different
||description
No hay manera de transformar el segundo mapa para que se vea tal como el primero.
||examplefile
sample_same
||description
En este caso los mapas ya son iguales, sin necesidad de aplicar ninguna operación.
||end

# Límites

- $1 \leq N \leq 500$

# Subtareas

- **(25 puntos)**
  - $1 \leq N \leq 10$
  - Se asegura que, en caso de que los mapas sean iguales, no es necesario aplicar ninguna acción.
- **(25 puntos)**
  - $1 \leq N \leq 50$
  - Se asegura que, en caso de que los mapas sean iguales, no es necesario aplicar ninguna rotación.
- **(25 puntos)**
  - $1 \leq N \leq 50$
  - Se asegura que, en caso de que los mapas sean iguales, no es necesario aplicar ninguna inversión vertical o inversión horizontal.
- **(25 puntos)**
  - $1 \leq N \leq 500$
  - Cualquier acción podría ser necesaria para validar que los mapas son iguales.

# Consideraciones

Todos los casos de cada subtarea están agrupados.
