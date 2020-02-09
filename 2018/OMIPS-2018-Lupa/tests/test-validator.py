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

        self.assertEqual(world.w, 9)
        self.assertEqual(world.h, 6)

        self.assertEqual(world.x, 1)
        self.assertEqual(world.y, 1)

        self.assertEqual(world.lista_zumbadores, {
            (9,6): 'INFINITO'
        })

        self.assertEqual(world.despliega, ['MUNDO'])

        toCheck = [(x,y) for x in range(1,10) for y in range(1,6)]

        self.assertEqual(world.lista_dump, set(toCheck))

Test().run()
