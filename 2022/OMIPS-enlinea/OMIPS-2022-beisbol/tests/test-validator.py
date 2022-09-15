#!/usr/bin/python3
# -*- coding: utf-8 -*-

from libkarel import kareltest


class Test(kareltest.TestCase):
    # pylint: disable=too-many-statements
    def test(self):
        world = self.world

        # Karel inicia en la casilla (1,1) viendo al norte.
        self.assertEqual(1, world.y)
        self.assertEqual(1, world.x)
        self.assertEqual(world.direccion, 'NORTE')

        # No paredes internas.
        self.assertNoInnerWalls()

        # Solo se evalúa la posición final de Karel.
        self.assertEqual(world.despliega, ['POSICION'])

        # Asegurar que haya 4 zumbadores.
        self.assertEqual(len(world.lista_zumbadores), 4)

        # Verificar que formen un rombo o cuadrado los zumbadores.
        beepers = world.lista_zumbadores

        # Verificar que los zumbadores sean de tamaño 1.
        for v in beepers.values():
            self.assertEqual(v, 1)

        # Verificar para el primer beeper cuántos están en su misma fila o
        # columna.
        candidate = 0
        distanciaA = 0
        distanciaB = 0

        # Obtener el primer beeper en beepers.
        actual = list(beepers.keys())[0]

        for (x, y), v in beepers.items():
            if x == actual[0] and y == actual[1]:
                continue
            if x == actual[0] or y == actual[1]:
                candidate += 1
                # Calcula distancia Manhattan.
                distanciaA = abs(x - actual[0]) + abs(y - actual[1])
            else:
                distanciaB = abs(x - actual[0]) + abs(y - actual[1])

        # Si candidate = 2 es un posible cuadrado.
        # Si candidate = 1 es un posible rombo.

        # Aseguramos que candidate sea igual a 1 o 2.
        self.assertTrue(candidate in [1, 2])

        # Verificar ahora para cada zumbador en beepers.
        for (x, y), v in beepers.items():
            cantActual = 0
            # Verificar si está en la misma fila o columna que el beeper
            # actual.
            for (p, q) in beepers.keys():
                if x == p and y == q:
                    continue

                if x == p or y == q:
                    cantActual += 1
                    # Asegurar que la distanciaA entre los zumbadores
                    # sea la misma.
                    distActual = abs(x - p) + abs(y - q)
                    self.assertEqual(distanciaA, distActual)

                    # Cuando es cuadrado, asegurar que si haya un centro para
                    # el cuadrado.
                    if candidate == 2:
                        self.assertTrue(distActual % 2 == 0)
                else:
                    # Asegurar que la distanciaB entre los zumbadores
                    # sea la misma.
                    distActual = abs(x - p) + abs(y - q)
                    self.assertEqual(distanciaB, distActual)

            # Aseguramos que sea la misma cantidad a candidate.
            self.assertEqual(cantActual, candidate)

        # Verificar que se cumplan condiciones para cada subtarea.
        if 'sub1' in self.caseName:
            # Subtarea 1: Al menos 1 de las bases esta en la fila 1, es un
            # cuadrado.
            self.assertEqual(world.mochila, 'INFINITO')

            # Aseguramos que al menos uno de los beepers esté en la fila 1.
            filaUno = False
            for (x, y) in beepers.keys():
                if y == 1:
                    filaUno = True
                    break
            self.assertTrue(filaUno)

            # Aseguramos que candidate sea 2.
            self.assertEqual(candidate, 2)

        elif 'sub2' in self.caseName:
            # Subtarea 2: Las bases están donde sea, es un cuadrado.
            self.assertEqual(world.mochila, 'INFINITO')

            # Aseguramos que candidate sea 2.
            self.assertEqual(candidate, 2)

        elif 'sub3' in self.caseName:
            # Subtarea 3: Una de las bases está en la fila 1, es un rombo.
            self.assertEqual(world.mochila, 'INFINITO')

            # Aseguramos que al menos uno de los beepers esté en la fila 1.
            filaUno = False
            for (x, y) in beepers.keys():
                if y == 1:
                    filaUno = True
                    break
            self.assertTrue(filaUno)

            # Aseguramos que candidate sea 1.
            self.assertEqual(candidate, 1)

        elif 'sub4' in self.caseName:
            # Subtarea 4: Las bases están donde sea, es un rombo.
            self.assertEqual(world.mochila, 'INFINITO')

            # Aseguramos que candidate sea 1.
            self.assertEqual(candidate, 1)

        elif 'sub5' in self.caseName:
            # Subtarea 5: No hay zumbadores en la mochila y bases donde sea,
            # rombo o cuadrado.
            self.assertEqual(world.mochila, 0)

        else:
            self.fail(f"Invalid case name: {self.caseName}")


if __name__ == '__main__':
    kareltest.main()
