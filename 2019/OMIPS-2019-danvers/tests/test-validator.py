#!/usr/bin/python
# -*- coding: utf-8 -*-
import sys
import os
import collections

import libkarel
from kareltest import *

class Test(KarelTest):

    def test(self):
        world = self.world

        #Karel inicia en la casilla (1,1) viendo al norte.
        self.assertEqual(1, world.y)
        self.assertEqual(1, world.x)
        self.assertEqual(world.direccion, 'NORTE')

        #Karel tiene cero zumbadores en la mochila.
        self.assertEqual(world.mochila, 0)

        #Se evalúan todos los zumbadores del mundo
        self.assertEqual(world.despliega, ['UNIVERSO'])

        #Las únicas paredes en el mundo son las que lo delimitan.
        self.assertTightWorldSize()
        self.assertNoInnerWalls()

        #El mundo siempre medirá 100x100
        self.assertEqual(100, world.w)
        self.assertEqual(100, world.h)

        beepers = world.lista_zumbadores

        top = max(k[1] for k in beepers.keys())

        for i in range(1, 101):
            row = {k: v for k, v in beepers.items() if k[1] == i}

            if not row:
                #No hay renglones vacíos entre ductos
                self.assertEqual(i, top + 1)
                break

            left = min(k[0] for k in row)
            right = max(k[0] for k in row)

            #No hay espacios entre zumbadores de cada ducto
            self.assertEqual(left, 1)
            self.assertEqual(right, len(row))
Test().run()
