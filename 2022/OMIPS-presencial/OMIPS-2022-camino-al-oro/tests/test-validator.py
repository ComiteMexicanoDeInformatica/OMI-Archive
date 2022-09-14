#!/usr/bin/python3
# -*- coding: utf-8 -*-

from libkarel import kareltest


class Test(kareltest.TestCase):
    # pylint: disable=too-many-statements
    def test(self):
        world = self.world

        # Karel inicia en la casilla (1,1) viendo al este.
        self.assertEqual(1, world.y)
        self.assertEqual(1, world.x)
        self.assertEqual(world.direccion, 'ESTE')

        # Karel lleva infinitos zumbadores
        self.assertEqual(world.mochila, 'INFINITO',
                         'La mochila debe tener infinitos zumbadores')

        # No hay paredes internas.
        self.assertNoInnerWalls()

        # Solo se despliegan las casillas (1, 1) y (2, 1)
        self.assertEqual(world.despliega, ['AVANZA', 'MUNDO'])
        self.assertEqual(world.lista_dump, set([(1, 1)]))

        # Verifica que haya zumbadores en la posicion inicial de Karel
        A = world.zumbadores(1, 1)
        self.assertTrue(A > 0)

        # Verifica que se cumplan condiciones para cada Subtarea


if __name__ == '__main__':
    kareltest.main()
