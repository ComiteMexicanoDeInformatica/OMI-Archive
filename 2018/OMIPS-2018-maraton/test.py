#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import os

import libkarel
from kareltest import *

import unittest


class MaratonTest(KarelTest):
    def runTest(self):
        world = self.world

        self.assertEqual(world.direccion, 'NORTE')

        self.assertEqual(world.x, 1)
        self.assertEqual(world.y, 1)

        self.assertTrue(all(
            0 <= int(v) <= 99 and k[1] == 1
            for (k, v) in world.lista_zumbadores.iteritems()
        ))

        self.assertEqual(world.despliega, ['POSICION'])

        self.assertEqual(world.mochila, 'INFINITO')

        self.assertNoInnerWalls()


suite = KarelTestSuite()
suite.populate(MaratonTest)

runner = unittest.TextTestRunner()
result = runner.run(suite)
sys.exit(not result.wasSuccessful())
