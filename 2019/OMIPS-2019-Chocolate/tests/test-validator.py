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

        self.assertEqual(world.direccion, 'NORTE')

        self.assertEqual(world.mochila, 0)

        self.assertEqual(world.despliega, ['UNIVERSO'])

        beepers = world.lista_zumbadores

        #todos los montones son de 1 zumbador
        self.assertTrue(all(
            0 <= int(v) <= 1 and k[0] == world.x
            for k, v in beepers.items()
        ))

        total = sum(int(x) for x in beepers.values())
        top = max(k[1] for k in beepers.keys())
        bot = min(k[1] for k in beepers.keys())

        #el chocolate cabe bien en el mundo
        self.assertTrue(total % world.w == 0)

        #karel está hasta abajo de la columna
        self.assertEqual(bot, world.y)

        #la columna está pegada al techo del mundo
        self.assertEqual(top, world.h)

        #no hay huecos en la columna
        self.assertEqual(top - bot + 1, total)



Test().run()
