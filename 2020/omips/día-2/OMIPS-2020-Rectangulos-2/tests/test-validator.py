#!/usr/bin/python3
# -*- coding: utf-8 -*-
import sys
import os
import collections
import logging

import libkarel
from libkarel import kareltest


class Test(kareltest.TestCase):
    def test(self):
        world = self.world

        #Karel inicia en la casilla (1,1) viendo al norte.
        self.assertEqual(1, world.y)
        self.assertEqual(1, world.x)
        self.assertEqual(world.direccion, 'NORTE')

        #Karel tiene infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, 'INFINITO')

        #Las únicas paredes en el mundo son las que lo delimitan.
        self.assertTightWorldSize()
        self.assertNoInnerWalls()

        #El tamaño del mundo está entre 5 y 100.
        self.assertTrue(5 <= world.w <= 100)
        self.assertTrue(5 <= world.h <= 100)

        #No hay zumbadores en el mundo
        self.assertEqual(len(world.lista_zumbadores), 0)

        #Solo se evalúan los zumbadores en el mundo.
        self.assertEqual(world.despliega, ['UNIVERSO'])


if __name__ == '__main__':
    kareltest.main()
