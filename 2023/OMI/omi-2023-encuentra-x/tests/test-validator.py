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
        regex = r"^[0-9]+ [0-9]+ [0-9]+$"
        self.assertTrue(re.match(regex, lines[0]), "Se esperaban tres enteros"
                        " N, X, K en la primera línea.")
        N, X, K = map(int, lines[0].split())
        # Verifica que N esté dentro de los límites.
        self.assertTrue(1 <= N <= 1e6, f"N = {N} está fuera de los límites.")

        # Verifica que la segunda línea contenga N enteros separados por un
        # espacio.
        regex = r"^[0-9]+( [0-9]+)*$"
        self.assertTrue(re.match(regex, lines[1]), f"Se esperaban {N} enteros"
                        " en la segunda línea.")
        A = list(map(int, lines[1].split()))
        # Verifica que el tamaño del arreglo sea N.
        self.assertEqual(len(A), N, f"Se esperaban {N} enteros"
                         " en la segunda línea")
        # Verifica que todos los elementos sean distintos.
        self.assertTrue(len(A) == len(set(A)), "Los elementos del "
                        " arreglo no son distintos.")
        # Verifica que X sea un elemento del arreglo.
        self.assertTrue(X in A, "X no aparece entre los números del arreglo.")
        # Verifica que los elementos del arreglo estén dentro de los límites.
        self.assertTrue(all(1 <= ai <= 1e9 for ai in A), "Hay elementos del"
                        " arreglo fuera de los límites.")
        if "sub2" in case_name:
            # el arreglo debe contener todos los enteros del 1 al N.
            self.assertTrue(max(A) == N, "el arreglo no consta"
                            " de los enteros del 1 a N.")
        # Verifica que el arreglo sea el resultado
        # de rotar un arreglo ordenado.
        pos = 0
        while pos < N - 1 and A[pos] < A[pos + 1]:
            pos += 1
        pos += 1
        while pos < N - 1 and A[pos] < A[pos + 1]:
            pos += 1
        if "sub3" in case_name:
            self.assertTrue(pos == N, "El arreglo no está ordenado.")
        if pos != N:
            self.assertTrue(pos == N - 1 and A[N - 1] < A[0], "El arreglo no "
                            "es el resultado de rotar un arreglo ordenado.")
        # Verifica las concideraciones de K en las subtareas.
        if "sub1" in case_name:
            self.assertTrue(K == N, f"K = {K} no es igual a N = {N}.")
        elif "sub4" in case_name:
            self.assertTrue(K == 21, f"K = {K} no es igual a 21.")
        else:
            self.assertTrue(1 <= K <= 20, f"K = {K} está fuera"
                            " de los límites.")


if __name__ == '__main__':
    validatortest.main()
