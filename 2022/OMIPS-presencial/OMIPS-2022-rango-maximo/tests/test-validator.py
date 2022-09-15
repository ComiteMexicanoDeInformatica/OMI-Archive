#!/usr/bin/python3
# -*- coding: utf-8 -*-

from libkarel import kareltest


class Test(kareltest.TestCase):
    def test(self):
        world = self.world

        # Karel empieza en la (1, 1) orientado al norte.
        self.assertEqual(1, world.y)
        self.assertEqual(1, world.x)
        self.assertEqual(world.direccion, "NORTE")

        # Karel lleva infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, "INFINITO")

        # El mundo es de 100 x 100.
        self.assertEqual(100, world.h)
        self.assertEqual(100, world.w)

        # No hay paredes internas en el mundo.
        self.assertTightWorldSize()
        self.assertNoInnerWalls()

        # Los montones de zumbadores tienen valores entre 1 y 100.
        K = world.zumbadores(1, 2)
        beepers = []
        self.assertTrue(1 <= K <= 100)
        for x in range(1, 101):
            k = world.zumbadores(x, 1)
            if k == 0:
                break
            self.assertTrue(1 <= k <= 100)
            beepers.append(k)

        # No hay espacios entre los zumbadores de la primera línea.
        self.assertEqual(len(beepers) + 1, len(world.lista_zumbadores))

        # Solo importan los zumbadores que dejes en la (1,1).
        self.assertEqual(world.despliega, ["MUNDO"])
        self.assertEqual(world.lista_dump, {(1, 1)})

        if "sub1" in self.caseName:
            # Todos los números de la lista son menores o iguales a K.
            for k in beepers:
                self.assertTrue(k <= K)
        elif "sub2" in self.caseName:
            # K = 1
            self.assertEqual(K, 1)
        elif "sub3" in self.caseName:
            # Todos los números de la lista son distintos.
            self.assertEqual(len(beepers), len(set(beepers)))
        elif "sub4" in self.caseName:
            # Sin restricciones adicionales.
            pass
        else:
            self.fail(f"Nombre de caso inválido: {self.caseName}")


if __name__ == '__main__':
    kareltest.main()
