#!/usr/bin/python3
# -*- coding: utf-8 -*-

from collections import Counter
from libkarel import kareltest


class Test(kareltest.TestCase):
    def test(self):
        world = self.world

        # Karel inicia en la posición (1, 1) orientado al norte.
        self.assertEqual(world.x, 1, "Karel debe iniciar en (1, 1)")
        self.assertEqual(world.y, 1, "Karel debe iniciar en (1, 1)")
        self.assertEqual(world.direccion, "NORTE",
                         "Karel debe iniciar orientado al norte")

        # El mundo de Karel es un rectángulo sin paredes internas.
        self.assertTightWorldSize()
        self.assertNoInnerWalls()
        self.assertEqual(world.h, 100, "Alto != 100")
        self.assertEqual(world.w, 100, "Ancho != 100")

        # Solo importan los zumbadores que dejes en la casilla (1, 1).
        self.assertEqual(world.despliega, ["MUNDO"])
        self.assertEqual(world.lista_dump, {(1, 1)})

        # Karel lleva infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, "INFINITO",
                         "La mochila debe tener infinitos zumbadores")

        # El numero de zumbadores en cada fila debe ser par.
        beepers = world.lista_zumbadores
        maximo = {}
        for (x, y) in beepers.keys():
            if y not in maximo or maximo[y] < x:
                maximo[y] = x
        self.assertTrue(all(m % 2 == 0 for m in maximo.values()),
                        "Las palabras deben ser de largo par")

        if "sub1" in self.caseName:
            # Solo vale la letra 1.
            beepers = Counter(world.lista_zumbadores.values())
            self.assertEqual(len(beepers), 1,
                             "Solo se permite una letra")
            self.assertEqual(world.zumbadores(1, 1), 1,
                             "Solo se permite la letra 1")
        elif "sub2" in self.caseName:
            # Las letras impares deben ser "1" y las demas de "2" a "9".
            beepers = world.lista_zumbadores
            for (x, y) in beepers.keys():
                if x % 2 == 1:
                    self.assertEqual(world.zumbadores(x, y), 1,
                                     "Zumbador 1 en posicion impar")
                else:
                    self.assertTrue(2 <= world.zumbadores(x, y) <= 9,
                                    "Zumbadores 2 a 9 en posicion par")
        elif "sub3" in self.caseName:
            # Todas las parejas deben ser distintas
            beepers = world.lista_zumbadores
            parejas = []
            for (x, y) in beepers.keys():
                if x % 2 == 1:
                    parejas.append(world.zumbadores(x, y) * 10 +
                                   world.zumbadores(x + 1, y))
            sparejas = Counter(parejas)
            self.assertEqual(len(parejas), len(sparejas),
                             "Todas las parejas deben ser distintas")
        elif "sub4" in self.caseName:
            pass
        else:
            self.fail(f"Nombre de caso inválido: {self.caseName}")


if __name__ == '__main__':
    kareltest.main()
