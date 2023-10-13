#!/usr/bin/python3
# -*- coding: utf-8 -*-

from libkarel import kareltest


class Test(kareltest.TestCase):
    def test(self):
        world = self.world

        # El mundo de Karel es un rectángulo sin paredes internas.
        self.assertTightWorldSize()
        self.assertNoInnerWalls()

        # El tamaño del mundo de Karel es de 100 x 100
        self.assertEqual(world.w, 100, "Ancho != 100")
        self.assertEqual(world.h, 100, "Alto != 100")

        # Karel inicia en la posición (1, 1) orientado al norte.
        self.assertEqual(world.x, 1, "Karel debe iniciar en (1, 1)")
        self.assertEqual(world.y, 1, "Karel debe iniciar en (1, 1)")
        self.assertEqual(world.direccion, "NORTE",
                         "Karel debe iniciar orientado al norte")

        # Karel lleva infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, 0,
                         "La mochila debe tener 0 zumbadores")

        # Solo importan los zumbadores que dejes en la casilla (1, 1).
        self.assertEqual(world.despliega, ["MUNDO"])
        self.assertEqual(world.lista_dump, {(1, 1)})

        # Sólo habrá zumbadores en la fila 1 del mundo.
        beepers = world.lista_zumbadores
        self.assertTrue(all(y == 1 for (x, y) in beepers.keys()),
                        "Solo puede haber zumbadores en la fila 1")

        # Los montones de la fila 1 pueden tener entre 1 y 100 zumbadores.
        # No hay espacios vacíos entre los montones de zumbadores.
        self.assertTrue(all(1 <= z < 100 for z in beepers.values()),
                        "Los montones deben tener entre 1 y 100 zumbadores")

        if "sub1" in self.caseName:
            # Los titanes van ordenados por altura
            beepers = world.lista_zumbadores
            ant = 0
            for z in beepers.values():
                self.assertTrue(z > ant,
                                "Las alturas no estrictamente crecientes")
                ant = z
        elif "sub2" in self.caseName:
            # Hay 2 titanes en el mundo.
            self.assertEqual(len(beepers), 2, "Solo puede haber 2 titanes")
        elif "sub3" in self.caseName:
            # La secuencia de titanes es no decreciente
            beepers = [world.zumbadores(x + 2, 1) for x in range(len(beepers))]
            self.assertEqual(beepers, sorted(beepers),
                             "Los titanes deben ir ordenados por altura")
        elif "sub4" in self.caseName:
            # Sin restricciones
            pass
        else:
            self.fail(f"Nombre de caso inválido: {self.caseName}")


if __name__ == '__main__':
    kareltest.main()
