#!/usr/bin/python3
# -*- coding: utf-8 -*-

from libkarel import kareltest


class Test(kareltest.TestCase):
    # pylint: disable=too-many-statements
    def test(self):
        world = self.world

        # Karel inicia pegado a la figura.
        if world.direccion == 'NORTE':
            self.assertTrue(int(world.paredes(world.x, world.y)) & 4)
        elif world.direccion == 'OESTE':
            self.assertTrue(int(world.paredes(world.x, world.y)) & 2)
        elif world.direccion == 'SUR':
            self.assertTrue(int(world.paredes(world.x, world.y)) & 1)
        elif world.direccion == 'ESTE':
            self.assertTrue(int(world.paredes(world.x, world.y)) & 8)

        # Karel tiene infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, 'INFINITO')

        # Solo se evalúa la posición final de Karel.
        self.assertEqual(world.despliega, ['MUNDO'])


if __name__ == '__main__':
    kareltest.main()
