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

        # Verifica los zumbadores del mundo
        beepers = world.lista_zumbadores

        # Verifica que todos sean de tamaño 1 o 2
        for v in beepers.values():
            self.assertTrue(v in (1, 2), 'Distintos de 1 o 2')

        # Verifica que todos estén en la línea 1,
        # a partir de la columna 2
        # y que no hay espacios vacíos entre ellos
        cuenta = 0
        maxcol = 0
        for (col, fil), v in beepers.items():
            cuenta += 1
            maxcol = max(maxcol, col)
            self.assertEqual(fil, 1, 'Zumbadores fila != 1')
            self.assertTrue(col >= 2, 'Zumbador en la columna 1')
        self.assertTrue(maxcol - 1 == cuenta, 'Espacios')

        # Verifica que se hace dump de todas las posiciones
        # originalmente con zumbadores y la casilla (1, 1)
        self.assertEqual(world.despliega, ['MUNDO'], 'Condiciones')
        self.assertEqual(len(world.lista_dump), cuenta + 1)
        for (col, fil) in world.lista_dump:
            self.assertEqual(fil, 1)
            self.assertTrue(col <= maxcol)

        # Verificar condiciones para cada subtarea.
        if 'sub1' in self.caseName:
            # Subtarea 1: El mundo tiene altura 1
            self.assertEqual(world.h, 1, 'Altura !1')


if __name__ == '__main__':
    kareltest.main()
