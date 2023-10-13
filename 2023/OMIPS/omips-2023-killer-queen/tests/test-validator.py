#!/usr/bin/python3
# -*- coding: utf-8 -*-

from libkarel import kareltest


class Test(kareltest.TestCase):
    def test(self):
        world = self.world

        # El mundo de Karel es un cuadrado sin paredes internas.
        self.assertEqual(world.w, world.h, "El mundo debe ser cuadrado")
        self.assertTightWorldSize()
        self.assertNoInnerWalls()

        # Solo importan los zumbadores que dejes en la casilla (1, 1).
        self.assertEqual(world.despliega, ["MUNDO"])
        self.assertEqual(world.lista_dump, {(world.x, world.y)})

        # Hay un zumbador en la posicion inicial de Karel
        self.assertEqual(world.zumbadores(world.x, world.y), 1,
                         "Debe haber un zumbador en la posicion inicial")

        # Todos los montones deben de ser de 1 zumbador
        self.assertTrue(all(z == 1 for z in world.lista_zumbadores.values()),
                        "Los montones deben ser de 1 zumbador")

        fila = world.y
        columna = world.x
        diag1 = fila + columna
        diag2 = fila - columna

        if "sub1" in self.caseName:
            self.assertEqual(world.mochila, 1, "Karel debe llevar 1 zumbador")
            self.assertTrue(all(x == columna or y == fila
                                for (x, y) in world.lista_zumbadores.keys()),
                            "No estan en la misma fila o columna de la KQ")
        elif "sub2" in self.caseName:
            self.assertEqual(world.mochila, 1, "Karel debe llevar 1 zumbador")
        elif "sub3" in self.caseName:
            self.assertEqual(world.mochila, 0, "Karel debe llevar 0 zumbador")
            n = ne = e = se = s = so = o = no = 0
            for (x, y) in world.lista_zumbadores.keys():
                if x == columna and y == fila:
                    pass
                elif x == columna:
                    if y > fila:
                        n = n + 1
                    else:
                        s = s + 1
                elif y == fila:
                    if x > columna:
                        e = e + 1
                    else:
                        o = o + 1
                elif x + y == diag1:
                    if x > columna:
                        se = se + 1
                    else:
                        no = no + 1
                elif y - x == diag2:
                    if x > columna:
                        ne = ne + 1
                    else:
                        so = so + 1
            self.assertTrue(n < 2, "2 piezas al norte")
            self.assertTrue(ne < 2, "2 piezas al noreste")
            self.assertTrue(e < 2, "2 piezas al este")
            self.assertTrue(se < 2, "2 piezas al sureste")
            self.assertTrue(s < 2, "2 piezas al sur")
            self.assertTrue(so < 2, "2 piezas al suroeste")
            self.assertTrue(o < 2, "2 piezas al oeste")
            self.assertTrue(no < 2, "2 piezas al noroeste")
        elif "sub4" in self.caseName:
            self.assertEqual(world.mochila, 0, "Karel debe llevar 0 zumbador")
        else:
            self.fail(f"Nombre de caso inválido: {self.caseName}")


if __name__ == '__main__':
    kareltest.main()
