#!/usr/bin/python3
# -*- coding: utf-8 -*-

from libkarel import kareltest


class Test(kareltest.TestCase):
    def test(self):
        world = self.world

        # Karel lleva infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, "INFINITO",
                         "La mochila debe tener infinitos zumbadores")

        # Debe de haber solamente 2 montones
        beepers = world.lista_zumbadores
        self.assertEqual(len(beepers), 2, "hay mas de 2")

        # verificar que karel esta sobre un zumbador
        k = (0, 0)
        portal = (0, 0)
        for x, y in beepers.keys():
            if x == world.x and y == world.y:
                k = (x, y)
            else:
                portal = (x, y)

        self.assertTrue(k != (0, 0), 'No hay monton en donde karel')

        self.assertEqual(world.despliega, ["ORIENTACION", "MUNDO"])

        # zumbadores en portal.
        self.assertEqual(world.lista_dump, {portal})

        if "sub1" in self.caseName:
            # K debe ser impar
            self.assertTrue(world.zumbadores(k) % 2, 1,
                            "Zumbadores impares")
        elif "sub2" in self.caseName:
            self.assertTrue(world.h == 1 or world.w == 1,
                            "Ancho distinto de 1")
        elif "sub3" in self.caseName:
            self.assertTrue(world.h == 2 or world.w == 2,
                            "Ancho distinto de 1")
            self.assertNoInnerWalls()
        elif "sub4" in self.caseName:
            self.assertNoInnerWalls()
        elif "caso5" in self.caseName:
            self.assertEqual(k[0] != portal[0], "no estan en misma col")
        elif "caso6" in self.caseName:
            self.assertEqual(k[0] > portal[0] or k[1] > portal[1],
                             "no estan en cuadrante sup-der")
        elif "caso7" in self.caseName:
            self.assertEqual(k[1] >= portal[1], "no empieza al norte")
        elif "caso8" in self.caseName:
            pass

        else:
            self.fail(f"Nombre de caso inválido: {self.caseName}")


if __name__ == '__main__':
    kareltest.main()
