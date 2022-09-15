import re
import sys
import unittest
from omegaup.validator import validatortest


# Precalcula el número de felices encuentros en el rango [1, Ri]
def computePrefixSum(text):
    prefixSum = [0, 0]
    for i in range(1, len(text)):
        prefixSum.append(prefixSum[-1] + (text[i] == text[i - 1]))
    return prefixSum


class Test(unittest.TestCase):
    def test(self):
        caseName = sys.argv[1]
        with open("data.in", "r") as handle:
            original_input = handle.read()

        lines = original_input.split("\n")
        self.assertEqual(lines[-1], "", "Se esperaba una nueva línea al " +
                         "final del archivo")
        lines.pop()

        # Verifica que la primera línea contenga dos enteros T, Q
        regex = re.compile(r"\d+ \d+$")
        self.assertTrue(regex.match(lines[0]), "Se esperaban dos " +
                        "enteros T, Q en la primera línea")
        T, Q = map(int, lines[0].split())

        # Verifica que la segunda línea contenga T caracteres.
        text = lines[1]
        self.assertEqual(len(text), T, "Se esperaban T caracteres en la " +
                         "segunda línea")

        # Verifica que la entrada contenga 2 + Q líneas
        self.assertEqual(len(lines), 2 + Q, f"Se esperaban {2+Q} líneas " +
                         "en la entrada")

        # Verifica que las últimas Q líneas contengan dos enteros Li, Ri.
        L = []
        R = []
        for i in range(2, 2 + Q):
            self.assertTrue(regex.match(lines[i]), "Se esperaban dos " +
                            f"enteros Li, Ri en la línea {i+1}")
            Li, Ri = map(int, lines[i].split())
            L.append(Li)
            R.append(Ri)

        if "sub1" in caseName:
            # Subtarea 1: T, Q <= 1000
            self.assertTrue(1 <= T <= 1000, "T está fuera de los límites")
            self.assertTrue(1 <= Q <= 1000, "Q está fuera de los límites")
        else:
            # T, Q <= 10^5
            self.assertTrue(1 <= T <= 1e5, "T está fuera de los límites")
            self.assertTrue(1 <= Q <= 1e5, "Q está fuera de los límites")

        if "sub2" in caseName:
            # Subtarea 2: El texto contiene únicamente las letras 'A' y 'B'
            regex = re.compile(r"^[AB]+$")
            self.assertTrue(regex.match(text), "El texto solo puede " +
                            "contener los caracteres 'A' y 'B'")
        else:
            # El texto contiene letras mayúsculas y números
            regex = re.compile(r"^[A-Z\d]+$")
            self.assertTrue(regex.match(text), "El texto solo puede " +
                            "contener letras mayúsculas y números")

        if "sub3" in caseName:
            # Subtarea 3: Li = 1 para todas las preguntas
            for i in range(Q):
                self.assertTrue(L[i] == 1 and 1 <= R[i] <= T, "Li y Ri " +
                                f"están fuera de los límites para i = {i+1}")
        elif "sub4" in caseName:
            # Subtarea 4: 100 > Ri - Li - Ai donde Ai es la respuesta a la
            # i-ésima pregunta
            prefixSum = computePrefixSum(text)
            for i in range(Q):
                self.assertTrue(1 <= L[i] <= R[i] <= T, "Li y Ri están " +
                                f"fuera de los límites para i = {i+1}")
                Ai = prefixSum[R[i]] - prefixSum[L[i]]
                self.assertTrue(R[i] - L[i] - Ai < 100, "Li y Ri están " +
                                f"fuera de los límites para i = {i+1}")
        else:
            # Sin restricciones adicionales
            for i in range(Q):
                self.assertTrue(1 <= L[i] <= R[i] <= T, "Li y Ri están " +
                                f"fuera de los límites para i = {i+1}")


if __name__ == '__main__':
    validatortest.main()
