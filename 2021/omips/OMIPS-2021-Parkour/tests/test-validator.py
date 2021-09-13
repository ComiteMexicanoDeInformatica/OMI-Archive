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

        # El tamaño del mundo es de 100x100
        self.assertEqual(world.h, 100)
        self.assertEqual(world.w, 100)

        # Karel inicia en la casilla (1,1) viendo al norte.
        self.assertEqual(1, world.y)
        self.assertEqual(1, world.x)
        self.assertEqual(world.direccion, 'NORTE')

        # Karel tiene infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, 'INFINITO')

        # Se evalua solo el número de zumbadores en $1, 1$
        self.assertEqual(world.despliega, ['MUNDO'])
        self.assertEqual(world.lista_dump, {(1, 1)})

        X = world.zumbadores(1, 2)
        self.assertTrue(1 <= X <= 30)

        ans = 0
        N = 0
        maxDist = 0
        for x in range(1, world.h + 1):
            beep = world.zumbadores(x, 1)
            if(beep == 0):
                break
            N += 1
            self.assertTrue(beep > ans)
            self.assertTrue(beep <= 99)
            maxDist = max(maxDist, beep-ans)
            ans = beep

        self.assertTrue(N >= 2)

        if 'sub1' in self.caseName:
            self.assertEqual(X, 1)
            self.assertIsNone(world.limite_comando("AVANZA"))
        elif 'sub2' in self.caseName:
            self.assertTrue(maxDist <= 2*X)
            self.assertIsNone(world.limite_comando("AVANZA"))
        elif 'sub3' in self.caseName:
            self.assertIsNone(world.limite_comando("AVANZA"))
        elif 'sub4' in self.caseName:
            self.assertEqual(world.limite_comando("AVANZA"), 4 * N+2)
        else:
            self.fail(f"Invalid case name: {self.caseName}")


if __name__ == '__main__':
    kareltest.main()
