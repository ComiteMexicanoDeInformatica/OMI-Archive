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
        self.assertNoInnerWalls()

        self.assertEqual(world.x, 1)
        self.assertEqual(world.direccion, 'ESTE')

        self.assertEqual(world.mochila, 'INFINITO')

        # karel is standing on a beeper
        self.assertEqual(
            beepers.get((world.x, world.y), None),
            '1'
        )

        self.assertEqual(world.despliega, ['UNIVERSO'])

        self.assertTrue(int(v) == 1 for (_, v) in beepers.values())

        # no two beepers per column
        cols = [x for x,_ in beepers.keys()]
        self.assertEqual(len(set(cols)), len(cols))

        # there's a beeper in the last column
        self.assertTrue(world.w in cols)

        # all beepers form a line
        coords = list(beepers.keys())
        coords.sort()

        for i in range(len(coords)-1):
            ax, ay = coords[i]
            bx, by = coords[i+1]
            sign = -1 if i % 2 == 0 else 1
            self.assertEqual(bx - ax, sign * (by - ay))

        # subtasks
        if 'onlytwo' in self.caseName:
            self.assertEqual(len(beepers), 2)

Test().run()
