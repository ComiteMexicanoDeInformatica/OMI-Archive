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
        self.assertNoInnerWalls()

        self.assertEqual(world.direccion, 'SUR')

        self.assertEqual(world.mochila, 0)

        self.assertEqual(world.despliega, ['ORIENTACION'])
        
        self.assertTrue(world.y != 1)

        self.assertTrue(all(
            k[1] == 1 and int(v) == 1
            for k, v in world.lista_zumbadores.items()
        ))

Test().run()
