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

        # Verifica que la primera línea contenga dos enteros T, N
        regex = re.compile(r"\d+ \d+$")
        self.assertTrue(regex.match(lines[0]), "Se esperaban dos " +
                        "enteros T, N en la primera línea")
        T, N = map(int, lines[0].split())

        # Verifica que la segunda línea contenga un texto de longitud T
        # conformado solo por letras minúsculas
        text = lines[1]
        regex = re.compile(r"^[a-z]+$")
        self.assertEqual(len(text), T, "Se esperaban T caracteres en la " +
                         "segunda línea")
        self.assertTrue(regex.match(text), "El texto solo puede contener " +
                        "letras minúsculas")

        # Verifica que la entrada contenga 2 + N líneas
        self.assertEqual(len(lines), 2 + N, f"Se esperaban {2+N} líneas " +
                         "en la entrada")

        # Verifica que las últimas N líneas contengan un entero li seguido de
        # li caracteres.
        lengths = []
        words = []
        regex = re.compile(r"\d+ [a-z]+$")
        for i in range(2, 2 + N):
            self.assertTrue(regex.match(lines[i]), "Se esperaba un entero " +
                            f"li seguido de li caracteres en la línea {i+1}")
            li, word = lines[i].split()
            self.assertEqual(int(li), len(word), "Se esperaba un entero " +
                             f"li seguido de li caracteres en la línea {i+1}")
            lengths.append(int(li))
            words.append(word)

        # Verifica que la suma de las longitudes de las palabras no exceda 10^6
        maxT = 1e6
        maxN = 1e5
        self.assertTrue(sum(lengths) <= 1e6, "La suma de las longitudes no " +
                        "debe exceder 10^6 caracteres")

        if "sub1" in caseName:
            # Subtarea 1: Solo hay una palabra en la lista y siempre será OMI
            self.assertTrue(N == 1 and words[0] == "omi", "\"omi\" debe ser " +
                            "la única palabra en la lista")
        elif "sub2" in caseName:
            # Subtarea 2: N <= 10
            maxN = 10
        elif "sub3" in caseName:
            # Subtarea 3: T, N <= 1000
            maxT = 1000
            maxN = 1000
        elif "sub4" in caseName:
            # Sin restricciones adicionales
            pass
        else:
            self.fail(f"Nombre de caso inválido: {caseName}")

        self.assertTrue(1 <= T <= maxT, "T está fuera de los límites")
        self.assertTrue(1 <= N <= maxN, "N está fuera de los límites")


if __name__ == '__main__':
    validatortest.main()
