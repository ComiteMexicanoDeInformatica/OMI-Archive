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

        # Karel puede iniciar en cualquier lugar en cualquier direccion.

        # El tamaño del mundo está entre 1 y 100
        self.assertTrue(1 <= world.h <= 100)
        self.assertTrue(1 <= world.w <= 100)

        # Se evalua solo el número de zumbadores de la primera columna
        self.assertEqual(world.despliega, ['MUNDO'])
        toCheck = [(1,y) for y in range(1, world.h + 1)]
        self.assertEqual(world.lista_dump, set(toCheck))

        # la suma zumbadores en cada renglon no excede 99
        for y in range (1, world.h+1):
            n=0
            for x in range (1,world.w+1):
                n += world.zumbadores(x,y)
                self.assertTrue(n<100)

        # Solo hay paredes verticales
        self.assertTrue(all(
            not world.paredes(x+1, y+1) & libkarel.Direccion.NORTE
            for x in range(world.w)
            for y in range(world.h-1)
        ))

        #subtarea 1
        if 'st1' in self.caseName:
            self.assertEqual(world.mochila, 0)
            # Solo hay montones de 1 zumbador.
            self.assertTrue(all(
                0 <= int(v) <= 1
                for k, v in world.lista_zumbadores.items()
            ))
        #subtarea 2
        elif 'st2' in self.caseName:
            self.assertEqual(world.mochila, 0)
            renglonesConZumbadores = 0
            for y in range (1, world.h+1):
                for x in range (1,world.w+1):
                    if world.zumbadores(x,y) > 0:
                        renglonesConZumbadores += 1
                        break;
            self.assertEqual(renglonesConZumbadores,1)
        #subtarea 3
        elif 'st3' in self.caseName:
            self.assertEqual(world.mochila, 0)
            for y in range (1, world.h+1):
                montonesEnRenglon = 0
                for x in range (1,world.w+1):
                    if world.zumbadores(x,y) > 0:
                        montonesEnRenglon += 1
                self.assertTrue(montonesEnRenglon < 2)
        #subtarea 4
        elif 'st4' in self.caseName:
            self.assertEqual(world.mochila, 0)
        #subtarea 5
        elif 'st5' in self.caseName:
            self.assertEqual(world.mochila, 'INFINITO')
            # Solo hay montones de 1 zumbador.
            self.assertTrue(all(
                0 <= int(v) <= 1
                for k, v in world.lista_zumbadores.items()
            ))
        #subtarea 6
        elif 'st6' in self.caseName:
            self.assertEqual(world.mochila, 'INFINITO')
            renglonesConZumbadores = 0
            for y in range (1, world.h+1):
                for x in range (1,world.w+1):
                    if world.zumbadores(x,y) > 0:
                        renglonesConZumbadores += 1
                        break;
            self.assertEqual(renglonesConZumbadores,1)
        #subtarea 7
        elif 'st7' in self.caseName:
            self.assertEqual(world.mochila, 'INFINITO')
            for y in range (1, world.h+1):
                montonesEnRenglon = 0
                for x in range (1,world.w+1):
                    if world.zumbadores(x,y) > 0:
                        montonesEnRenglon += 1
                self.assertTrue(montonesEnRenglon < 2)
        #subtarea 8
        elif 'st8' in self.caseName:
            self.assertEqual(world.mochila, 'INFINITO')
        else:
            self.fail(f"Invalid case name: {caseName}")


if __name__ == '__main__':
    kareltest.main()
