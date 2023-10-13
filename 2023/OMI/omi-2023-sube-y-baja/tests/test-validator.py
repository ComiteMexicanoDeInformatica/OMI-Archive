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
                        " y Q en la primera línea.")

        # Verifica que N y Q estén dentro de los límites.
        N, Q = map(int, lines[0].split())
        if "sub1" in case_name:
            # Subtarea 1. 1 <= N, Q <= 1000
            self.assertTrue(1 <= N <= 1000, "N está fuera de los límites.")
            self.assertTrue(1 <= Q <= 1000, "Q está fuera de los límites.")
        else:
            # 1 <= N, Q, <= 10^5
            self.assertTrue(1 <= N <= 1e5, "N está fuera de los límites.")
            self.assertTrue(1 <= Q <= 1e5, "Q está fuera de los límites.")

        # Verifica que la segunda línea contenga N enteros separados por un
        # espacio.
        regex = r"^[0-9]+( [0-9]+)*$"
        self.assertTrue(re.match(regex, lines[1]), f"Se esperaban {N} enteros"
                        " en la segunda línea")
        values = list(map(int, lines[1].split()))
        self.assertEqual(len(values), N, f"Se esperaban {N} enteros en la"
                         " segunda línea")

        # Verifica que los valores del arreglo estén dentro de los límites.
        self.assertTrue(all(0 <= ai <= 1e6 for ai in values), "Algún valor del"
                        "arreglo está fuera de los límites.")

        if "sub3" in case_name:
            # Subtarea 3. Todos los valores del arreglo son distintos.
            self.assertEqual(len(values), len(set(values)), "Los valores del"
                             " arreglo deben ser distintos.")

        # Verifica que las siguientes Q líneas contengan dos enteros L, R.
        regex = r"^[0-9]+ [0-9]+$"
        self.assertEqual(len(lines), Q + 2, f"Se esperaban {Q} líneas después"
                         " de la segunda línea.")
        for i in range(2, Q + 2):
            self.assertTrue(re.match(regex, lines[i]), "Se esperaban dos"
                            f" enteros Lj, Rj, en la línea {i + 1}")

            # Verifica que Lj, Rj estén dentro de los límites.
            L, R = map(int, lines[i].split())
            self.assertTrue(1 <= L < R <= N, "Lj y Rj están fuera de los"
                            " límites.")

            if "sub2" in case_name:
                # Subtarea 2. Lj + 2 = Rj.
                self.assertEqual(L + 2, R, "Los rangos deben ser de largo 3.")


if __name__ == '__main__':
    validatortest.main()
