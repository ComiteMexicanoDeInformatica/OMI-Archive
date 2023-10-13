#!/usr/bin/python3
# -*- coding: utf-8 -*-

from collections import Counter
from libkarel import kareltest


class Test(kareltest.TestCase):
    def test(self):
        world = self.world

        # El mundo de Karel es un rectángulo sin paredes internas.
        self.assertTightWorldSize()
        self.assertNoInnerWalls()
        self.assertEqual(world.h, 100, "Alto != 100")
        self.assertEqual(world.w, 100, "Ancho != 100")

        # Karel inicia en la posición (1, 1) orientado al norte.
        self.assertEqual(world.x, 1, "Karel debe iniciar en (1, 1)")
        self.assertEqual(world.y, 1, "Karel debe iniciar en (1, 1)")
        self.assertEqual(world.direccion, "NORTE",
                         "Karel debe iniciar orientado al norte")

        # Karel lleva infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, "INFINITO",
                         "La mochila debe tener infinitos zumbadores")

        # Solo importan los zumbadores que dejes en las
        # casillas (1, 1) y (1, 2).
        self.assertEqual(world.despliega, ["MUNDO"])
        self.assertEqual(world.lista_dump, {(1, 1), (2, 1)})

        # Sólo habrá zumbadores en la fila 1 del mundo.
        beepers = world.lista_zumbadores
        self.assertTrue(all(y == 1 for (x, y) in beepers.keys()),
                        "Solo puede haber zumbadores en la fila 1")

        # Los montones de la fila 1 pueden tener entre 1 y 100 zumbadores.
        # No hay espacios vacíos entre los montones de zumbadores.
        self.assertTrue(all(1 <= z <= 100 for z in beepers.values()),
                        "Los montones deben tener entre 1 y 100 zumbadores")
        unicos = Counter(list(beepers.values()))
        if "sub1" in self.caseName:
            # Hay al menos una pareja de calcetines del mismo color
            self.assertTrue(len(beepers) != len(unicos),
                            "Debe haber una pareja de kalcetines iguales")
        elif "sub2" in self.caseName:
            # Los calcetines estan ordenados de menor a mayor
            self.assertTrue(all(world.zumbadores(1, x) <=
                                world.zumbadores(1, x + 1)
                                for x in range(len(beepers) - 1)),
                            "Zumbadores no van de menor a mayor")
        elif "sub3" in self.caseName:
            # Los calcetines de la solucion tienen diferencia de 1
            self.assertEqual(len(beepers), len(unicos),
                             "No puede haber kalcetines iguales")
            tmp = list(world.lista_zumbadores.values())
            tmp.sort()
            self.assertTrue(any(tmp[x] + 1 == tmp[x + 1]
                                for x in range(len(tmp) - 1)),
                            "Debe haber una pareja con diferencia 1")
        elif "sub4" in self.caseName:
            pass

        else:
            self.fail(f"Nombre de caso inválido: {self.caseName}")


if __name__ == '__main__':
    kareltest.main()
