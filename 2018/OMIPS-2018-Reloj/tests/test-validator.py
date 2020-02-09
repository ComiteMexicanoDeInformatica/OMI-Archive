#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import os

import libkarel
from kareltest import *

class Test(KarelTest):
    def test(self):
        world = self.world

        self.assertTightWorldSize()
        self.assertNoInnerWalls()

        self.assertEqual(world.x, 1)
        self.assertEqual(world.y, 1)

        self.assertEqual(world.direccion, 'NORTE')

        self.assertEqual(world.mochila, 0)

        self.assertTrue(world.w == 3)
        self.assertTrue(world.h == 3)

        self.assertEqual(world.despliega, ['MUNDO'])
        self.assertEqual(
            world.lista_dump,
            set([(1,2), (2,2), (3,2)])
        )

        delta = int(world.lista_zumbadores.get((1,1), 0))
        secs = int(world.lista_zumbadores.get((3,2), 0))
        mins = int(world.lista_zumbadores.get((2,2), 0))
        hrs = int(world.lista_zumbadores.get((1,2), 0))

        self.assertTrue(1 <= delta <= 99999)
        self.assertTrue(0 <= secs <= 59)
        self.assertTrue(0 <= mins <= 59)
        self.assertTrue(0 <= hrs <= 23)

        self.assertEqual(
            world.lista_zumbadores[(1,3)],
            'INFINITO'
        )

        if 'seconds' in self.caseName:
            self.assertTrue(delta <= 60)
            self.assertTrue((secs + delta) // 60 == 0)
        elif 'minutes' in self.caseName:
            self.assertTrue(mins + (secs + delta) // 60 < 60)

Test().run()
