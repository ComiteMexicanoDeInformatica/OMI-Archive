import re
import sys
import unittest
from omegaup.validator import validatortest


def checkNM(self, N, M, case_name):
    self.assertTrue(1 <= N <= 500, "N está fuera de los límites.")
    self.assertTrue(1 <= M <= 500, "M está fuera de los límites.")
    if "sub1" in case_name:
        self.assertTrue(1 <= N <= 20, "N está fuera de los límites.")
        self.assertTrue(1 <= M <= 20, "M está fuera de los límites.")
    if "sub3" in case_name:
        self.assertTrue(1 <= N <= 100, "N está fuera de los límites.")
        self.assertTrue(1 <= M <= 100, "M está fuera de los límites.")


class Test(unittest.TestCase):
    def test(self):
        case_name = sys.argv[1]
        with open("data.in", "r") as handle:
            original_input = handle.read()
        lines = original_input.split("\n")
        self.assertEqual(lines[-1], "", "Se esperaba un salto de línea al"
                         " final del archivo.")
        lines.pop()
        # Verifica que la primera línea contenga dos enteros N y M.
        regex = r"^[0-9]+ [0-9]+$"
        self.assertTrue(re.match(regex, lines[0]), "Se esperaban dos ente"
                        "ros N y M en la primera línea.")
        # Verifica que N y M estén dentro de los límites.
        N, M = map(int, lines[0].split())
        checkNM(self, N, M, case_name)
        # Verifica que los caracteres sean válidos.
        for i in range(1, N + 1):
            S = lines[i].split()
            S = str(S)
            self.assertTrue(len(S) - 4 == M, f"Hay {len(S)} caracteres"
                            f" en la fila {i} del tablero.")
            for Sj in S[2:-2]:
                self.assertTrue(Sj in ('.', '#'), "Hay un"
                                f" caracter inválido {Sj}.")
        # Verifica que Q sea un valor adecuado.
        self.assertTrue(re.match(r"[0-9]+", lines[N + 1]), "Se esper"
                        f"aban un entero Q en la línea {N + 1}.")
        Q = lines[N + 1].split()
        Q = str(Q)
        Q = int(Q[2:-2])
        if "sub2" in case_name:
            self.assertTrue(Q == 1, "El valor de Q es inválido.")
        elif "sub1" in case_name:
            self.assertTrue(1 <= Q <= 20, "El valor de Q es inválido.")
        else:
            self.assertTrue(1 <= Q <= 30000, "El valor de Q"
                            " está fuera de los límites.")
        # Verificar que las queries sean correctas.
        for i in range(N + 2, N + 2 + Q):
            regex = r"^[0-9]+ [0-9]+ [0-9]+ [0-9]+$"
            self.assertTrue(re.match(regex, lines[i]), "Se esperaban"
                            f" cuatro enteros en la línea {i + 1}")
            a, b, c, d = map(int, lines[i].split())
            self.assertTrue(1 <= a <= N, "Las coordenadas en la query"
                            f" {i - N - 1} son inválidas.")
            self.assertTrue(1 <= b <= M, "Las coordenadas en la query"
                            f" {i - N - 1} son inválidas.")
            self.assertTrue(1 <= c <= N, "Las coordenadas en la query"
                            f" {i - N - 1} son inválidas.")
            self.assertTrue(1 <= d <= M, "Las coordenadas en la query"
                            f" {i - N - 1} son inválidas.")


if __name__ == '__main__':
    validatortest.main()
