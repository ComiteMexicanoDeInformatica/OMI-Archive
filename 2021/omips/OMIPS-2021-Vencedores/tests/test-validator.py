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

        # Revisa que despliegue los zumbadores
        self.assertEqual(world.despliega, ['MUNDO'])

        # Todos los montones son entre 1 y 99
        self.assertTrue(
            all(1 <= int(v) <= 99 for k, v in world.lista_zumbadores.items()))

        # No puede haber espacios entre montones
        flag = False
        N = 0
        for x in range(1, 101):
            if world.zumbadores(x, 1) == 0 and not flag:
                flag = True
            elif world.zumbadores(x, 1) > 0 and not flag:
                N += 1
            elif world.zumbadores(x, 1) > 0 and flag:
                self.fail(f"Hay espacios entre los montones: {self.caseName}")

        # En las subtareas 1 y 2 no debe haber repetidos
        if 'sub1' in self.caseName or 'sub2' in self.caseName:
            repeated = set()
            for k, v in world.lista_zumbadores.items():
                self.assertTrue(int(v) not in repeated)
                repeated.add(int(v))
                
        # En las subtareas 1 y 3 no se limitan los avanzas
        if 'sub1' in self.caseName or 'sub3' in self.caseName:
            self.assertIsNone(world.limite_comando("AVANZA"))
            
        # En las subtareas 2 y 4 los avanzas se limitan a 2N
        elif 'sub2' in self.caseName or 'sub4' in self.caseName:
            self.assertEqual(world.limite_comando("AVANZA"), 2 * N)

        if 'sub1' not in self.caseName and 'sub2' not in self.caseName and 'sub3' not in self.caseName and 'sub4' not in self.caseName:
            self.fail(f"Invalid case name: {self.caseName}")

if __name__ == '__main__':
    kareltest.main()
