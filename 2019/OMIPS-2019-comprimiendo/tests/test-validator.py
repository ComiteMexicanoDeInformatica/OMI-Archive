#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import os

import libkarel
from kareltest import *

class Test(KarelTest):
    def test(self):
        world = self.world
        self.assertTightWorldSize()
        N = world.h
        #El mundo siempre tiene que ser multiplo de 3
        self.assertEqual(N%3,0)

        # Karel empieza en (1,1) viendo al norte.
        self.assertEqual(world.x, 1)
        self.assertEqual(world.y, 1)
        self.assertEqual(world.direccion, 'NORTE')

        # Karel tiene infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, 'INFINITO')

        # Se evalúan todos los zumbadores del mundo
        self.assertEqual(world.despliega, ['UNIVERSO'])

        #valida que los zumbadores existan en la granja
        beepers = world.lista_zumbadores
        for i in range(1, world.w+1):
            for j in range(1, int(((world.h/3)*2)+1)):
                self.assertTrue(int(beepers.get((i,j), 0))>0)
                # Valida que las parejas sean iguales
                if j&1 :
                	self.assertTrue(int(beepers.get((i,j), 0)) == int(beepers.get((i,j+1), 0)))

        #valida que no haya zumbadores en la granja
        for i in range(1, world.w+1):
            for j in range(int(((world.h/3)*2)+1),world.h+1 ):
                self.assertTrue(int(beepers.get((i,j), 0))==0)
                	
        #Valida que no hay walls adicionales en el mundo, basta con checar la de  el norte y la del este y hasta n-1,m-1 para que no las confunda con las que delimitan el mundo
        for i in range(1, world.w+1):
            for j in range(1,world.h+1):
                if j!=int((world.h/3)*2):
                    if j!=world.h:
                        self.assertFalse(world.paredes(i,j) & libkarel.Direccion.NORTE)
                    if i!=world.w:
                        self.assertFalse(world.paredes(i,j) & libkarel.Direccion.ESTE)
        #valida que existe la wall
        for i in range(1,world.w):
           self.assertTrue(world.paredes(i,int(((world.h/3)*2))) & libkarel.Direccion.NORTE)

        #Valida que existe salida en el último punto de la wall
        self.assertFalse( world.paredes(world.w,int(((world.h/3)*2))) & libkarel.Direccion.NORTE)



                


Test().run()
