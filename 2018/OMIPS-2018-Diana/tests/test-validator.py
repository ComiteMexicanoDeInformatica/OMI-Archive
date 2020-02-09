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

        self.assertEqual(world.mochila, 0)

        self.assertEqual(world.despliega, ['ORIENTACION'])

        self.assertTrue(world.w == 15)
        self.assertTrue(world.h == 15)

        beepers = world.lista_zumbadores

        self.assertTrue(all(
            0 <= int(v) <= 1
            for k, v in beepers.items()
        ))

Test().run()
