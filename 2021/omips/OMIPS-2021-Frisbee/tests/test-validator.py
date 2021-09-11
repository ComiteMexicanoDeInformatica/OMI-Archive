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

        # Las únicas paredes en el mundo son las que lo delimitan.
        self.assertNoInnerWalls()

        #Inicia mirando al norte
        self.assertEqual(world.direccion, 'NORTE')

        #Karel tiene infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, 'INFINITO')
        
        # Solo importan los zumbadores que dejes en la casilla (1,1)
        self.assertEqual(world.despliega, ['MUNDO'])
        self.assertEqual(world.lista_dump, set([(1, 1)]))

        beepers = world.lista_zumbadores 

        #Verificar que solo exista un beeper
        self.assertTrue(len(beepers) == 1)

        #Verificar que este arriba o derecha
        for (x,y),v in beepers.items():
            self.assertTrue(world.x <= x)
            self.assertTrue(world.y <= y)
            self.assertFalse(world.x == x and world.y == y)
            self.assertTrue(v == 1)

        
        if 'sub1' in self.caseName:
            #Karel inicia en la casilla (1,1) viendo al norte.
            self.assertEqual(1, world.y)
            self.assertEqual(1, world.x)
        elif 'sub2' not in self.caseName:
            self.fail(f"Invalid case name: {self.caseName}")



if __name__ == '__main__':
    kareltest.main()