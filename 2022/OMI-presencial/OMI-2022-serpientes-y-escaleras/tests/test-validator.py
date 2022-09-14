import re
import sys
import unittest
from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        caseName = sys.argv[1]
        with open("data.in", "r") as handle:
            original_input = handle.read()

        lines = original_input.split("\n")
        self.assertEqual(lines[-1], "", "Se esperaba una nueva línea al " +
                         "final del archivo")
        lines.pop()

        # Límites
        if "sub1" in caseName:
            # Subtarea 1: N, M <= 500
            maxN = 500
            maxM = 500
        elif "sub2" in caseName:
            # Subtarea 2: N, M <= 10^5
            maxN = 1e5
            maxM = 1e5
        elif "sub3" in caseName:
            # Subtarea 3: Sin reestricciones adicionales. 1 <= N, M <= 10^6
            maxN = 1e6
            maxM = 1e6
        else:
            self.fail(f"Nombre de caso inválido: {caseName}")

        # Verifica que la primera línea contenga dos enteros N, M
        regex = re.compile(r"\d+ \d+$")
        self.assertTrue(regex.match(lines[0]), "Se esperaban dos " +
                        "enteros N, M en la primera línea")

        N, M = map(int, lines[0].split())
        self.assertTrue(1 <= N <= maxN, "N está fuera de los límites")
        self.assertTrue(1 <= M <= maxM, "M está fuera de los límites")

        # Verifica que la entrada contenga 1 + N líneas
        self.assertEqual(len(lines), 1 + N, f"Se esperaban {1+N} líneas " +
                         "en la entrada")

        # Verifica que la siguientes N líneas contengan dos enteros li, ri
        portals = []
        for i in range(1, 1 + N):
            self.assertTrue(regex.match(lines[i]), "Se esperaban dos " +
                            f"enteros li, ri en la línea {i+1}")
            li, ri = map(int, lines[i].split())
            portals.extend([li, ri])
            self.assertTrue(0 <= li <= 2*N + 1, "li está fuera de los " +
                            f"límites para i = {i}")
            self.assertTrue(0 <= ri <= 2*N + 1, "ri está fuera de los " +
                            f"límites para i = {i}")

        # Verifica que todos los portales se encuentren en posiciones distintas
        self.assertEqual(len(portals), len(set(portals)), "Los portales " +
                         "deben de estar en posiciones distintas")


if __name__ == '__main__':
    validatortest.main()
