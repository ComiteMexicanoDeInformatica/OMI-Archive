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

        #Karel inicia en la casilla (1,1) viendo al norte.
        self.assertEqual(1, world.y)
        self.assertEqual(1, world.x)
        self.assertEqual(world.direccion, 'NORTE')

        #Karel tiene cero zumbadores en la mochila.
        self.assertEqual(world.mochila, 0)
        
        # Solo importan los zumbadores que dejes en la casilla (1,1)
        self.assertEqual(world.despliega, ['MUNDO'])
        self.assertEqual(world.lista_dump, set([(1, 1)]))

        beepers = world.lista_zumbadores 
        empty = 1
        uno = True

        #Verificar que todos los beepers esten en la fila 1 y esten en el rango de valor
        for (x,y),v in beepers.items():
            self.assertTrue(y == 1)
            self.assertTrue(1 <= v <= world.h)
            if v != 1:
                uno = False

        #Verificar que esten contiguos los beepers e inicie en (1,1) los beepers
        for x in range(1,world.w+1):
            if (x,1) in beepers:
                self.assertEqual(empty, 1)
            else:
                empty = 0

        
        if 'sub1' in self.caseName:
            #Todos los grupos son de 1 persona
            self.assertTrue(uno)
        elif 'sub2' in self.caseName:
            #Limite de movimientos (cantidad de grupos + altura) x 2
            self.assertEqual(world.limite_comando("AVANZA"), 2 * ( len(beepers) + world.h) )
        elif 'sub3' not in self.caseName:
            self.fail(f"Invalid case name: {self.caseName}")



if __name__ == '__main__':
    kareltest.main()