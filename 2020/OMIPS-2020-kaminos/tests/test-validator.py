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

        # No hay paredes internas en el mundo
        self.assertNoInnerWalls()

        # Karel empieza en la casilla (1,1) viendo al norte.
        self.assertEqual(world.y, 1)
        self.assertEqual(world.x, 1)
        self.assertEqual(world.direccion, 'NORTE')

        # Karel tiene infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, 'INFINITO')

        zumbadores = world.lista_zumbadores
        # Hay zumbadores en todas las casillas del mundo.
        a = world.h * world.w
        self.assertEqual(len(zumbadores), a)

        # Los montones de zumbadores pueden ser entre 1 y 4.
        self.assertTrue(all(
            1 <= int(v) <= 4
            for k, v in zumbadores.items()
        ))

        # Ancho del mundo va de 2 a 99
        self.assertTrue(2 <= world.w <= 99)

        # Alto del mundo va de 2 a 99
        self.assertTrue(2 <= world.h <= 99)

        # Se evalua el estado de todo el mundo.
        self.assertEqual(world.despliega, ['UNIVERSO'])

Test().run()
