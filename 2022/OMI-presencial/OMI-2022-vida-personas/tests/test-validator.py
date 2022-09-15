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
            # Subtarea 1: N, Q, ai, bi <= 1000
            maxN = 1000
            maxQ = 1000
            maxab = 1000
        elif "sub2" in caseName:
            # Subtarea 2: N, ai, bi <= 1000, Q <= 10^4
            maxN = 1000
            maxQ = 1e4
            maxab = 1000
        elif "sub3" in caseName:
            # Subtarea 3: N, ai, bi <= 10^6, Q <= 10^4
            maxN = 1e6
            maxQ = 1e4
            maxab = 1e6
        elif "sub4" in caseName:
            # Subtarea 4: Sin reestricciones adicionales
            # 1 <= N, Q <= 10^6, 1 <= ai, bi <= 10^9
            maxN = 1e6
            maxQ = 1e6
            maxab = 1e9
        else:
            self.fail(f"Nombre de caso inválido: {caseName}")

        # Verifica que la primera línea contenga dos enteros N, Q
        regex = re.compile(r"\d+ \d+$")
        self.assertTrue(regex.match(lines[0]), "Se esperaban dos " +
                        "enteros N, Q en la primera línea")

        N, Q = map(int, lines[0].split())
        self.assertTrue(1 <= N <= maxN, "N está fuera de los límites")
        self.assertTrue(1 <= Q <= maxQ, "Q está fuera de los límites")

        # Verifica que la entrada contenga 1 + N + Q líneas
        self.assertEqual(len(lines), 1 + N + Q, f"Se esperaban {1 + N + Q} " +
                         "líneas en la entrada")

        # Verifica que las siguientes N líneas contengan dos enteros ai, bi
        for i in range(1, 1 + N):
            self.assertTrue(regex.match(lines[i]), "Se esperaban dos " +
                            f"enteros ai, bi en la línea {i+1}")
            ai, bi = map(int, lines[i].split())
            self.assertTrue(1 <= ai <= bi <= maxab, "ai, bi están fuera de " +
                            f"los límites en la línea {i + 1}")

        # Verifica que las últimas Q líneas contengan un entero xj.
        regex = re.compile(r"\d+$")
        for i in range(1 + N, 1 + N + Q):
            self.assertTrue(regex.match(lines[i]), "Se esperaba un entero " +
                            f"xj en la línea {i + 1}")


if __name__ == '__main__':
    validatortest.main()
