Karel tiene un nuevo trabajo como encargado del almacén de una tienda departamental. Al llegar hoy, Karel encontró cajas amontonadas a la mitad del almacén que están estorbando. A Karel le gusta tener su almacén ordenado, por lo que pide tu ayuda para arreglar el _desastre_.

El mundo representa el almacén donde trabaja Karel. Cada zumbador en el mundo representa una caja. Se dice que una posición del mundo está _libre_ si no hay ninguna caja en esa posición, igualmente se dice que está _ocupada_ si hay alguna caja en esa posición. El almacén es un cuarto que puede tener **cualquier** forma, pero no tiene paredes internas, es decir, si el almacén está vacío (no hay cajas), Karel puede moverse de cualquier posición a cualquier otra.

A Karel le gusta ordenar el almacén de modo que se cumplan los siguientes requisitos:

- Máximo puede haber una caja en cada posición del mundo.
- Las cajas pueden estar en cualquier lugar del almacen siempre y cuando sea posible llegar de cualquier posición _libre_ del almacén a cualquier otra posición _libre_. Es decir, no puede haber cajas que _estorben_ y hagan imposible el paso de una parte del almacén a otra.

En el almacén ya hay algunas cajas acomodadadas y se te asegura que dichas cajas están acomodadas de forma que los dos requisitos previos se cumplen. Karel inicia en alguna posición del almacén parado sobre el montón de cajas estorbando. Ayúdale a acomodar las cajas de ese montón en el almacén.

# Problema

Escribe un programa que recoja las cajas del montón donde inicia Karel y las acomode en posiciones del almacén que cumplan con los requerimientos de Karel.

# Entrada

![Mundo de entrada](sample.in.png)

# Salida

![Mundo de salida](sample.out.png)

# Explicación

En las imágenes superiores se observa un posible mundo de entrada. Karel inicia en un montón de 5 cajas por acomodar. El mundo de salida muestra en un recuadro azul las posiciones donde Karel decidió acomodar las cajas. Las posiciones con un recuadro rojo muestran **algunos** de los lugares en los que si Karel hubiera dejado una caja, podría haber dejado zonas del almacén inaccesibles y por lo tanto un acomodo inválido.

Observa que la solución que se da no es la única posible, existen muchas otras formas de acomodar las cajas que también son válidas.

# Consideraciones

- Karel empieza en alguna casilla del almacén sobre el montón de cajas que hay que acomodar.
- Karel lleva infinitos zumbadores en la mochila.
- **No importa la posición ni la orientación final de Karel**.
- **Karel NO debe mover ninguna de las cajas que están acomodadas en el almacén, sólo puede mover las del montón inicial.**
- **Se te asegura que simpre será posible acomodar las cajas.**

# Subtareas

- (9 puntos): El almacén de Karel es un mundo rectangular de altura 1.
- (15 puntos): El almacén de Karel es un _pasillo_ de ancho 1.
- (32 puntos): El almacén no tiene ninguna caja además de las del montón original.
- (11 puntos): El almacén de Karel es un rectángulo.
- (33 puntos): No hay ninguna restricción.
