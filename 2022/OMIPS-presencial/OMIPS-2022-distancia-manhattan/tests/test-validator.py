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
        self.assertEqual(world.mochila, "INFINITO")

        # Solo importan los zumbadores que dejes donde empieza Karel.
        self.assertEqual(world.despliega, ["MUNDO"])
        self.assertEqual(world.lista_dump, {(world.x, world.y)})

        # Hay un único zumbador que representa la casa de Darel.
        beepers = world.lista_zumbadores
        self.assertEqual(len(beepers), 1)
        self.assertEqual(list(beepers.values())[0], 1)

        if "sub1" in self.caseName:
            # Karel empieza en la (1, 1) viendo al norte.
            self.assertEqual(1, world.y)
            self.assertEqual(1, world.x)
            self.assertEqual(world.direccion, "NORTE")
        elif "sub2" in self.caseName:
            # La casa de Darel está en la misma fila o columna.
            xDarel, yDarel = list(beepers.keys())[0]
            self.assertTrue(world.x == xDarel or world.y == yDarel)
        elif "sub3" in self.caseName:
            # Sin restricciones adicionales.
            pass
        else:
            self.fail(f"Nombre de caso inválido: {self.caseName}")


if __name__ == '__main__':
    kareltest.main()
