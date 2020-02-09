#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import os

import libkarel
from kareltest import *

class Test(KarelTest):
    def test(self):
        world = self.world

        beepers = world.lista_zumbadores

        self.assertTightWorldSize()
        self.assertNoInnerWalls()

        self.assertTrue(world.h >= 2)

        self.assertEqual(world.x, 1)
        self.assertEqual(world.y, 1)
        self.assertEqual(world.direccion, 'NORTE')

        self.assertTrue(all(
            v != 'INFINITO'
            for v in beepers.values()
        ))

        ids = [int(v) for v in beepers.values()]

        # unique ids
        self.assertEqual(len(ids), len(set(ids)))

        # coords fit
        self.assertTrue(not ids or max(ids) <= world.w)

        self.assertEqual(world.mochila, 'INFINITO')

        self.assertEqual(
            world.despliega,
            ['MUNDO']
        )

        toCheck = [(x,y)
                   for x in range(1, world.w + 1)
                   for y in [1,2]]

        self.assertEqual(world.lista_dump, set(toCheck))

        if 'emptyrows' in self.caseName:
            self.assertTrue(all(
                not y in [1, 2]
                for _,y in beepers.keys()
            ))
        else:
            self.assertTrue(any(
                y in [1, 2]
                for _,y in beepers.keys()
            ))

Test().run()
