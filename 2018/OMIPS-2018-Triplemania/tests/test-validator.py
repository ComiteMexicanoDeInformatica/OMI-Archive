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

        self.assertTrue(2 <= world.w <= 10)
        self.assertTrue(2 <= world.h <= 10)

        self.assertEqual(world.x, 1)
        self.assertEqual(world.y, 1)
        self.assertEqual(world.direccion, 'NORTE')

        self.assertEqual(world.mochila, 0)

        self.assertEqual(world.despliega, ['POSICION'])

        beepers = world.lista_zumbadores

        self.assertTrue(all(
            (x,y) in beepers and 1 <= int(beepers[(x,y)]) <= 99
            for x in range(1, world.w + 1)
            for y in range(1, world.h + 1)
        ))
        
        rows = [[beepers[(x,y)] for x in range(1, world.w + 1)]
                for y in range(1, world.h + 1)]

        rows.sort()

        self.assertTrue(rows[0] != rows[1])

        if 'two' in self.caseName:
            self.assertEqual(world.w, 2)
        elif 'three' in self.caseName:
            self.assertEqual(world.w, 3)

Test().run()
