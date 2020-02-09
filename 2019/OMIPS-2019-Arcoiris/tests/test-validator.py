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

        # No hay paredes internas en el mundo
        self.assertNoInnerWalls()

        # Karel empieza en (1,1) viendo al norte.
        self.assertEqual(world.x, 1)
        self.assertEqual(world.y, 1)
        self.assertEqual(world.direccion, 'NORTE')

        # Karel tiene infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, 'INFINITO')

        # No hay zumbadores en el mundo
        self.assertEqual(len(world.lista_zumbadores), 0)

        # Altura del mundo
        N = world.h

        # Altura va de 7 a 99
        self.assertTrue(7 <= N <= 99)

        # El mundo es exactamente del tamaño para
        # contener el arcoiris
        self.assertEqual(world.w, 2*N-1)

        # Se evalúan todos los zumbadores del mundo
        self.assertEqual(world.despliega, ['UNIVERSO'])


Test().run()
