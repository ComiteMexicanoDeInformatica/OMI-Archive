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

        # Solo importan los zumbadores que dejes en la casilla (1,1)
        self.assertEqual(world.despliega, ['MUNDO'])
        self.assertEqual(world.lista_dump, set([(1, 1)]))

        # Todos los montones son entre 1 y 99, en caso de K = 0 no aparecerá en la lista
        self.assertTrue(all(1 <= int(v) <= 99 for k, v in world.lista_zumbadores.items()))

        # El valor de k es 0 u 1 en los primeros 3 subcasos
        if 'sub1' in self.caseName:
            self.assertEqual(0, world.zumbadores(1, 2))
        elif 'sub2' in self.caseName or 'sub3' in self.caseName:
            self.assertEqual(1, world.zumbadores(1, 2))

        # No existen valores repetidos en la primera fila
        if 'sub2' in self.caseName or 'sub4' in self.caseName:
            repeated = set()
            for k, v in world.lista_zumbadores.items():
                if int(k[1]) != 2:
                    self.assertTrue(int(v) not in repeated)
                    repeated.add(int(v))

        # No existen espacios vacíos en la primera fila
        flag = True
        for x in range(1, 100):
            if flag:
                flag = bool(world.zumbadores(x, 1) != 0)
            else:
                self.assertEqual(0, world.zumbadores(x, 1))


if __name__ == '__main__':
    kareltest.main()
