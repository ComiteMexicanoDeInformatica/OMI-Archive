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

        # Verifica que la primera línea contenga un entero N.
        regex = r"^[0-9]+$"
        self.assertTrue(re.match(regex, lines[0]), "Se esperaba un entero N"
                        " en la primera línea.")
        N = int(lines[0])

        # Verifica que la segunda línea contenga N enteros separados por un
        # espacio.
        regex = r"^[0-9]+( [0-9]+)*$"
        self.assertTrue(re.match(regex, lines[1]), f"Se esperaban {N} enteros"
                        " en la segunda línea")
        favorite_teams = list(map(int, lines[1].split()))
        self.assertEqual(len(favorite_teams), N, f"Se esperaban {N} enteros"
                         " en la segunda línea")

        MAXN = 2e5
        MAXAi = 1000

        if "sub1" in case_name:
            # Subtarea 1. N <= 30
            MAXN = 30
        elif "sub2" in case_name:
            # Subtarea 2. N <= 500
            MAXN = 500
        elif "sub3" in case_name:
            # Subtarea 3. N <= 5000, ai <= 10
            MAXN = 5000
            MAXAi = 10
        elif "sub4" in case_name:
            # Subtarea 4. Sin restricciones adicionales.
            pass
        else:
            self.fail(f"Nombre de caso inválido: {case_name}")

        # Verifica que N y ai estén dentro de los límites.
        self.assertTrue(2 <= N <= MAXN, "N está fuera de los límites")
        self.assertTrue(all(1 <= ai <= MAXAi for ai in favorite_teams),
                        "Algún ai está fuera de los límites")


if __name__ == '__main__':
    validatortest.main()
