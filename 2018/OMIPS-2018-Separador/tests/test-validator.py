#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import os

import libkarel
from kareltest import *

class Test(KarelTest):
    def test(self):
        world = self.world

        beepers = world.lista_zumbadores

        self.assertTightWorldSize()

        self.assertEqual(world.x, 1)
        self.assertEqual(world.y, 1)
        self.assertEqual(world.direccion, 'NORTE')

        self.assertTrue(all(
            k == (1,1) or k[1] == 2
            for k, v in beepers.items()
        ))

        self.assertTrue(all(
            k == (1,1) or 0 <= int(v) <= 1
            for k, v in beepers.items()
        ))

        target = int(beepers[(1,1)])
        self.assertTrue(1 <= target <= 100)
        self.assertTrue(target <= len(beepers))

        self.assertNoInnerWalls()

        self.assertEqual(world.despliega, ['POSICION'])

        if 'inf' in self.caseName:
            self.assertEqual(world.mochila, 'INFINITO')
        else:
            self.assertEqual(world.mochila, 0)

Test().run()
