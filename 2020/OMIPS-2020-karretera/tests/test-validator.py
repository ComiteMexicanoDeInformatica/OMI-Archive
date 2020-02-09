#!/usr/bin/python3
# -*- coding: utf-8 -*-

import sys
import os

import libkarel
from kareltest import *

class Test(KarelTest):
    def test(self):
        world = self.world

        self.assertTightWorldSize()
        self.assertNoInnerWalls()

        # Karel está en un mundo de 5xN
        self.assertEqual(world.h, 5)
        self.assertTrue(1 <= world.w <= 100)

        # Karel empieza en (1,1) viendo al norte.
        self.assertEqual(world.x, 1)
        self.assertEqual(world.y, 1)
        self.assertEqual(world.direccion, 'NORTE')

        # En la casilla 1,1 hay infinitos zumbadores
        self.assertEqual(world.zumbadores(1,1), 'INFINITO')

        # Karel no tiene zumbadores en la mochila
        self.assertEqual(world.mochila, 0)

        # valida que tenga todos los despliega necesarios
        self.assertEqual(world.despliega, ['UNIVERSO', 'MOCHILA', 'AVANZA', 'COGE_ZUMBADOR', 'DEJA_ZUMBADOR'])

Test().run()
