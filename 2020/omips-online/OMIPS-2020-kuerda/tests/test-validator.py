#!/usr/bin/python3
# -*- coding: utf-8 -*-
import sys
import os
import collections

import libkarel
from kareltest import *

class Test(KarelTest):
    def test(self):
        world = self.world
        zumbadores = world.lista_zumbadores

        self.assertTightWorldSize()

        # No hay paredes internas en el mundo
        self.assertNoInnerWalls()

        # Karel empieza en la casilla (1,1) viendo al este.
        self.assertEqual(world.y, 1)
        self.assertEqual(world.x, 1)
        self.assertEqual(world.direccion, 'ESTE')

        # Karel tiene infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, 'INFINITO')

        # El mundo siempre es de 100x100
        self.assertEqual(world.h, 100)
        self.assertEqual(world.w, 100)

        n = world.zumbadores(1,2)
        # N se encuentra en 1,2. Puede ser de 1 a 20
        self.assertTrue(1 <= n <= 20)

        pCount = len(zumbadores) - 1
        # debe haber al menos N + 1 participantes y a lo mas 2N
        self.assertTrue(n+1 <= pCount <= 2*n)

        maxX = 0
        for k, v in zumbadores.items():
            # Solo N está en 1,2.
            if k[1] != 1:
                self.assertEqual(k[1], 2)
                self.assertEqual(k[0], 1)
                continue

            # El resto de los zumbadores sólo están en la fila 1
            self.assertEqual(k[1], 1)
            if k[0] > maxX:
                maxX = k[0]

        # No hay huecos entre concursantes
        self.assertEqual(maxX, pCount)

        izq = 0 #1 asciende, -1 desciende
        der = 0 #1 asciende, -1 desciende
        pivote = 0

        for i in range(1, n):
            if pivote != 0:
                break
            if world.zumbadores(i, 1) == world.zumbadores(i+1, 1):
                pivote = i+1
            elif world.zumbadores(i, 1) < world.zumbadores(i+1, 1):
                if izq == 0:
                    izq = 1
                elif izq == -1:
                    pivote = i+1
            elif world.zumbadores(i, 1) > world.zumbadores(i+1, 1):
                if izq == 0:
                    izq = -1
                elif izq == 1:
                    pivote = i+1

        # todo el equipo cumple ser de la izquierda
        if pivote == 0:
            pivote = n+1
            # el equipo de la derecha es minimo 1 y a lo mas N.
            self.assertTrue(1 <= maxX - pivote + 1 <= n)

        if pivote == maxX:
            der = 0
        elif world.zumbadores(pivote, 1) < world.zumbadores(pivote+1, 1):
            der = 1
        elif world.zumbadores(pivote, 1) > world.zumbadores(pivote+1, 1):
            der = -1

        # la direccion es 0 si el equipo mide 1.
        if izq == 0:
            self.assertEqual(pivote, 2)
        if der == 0:
            self.assertEqual(pivote, maxX)

        # en la subtarea 2N cada equipo mide N.
        if '2n' in self.caseName:
            self.assertEqual(pivote, n+1)

        # En esta subtarea los dos equipos van en la misma dirección.
        if 'samedir' in self.caseName and izq != 0 and der !=0:
            self.assertEqual(izq, der)

        # derecha desciende
        if der == -1:
            # Todas las fuerzas del equipo derecho están en orden descendente.
            self.assertTrue(all(
                world.zumbadores(x, 1) > world.zumbadores(x+1, 1)
                for x in range(pivote, maxX)
            ))
        # derecha asciende
        elif der == 1:
            # Todas las fuerzas del equipo derecho están en orden ascendente.
            self.assertTrue(all(
                world.zumbadores(x, 1) < world.zumbadores(x+1, 1)
                for x in range(pivote, maxX)
            ))

        # No existen dos jugadores con la misma fuerza en un equipo.
        left = [world.zumbadores(x, 1) for x in range(1, pivote)]
        self.assertEqual(len(left), len(set(left)))
        self.assertTrue(len(left) <= n)

        right = [world.zumbadores(x, 1) for x in range(pivote, maxX+1)]
        self.assertEqual(len(right), len(set(right)))
        self.assertTrue(len(right) <= n)

        # en la subtarea 2N cada equipo mide N.
        if '2n' in self.caseName:
            self.assertEqual(pCount, 2*n)
            self.assertEqual(len(left), n)
            self.assertEqual(len(right), n)

        # hay al menos un equipo de longitud N
        self.assertTrue(len(left) == n or len(right) == n)

        # Se evalua solo la orientación final de Karel.
        self.assertEqual(world.despliega, ['ORIENTACION'])

Test().run()
