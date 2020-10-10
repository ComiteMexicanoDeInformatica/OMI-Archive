#!/usr/bin/python3
# -*- coding: utf-8 -*-
import sys
import os
import collections
import logging

import libkarel
from libkarel import kareltest


class Test(kareltest.TestCase):
    def cellWallsCount(self, x, y):
        c = 0
        w = self.world.paredes(x, y)

        if w & libkarel.Direccion.NORTE:
            c += 1
        if w & libkarel.Direccion.SUR:
            c += 1
        if w & libkarel.Direccion.ESTE:
            c += 1
        if w & libkarel.Direccion.OESTE:
            c += 1

        return c

    def assertCorridor(self):
        cells = self.reachableCells()
        counters = collections.defaultdict(int)

        for x, y in cells:
            w = self.world.paredes(x, y)
            c = 0
            if (x, y + 1) in cells and (not w & libkarel.Direccion.NORTE):
                c += 1
            if (x, y - 1) in cells and (not w & libkarel.Direccion.SUR):
                c += 1
            if (x + 1, y) in cells and (not w & libkarel.Direccion.ESTE):
                c += 1
            if (x - 1, y) in cells and (not w & libkarel.Direccion.OESTE):
                c += 1

            counters[c] += 1

        self.assertEqual(2, counters[1])
        self.assertEqual(len(cells) - 2, counters[2])

    def test(self):
        world = self.world

        self.assertTightWorldSize()

        # Karel no tiene zumbadores en la mochila.
        self.assertEqual(world.mochila, 0)

        # Se evalúa la posición y orientación final de Karel.
        self.assertEqual(set(world.despliega), set(
            ['ORIENTACION', 'POSICION']))

        # El pasillo nunca se bifurcará.
        self.assertCorridor()

        dir_dict = {
            "NORTE": libkarel.Direccion.NORTE,
            "SUR": libkarel.Direccion.SUR,
            "ESTE": libkarel.Direccion.ESTE,
            "OESTE": libkarel.Direccion.OESTE
        }

        kdir = dir_dict[world.direccion]

        # Karel empieza con frente libre
        self.assertFalse(world.paredes(world.x, world.y) & kdir)

        # Karel empieza en un extremo del pasillo
        self.assertEqual(self.cellWallsCount(world.x, world.y), 3)

        # Sólo hay un zumbador en el mundo.
        self.assertEqual(len(world.lista_zumbadores), 1)

        # Altura del mundo va de 1 a 100
        self.assertTrue(1 <= world.h <= 100)

        # Ancho del mundo va de 1 a 100
        self.assertTrue(1 <= world.w <= 100)

        # no puede ser de 1x1
        self.assertFalse(world.w == world.h == 1)

        # Los cuartos no tienen el mismo tamaño
        # Los cuartos miden al menos 1 (el zumbador solamente es adyacente a 2 paredes)
        xbeep = list(world.lista_zumbadores.keys())[0][0]
        ybeep = list(world.lista_zumbadores.keys())[0][1]

        self.assertEqual(self.cellWallsCount(xbeep, ybeep), 2)

        cells = self.reachableCells()
        paredes = {
            libkarel.Direccion.NORTE: 0,
            libkarel.Direccion.SUR: 0,
            libkarel.Direccion.ESTE: 0,
            libkarel.Direccion.OESTE: 0
        }

        for x, y in cells:
            w = self.world.paredes(x, y)

            if w & libkarel.Direccion.NORTE:
                paredes[libkarel.Direccion.NORTE] += 1
            if w & libkarel.Direccion.SUR:
                paredes[libkarel.Direccion.SUR] += 1
            if w & libkarel.Direccion.ESTE:
                paredes[libkarel.Direccion.ESTE] += 1
            if w & libkarel.Direccion.OESTE:
                paredes[libkarel.Direccion.OESTE] += 1

        if 'straight' in self.caseName:
            s = libkarel.Direccion.SUR
            n = libkarel.Direccion.NORTE
            o = libkarel.Direccion.OESTE
            e = libkarel.Direccion.ESTE

            if (kdir & s) or (kdir & n):
                self.assertEqual(paredes[s] + paredes[n], 2)
            if (kdir & e) or (kdir & o):
                self.assertEqual(paredes[e] + paredes[o], 2)


if __name__ == '__main__':
    kareltest.main()
