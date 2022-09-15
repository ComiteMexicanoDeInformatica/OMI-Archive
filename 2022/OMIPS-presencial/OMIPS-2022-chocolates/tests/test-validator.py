#!/usr/bin/python3
# -*- coding: utf-8 -*-

from libkarel import kareltest


class Test(kareltest.TestCase):
    # pylint: disable=too-many-statements
    def test(self):
        world = self.world

        # Karel inicia en la casilla (1,1) viendo al norte.
        self.assertEqual(1, world.y)
        self.assertEqual(1, world.x)
        self.assertEqual(world.direccion, 'NORTE')

        # Karel lleva infinitos zumbadores
        self.assertEqual(world.mochila, 'INFINITO',
                         'La mochila debe tener infinitos zumbadores')

        # No hay paredes internas.
        self.assertNoInnerWalls()

        # Solo se despliegan las casillas (1, 1) y (2, 1)
        self.assertEqual(world.despliega, ['MUNDO'])
        self.assertEqual(world.lista_dump, set([(1, 1), (2, 1)]))

        # Verifica los zumbadores del mundo
        self.assertEqual(len(world.lista_zumbadores), 3)

        A = world.zumbadores(1, 1)
        B = world.zumbadores(2, 1)
        P = world.zumbadores(3, 1)
        self.assertTrue(A > 0)
        self.assertTrue(B > 0)
        self.assertTrue(P > 0)

        # Verifica que se cumplan condiciones para cada Subtarea
        if 'sub1' in self.caseName:
            # A + B = P
            self.assertEqual(A + B, P)

        elif 'sub2' in self.caseName:
            # A, B < P
            self.assertTrue(A < P)
            self.assertTrue(B < P)

        elif 'sub3' in self.caseName:
            # P = 2
            self.assertEqual(P, 2)


if __name__ == '__main__':
    kareltest.main()
