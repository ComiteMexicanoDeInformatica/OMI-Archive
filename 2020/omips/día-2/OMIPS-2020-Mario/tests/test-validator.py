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

        #todos los montones son de 0 o 1 zumbador
        self.assertTrue(all(
            0 <= int(v) <= 1
            for k, v in world.lista_zumbadores.items()
        ))

        #Solo importan los zumbadores que dejes en la casilla (1,1)
        self.assertEqual(world.despliega, ['MUNDO'])
        self.assertEqual(world.lista_dump, set([(1, 1)]))



if __name__ == '__main__':
    kareltest.main()
