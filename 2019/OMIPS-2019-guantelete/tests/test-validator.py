#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import os
import collections

import libkarel
from kareltest import *

class Test(KarelTest):
    def test(self):
        world = self.world

        #Karel inicia en la casilla (1,1) viendo al norte.
        self.assertEqual(1, world.y)
        self.assertEqual(1, world.x)
        self.assertEqual(world.direccion, 'NORTE')

        #Karel tiene infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, 'INFINITO')

        #Las únicas paredes en el mundo son las que lo delimitan.
        self.assertTightWorldSize()
        self.assertNoInnerWalls()

        #El mundo siempre medirá 100x100
        self.assertEqual(100, world.w)
        self.assertEqual(100, world.h)

        #Solo importan los zumbadores que dejes en la casilla (1,1)
        self.assertEqual(world.despliega, ['MUNDO'])
        self.assertEqual(world.lista_dump, set([(1,1)]))

        beepers = world.lista_zumbadores
        columnas = collections.defaultdict(set)
        bucket = collections.defaultdict(int)
        filas = collections.defaultdict(int)
        answer = set()

        #los zumbadores empiezan en la columna 2
        self.assertTrue(all(
            k[0] >= 2
            for k, v in beepers.items()
        ))

        for (x, y), v in beepers.items():
            columnas[x].add(v)
            filas[y] += 1
            bucket[v] += 1


        altura = len(next(iter(columnas.values())))
        n = len(columnas)

        for index, count in bucket.items():
            if (count == n):
                answer.add(index)

        #valida que no haya huecos
        self.assertTrue(all(filas[i] == n for i in range(1, altura + 1)))
        #todas las columnas son de la misma altura
        self.assertTrue(all(len(v) == altura for x, v in columnas.items()))
        #las columnas son de altura minimo 3
        self.assertTrue(altura >= 3)
        #hay almenos 3 columnas
        self.assertTrue(len(columnas) >= 3)
        #Hay al menos 2 intrusos diferentes
        self.assertEqual(len(answer), altura -1)
        #todas las columnas contienen todos los elementos de answer
        self.assertTrue(all(len(answer.difference(v)) == 0 for x, v in columnas.items()))

Test().run()
