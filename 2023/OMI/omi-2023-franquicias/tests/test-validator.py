#!/usr/bin/python
# -*- coding: utf-8 -*-
import re
import sys
import unittest
from omegaup.validator import validatortest


def checkNMFP(
        self,
        N,
        M,
        F,
        P,
        case_name,
):
    self.assertTrue(1 <= N <= 100000, "N esta fuera de los limites.")
    self.assertTrue(1 <= M <= 1000000, "M esta fuera de los limites.")
    self.assertTrue(1 <= F <= 100000, "F esta fuera de los limites.")
    self.assertTrue(1 <= P <= 100000, "P esta fuera de los limites.")
    if "franquicias1" in case_name:
        self.assertTrue(N == 1, "N esta fuera de los limites.")
        self.assertTrue(M == 1000, "M esta fuera de los limites.")
    if "franquicias2" in case_name:
        self.assertTrue(N == 1, "N esta fuera de los limites.")
    if "franquicias3" in case_name:
        self.assertTrue(N == 2 * F, "N != 2F")
    if "franquicias4" in case_name:
        self.assertTrue(N == 2 * F, "N != 2F")


def checkBC(
        self,
        B,
        C,
        case_name,
):
    self.assertTrue(0 <= B <= 1000000, "B esta fuera de los limites.")
    self.assertTrue(0 <= C <= 1000000, "C esta fuera de los limites.")
    if "franquicias1" in case_name:
        self.assertTrue(C == 0, "C esta fuera de los limites.")
    if "franquicias3" in case_name:
        self.assertTrue(C == 0, "C esta fuera de los l\xc3\xadmites.")


def checkThirdLine(
        self,
        linea,
        M,
        F,
):
    self.assertTrue(
        len(linea.split()) == F,
        "La tercera linea tiene una cantidad equivocada de elementos",
    )

    for entero in linea.split():
        try:
            int(entero)
        except ValueError:
            self.assertTrue(
                False, "La tercera linea contiene un elemento que no es"
            )
        self.assertTrue(
            1 <= int(entero) <= M, "Un entero en la tercera linea esta "
        )

    # Valida que no hay numeros repetidos.

    numeros = set()
    for entero in linea.split():
        self.assertFalse(
            entero in numeros, "Se encontro un elemento repetido en la "
        )
        numeros.add(entero)


class Test(unittest.TestCase):
    def test(self):
        case_name = sys.argv[1]
        with open("data.in", "r") as handle:
            original_input = handle.read()
        lines = original_input.split("\n")
        self.assertEqual(
            lines[-1], "", "Se esperaba un salto de linea al final del "
        )
        lines.pop()

        # Verifica que la primera linea contenga tres enter N, M, F y P

        regex = r"^[0-9]+ [0-9]+ [0-9]+ [0-9]+$"
        self.assertTrue(
            re.match(regex, lines[0]),
            "Se esperaban cuatro enterosN, M, F y P en la primera lin.",
        )

        # Verifica que N y M esten dentro de los limites.

        (N, M, F, P) = map(int, lines[0].split())
        regex = r"^[0-9]+ [0-9]+$"
        self.assertTrue(
            re.match(regex, lines[1]),
            "Se esperaban dos enterosB y C en la segunda linea.",
        )
        (B, C) = map(int, lines[1].split())
        checkNMFP(
            self,
            N,
            M,
            F,
            P,
            case_name,
        )
        checkBC(self, B, C, case_name)
        checkThirdLine(self, lines[2], M, F)

        # Verifica que los caracteres sean validos.

        for i in range(3, P + 3):
            regex = r"^[0-9]+ [0-9]+$"
            self.assertTrue(re.match(regex, lines[i]), "Se esperaban d")
            (oficina, progs) = map(int, lines[i].split())
            self.assertTrue(1 <= oficina <= M, "Oficina esta fuera de ")
            self.assertTrue(
                1 <= progs <= 1e6, "Cantidad de programadores fuera de "
            )


if __name__ == "__main__":
    validatortest.main()
