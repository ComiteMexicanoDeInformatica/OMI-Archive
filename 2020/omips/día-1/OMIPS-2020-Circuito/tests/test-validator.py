#!/usr/bin/python3
# -*- coding: utf-8 -*-
import sys
import os
import collections
import logging

import libkarel
from libkarel import kareltest


class Test(kareltest.TestCase):
    def test(self):
        world = self.world

        # Las únicas paredes en el mundo son las que lo delimitan.
        self.assertTightWorldSize()
        self.assertNoInnerWalls()

        # No hay zumbadores en la posición inicial de Karel.
        self.assertEqual(world.zumbadores(world.x, world.y), 0)

        # El tamaño del mundo está entre 5 y 50
        self.assertTrue(5 <= world.h <= 50)
        self.assertTrue(5 <= world.w <= 50)

        self.assertTrue(all(
            0 <= int(v) <= 1 and  # todos los montones son de 0 o 1 zumbador
            # no hay zumbadores en la columna 1,ni en la de hasta la derecha
            1 < k[0] < world.w and
            # no hay zumbadores en la fila 1, ni en la superior
            1 < k[1] < world.h
            for k, v in world.lista_zumbadores.items()
        ))

        # Solo importan la orientación final de Karel.
        self.assertEqual(world.despliega, ['ORIENTACION'])

        ort = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        # El circuito no tiene paredes pegadas.
        for k, v in world.lista_zumbadores.items():
            ad = sum(world.zumbadores(k[0]+dx, k[1]+dy) for (dx, dy) in ort)
            self.assertEqual(ad, 2)

        # Se asigna un peso a cada celda ortogonalmente adyacente.
        d = dict(zip(ort, [1, 2, 4, 8]))
        esq = collections.defaultdict(list)

        for k, v in world.lista_zumbadores.items():
            x = 0
            for m, n in d.items():
                x += (world.zumbadores(k[0]+m[0], k[1]+m[1]) * n)
            # las celdas que son esquina suman 5, 6, 9 o 10.
            if x in [5, 6, 9, 10]:
                esq[(k[0], k[1])] = x

        # tipos de esquina que al ser diagonalmente adyacentes, significa que se cierra el paso.
        clash = {5: 10, 6: 9, 9: 6, 10: 5}

        # revisa las esquinas con sus esquinas diagonalmente adyacentes, y validar si son pares con conflicto.
        for k, v in esq.items():
            for dx, dy in [(1, 1), (1, -1), (-1, -1), (-1, 1)]:
                if (k[0]+dx, k[1]+dy) in esq:
                    self.assertNotEqual(clash[v], esq[(k[0]+dx, k[1]+dy)])

        # Para la subtarea 1, Karel tiene infinitos zumbadores en la mochila.
        if '_inf' in self.caseName:
            self.assertEqual(world.mochila, 'INFINITO')
        else:
            # Para la subtarea 2, Karel no tiene zumbadores en la mochila.
            self.assertEqual(world.mochila, 0)


if __name__ == '__main__':
    kareltest.main()
