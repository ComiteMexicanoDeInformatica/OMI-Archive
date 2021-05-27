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

        self.assertTightWorldSize()

        # Karel inicia en la casilla (1,1) viendo al norte.
        self.assertEqual(1, world.y)
        self.assertEqual(1, world.x)
        self.assertEqual(world.direccion, 'NORTE')

        # Karel tiene infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, 'INFINITO')

        # El tamaño del mundo es de 100x100
        self.assertTrue(world.h == 100)
        self.assertTrue(world.w == 100)

        # Se evalúa el estado del mundo.
        self.assertEqual(world.despliega, ['MUNDO'])

        pared = 0
        for x in world.mapa_paredes.items():
            if x[0][0] > 0 and x[0][0] < 100 and x[0][1] == 1 and int(x[1]) & 4:
                # Solo debe haber una pared
                self.assertEqual(pared,0)
                pared = x[0][0]

        # La pared debe estar mínimo entre las columnas 1 y 2 y máximo entre las columnas 99 y 100.
        self.assertTrue(1 <= pared <= 99)

        # No debe haber casillas vacías en la llave
        for x in range(1, pared + 1):
            self.assertTrue(world.zumbadores(x,1) > 0)

        maxX = pared+1
        # No debe haber casillas vacías en medio de la palabra
        for x in range(pared+1, 101):
            if world.zumbadores(x, 1) > 0:
                maxX = max(x, maxX)

        for x in range(pared+1, maxX):
            self.assertTrue(world.zumbadores(x,1) > 0)

        beeperXSet = []
        keyLetters = {0}
        wordLetters = {0}
        farBeep = 1
        for x in world.lista_zumbadores.items():
            # Solo deben haber zumbadores en la fila inferior
            self.assertTrue(x[0][1] <= 1)
            beeperXSet.append(x[0][0])
            farBeep = max(farBeep, x[0][0])
            if x[0][0] <= pared:
                # No se deben repetir letras en la llave
                self.assertFalse(x[1] in keyLetters)
                keyLetters.add(x[1])
            else:
                wordLetters.add(x[1])
        self.assertEqual(len(beeperXSet), farBeep)

        if 'st1' in self.caseName or 'st2' in self.caseName:
            # Solo para la subtarea 3, en la palabra existen letras que no están en la llave.
            self.assertTrue(all(
                x in keyLetters
                for x in wordLetters
            ))
        if 'st1' in self.caseName:
            # Para la subtarea 1, solo hay dos letras en la llave.
            self.assertEqual(pared, 2)
        elif 'st2' in self.caseName:
            # Para la subtarea 2, solo hay hasta 10 letras diferentes.
            self.assertTrue(pared <= 10)
        else:
            self.assertTrue('st3' in self.caseName)
            


if __name__ == '__main__':
    kareltest.main()
