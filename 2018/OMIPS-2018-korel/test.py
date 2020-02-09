#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import os

import libkarel
from kareltest import *

import unittest


class KorelTest(KarelTest):
    def runTest(self):
        world = self.world

        beepers = world.lista_zumbadores

        self.assertEqual(list(beepers.keys()), [(world.x, world.y)])

        self.assertTrue(0 <= int(v) <= 99 for (_, v) in beepers.values())

        self.assertEqual(world.despliega, ['POSICION'])

        if 'inf' in self.filename:
            self.assertEqual(world.mochila, 'INFINITO')
        else:
            self.assertEqual(world.mochila, 0)


suite = KarelTestSuite()
suite.populate(KorelTest)

runner = unittest.TextTestRunner()
result = runner.run(suite)
sys.exit(not result.wasSuccessful())
