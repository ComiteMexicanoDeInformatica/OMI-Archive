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
        if 'facil' in self.caseName:
            # Hay zumbadores en todas las casillas del mundo, excepto la primer fila y columna.
            a = (world.h-1) * (world.w-1)
        else:
            # Hay zumbadores en todas las casillas del mundo, excepto en la casilla 1,1.
            a = (world.h * world.w) -1

        self.assertEqual(len(zumbadores), a)
        self.assertEqual(zumbadores.get((1,1)), None)

        # Los montones de zumbadores pueden ser entre 1 y 1000.
        self.assertTrue(all(
            1 <= int(v) <= 1000
            for k, v in zumbadores.items()
        ))

        # Ancho del mundo va de 2 a 99
        self.assertTrue(2 <= world.w <= 99)

        # Se evalua solo el número de zumbadores en la casilla 1,1.
        self.assertEqual(world.despliega, ['MUNDO'])

        # La subtarea 1 es solo una fila.
        if 'fila' in self.caseName:
            # Altura del mundo es 1
            self.assertEqual(world.h, 1)
        else:
            # Altura del mundo va de 1 a 99
            self.assertTrue(1 <= world.h <= 99)


Test().run()
