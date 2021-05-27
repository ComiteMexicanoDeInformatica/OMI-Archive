#!/usr/bin/python3
# -*- coding: utf-8 -*-
import sys
import os
import collections

import libkarel
from libkarel import kareltest


class Test(kareltest.TestCase):
    def test(self):
        world = self.world

        # Las únicas paredes en el mundo son las que lo delimitan.
        self.assertTightWorldSize()
        self.assertNoInnerWalls()

        # Karel inicia en la casilla (1,1) viendo al norte.
        self.assertEqual(1, world.y)
        self.assertEqual(1, world.x)
        self.assertEqual(world.direccion, 'NORTE')

        # Karel tiene infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, 'INFINITO')

        # El tamaño del mundo es de 100x100
        self.assertEqual(world.h, 100)
        self.assertEqual(world.w, 100)

        N = world.zumbadores(1, 1)
        K = world.zumbadores(2, 1)

        self.assertLessEqual(2, K)
        self.assertLessEqual(K, N)
        self.assertLessEqual(N, 100)

        # Las montañas son de 1 a 100 de altura
        self.assertTrue(
            all(1 <= int(world.zumbadores(x, 2)) <= 100
                for x in range(1, N + 1)))

        #Se asegura que la respuesta siempre será mayor o igual a 0.
        #los numeros no están ordenados decrecientemente
        self.assertTrue(
            any(
                world.zumbadores(x, 2) < world.zumbadores(x + 1, 2)
                for x in range(1, N)))

        self.assertEqual(world.despliega, ['MUNDO'])
        if 'st1' in self.caseName:
            #los numeros estan ordenandos
            self.assertTrue(
                all(
                    world.zumbadores(x, 2) <= world.zumbadores(x + 1, 2)
                    for x in range(1, N)))
            self.assertIsNone(world.limite_comando("AVANZA"))
        elif 'st2' in self.caseName:
            self.assertIsNone(world.limite_comando("AVANZA"))
        elif 'st3' in self.caseName:
            # Karel puede avanzar a lo más $7*N$ veces.
            self.assertEqual(world.limite_comando("AVANZA"), 8 * N)
        else:
            self.fail(f"Invalid case name: {self.caseName}")


if __name__ == '__main__':
    kareltest.main()
