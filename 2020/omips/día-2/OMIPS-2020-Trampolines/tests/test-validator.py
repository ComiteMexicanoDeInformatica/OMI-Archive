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

        #Karel inicia en la casilla (1,1) viendo al norte.
        self.assertEqual(1, world.y)
        self.assertEqual(1, world.x)
        self.assertEqual(world.direccion, 'NORTE')

        #Karel no tiene zumbadores en la mochila.
        self.assertEqual(world.mochila, 0)

        #Las únicas paredes en el mundo son las que lo delimitan.
        self.assertTightWorldSize()
        self.assertNoInnerWalls()

        self.assertTrue(all(
            0 <= int(v) <= 99 and #todos los montones son de 0 a 99 zumbadores
            k[1] != 1 #no hay zumbadores en la fila 1
            for k, v in world.lista_zumbadores.items()
        ))

        #Solo importan los zumbadores que dejes en la casilla (1,1)
        self.assertEqual(world.despliega, ['MUNDO'])
        self.assertEqual(world.lista_dump, set([(1, 1)]))

        #Todos los trampolines empiezan en la fila 2
        for x in range(1, world.w +1):
            if world.zumbadores(x,2) == 0:
                self.assertTrue(all(
                    world.zumbadores(x,y) == 0
                    for y in range(2,world.h+1)
                ))

        if 'easy' in self.caseName:
            for x in range(1, world.w +1):
                y = 2
                while (y < world.h) and world.zumbadores(x,y) > 0:
                    y2 = world.zumbadores(x,y)+y
                    if y2 >= world.h:
                        break

                    #si llega a una casilla vacía, validar que no hay zumbadores extras en la columna.
                    if world.zumbadores(x,y2) == 0:
                        self.assertTrue(all(
                            world.zumbadores(x,y3) == 0
                            for y3 in range(y+1,world.h+1)
                        ))

                    y = y2



if __name__ == '__main__':
    kareltest.main()
