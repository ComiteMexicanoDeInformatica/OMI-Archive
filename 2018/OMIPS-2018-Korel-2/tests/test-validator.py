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

        self.assertEqual(world.mochila, 'INFINITO')

        self.assertEqual(len(world.lista_zumbadores), 1)

        beeper = list(world.lista_zumbadores.keys())[0]

        self.assertTrue(beeper in self.reachableCells())

        if 'hard' not in self.caseName:
            self.assertEqual(
                set(world.despliega),
                set(['ORIENTACION', 'POSICION'])
            )
        else:
            self.assertEqual(
                set(world.despliega),
                set(['ORIENTACION', 'POSICION', 'MUNDO'])
            )

            self.assertEqual(
                world.lista_dump,
                set([beeper])
            )

Test().run()
