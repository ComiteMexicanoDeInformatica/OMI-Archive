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

        # Karel no tiene zumbadores en la mochila.
        self.assertEqual(world.mochila, 0)

        # El tamaño del mundo está entre 2 y 100
        self.assertTrue(2 <= world.h <= 100)
        self.assertTrue(2 <= world.w <= 100)

        # Solo importa la posición final de Karel.
        self.assertEqual(world.despliega, ['POSICION'])

        # Solo hay zumbadores en las primeras 2 columnas.
        self.assertTrue(all(
            1 <= k[0] <= 2
            for k, v in world.lista_zumbadores.items()
        ))

        maxY = 0
        for y in range (1, world.h+1):
            if world.zumbadores(1,y) > 0:
                # las instrucciones solo pueden ser 1,2,3,4.
                self.assertTrue(1 <= world.zumbadores(1,y) <= 4)

                # siempre hay pasos para una dirección
                self.assertGreater(world.zumbadores(2,y),0)

                if y > maxY:
                    maxY = y

        # no hay espacios entre instrucciones
        self.assertTrue(all(
            world.zumbadores(1,y) > 0 and
            world.zumbadores(2,y) > 0
            for y in range(1, maxY+1)
        ))


        # ninguna instrucción te hace chocar con pared
        # 1 norte, 2 oeste, 3 sur, 4 este
        cx = 1
        cy = 1
        for y in range(1, maxY+1):
            d = world.zumbadores(1,y)
            s = world.zumbadores(2,y)
            if d == 2:
                cx -= s
            elif d == 4:
                cx += s
            elif d == 1:
                cy += s
            elif d == 3:
                cy -= s

            self.assertTrue(cx > 0 and cx <= world.w)
            self.assertTrue(cy > 0 and cy <= world.h)

        # Para la subtarea 1, solo hay pasos de tamaño 1.
        if 'st1' in self.caseName:
            self.assertTrue(all(
                world.zumbadores(2,y) == 1
                for y in range(1, maxY+1)
            ))
        elif 'st2' in self.caseName:
            # Para la subtarea 2, hay a lo más renglon de cada orientación.
            self.assertTrue(1 <= maxY <= 4)
            dirs = {1:0,2:0,3:0,4:0}
            for y in range(1, maxY+1):
                d = world.zumbadores(1,y)
                dirs[d] += 1

            for k in dirs.keys():
                self.assertTrue(0 <= dirs[k] <= 1)
        elif 'st3' not in self.caseName:
            self.fail(f"Invalid case name: {caseName}")


if __name__ == '__main__':
    kareltest.main()
