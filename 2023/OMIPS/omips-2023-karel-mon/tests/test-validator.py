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

        # Sólo habrá zumbadores en la fila 1 y 2 del mundo.
        beepers = world.lista_zumbadores
        self.assertTrue(all(y <= 2 for (x, y) in beepers.keys()),
                        "Solo puede haber zumbadores en filas 1 y 2")

        # Los montones pueden tener entre 1 y 100 zumbadores.
        beepers = list(world.lista_zumbadores.values())
        self.assertTrue(all(1 <= k <= 100 for k in beepers),
                        "Los montones deben tener entre 1 y 100 zumbadores")

        # Solo importa la orientacion final de Karel
        self.assertEqual(world.despliega, ["ORIENTACION"])

        if "sub1" in self.caseName:
            # El mazo 1 solo tiene una carta
            self.assertTrue(world.zumbadores(1, 1) > 0,
                            "Mazo 1 debe tener 1 carta")
            self.assertTrue(world.zumbadores(2, 1) == 0,
                            "Mazo 1 maximo 1 carta")
        elif "sub2" in self.caseName:
            # Ambos jugadores tienen 2 mazos en sus cartas.
            self.assertEqual(len(beepers), 4, "Solo puede haber zumbadores")
            self.assertTrue(world.zumbadores(1, 3) == 0,
                            "3 cartas en el mazo 1")
            self.assertTrue(world.zumbadores(2, 3) == 0,
                            "3 cartas en el mazo 2")
        elif "sub3" in self.caseName:
            # Los dos mazos tienen las mismas cartas
            m1 = []
            m2 = []
            for (x, y) in world.lista_zumbadores:
                if y == 1:
                    m1.append(world.zumbadores(x, y))
                else:
                    m2.append(world.zumbadores(x, y))
            m1.sort()
            m2.sort()
            self.assertEqual(len(m1), len(m2),
                             "Mazos no miden lo mismo")
            self.assertTrue(all(m1[i] == m2[i] for i in range(len(m1))),
                            "Mazos no son iguales")
        elif "sub4" in self.caseName:
            # Los mazos tienen todas sus cartas distintas
            m1 = []
            m2 = []
            for (x, y) in world.lista_zumbadores:
                if y == 1:
                    m1.append(world.zumbadores(x, y))
                else:
                    m2.append(world.zumbadores(x, y))
            c1 = Counter(m1)
            c2 = Counter(m2)
            self.assertEqual(len(m1), len(c1),
                             "Cartas de m1 no son distintas")
            self.assertEqual(len(m2), len(c2),
                             "Cartas de m2 no son distintas")
        elif "sub5" in self.caseName:
            pass
        else:
            self.fail(f"Nombre de caso inválido: {self.caseName}")


if __name__ == '__main__':
    kareltest.main()
