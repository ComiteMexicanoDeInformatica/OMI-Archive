#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import os

import libkarel
from kareltest import *

class Test(KarelTest):
    def test(self):
        world = self.world

        self.assertEqual(world.mochila, 'INFINITO')

        self.assertEqual(world.lista_zumbadores, {})

        self.assertEqual(world.despliega, ['ORIENTACION'])

Test().run()
