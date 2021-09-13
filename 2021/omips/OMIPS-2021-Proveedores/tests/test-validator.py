#!/usr/bin/python3
# -*- coding: utf-8 -*-
import sys
import os
import collections

import libkarel
from libkarel import kareltest


class Test(kareltest.TestCase):
    def test(self):
        world = self.world

        # Las únicas paredes en el mundo son las que lo delimitan.
        self.assertNoInnerWalls()

        # Karel inicia en la casilla (1,1) viendo al norte.
        self.assertEqual(1, world.y)
        self.assertEqual(1, world.x)
        self.assertEqual(world.direccion, 'NORTE')

        # Karel tiene infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, 'INFINITO')

        # El tamaño del mundo es entre 2 y 100
        self.assertTrue(2 <= world.h <= 100)
        self.assertTrue(2 <= world.w <= 100)

        # Solo importan los zumbadores que dejes en la casilla (1,1)
        self.assertEqual(world.despliega, ['MUNDO'])
        self.assertEqual(world.lista_dump, set([(1, 1)]))

        # Primer renglón y columna se encuentran vacíos
        self.assertTrue(all(world.zumbadores(x, 1) == 0 for x in range(world.w)))
        self.assertTrue(all(world.zumbadores(1, y) == 0 for y in range(world.h)))

        # Solo hay montones de 1 zumbador en el mundo
        self.assertTrue(all(0 <= int(v) <= 1 for k, v in world.lista_zumbadores.items()))


if __name__ == '__main__':
    kareltest.main()
