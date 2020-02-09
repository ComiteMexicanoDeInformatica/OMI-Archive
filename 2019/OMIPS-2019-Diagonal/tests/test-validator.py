#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import os
import collections

import libkarel
from kareltest import *

class Test(KarelTest):

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

        #El mundo siempre será cuadrado
        self.assertEqual(world.h, world.w)
        
        # Se evalúan todos los zumbadores del mundo
        self.assertEqual(world.despliega, ['UNIVERSO'])

        #Hay exactamente un zumbador por columna
        zumbadores = world.lista_zumbadores

        for k, v in zumbadores.items():
            self.assertTrue(v == '1')

        xs = [k[0] for k,v in zumbadores.items()]

        self.assertTrue(len(xs) == len(set(xs)))

Test().run()
