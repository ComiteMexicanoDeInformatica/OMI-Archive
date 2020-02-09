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
        self.assertNoInnerWalls()

        # Karel está en un mundo de 1xN
        self.assertEqual(world.h, 1)
        N = world.w

        # Karel empieza en (1,1) viendo al este.
        self.assertEqual(world.x, 1)
        self.assertEqual(world.y, 1)
        self.assertEqual(world.direccion, 'ESTE')

        # Karel no tiene zumbadores en la mochila
        self.assertEqual(world.mochila, 0)

        # Sólo importa cómo quedan todos los zumbadores del mundo
        self.assertEqual(world.despliega, ['UNIVERSO'])

        # Ninguna línea se sale del mapa
        beepers = world.lista_zumbadores

        def dir(x):
            if x % 2 == 1:
                return x-1
            else:
                return -(x-1)

        self.assertTrue(all(
            k[1] == 1 and # Los zumbadores están en la fila 1
            1 <= k[0] + dir(int(v)) <= N # No se salen las líneas
            for k, v in beepers.items()
        ))

        # Sólo hay zumbadores impares para la subtarea noEvenNumbers

        if 'noEvenNumbers' in self.caseName:
            self.assertTrue(all(
                int(v) % 2 == 1 # El montón de zumbadores es impar
                for k, v in beepers.items()
            ))

        # TODO: checar que el tag de avanza esté bien.

Test().run()
