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

        # Karel tiene infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, 'INFINITO')

        # No hay zumbadores en el mundo
        self.assertEqual(len(world.lista_zumbadores), 0)

        # Mundo de a lo mas 50 x 50
        self.assertTrue(world.h <= 50)
        self.assertTrue(world.w <= 50)

        # Se evalúan todos los zumbadores del mundo
        self.assertEqual(world.despliega, ['UNIVERSO'])


Test().run()
