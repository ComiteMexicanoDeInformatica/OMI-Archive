#!/usr/bin/python3
# -*- coding: utf-8 -*-
import sys
import os
import collections
import logging
from itertools import chain

import libkarel
from libkarel import kareltest


class Test(kareltest.TestCase):
    def test(self):
        world = self.world

        # Las únicas paredes en el mundo son las que lo delimitan.
        self.assertTightWorldSize()
        self.assertNoInnerWalls()

        # Karel inicia en la casilla (1,1) viendo al norte.
        self.assertEqual(1, world.y)
        self.assertEqual(1, world.x)
        self.assertEqual(world.direccion, 'NORTE')

        # Karel no tiene zumbadores en la mochila.
        self.assertEqual(world.mochila, 0)

        # Se evalúan los zumbadores en la casilla 1,1 y en la columna del "centro"
        self.assertEqual(world.despliega, ['MUNDO'])
        self.assertEqual(len(world.lista_dump), world.h)
        self.assertTrue(world.dump(1, 1))

        c = int((world.w + 1) / 2)
        self.assertTrue(all(world.dump(c, y) for y in range(2, world.h + 1)))

        # No hay zumbadores en la fila 1
        self.assertTrue(
            all(world.zumbadores(x, 1) == 0 for x in range(1, world.w + 1)))

        # Todas las filas tienen al menos 6 zumbadores
        for y in range(2, world.h + 1):
            s = sum(world.zumbadores(x, y) for x in range(1, world.w + 1))
            self.assertGreater(s, 5)

        # Los dos equipos tienen la misma cantidad de gladiadores
        # Las filas de gladiadores empiezan en la fila 2 y terminan al llegar a la pared al norte del mundo, no hay filas vacias.
        # Todas las filas tienen la misma cantidad de gladiadores.
        # No hay gladiadores con fuerza cero.
        hRange = range(2, world.h + 1)
        self.assertTrue(
            all(
                world.zumbadores(x, y) > 0 for y in hRange
                for x in chain(range(1, c - 1), range(c + 2, world.w + 1))))

        # Hay 3 columnas en blanco entre los dos equipos de gladiadores
        self.assertTrue(
            all(
                world.zumbadores(x, y) == 0 for y in hRange
                for x in range(c - 1, c + 2)))

        # Altura del mundo va de 2 a 100
        self.assertTrue(2 <= world.h <= 100)

        # Ancho del mundo va de 5 a 100
        self.assertTrue(5 <= world.w <= 100)


if __name__ == '__main__':
    kareltest.main()
