#!/usr/bin/python3
# -*- coding: utf-8 -*-

from libkarel import kareltest


class Test(kareltest.TestCase):
    def test(self):
        world = self.world

        # Las únicas paredes en el mundo son las que lo delimitan.
        self.assertTightWorldSize()
        self.assertNoInnerWalls()

        # Karel inicia en la casilla (1,1) viendo al norte.
        self.assertEqual(1, world.y, 'Karel debe iniciar en (1, 1)')
        self.assertEqual(1, world.x, 'Karel debe iniciar en (1, 1)')
        self.assertEqual(world.direccion, 'NORTE',
                         'Karel debe iniciar viendo al norte')

        # Karel tiene infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, 'INFINITO',
                         'La mochila debe tener infinitos zumbadores')

        # El mundo es de 100 filas x 100 columnas.
        self.assertEqual(100, world.h, 'El mundo debe ser de 100x100')
        self.assertEqual(100, world.w, 'El mundo debe ser de 100x100')

        # La energía actual y la máxima energía que puede almacenar la batería
        # son menores o iguales a 200.
        E = world.zumbadores(1, 2)
        R = world.zumbadores(2, 2)
        self.assertTrue(1 <= E <= R <= 200, 'E y R no están en los límites')

        # En la fila 1 hay montones de zumbadores consecutivos con las alturas.
        # El trayecto termina con la primera posición sin zumbadores ocuando
        # haya pared.
        alturas = []
        for i in range(1, world.w + 1):
            if world.zumbadores(i, 1) > 0:
                alturas.append(world.zumbadores(i, 1))
            else:
                break

        # Se asegura que el trayecto consta de al menos un zumbador.
        self.assertTrue(len(alturas) >= 1,
                        'La trayectoria debe tener longitud mayor o igual a 1')

        # No hay más zumbadores además de las alturas, E y R.
        self.assertEqual(len(alturas) + 2, len(world.lista_zumbadores),
                         'El mundo no puede contener zumbadores además de ' +
                         'la trayectoria, E y R')

        # Solo importa la orientación final de Karel y el número de zumbadores
        # en (1,1).
        self.assertEqual(set(world.despliega), set(['MUNDO', 'ORIENTACION']))
        self.assertEqual(world.lista_dump, set([(1, 1)]))

        if 'sub1' in self.caseName:
            # La posición actual de Karel tiene la altura máxima de todo el
            # trayecto.
            self.assertTrue(alturas[0] > max(alturas[1:]),
                            'La posición de Karel debe tener la altura máxima')
        elif 'sub2' in self.caseName:
            # Hay una serie de tramos que suben seguido de una serie de tramos
            # que bajan.
            i = 1
            while i < len(alturas) and alturas[i - 1] <= alturas[i]:
                i += 1
            while i < len(alturas):
                self.assertTrue(alturas[i - 1] >= alturas[i],
                                'La trayectoria debe ser creciente y luego ' +
                                'decreciente')
                i += 1
            # Se asegura que Karel puede terminar el trayecto.
            self.assertTrue(max(alturas) - alturas[0] <= R,
                            'Karel no puede terminar el trayecto')
        elif 'sub3' in self.caseName:
            # Hay una serie de tramos que bajan seguido de una serie de tramos
            # que suben.
            i = 1
            while i < len(alturas) and alturas[i - 1] >= alturas[i]:
                i += 1
            while i < len(alturas):
                self.assertTrue(alturas[i - 1] <= alturas[i],
                                'La trayectoria debe ser decreciente y ' +
                                'luego creciente')
                i += 1
            # Se asegura que Karel puede terminar el trayecto.
            self.assertTrue(alturas[-1] - min(alturas) <= R,
                            'Karel no puede terminar el trayecto')
        elif 'sub4' in self.caseName:
            # La posición actual de Karel tiene altura 1.
            self.assertEqual(alturas[0], 1,
                             'La posición de Karel debe ser de altura 1')
            # Se asegura que Karel puede terminar el trayecto.
            self.assertTrue(max(alturas) <= R + 1,
                            'Karel no puede terminar el trayecto')
        elif 'sub5' in self.caseName:
            # La posición actual de Karel tiene altura 1.
            self.assertEqual(alturas[0], 1,
                             'La posición de Karel debe ser de altura 1')
        elif 'sub6' in self.caseName:
            # Sin ninguna restricción.
            pass
        else:
            self.fail(f"Nombre de caso inválido: {self.caseName}")


if __name__ == '__main__':
    kareltest.main()
