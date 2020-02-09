#!/usr/bin/python3
# -*- coding: utf-8 -*-
import sys
import os
import collections

import libkarel
from kareltest import *

class Test(KarelTest):
    def test(self):
        counters = collections.defaultdict(int)
        world = self.world

        self.assertTightWorldSize()

        # Karel empieza en la casilla (1,1) viendo al norte.
        self.assertEqual(world.y, 1)
        self.assertEqual(world.x, 1)
        self.assertEqual(world.direccion, 'NORTE')

        # Karel tiene solo un zumbador en la mochila.
        self.assertEqual(world.mochila, 1)

        # No hay zumbadores en el mundo
        self.assertEqual(len(world.lista_zumbadores), 0)

        # Altura del mundo va de 1 a 100
        self.assertTrue(1 <= world.h <= 100)

        # Ancho del mundo va de 2 a 100
        self.assertTrue(1 <= world.w <= 100)

        topX = 0
        topY = 0
        for i in range(1, world.w + 1):
            for j in range(2, world.h + 1):
                if world.paredes(i,j) & libkarel.Direccion.SUR:
                    counters[j] += 1
                    if j > topY:
                        topY = j
                        topX = i

        # No hay paredes horizontales en la columna 1
        self.assertTrue(all(
            not world.paredes(1, y) & libkarel.Direccion.SUR
            for y in range(2, world.h + 1)
        ))

        # El edificio solo tiene un punto más alto
        self.assertEqual(counters[topY], 1)

        # Se evalua solo el número de zumbadores en la casilla más alta
        self.assertEqual(world.despliega, ['MUNDO'])
        self.assertEqual(world.lista_dump, set([(topX,topY)]))

Test().run()
