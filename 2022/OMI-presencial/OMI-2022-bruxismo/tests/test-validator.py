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

        # Verifica que la primera línea contenga dos enteros N, T
        regex = re.compile(r"\d+ \d+$")
        self.assertTrue(regex.match(lines[0]), "Se esperaban dos " +
                        "enteros N, T en la primera línea")
        N, T = map(int, lines[0].split())

        if "sub1" in caseName:
            # Subtarea 1: N, T <= 1000
            self.assertTrue(1 <= N <= 1000, "N está fuera de los límites")
            self.assertTrue(1 <= T <= 1000, "T está fuera de los límites")
        else:
            # 1 <= N <= 10^5, 1 <= T <= 10^4
            self.assertTrue(1 <= N <= 1e5, "N está fuera de los límites")
            self.assertTrue(1 <= T <= 1e4, "T está fuera de los límites")

        # Verifica que la entrada contenga 2 + N líneas
        self.assertEqual(len(lines), 2 + N, f"Se esperaban {2+N} líneas " +
                         "en la entrada")

        # Verifica que las siguientes N líneas contengan cuatro enteros Di, Ai,
        # Bi, Mi
        regex = re.compile(r"\d+ \d+ \d+ \d+$")
        A = []
        B = []
        M = []
        for i in range(1, 1 + N):
            self.assertTrue(regex.match(lines[i]), "Se esperaban cuatro " +
                            f"enteros Di, Ai, Bi, Mi en la línea {i+1}")
            Di, Ai, Bi, Mi = map(int, lines[i].split())
            self.assertTrue(1 <= Ai <= 100, "Ai está fuera de los límites " +
                            f"en la línea {i+1}")
            self.assertTrue(1 <= Bi <= 100, "Bi está fuera de los límites " +
                            f"en la línea {i+1}")
            self.assertTrue(1 <= Di <= 1e9, "Di está fuera de los límites " +
                            f"en la línea {i+1}")
            self.assertTrue(1 <= Mi <= 1e6, "Mi está fuera de los límites " +
                            f"en la línea {i+1}")
            A.append(Ai)
            B.append(Bi)
            M.append(Mi)

        if "sub2" in caseName:
            # Subtarea 2: Ai = Aj, Bi = Bj, Mi = Mj
            self.assertEqual(len(set(A)), 1, "Todos los Ai deben ser iguales")
            self.assertEqual(len(set(B)), 1, "Todos los Bi deben ser iguales")
            self.assertEqual(len(set(M)), 1, "Todos los Mi deben ser iguales")
        elif "sub3" in caseName:
            # Subtarea 3: Ai = Bi
            self.assertTrue(all(Ai == Bi for Ai, Bi in zip(A, B)), "Ai y Bi " +
                            "deben ser iguales")

        # Verifica que la última línea contenga T enteros
        regex = re.compile(r"^\d+(\s\d+)*$")
        self.assertTrue(regex.match(lines[-1]), "Se esperaban T enteros en " +
                        "la última línea")
        F = list(map(int, lines[-1]))
        self.assertEqual(len(F), T, "Se esperaban T enteros en la última " +
                         "línea")
        self.assertTrue(all(1 <= Fj <= 1e9 for Fj in F), "Algún Fj está " +
                        "fuera de los límites")


if __name__ == '__main__':
    validatortest.main()
