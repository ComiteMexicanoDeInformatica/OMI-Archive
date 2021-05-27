Karel trabaja en la oficina secreta de la Organización Mundial de Investigación (OMI). En la oficina hay cámaras de alta seguridad que protegen todos los datos de la organización.

En una tarde como cualquier otra, el Malévolo Agrupador de Casos Pacha (MAC Pacha) consiguió el mapa de la oficina y planea robar toda la información.

MAC Pacha sabe que la oficina secreta de la OMI es un rectángulo de dimensiones $N \times M$ sin paredes interiores y que un zumbador en una posición representa una cámara de seguridad. Además, sabe que las cámaras solo tienen vista hacia la parte superior derecha de la oficina (Ver la figura de abajo).

![Cámara](camara.png)

Karel se dió cuenta que si quita todas las cámaras que son vistas por alguna otra cámara mantiene la misma visibilidad de la oficina.

Karel quiere mejorar la seguridad de la oficina para evitar que MAC Pacha robe la información, por lo que necesita recoger todas las cámaras que puede reubicar.

# Problema

Karel debe recoger todas las cámaras que son vistas por alguna otra cámara.

# Ejemplo

## Entrada

![Ejemplo de Entrada](sample.in.png)

## Salida

![Ejemplo de Salida](sample.out.png)

Karel solo deja los zumbadores en las casillas $(3,1)$ y $(2,3)$ pues estas cámaras no son vistas por ninguna otra.

# Consideraciones

- Karel empieza en la casilla $(1,1)$ viendo al norte.
- Karel tiene infinitos zumbadores en la mochila.
- Las únicas paredes son las que delimitan al mundo.
- La altura del mundo puede ser entre $1$ y $100$.
- El ancho del mundo puede ser entre $1$ y $100$.
- No importa la posición ni orientación final de Karel.

# Subtareas

- **(70 puntos)**: No hay límite en los movimientos de Karel.
- **(20 puntos)**: Karel puede avanzar a lo más $$8*N*M$$ veces y todos los casos están agrupados.
- **(10 puntos)**: Karel puede avanzar a lo más $$2*N*M$$ veces y todos los casos están agrupados.
