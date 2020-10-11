#!/usr/bin/python3
# -*- coding: utf-8 -*-
import sys
import os
import collections
import logging
import math

import libkarel
from libkarel import kareltest


class Test(kareltest.TestCase):

    def test(self):
        world = self.world

        #Karel inicia en la casilla (1,1) viendo al norte.
        self.assertEqual(1, world.y)
        self.assertEqual(1, world.x)
        self.assertEqual(world.direccion, 'NORTE')

        #Las únicas paredes en el mundo son las que lo delimitan.
        self.assertTightWorldSize()
        self.assertNoInnerWalls()

        #Karel tiene infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, 'INFINITO')

        # Solo se evalúa la posición final de Karel
        self.assertEqual(world.despliega, ['POSICION'])

        #Solo hay montones de 1 zumbador en el mundo
        self.assertTrue(all(
            0 <= int(v) <= 1
            for k, v in world.lista_zumbadores.items()
        ))

        #Para la subtarea 1, el mundo es de 1xm
        if '1xm' in self.caseName:
            self.assertEqual(1, world.h)

        #Para la subtarea 2, hay a lo más 2 montones
        if 'am2b' in self.caseName:
            self.assertTrue(len(world.lista_zumbadores) <= 2)


if __name__ == '__main__':
    kareltest.main()
