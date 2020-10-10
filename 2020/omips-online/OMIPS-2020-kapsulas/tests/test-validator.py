#!/usr/bin/python3
# -*- coding: utf-8 -*-
import sys
import os

import libkarel
from collections import defaultdict
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

        # Los montones de zumbadores pueden ser entre 1 y 15.
        self.assertTrue(all(
            1 <= int(v) <= 15
            for k, v in world.lista_zumbadores.items()
        ))

        # Ancho del mundo va de 1 a 40
        self.assertTrue(1 <= world.w <= 40)

        # Altura del mundo va de 1 a 40
        self.assertTrue(1 <= world.w <= 40)

        # El mundo siempre es rectangular.
        self.assertEqual(
            len(self.reachableCells()),
            world.w * world.h
        )

        # Se evalúa el estado de todo el mundo.
        # No importa la posición ni orientación final de Karel.
        self.assertEqual(world.despliega, ['UNIVERSO'])

        # Ningún cuadro se sale del mundo
        self.assertTrue(all(
            1 <= k[0] - int(v) and
            k[0] + int(v) <= world.w and
            1 <= k[1] - int(v) and
            k[1] + int(v) <= world.h
            for k, v in world.lista_zumbadores.items()
        ))

        # las capsulas no se intersectan en la subtarea fácil
        if 'easy' in self.caseName:
            matrix = defaultdict(int)
            for k,v in world.lista_zumbadores.items():
                for i in range(k[0]-int(v), k[0]+int(v)):
                    for j in range(k[1]-int(v), k[1]+int(v)):
                        matrix[i,j] += 1

            self.assertTrue(all(
                v in (0,1)
                for k, v in matrix.items()
            ))

Test().run()
