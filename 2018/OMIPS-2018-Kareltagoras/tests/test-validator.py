#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import os

import libkarel
from kareltest import *

class Test(KarelTest):
    def test(self):
        world = self.world

        self.assertNoInnerWalls()
        self.assertTightWorldSize()

        self.assertEqual(world.x, 1)
        self.assertEqual(world.y, 1)
        self.assertEqual(world.direccion, 'NORTE')

        self.assertEqual(world.mochila, 'INFINITO')

        self.assertEqual(world.lista_dump, {(1,1)})

        if 'easy' in self.caseName:
            self.assertEqual(world.despliega, ['MUNDO'])
        else:
            self.assertEqual(
                set(world.despliega),
                set(['ORIENTACION', 'MUNDO'])
            )

Test().run()
