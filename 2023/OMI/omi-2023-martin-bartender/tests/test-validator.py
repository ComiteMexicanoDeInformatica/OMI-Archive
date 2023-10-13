import re
import sys
import unittest
from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        case_name = sys.argv[1]
        with open("data.in", "r") as handle:
            original_input = handle.read()

        lines = original_input.split("\n")
        self.assertEqual(lines[-1], "", "Se esperaba un salto de línea al"
                         " final del archivo.")
        lines.pop()

        # Verifica que la primera línea contenga dos enteros N y Q.
        regex = r"^[0-9]+ [0-9]+$"
        self.assertTrue(re.match(regex, lines[0]), "Se esperaban dos enteros N"
                        " y K en la primera línea.")

        # Verifica que N y Q estén dentro de los límites.
        N, K = map(int, lines[0].split())
        self.assertTrue(K <= N, "K está fuera de los límites.")
        if "sub4" in case_name:
            # Subtarea 1. 1 <=  K <= N <= 1000
            self.assertTrue(1 <= N <= 1000, "N está fuera de los límites.")
            self.assertTrue(1 <= K <= 1000, "K está fuera de los límites.")
        else:
            # 1 <= N, Q, <= 10^5
            self.assertTrue(1 <= N <= 1e5, "N está fuera de los límites.")
            self.assertTrue(1 <= K <= 1e5, "K está fuera de los límites.")

        regex = r"^[0-9]+( [0-9]+)*$"
        self.assertTrue(re.match(regex, lines[1]), f"Se esperaban {N} enteros"
                        " en la segunda línea")
        values = list(map(int, lines[1].split()))
        self.assertEqual(len(values), N, f"Se esperaban {N} enteros en la"
                         " segunda línea")

        # Verifica que los valores del arreglo estén dentro de los límites.
        self.assertTrue(all(1 <= ai <= 1e5 for ai in values), "Algún valor"
                        " del arreglo está fuera de los límites.")
        if "sub1" in case_name:
            # Subtarea 1. Todos los valores del arreglo son iguales.
            self.assertTrue(all(ai == values[0] for ai in values), "No todos"
                            " los valores del arreglo son iguales.")
        if "sub2" in case_name:
            self.assertTrue(K == N, "K no es igual a N.")

        if "sub3" in case_name:
            self.assertTrue(K == 1, "K no es igual a 1.")


if __name__ == '__main__':
    validatortest.main()
