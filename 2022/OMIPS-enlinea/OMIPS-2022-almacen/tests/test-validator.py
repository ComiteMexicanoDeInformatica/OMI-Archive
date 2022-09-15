#!/usr/bin/python3
# -*- coding: utf-8 -*-

import collections
from typing import Deque, Set
from libkarel import kareltest
import libkarel


# Cuenta cuantas casillas libres hay (sin pasar por casillas con zumbador)
def libresCont(world) -> int:
    q: Deque[libkarel.Casilla] = collections.deque(
        ((world.x, world.y), ))
    visited: Set[libkarel.Casilla] = set()

    cont = 0
    while q:
        x, y = q.popleft()
        if (x, y) in visited:
            continue
        visited.add((x, y))
        cont += 1
        mask = world.paredes(x, y)

        if not mask & libkarel.Direccion.NORTE:
            if world.zumbadores(x, y + 1) == 0:
                q.append((x, y + 1))
        if not mask & libkarel.Direccion.SUR:
            if world.zumbadores(x, y - 1) == 0:
                q.append((x, y - 1))
        if not mask & libkarel.Direccion.ESTE:
            if world.zumbadores(x + 1, y) == 0:
                q.append((x + 1, y))
        if not mask & libkarel.Direccion.OESTE:
            if world.zumbadores(x - 1, y) == 0:
                q.append((x - 1, y))

    return cont


class Test(kareltest.TestCase):
    # pylint: disable=too-many-statements
    def test(self):
        world = self.world

        # Karel tiene infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, 'INFINITO')

        zumbadores = world.lista_zumbadores
        cajas = 0

        # Verifica que todos los montones, a exepción del de la
        # posicion de Karel, son de 1 zumbador
        for (x, y), v in zumbadores.items():
            cajas += 1
            self.assertTrue(v == 1 or (x == world.x and y == world.y),
                            'Montones distintos de 1')

        # Verifica que todas las casillas libres están conectadas
        cajas -= 1
        k = world.zumbadores(world.x, world.y)
        casillas = self.reachableCells()
        libres = libresCont(world)
        self.assertEqual(len(casillas), cajas + libres)

        # Verifica que la cantidad de casillas libres es mayor o igual a K
        self.assertTrue(libres >= k, 'Más cajas que casillas libres')

        # Verifica que se hace dump de todas las casillas
        self.assertEqual(world.despliega, ['UNIVERSO'], 'Condiciones')

        # Verificar condiciones para cada subtarea
        h = world.h
        w = world.w
        if 'sub1' in self.caseName:
            # Subtarea1: El mundo tiene altura 1
            self.assertEqual(h, 1, 'Subtarea 1')
            self.assertNoInnerWalls()

        if 'sub2' in self.caseName:
            # Subtarea2: El mundo es un pasillo de ancho 1
            for (x, y) in casillas:
                m = world.paredes(x, y)
                self.assertTrue(bin(m).count("1") > 1, 'Subtarea 2')

        if 'sub3' in self.caseName:
            # Subtarea3: No hay más zumbadores en el mundo
            self.assertEqual(cajas, 0, 'Subtarea 3')

        if 'sub4' in self.caseName:
            # Subtarea4: El mundo es un rectángulo
            self.assertNoInnerWalls()
            self.assertEqual(len(casillas), h * w, 'Subtarea 4')


if __name__ == '__main__':
    kareltest.main()
