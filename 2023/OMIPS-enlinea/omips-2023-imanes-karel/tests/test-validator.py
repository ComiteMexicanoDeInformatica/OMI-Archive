#!/usr/bin/python3
# -*- coding: utf-8 -*-

from typing import List
from libkarel import kareltest


# Devuelve el número de grupos que quedan al final.
def solution(x: List[int]) -> int:
    # Determina la dirección a la que se mueve cada iman.
    dx = ['>']
    for i in range(1, len(x) - 1):
        dx.append('<' if x[i] - x[i - 1] <= x[i + 1] - x[i] else '>')
    dx.append('<')
    # Cuenta el número de grupos que se forman.
    groups = 1
    for i in range(len(x) - 1):
        if dx[i] == '<' and dx[i + 1] == '>':
            groups += 1
    return groups


class Test(kareltest.TestCase):
    def test(self):
        world = self.world

        # Karel inicia en la posición (1, 1) orientado al norte.
        self.assertEqual(world.x, 1, "Karel debe iniciar en (1, 1)")
        self.assertEqual(world.y, 1, "Karel debe iniciar en (1, 1)")
        self.assertEqual(world.direccion, "NORTE",
                         "Karel debe iniciar orientado al norte")

        # Karel lleva infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, "INFINITO",
                         "La mochila debe tener infinitos zumbadores")

        # Sólo habrá zumbadores en la fila 1 del mundo.
        beepers = world.lista_zumbadores
        self.assertTrue(all(y == 1 for (x, y) in beepers.keys()),
                        "Solo puede haber zumbadores en la fila 1")

        # Los montones de la fila 1 pueden tener entre 1 y 100 zumbadores.
        # No hay espacios vacíos entre los montones de zumbadores y estos
        # siempre van ordenados.
        beepers = [world.zumbadores(x + 1, 1) for x in range(len(beepers))]
        self.assertTrue(all(1 <= k <= 100 for k in beepers),
                        "Los montones deben tener entre 1 y 100 zumbadores")
        self.assertEqual(beepers, sorted(beepers),
                         "Los montones de zumbadores deben estar ordenados")

        # El mundo de Karel es un rectángulo sin paredes internas.
        self.assertTightWorldSize()
        self.assertNoInnerWalls()

        # # Solo importan los zumbadores que dejes en la casilla (1, 1).
        self.assertEqual(world.despliega, ["MUNDO"])
        self.assertEqual(world.lista_dump, {(1, 1)})

        if "sub1" in self.caseName:
            # Hay 3 imanes en el mundo.
            self.assertEqual(len(beepers), 3, "Solo puede haber 3 imanes")
        elif "sub2" in self.caseName:
            # Hay 4 imanes en el mundo.
            self.assertEqual(len(beepers), 4, "Solo puede haber 4 imanes")
        elif "sub3" in self.caseName:
            # Puede haber cualquier cantidad de imanes pero el número de grupos
            # que se forman siempre será 1 ó 2.
            self.assertLessEqual(solution(beepers), 2, "El número de grupos "
                                 "que se forman debe ser 1 o 2")
        elif "sub4" in self.caseName:
            # Puede haber cualquier cantidad de imanes y quedar cualquier
            # cantidad de grupos.
            pass
        else:
            self.fail(f"Nombre de caso inválido: {self.caseName}")


if __name__ == '__main__':
    kareltest.main()
