#!/usr/bin/python3
# -*- coding: utf-8 -*-
import sys
import os
import collections
import logging
import math

import libkarel
from libkarel import kareltest


class Test(kareltest.TestCase):
    def test(self):
        world = self.world

        #Karel inicia en la casilla (1,1) viendo al norte.
        self.assertEqual(1, world.y)
        self.assertEqual(1, world.x)
        self.assertEqual(world.direccion, 'NORTE')

        #Karel tiene infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, 'INFINITO')

        #El mundo siempre será cuadrado
        self.assertEqual(world.h, world.w)
        #La dimensión está entre 2 y 100
        self.assertTrue(2 <= world.h <= 100)
        #Checar que la dimensión sea potencia de 2
        self.assertEqual(world.h & (world.h - 1), 0)
        n = int(math.log2(world.h))

        #Las únicas paredes en el mundo son las que lo delimitan.
        self.assertTightWorldSize()
        self.assertNoInnerWalls()

        # Solo hay zumbadores en la (1, 1) y está entre (4^n - 1)/3 y 4*(4^n - 1)/3
        self.assertEqual(len(world.lista_zumbadores), 1)
        self.assertTrue(
            all(
                int((4**n - 1) / 3) <= int(v) <= int(4 * (4**n - 1) / 3)
                and k[0] == 1 and k[1] == 1
                for k, v in world.lista_zumbadores.items()))

        # Solo se evalúa la posición final de Karel
        self.assertEqual(world.despliega, ['POSICION'])

        # Casos fijos
        fixed = {'1.in': 44, '2.in': 35, '3.in': 56, '4.in': 62, '5.in': 71}

        if self.caseName in fixed:
            self.assertEqual(world.h, 8)
            self.assertEqual(fixed[self.caseName], world.zumbadores(1, 1))


if __name__ == '__main__':
    kareltest.main()
