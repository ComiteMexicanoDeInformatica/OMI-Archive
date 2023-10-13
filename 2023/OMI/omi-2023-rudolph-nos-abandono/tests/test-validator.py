import re
# import sys
import unittest
from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        # case_name = sys.argv[1]
        with open("data.in", "r") as handle:
            original_input = handle.read()

        lines = original_input.split("\n")
        self.assertEqual(lines[-1], "", "Se esperaba un salto de línea al"
                         " final del archivo.")
        lines.pop()

        # Verifica que la primera línea contenga tres enteros N, L, R.
        regex = r"^[0-9]+ [0-9]+ [0-9]+$"
        self.assertTrue(re.match(regex, lines[0]), "Se esperaban tres enteros"
                        " N, L, R en la primera línea.")
        N, L, R = map(int, lines[0].split())
        # Verifica que N esté dentro de los límites.
        self.assertTrue(1 <= N <= 4096, f"N = {N} está fuera"
                        " de los límites.")
        self.assertTrue(L <= R, "el límite inferior es mayor al "
                        "límite superior")

        # Verifica que la segunda línea contenga N enteros separados por un
        # espacio.
        regex = r"^[0-9]+( [0-9]+)*$"
        self.assertTrue(re.match(regex, lines[1]), f"Se esperaban {N}"
                        " enteros en la segunda línea.")
        A = list(map(int, lines[1].split()))

        # Verifica que N sea una permutación de los primeros N enteros.
        # Verifica que la cantidad de números en el arreglo sea N.
        self.assertTrue(len(A) == N, f"Se esperaban {N} enteros"
                        " en la segunda línea")
        # Verifica que todos los elementos sean distintos.
        self.assertTrue(len(A) == len(set(A)), "Los elementos del "
                        " arreglo no son distintos.")
        # el arreglo debe contener todos los enteros del 1 al N.
        self.assertTrue(max(A) == N and min(A) == 1, "el arreglo no consta"
                        " de los enteros del 1 a N.")


if __name__ == '__main__':
    validatortest.main()
