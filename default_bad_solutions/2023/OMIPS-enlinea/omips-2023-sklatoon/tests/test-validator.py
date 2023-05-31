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

        # Karel lleva inifinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, "INFINITO",
                         "La mochila debe tener infinitos zumbadores")

        # El mundo de Karel es un rectángulo sin paredes internas.
        self.assertTightWorldSize()
        self.assertNoInnerWalls()

        # Los montones de zumbadores pueden estar en cualquier lugar del mundo,
        # pero sólo habrá montones con tres valores distintos, el pelotón 1,
        # el pelotón 2 y las posiciones pintadas por ambos.
        beepers_groups = Counter(world.lista_zumbadores.values())
        self.assertLessEqual(len(beepers_groups), 3, "Se esperaban 3 valores "
                             "distintos para los montones de zumbadores")
        if len(beepers_groups) == 3:
            values = sorted(beepers_groups.keys())
            self.assertEqual(values[0] + values[1], values[2],
                             "El tercer montón debe ser la suma de los "
                             "primeros dos montones")

        # Solo importan los zumbadores que dejes en la casilla (1, 1).
        self.assertEqual(world.despliega, ["MUNDO"])
        self.assertEqual(world.lista_dump, {(1, 1)})

        if "sub1" in self.caseName:
            # Sólo un pelotón pintó posiciones del mundo.
            self.assertEqual(len(beepers_groups), 1, "Todos los montones de "
                             "zumbadores deben ser iguales")
        elif "sub2" in self.caseName:
            # No hay ninguna posición en la que hayan pintado ambos pelotones.
            # Además, el ancho del mundo es mayor que cualquiera de los colores
            # asignados a los pelotones.
            self.assertEqual(len(beepers_groups), 2, "Se esperaban 2 valores "
                             "distintos para los montones de zumbadores")
            self.assertGreater(world.w, max(beepers_groups.keys()),
                               "El ancho del mundo debe ser mayor que los "
                               "montones de zumbadores")
        elif "sub3" in self.caseName:
            # El ancho del mundo es mayor que la suma de los colores asignados
            # a ambos pelotones.
            self.assertGreater(world.w, max(beepers_groups.keys()),
                               "El ancho del mundo debe ser mayor que los "
                               "montones de zumbadores")
        elif "sub4" in self.caseName:
            # No hay posiciones pintadas por ambos pelotones. El ancho y alto
            # del mundo son menores que los colores asignados a los pelotones.
            self.assertEqual(len(beepers_groups), 2, "Se esperaban 2 valores "
                             "distintos para los montones de zumbadores")
            self.assertLess(world.w, min(beepers_groups.keys()),
                            "El ancho del mundo debe ser menor que los "
                            "montones de zumbadores")
            self.assertLess(world.h, min(beepers_groups.keys()),
                            "El alto del mundo debe ser menor que los "
                            "montones de zumbadores")
        elif "sub5" in self.caseName:
            # El alto y ancho del mundo son menores que los colores asignados a
            # los pelotones.
            self.assertLess(world.w, min(beepers_groups.keys()),
                            "El ancho del mundo debe ser menor que los "
                            "montones de zumbadores")
            self.assertLess(world.h, min(beepers_groups.keys()),
                            "El alto del mundo debe ser menor que los "
                            "montones de zumbadores")
        else:
            self.fail(f"Nombre de caso inválido: {self.caseName}")


if __name__ == '__main__':
    kareltest.main()
