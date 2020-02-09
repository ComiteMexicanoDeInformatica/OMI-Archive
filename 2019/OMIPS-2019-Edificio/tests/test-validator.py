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

        # Karel empieza en la fila más alta del mundo
        self.assertEqual(world.y, world.h)

        # Karel tiene infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, 'INFINITO')

        # Solo hay paredes horizontales
        self.assertTrue(all(
            not world.paredes(x+1, y+1) & libkarel.Direccion.ESTE
            for x in range(world.w-1)
            for y in range(world.h)
        ))


        # Karel puede llegar a la casilla (1,1)
        self.assertTrue((1, 1) in self.reachableCells())

        # Se evalua solo el número de zumbadores de la casilla (1,1)
        self.assertEqual(world.despliega, ['MUNDO'])
        self.assertEqual(world.lista_dump, set([(1,1)]))

        # No hay zumbadores en el mundo
        self.assertEqual(len(world.lista_zumbadores), 0)

Test().run()
