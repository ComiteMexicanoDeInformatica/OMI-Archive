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
        empty = 1

        #Verificar que existan beepers
        self.assertTrue(len(beepers) >= 1)

        #Verificar que todos los beepers esten en la fila 1 y esten en el rango de valor
        for (x,y),v in beepers.items():
            self.assertTrue(y == 1)
            self.assertTrue(1 <= v <= 99)

        #Verificar que esten contiguos los beepers e inicie en (1,1) los beepers
        for x in range(1,world.w+1):
            if (x,1) in beepers:
                self.assertEqual(empty, 1)
            else:
                empty = 0

        if 'sub1' in self.caseName:
            self.assertIsNone(world.limite_comando("AVANZA"))
        elif 'sub2' in self.caseName:
            self.assertEqual(world.limite_comando("AVANZA"), len(beepers))
        else :
            self.fail(f"Invalid case name: {self.caseName}")



if __name__ == '__main__':
    kareltest.main()