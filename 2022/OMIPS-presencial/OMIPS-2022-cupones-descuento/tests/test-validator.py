#!/usr/bin/python3
# -*- coding: utf-8 -*-

from libkarel import kareltest


class Test(kareltest.TestCase):
    def test(self):
        world = self.world

        # Karel empieza en la (1, 1) orientado al norte.
        self.assertEqual(1, world.y)
        self.assertEqual(1, world.x)
        self.assertEqual(world.direccion, "NORTE")

        # Karel lleva infinitos zumbadores en la mochila.
        self.assertEqual(world.mochila, "INFINITO")

        # Las únicas paredes en el mundo son las que lo delimitan.
        self.assertTightWorldSize()
        self.assertNoInnerWalls()

        products = []
        coupons = []
        for x in range(1, 101):
            k = world.zumbadores(x, 1)
            if k == 0:
                break
            products.append(k)
        for x in range(1, 101):
            k = world.zumbadores(x, 2)
            if k == 0:
                break
            coupons.append(k)

        # No hay espacios entre los zumbadores de la primera y segunda fila.
        self.assertEqual(len(products) + len(coupons),
                         len(world.lista_zumbadores))

        # Solo importan los zumbadores que dejes en la casilla (1,1).
        self.assertEqual(world.despliega, ['MUNDO'])
        self.assertEqual(world.lista_dump, {(1, 1)})

        if "sub1" in self.caseName:
            # Todos los cupones tienen C = 1. Los artículos están ordenados por
            # precio de menor a mayor.
            self.assertTrue(all(C == 1 for C in coupons))
            self.assertTrue(all(products[i] <= products[i + 1]
                                for i in range(len(products) - 1)))
        elif "sub2" in self.caseName:
            # Solo hay un cupón. Los artículos están ordenados por precio de
            # menor a mayor.
            self.assertEqual(len(coupons), 1)
            self.assertTrue(all(products[i] <= products[i + 1]
                                for i in range(len(products) - 1)))
        elif "sub3" in self.caseName:
            # Todos los cupones tienen la misma C. Los artículos están
            # ordenados por precio de menor a mayor.
            self.assertTrue(all(C == coupons[0] for C in coupons))
            self.assertTrue(all(products[i] <= products[i + 1]
                                for i in range(len(products) - 1)))
        elif "sub4" in self.caseName:
            # Todos los artículos cuestan lo mismo.
            self.assertTrue(all(P == products[0] for P in products))
        elif "sub5" in self.caseName:
            # Sin reestricciones adicionales.
            pass
        else:
            self.fail(f"Nombre de caso inválido: {self.caseName}")


if __name__ == '__main__':
    kareltest.main()
