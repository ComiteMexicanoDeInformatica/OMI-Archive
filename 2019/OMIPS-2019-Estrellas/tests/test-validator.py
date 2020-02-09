#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import os

import libkarel
from kareltest import *

class Test(KarelTest):
    def test(self):
        world = self.world
        self.assertTightWorldSize()

        # No paredes internas
        self.assertNoInnerWalls()

        # Karel empieza en (1,1) viendo al norte
        self.assertEqual(world.x, 1)
        self.assertEqual(world.y, 1)
        self.assertEqual(world.direccion, 'NORTE')

        # Karel tiene infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, 'INFINITO')

        # Primer coordenada arriba de Karel
        self.assertTrue((1, 1) in world.lista_zumbadores)

        #Mundo de 100 x 100
        self.assertTrue(world.w == 100)
        self.assertTrue(world.h == 100)

        # Se evalúan todos los zumbadores del mundo
        self.assertEqual(world.despliega, ['UNIVERSO'])

        # Coordenadas bien dadas y contiguas.
        zumb = 0
        for i in range(1, 101):
            if (i, 1) in world.lista_zumbadores:
                zumb += 1
                self.assertTrue((i, 2) in world.lista_zumbadores and (i, 3) in world.lista_zumbadores)
            else:
                break

        self.assertTrue(len(world.lista_zumbadores) % 3 == 0)
        self.assertEqual(len(world.lista_zumbadores) / 3, zumb)
        self.assertTrue(zumb <= 90)

        #Coordendas todas diferentes para nombre norestriction
        coord = set((0, 0, 0))

        if 'samez' in self.caseName:
            zumbadores = world.lista_zumbadores

            zs = [zumbadores.get((i, 3)) for i in range(0, len(zumbadores))]

            uniqueZs = [i for i in set(zs) if i is not None]

            self.assertTrue(len(uniqueZs) == 1)

        for i in range(1, zumb + 1):
            z = (world.zumbadores(i, 1), world.zumbadores(i, 2), world.zumbadores(i, 3))
            self.assertFalse(z in coord)
            coord.add(z)

            if 'samexyz' in self.caseName:
                xy = world.zumbadores(i, 1) == world.zumbadores(i, 2)
                yz = world.zumbadores(i, 2) == world.zumbadores(i, 3)

                self.assertTrue(xy and yz)

Test().run()
