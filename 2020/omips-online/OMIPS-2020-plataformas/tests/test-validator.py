#!/usr/bin/python3
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

        # Karel está en un mundo de NxM (2 <= N, M <= 99)
        self.assertTrue(2 <= world.h <= 99)
        self.assertTrue(2 <= world.w <= 99)

        # Karel empieza en (1,1) viendo al norte. No hay zumbadores en esa casilla
        self.assertEqual(world.x, 1)
        self.assertEqual(world.y, 1)
        self.assertEqual(world.zumbadores(1,1), 0)
        self.assertEqual(world.direccion, 'NORTE')

        # Hay infinitos zumbadores en la mochila
        self.assertEqual(world.mochila, 'INFINITO')

        # Cada monton es de zumbador 1
        beepers = world.lista_zumbadores
        self.assertTrue(all(
                int(v) == 1
                for k, v in beepers.items()
        ))

        # Validar que en cada fila hay una plataforma (hay al menos un zumbador y todos son adyacentes)
        n = world.h
        m = world.w

        for i in range(1, n+1):
            mini = 0
            maxi = 0

            for j in range(1, m+1):
                if world.zumbadores(j,i) != 0:
                    if mini==0:
                        mini = j
                    maxi = j

            self.assertTrue(mini > 0)

            for j in range(mini, maxi + 1):
                self.assertEqual(world.zumbadores(j,i), 1)

        # Se evalua solo el número de zumbadores de la casilla (1,1)
        self.assertEqual(world.despliega, ['MUNDO'])
        self.assertEqual(world.lista_dump, set([(1,1)]))

Test().run()
