import re
import sys
import unittest
from omegaup.validator import validatortest


class Test(unittest.TestCase):
    # pylint: disable=too-many-statements
    def test(self):
        caseName = sys.argv[1]
        with open("data.in", "r") as handle:
            original_input = handle.read()

        lines = original_input.split("\n")
        self.assertEqual(lines[-1], "", "Se esperaba una nueva línea al " +
                         "final del archivo")
        lines.pop()

        # Límites
        # 1 <= N <= 10^5, 0 <= d <= 10^9, 1 <= Pi <= 10^9, 0 <= E <= 10^5
        maxN = 1e5
        maxd = 1e9
        maxP = 1e9
        maxE = 1e5
        if "sub1" in caseName:
            # Subtarea 1: N, Pi <= 1000, E = 0
            maxN = 1000
            maxP = 1000
            maxE = 0
        elif "sub2" in caseName:
            # Subtarea 2: N <= 1000, E = 0
            maxN = 1000
            maxE = 0
        elif "sub3" in caseName:
            # Subtarea 3: N, E <= 1000
            maxN = 1000
            maxE = 1000
        elif "sub4" in caseName:
            # Subtarea 4: E <= 10
            maxE = 10
        elif "sub5" in caseName:
            # Subtarea 5: Sin reestricciones adicionales
            pass
        else:
            self.fail(f"Nombre de caso inválido: {caseName}")

        # Verifica que la primera línea contenga dos enteros N, d
        regex = re.compile(r"\d+ \d+$")
        self.assertTrue(regex.match(lines[0]), "Se esperaban dos " +
                        "enteros N, d en la primera línea")
        N, d = map(int, lines[0].split())
        self.assertTrue(1 <= N <= maxN, "N está fuera de los límites")
        self.assertTrue(0 <= d <= maxd, "d está fuera de los límites")

        # Verifica que la segunda línea contenga N enteros ordenados de menor a
        # mayor
        regex = re.compile(r"^\d+(\s\d+)*$")
        self.assertTrue(regex.match(lines[1]), f"Se esperaban {N} enteros " +
                        "en la segunda línea")
        P = list(map(int, lines[1].split()))
        self.assertEqual(len(P), N, f"Se esperaban {N} enteros en la " +
                         "segunda línea")
        self.assertTrue(all(P[i-1] <= P[i] for i in range(1, N)), "Los " +
                        "Pi deben estar ordenados de menor a mayor")
        self.assertTrue(all(1 <= Pi <= maxP for Pi in P), "Algún Pi está " +
                        "fuera de los límites")

        # Verifica que la tercera línea contenga un entero E
        regex = re.compile(r"\d+$")
        self.assertTrue(regex.match(lines[2]), "Se esperaba un entero E en " +
                        "la tercera línea")
        E = int(lines[2])
        self.assertTrue(0 <= E <= maxE, "E está fuera de los límites")

        # Verifica que después haya E bloques
        numOfChanges = 0
        offset = 3
        for _ in range(E):
            # Verifica que la primera línea del bloque contenga un entero C
            regex = re.compile(r"\d+$")
            self.assertTrue(regex.match(lines[offset]), "Se esperaba un " +
                            f"entero C en la línea {offset+1}")
            C = int(lines[offset])
            self.assertTrue(1 <= C <= N, "C está fuera de los límites en la " +
                            f"línea {offset+1}")
            # Verifica que después haya C líneas
            self.assertTrue(len(lines) >= offset + 1 + C, "Se esperaban " +
                            f"{C} líneas después de la línea {offset+1}")
            # Verifica que las siguientes C líneas contengan dos enteros i, Pi
            regex = re.compile(r"\d+ \d+$")
            for j in range(offset + 1, offset + 1 + C):
                self.assertTrue(regex.match(lines[j]), "Se esperaban dos " +
                                f"enteros i, Pi en la línea {j+1}")
                i, Pi = map(int, lines[j])
                self.assertTrue(1 <= i <= N, "i está fuera de los límites " +
                                f"en la línea {j+1}")
                self.assertTrue(1 <= Pi <= maxP, "Pi está fuera de los " +
                                f"límites en la línea {j+1}")
            offset += 1 + C
            numOfChanges += C

        # Verifica que la cantidad de cambios entre todos los bloques es menor
        # o igual a 10^5
        self.assertTrue(numOfChanges <= 1e5, "Se excedió el máximo número " +
                        "de cambios permitidos")

        # Verifica que ya no haya más líneas que leer
        self.assertEqual(len(lines), offset, f"Se esperaban {offset} líneas " +
                         "en la entrada")


if __name__ == '__main__':
    validatortest.main()
