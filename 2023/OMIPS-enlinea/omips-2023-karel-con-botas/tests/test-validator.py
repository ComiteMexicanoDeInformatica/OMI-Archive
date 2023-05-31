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

        # Karel lleva infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, "INFINITO",
                         "La mochila debe tener infinitos zumbadores")

        # El mundo de Karel es un rectángulo sin paredes internas.
        self.assertTightWorldSize()
        self.assertNoInnerWalls()

        # Los montones que representan la energía en los años que ha vivido
        # Karel se encuentran en la fila 1.
        beepers = world.lista_zumbadores
        self.assertTrue(all(y == 1 for x, y in beepers.keys()),
                        "Los montones de zumbadores deben estar en la fila 1")

        # No existen espacios vacíos entre los montones de la fila 1.
        beepers = [world.zumbadores(x + 1, 1) for x in range(len(beepers))]
        self.assertTrue(all(k > 0 for k in beepers),
                        "No debe haber espacios vacíos en la fila 1")

        # Verifica que los zumbadores representen una secuencia válida, i.e.,
        # verifica que counter[x] <= counter[y] para x < y donde counter[x]
        # denota el número de veces que x aparece como montón de zumbadores.
        counter = Counter(beepers)
        counter = [counter[k + 1] for k in range(max(beepers))]
        self.assertEqual(counter, sorted(counter), "Los montones de "
                         "zumbadores no forman una secuencia válida")

        # Solo importan los zumbadores que dejes en la casilla (1, 1).
        self.assertEqual(world.despliega, ["MUNDO"])
        self.assertEqual(world.lista_dump, {(1, 1)})

        if "sub1" in self.caseName:
            # La energía máxima de Karel es igual a 1.
            self.assertEqual(max(beepers), 1,
                             "La energía máxima de Karel debe ser 1")
        elif 'sub2' in self.caseName:
            # Los años de vida de Karel pasan en orden.
            self.assertTrue(all(beepers[i] == beepers[i + 1] + 1 or
                                beepers[i + 1] == beepers[0]
                                for i in range(len(beepers) - 1)),
                            "Los montones de zumbadores deben estar ordenados")
        elif "sub3" in self.caseName:
            # La energía máxima de Karel es igual a 10.
            self.assertEqual(max(beepers), 10,
                             "La energía máxima de Karel debe ser 10")
        elif "sub4" in self.caseName:
            # El alto del mundo es mayor que la energía máxima de Karel.
            self.assertGreater(world.h, max(beepers), "El alto del mundo debe "
                               "ser mayor que la energía máxima")
        elif "sub5" in self.caseName:
            # El alto del mundo de Karel es 1.
            self.assertEqual(world.h, 1, "El mundo debe tener altura 1")
        elif "sub6" in self.caseName:
            # Karel puede ejecutar la instrucción ´avanza/move´ un máximo de
            # 2N veces donde N es el ancho del mundo.
            self.assertEqual(world.limite_comando("AVANZA"), 2*world.w,
                             "El límite de llamadas a 'AVANZA' debe ser 2N")
        else:
            self.fail(f"Nombre de caso inválido: {self.caseName}")


if __name__ == '__main__':
    kareltest.main()
