#!/usr/bin/python3
# -*- coding: utf-8 -*-
import sys
import os
import collections
import logging

import libkarel
from libkarel import kareltest


class Test(kareltest.TestCase):
    def test(self):
        world = self.world

        #Las únicas paredes en el mundo son las que lo delimitan.
        self.assertTightWorldSize()
        self.assertNoInnerWalls()

        #Karel empieza pegado a la pared
        self.assertTrue(world.x == 1 or
                        world.x == world.w or
                        world.y == 1 or
                        world.y == world.h)
        
        # Karel empieza con frente libre
        frente_dict = {
            "NORTE": libkarel.Direccion.NORTE,
            "ESTE": libkarel.Direccion.ESTE,
            "SUR": libkarel.Direccion.SUR,
            "OESTE": libkarel.Direccion.OESTE
        }

        kdir = frente_dict[world.direccion]
        self.assertFalse(world.paredes(world.x, world.y) & kdir)

        # Karel empieza con la derecha bloqueada
        der_dict = {
            "NORTE": libkarel.Direccion.ESTE,
            "ESTE": libkarel.Direccion.SUR,
            "SUR": libkarel.Direccion.OESTE,
            "OESTE": libkarel.Direccion.NORTE
        }
        kdir = der_dict[world.direccion]
        self.assertTrue(world.paredes(world.x, world.y) & kdir)

        # Karel tiene $2(N+M-2)$ en la mochila.
        self.assertEqual(world.mochila, 2 * (world.h + world.w - 2))
        # $2 \le N,M \le 100$
        self.assertTrue(2 <= world.h <= 100)
        self.assertTrue(2 <= world.w <= 100)

        # No hay zumbadores en el mundo
        self.assertEqual(len(world.lista_zumbadores), 0)

        # Solo se evalua la posición final de Karel.
        self.assertEqual(world.despliega, ['POSICION'])


if __name__ == '__main__':
    kareltest.main()
