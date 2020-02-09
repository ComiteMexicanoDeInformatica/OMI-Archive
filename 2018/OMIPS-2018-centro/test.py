#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import os

import libkarel
from kareltest import *

import unittest


class CentroTest(KarelTest):
    def runTest(self):
        world = self.world

        self.assertEqual(world.lista_zumbadores, {})

        self.assertEqual(world.despliega, ['POSICION'])

        self.assertTrue(world.w % 2 == 1)
        self.assertTrue(world.h % 2 == 1)

        if 'infinite' in self.filename:
            self.assertEqual(world.mochila, 'INFINITO')
        else:
            self.assertEqual(world.mochila, 0)

        w, h = self.worldBoundaries()

        self.assertEqual(w, world.w)
        self.assertEqual(h, world.h)

        self.assertNoInnerWalls()


suite = KarelTestSuite()
suite.populate(CentroTest)

runner = unittest.TextTestRunner()
result = runner.run(suite)
sys.exit(not result.wasSuccessful())
