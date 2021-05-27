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

        # Solo hay montones de 1 zumbador en el mundo
        self.assertTrue(
            all(0 <= int(v) <= 1 for k, v in world.lista_zumbadores.items()))

        # Se evalúa el estado del mundo.
        self.assertEqual(world.despliega, ['UNIVERSO'])

        if 'st3' in self.caseName:
            # Karel puede avanzar a lo más $2*N*M$ veces.
            self.assertEqual(world.limite_comando("AVANZA"),
                             2 * world.w * world.h)
        elif 'st2' in self.caseName:
            # Karel puede avanzar a lo más $8*N*M$ veces.
            self.assertEqual(world.limite_comando("AVANZA"),
                             8 * world.w * world.h)
        else:
            self.assertIsNone(world.limite_comando("AVANZA"))


if __name__ == '__main__':
    kareltest.main()
