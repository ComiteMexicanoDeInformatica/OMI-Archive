#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import os

import libkarel
from kareltest import *

class Test(KarelTest):
    def test(self):
        world = self.world

        # No hay paredes internas en el mundo
        self.assertNoInnerWalls()
        # Karel tiene infinitos zumbadores en la mochila
        self.assertEqual(world.mochila, 'INFINITO')

        # haz dump de todas las casillas del mundo
        self.assertTightWorldSize()
        self.assertEqual(world.despliega, ['UNIVERSO'])

        # El alto y ancho del mundo no serán mayores de 40.
        self.assertTrue(world.w <= 40)
        self.assertTrue(world.h <= 40)

        # Karel empieza en (1,1) viendo al norte.
        self.assertEqual(world.x, 1)
        self.assertEqual(world.y, 1)
        self.assertEqual(world.direccion, 'NORTE')

        beepers = world.lista_zumbadores
        valid = True

        #valida que los zumbadores iniciales cumplan la regla beepers[i][j] > max(beepers[i-1][j], beepers[i][j-1])
        for i in range(1, world.w+1):
            for j in range(1, world.h+1):
                prev = max(int(beepers.get((i-1,j), 0)), int(beepers.get((i,j-1), 0)))
                current = int(beepers.get((i,j), 0))
                if current > 0:
                    if (current <= prev):
                        valid = False
                else:
                    beepers[(i,j)] = current + 1

        self.assertTrue(valid)

Test().run()
