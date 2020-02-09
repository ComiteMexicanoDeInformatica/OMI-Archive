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

        #Karel no tiene zumbadores en la mochila
        self.assertEqual(world.mochila, 0)

        #Las únicas paredes en el mundo son las que lo delimitan.
        self.assertTightWorldSize()
        self.assertNoInnerWalls()

        # Sólo se evalúa la posición final de Karel
        self.assertEqual(world.despliega, ['POSICION'])

        #Hay al menos un zumbador por fila, y exactamente uno en la primera fila, cada monton con a lo mas N zumbadores
        for i in range(1, world.h):
            montones = 0
            for j in range(1, world.w + 1):
                if (j, i) in world.lista_zumbadores:
                    montones += 1
                    self.assertTrue(world.zumbadores(j, i)<= world.h)
            self.assertTrue(montones >= 1)
            if i == 1:
                self.assertEqual(1, montones)

        # Las pistas son validas
        pista = 1

        for i in range(1, world.w + 1):
            if (i, 1) in world.lista_zumbadores:
                pista = world.zumbadores(i, 1)
                break

        pistas = 1;
        for i in range(2, world.h):
            pista = world.zumbadores(pista, i)
            if pista > 0:
                pistas += 1
            else:
                break

        # hay menos pistas reales que el alto del mundo
        self.assertTrue(pistas < world.h)

Test().run()
