#!/usr/bin/python3
# -*- coding: utf-8 -*-

import math
from libkarel import kareltest


def is_prime(n: int) -> bool:
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return n > 1


def is_square(n: int) -> bool:
    return n == int(math.sqrt(n))**2


class Test(kareltest.TestCase):
    def test(self):
        world = self.world

        # Karel inicia en la posición (1,1) viendo al norte.
        self.assertEqual(world.x, 1, "Karel debe iniciar en (1, 1)")
        self.assertEqual(world.y, 1, "Karel debe iniciar en (1, 1)")
        self.assertEqual(world.direccion, "NORTE",
                         "Karel debe iniciar orientado al norte")

        # Karel tiene zumbadores infinitos en la mochila.
        self.assertEqual(world.mochila, "INFINITO",
                         "La mochila debe tener infinitos zumbadores")

        # El montón de zumbadores con el área estará en la casilla (1,1).
        # El montón de zumbadores iniciales no será mayor a 400.
        self.assertTrue(1 <= world.zumbadores(1, 1) <= 400, "El número de "
                        "zumbadores en (1, 1) debe estar entre 1 y 400")

        # El mundo de Karel es un rectángulo sin paredes internas.
        self.assertTightWorldSize()
        self.assertNoInnerWalls()

        # La altura y la base del triángulo deben estar en las casillas (1,1) y
        # (2,1).
        # No importa la orientación ni posición final de karel.
        self.assertEqual(world.despliega, ["MUNDO"])
        self.assertEqual(world.lista_dump, {(1, 1), (2, 1)})

        if "sub1" in self.caseName:
            # La diferencia entre base y altura no será tomada en cuenta.
            pass
        elif "sub2" in self.caseName:
            # Se te asegura que el área del triángulo es un número primo.
            self.assertTrue(is_prime(world.zumbadores(1, 1)),
                            "El número de zumbadores en (1, 1) debe ser primo")
        elif "sub3" in self.caseName:
            # El área del triángulo es la mitad de un número cuadrado.
            self.assertTrue(is_square(2*world.zumbadores(1, 1)),
                            "El número de zumbadores en (1, 1) debe ser la "
                            "mitad de un cuadrado")
        elif "sub4" in self.caseName:
            # No hay consideraciones adicionales.
            pass
        else:
            self.fail(f"Nombre de caso inválido: {self.caseName}")


if __name__ == '__main__':
    kareltest.main()
