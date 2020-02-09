#!/usr/bin/python2

from __future__ import division

import Main


# Este archivo se llama lerp porque utiliza interpolación lineal (Linear
# intERPolation).
def encuentraCasa(origen, destino):
    prev = Main.avanza(-1)
    curr = origen
    succ = Main.avanza(2)
    Main.avanza(-1)  # Regresa al origen.

    # Encuentra la dirección en la cual crecen los números de las casas.
    direction = 0
    if prev < curr < succ:
        direction = 1
    elif curr < min(prev, succ) and prev > succ:
        direction = 1
    elif curr > max(prev, succ) and prev < succ:
        direction = 1
    else:
        direction = -1

    # A veces este hack horrendo se queda atorado en un ciclo. Cuando eso
    # ocurre, avanzamos una casa más para salirnos.
    seen = set()
    while True:
        # Depende de la dirección y de si el destino está "antes" o "después"
        # de la casa actual, es hacia dónde nos movemos.
        #
        # Ya que encontramos la diferencia en números de la casa actual y su
        # vecino en la dirección deseada, hacemos interpolación lineal para
        # estimar cuántas casas hay que avanzar. Como ya nos habíamos movido
        # una casa en esa dirección, la desconsideramos al momento de calcular
        # el número de casas.
        if destino > curr:
            succ = Main.avanza(direction)
            step_size = succ - curr
            steps = (destino - curr) // step_size - direction
        else:
            prev = Main.avanza(-direction)
            step_size = curr - prev
            steps = (destino - curr) // step_size + direction

        curr = Main.avanza(steps)

        # Finalmente, si ya habíamos visto este elemento en particular, nos
        # movemos una casa en la dirección en la que la numeración crece para
        # salirnos del ciclo.
        if curr in seen:
            if destino > curr:
                curr = Main.avanza(direction)
            else:
                curr = Main.avanza(-direction)
        seen.add(curr)
