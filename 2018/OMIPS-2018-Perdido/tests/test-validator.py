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

        self.assertNoInnerWalls()
        self.assertTightWorldSize()

        self.assertEqual(world.x, 1)
        self.assertEqual(world.y, 1)
        self.assertEqual(world.direccion, 'NORTE')

        self.assertEqual(
            set(world.despliega),
            set(['POSICION', 'ORIENTACION'])
        )

        target = int(beepers[(1,1)])

        self.assertTrue(1 <= target <= 99)

        self.assertTrue(all(
            k == (1,1) or k[1] != 1
            for k, v in beepers.items()
        ))

        self.assertEqual(
            2 if 'N' in self.caseName else 1,
            sum(
                1 for k, v in beepers.items()
                if int(v) == target
            )
        )

        if 'inf' in self.caseName:
            self.assertEqual(world.mochila, 'INFINITO')
        else:
            self.assertEqual(world.mochila, 0)

Test().run()
