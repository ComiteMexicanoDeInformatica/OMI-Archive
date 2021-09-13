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

        #Karel tiene infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, 'INFINITO')


        # Solo se evalúa la orientación final de Karel
        self.assertEqual(world.despliega, ['ORIENTACION'])
        
        beepers = world.lista_zumbadores 
        
        #Verificar que existan beepers
        self.assertTrue(len(beepers) >= 1)

        p = -1
        q = -1
        found = False

        #Encontrar posicion de la moneda
        for (x,y),v in beepers.items():
            if v == 2:
                self.assertFalse(found)
                p = x
                q = y
                found = True
            
        if 'sub1' in self.caseName:
            self.assertEqual(len(beepers), 1)
            self.assertTrue(found)
        elif 'sub2' in self.caseName:
            self.assertTrue(found)
            self.assertTrue(p == q)
        elif 'sub3' in self.caseName:
            self.assertTrue(1 <= world.h <= 8)
            self.assertTrue(1 <= world.w <= 8)
        elif 'sub4' not in self.caseName:
            self.fail(f"Invalid case name: {self.caseName}")



if __name__ == '__main__':
    kareltest.main()