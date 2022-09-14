#!/usr/bin/python3
# -*- coding: utf-8 -*-

from libkarel import kareltest


class Test(kareltest.TestCase):
    def test(self):
        world = self.world

        # Las únicas paredes en el mundo son las que lo delimitan.
        self.assertTightWorldSize()
        self.assertNoInnerWalls()

        # Karel tiene infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, 'INFINITO',
                         'La mochila debe tener infinitos zumbadores')

        # Solo importan los zumbadores que dejes en la casilla (1,1).
        self.assertEqual(world.despliega, ['MUNDO'])
        self.assertEqual(world.lista_dump, set([(1, 1)]))

        if 'sub1' in self.caseName:
            # Karel empieza en la (1, 1) y el mundo tiene altura 1.
            self.assertStartAt11()
            self.assertEqual(1, world.h, 'El mundo debe tener altura 1')
        elif 'sub2' in self.caseName:
            # Karel empieza en la (1, 1), no hay límite de avanza / move y a lo
            # más hay un niño por cada casilla.
            self.assertStartAt11()
            self.assertMoveLimits(False)
            self.assertAtMost1BeeperPerCell()
        elif 'sub3' in self.caseName:
            # Karel empieza en la (1, 1), no hay límite de avanza / move y
            # puede haber cualquier cantidad de niños en una misma casilla.
            self.assertStartAt11()
            self.assertMoveLimits(False)
        elif 'sub4' in self.caseName:
            # Karel empieza en la (1, 1), puedes llamar avanza / move a lo más
            # 2 x A veces y a lo más hay un niño por cada casilla.
            self.assertStartAt11()
            self.assertMoveLimits(True)
            self.assertAtMost1BeeperPerCell()
        elif 'sub5' in self.caseName:
            # Karel empieza en la (1, 1), puedes llamar avanza / move a lo más
            # 2 x A veces y puede haber cualquier cantidad de niños en una
            # misma casilla.
            self.assertStartAt11()
            self.assertMoveLimits(True)
        elif 'sub6' in self.caseName:
            # Karel inicia en cualquier posición, no hay límite de
            # avanza / move.
            self.assertMoveLimits(False)
        elif 'sub7' in self.caseName:
            # Karel inicia en cualquier posición, puedes llamar avanza / move a
            # lo más 2 x A veces.
            self.assertMoveLimits(True)
        else:
            self.fail(f"Nombre de caso inválido: {self.caseName}")

    def assertStartAt11(self):
        world = self.world
        self.assertEqual(1, world.y, 'Karel debe iniciar en (1, 1)')
        self.assertEqual(1, world.x, 'Karel debe iniciar en (1, 1)')

    def assertMoveLimits(self, limited):
        world = self.world
        if limited:
            self.assertEqual(world.limite_comando("AVANZA"), 2*world.w*world.h,
                             'El límite de llamadas a "AVANZA" debe ser 2 x A')
        else:
            self.assertTrue(world.limite_comando("AVANZA") is None,
                            'No debe haber límite de "AVANZA"')

    def assertAtMost1BeeperPerCell(self):
        world = self.world
        beepers = world.lista_zumbadores
        for k in beepers.values():
            self.assertEqual(1, k, 'A lo más un beeper por casilla')


if __name__ == '__main__':
    kareltest.main()
