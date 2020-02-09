#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import os
import collections

import libkarel
from kareltest import *

class Test(KarelTest):
    def assertCorridor(self):
        cells = self.reachableCells()
        counters = collections.defaultdict(int)

        for x, y in cells:
            w = self.world.paredes(x, y)
            c = 0;
            if (x, y + 1) in cells and (not w & libkarel.Direccion.NORTE):
                c += 1
            if (x, y - 1) in cells and (not w & libkarel.Direccion.SUR):
                c += 1
            if (x + 1, y) in cells and (not w & libkarel.Direccion.ESTE):
                c += 1
            if (x - 1, y) in cells and (not w & libkarel.Direccion.OESTE):
                c += 1

            counters[c] += 1;

        self.assertEqual(2, counters[1]);
        self.assertEqual(len(cells) - 2, counters[2]);

    def test(self):
        world = self.world
        #Karel tiene infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, 'INFINITO')
        #No importa la posición ni orientación final de karel.
        self.assertEqual(world.despliega, ['UNIVERSO'])
        #El pasillo nunca se bifurcará.
        self.assertCorridor()
        self.assertTightWorldSize()

Test().run()
