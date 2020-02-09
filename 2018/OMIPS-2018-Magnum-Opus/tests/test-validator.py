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

        w = world.w
        h = world.h

        self.assertTrue(1 <= w <= 50)
        self.assertTrue(1 <= h <= 50)

        self.assertTrue(w % 2 == 1)
        self.assertTrue(h % 2 == 1)

        cx = w // 2 + 1
        cy = h // 2 + 1

        self.assertEqual(world.x, cx)
        self.assertEqual(world.y, cy)
        self.assertEqual(world.direccion, 'NORTE')

        def layer(k):
            return max(abs(k[0] - cx), abs(k[1] - cy))

        layerColor = {
            layer(k): int(v)
            for k, v
            in beepers.items()
        }

        self.assertTrue(all(
            int(v) == layerColor[layer(k)]
            for k, v in beepers.items()
        ))

        self.assertTrue(all(
            1 <= int(v) <= 99
            for k, v in beepers.items()
        ))

        self.assertEqual(world.despliega, ['UNIVERSO'])
        self.assertEqual(world.mochila, 'INFINITO')

Test().run()
