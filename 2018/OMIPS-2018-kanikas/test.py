#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import os

import libkarel
from kareltest import *

import unittest


class KanikasTest(KarelTest):
    def runTest(self):
        world = self.world

        self.assertEqual(world.direccion, 'NORTE')

        self.assertEqual(world.x, 1)
        self.assertEqual(world.y, 1)

        self.assertTrue(all(
            0 <= int(v) <= 99 and k[1] == 1
            for (k, v) in world.lista_zumbadores.iteritems()
        ))

        self.assertEqual(world.despliega, ['ORIENTACION'])

        if 'inf' in self.filename:
            self.assertEqual(world.mochila, 'INFINITO')
        else:
            self.assertEqual(world.mochila, 0)

        self.assertNoInnerWalls()


suite = KarelTestSuite()
suite.populate(KanikasTest)

runner = unittest.TextTestRunner()
result = runner.run(suite)
sys.exit(not result.wasSuccessful())
