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

        self.assertEqual(world.x, 1)
        self.assertEqual(world.y, 1)

        self.assertTrue(world.w <= 40)
        self.assertTrue(world.h <= 40)
        
        self.assertTrue((1,1) not in world.lista_zumbadores)

        self.assertEqual(world.direccion, 'NORTE')

        self.assertEqual(world.mochila, 0)

        self.assertEqual(world.despliega, ['MUNDO'])
        self.assertEqual(world.lista_dump, set([(1,1)]))

        if 'nofirstrow' in self.caseName:
            self.assertTrue(all(
                y != 1
                for x, y
                in world.lista_zumbadores.keys()
            ))
        else:
            self.assertTrue(any(
                y == 1
                for x, y
                in world.lista_zumbadores.keys()
            ))

Test().run()
