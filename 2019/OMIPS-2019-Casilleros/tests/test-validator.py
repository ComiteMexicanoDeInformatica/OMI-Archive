#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import os

import libkarel
from kareltest import *

class Test(KarelTest):
    def test(self):
        world = self.world

        self.assertTightWorldSize()

        # Karel está en un mundo de 1xn
        self.assertEqual(world.h, 1)
        N = world.w

        # N va entre 1 y 5000
        if 'easy' in self.caseName:
            self.assertTrue(1 <= N <= 50)
        else:
            self.assertTrue(2500 < N <= 5000)

        # No hay paredes internas en el mundo
        self.assertNoInnerWalls()

        # Karel empieza en (1,1) viendo al norte.
        self.assertEqual(world.x, 1)
        self.assertEqual(world.y, 1)
        self.assertEqual(world.direccion, 'NORTE')

        # Karel tiene N beepers en la mochila
        self.assertEqual(world.mochila, N)

        self.assertEqual(world.despliega, ['UNIVERSO'])

        # Todo está apagado al principio
        self.assertEqual(len(world.lista_zumbadores), 0)

Test().run()
