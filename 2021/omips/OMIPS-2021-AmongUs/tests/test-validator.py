#!/usr/bin/python3
# -*- coding: utf-8 -*-
import sys
import os
import collections
import logging
import math

import libkarel
from libkarel import kareltest


class Test(kareltest.TestCase):

    def test(self):
        world = self.world

        #Karel inicia en la casilla (1,1) viendo al norte.
        self.assertEqual(1, world.y)
        self.assertEqual(1, world.x)
        self.assertEqual(world.direccion, 'NORTE')

        #Karel tiene infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, 'INFINITO')

        #No paredes internas
        #self.assertNoInnerWalls()

        # Solo se evalúa la posición final de Karel
        self.assertEqual(world.despliega, ['POSICION'])

        # Asegurar que haya al menos 3 amigos de Karel
        self.assertTrue(len(world.lista_zumbadores) >= 3)

        #Verificar que en realidad si exista solo un impostor
        beepers = world.lista_zumbadores
        cand = 0 #cantidad candidatos a impostores
        reach = 0 #cuantos alcanza el impostor

        #Para cada posible impostor (x,y) verificar que para cada amigo (p,q) esten a distancia v
        for (x,y),z in beepers.items():
            cant = 0
            cantI = 0
            for (p,q), v in beepers.items():
                if (x,y) is not (p,q):
                    if abs(x-p) + abs(y-q) == v:
                        cant+=1
                    if abs(x-p) + abs(y-q) == z:
                        cantI+=1
            if cant == len(beepers)-1:
                cand+=1
                reach = cantI
        
        self.assertEqual(cand, 1)

        #Verificar que se cumplan condiciones para cada subtarea

        if 'sub1' in self.caseName:
            #subtarea 1 mundo de alto 1, el impostor dice distancia a la que no hay ningun otro jugador y las distancias reportadas por 
            # los jugadores y por el impostor nunca te llevan a una posicion fuera del patio de la escuela
            self.assertEqual(world.h, 1)
            self.assertEqual(reach, 0)
            for (x,y), v in beepers.items():
                self.assertFalse(x - v <= 0 or x + v > world.w)
        elif 'sub2' in self.caseName:
            #subtarea 2 mundo alto 1
            self.assertEqual(world.h, 1)
        elif 'sub3' in self.caseName:
            #subtarea 3 No hay jugador en la distancia reportada por el impostor
            self.assertEqual(reach, 0)
        elif 'sub4' in self.caseName:
            #Las distancias reportadas por los jugadores y por el impostor nunca te llevan
            #a una posicion fuera del patio de la escuela
            for (x,y), v in beepers.items():
                self.assertFalse(x - v <= 0 or x + v > world.w or y - v <= 0 or y + v > world.h)
        elif not 'sub5' in self.caseName:
            self.fail(f"Invalid case name: {caseName}")



if __name__ == '__main__':
    kareltest.main()