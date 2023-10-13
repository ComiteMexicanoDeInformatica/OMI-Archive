import re
import sys
import unittest
from omegaup.validator import validatortest


def checkNQ(self, N, Q, case_name):
    if "sub1" in case_name:
        # Subtarea 1. 1 <= N, Q <= 1000
        self.assertTrue(2 <= N <= 1000, "N está fuera"
                        " de los límites.")
        self.assertTrue(2 <= Q <= 1000, "Q está fuera"
                        " de los límites.")
    if "sub2" in case_name:
        # 1 <= N, Q, <= 10^5
        self.assertTrue(2 <= N <= 1e5, "N está fuera"
                        " de los límites.")
        self.assertTrue(2 <= Q <= 1e5, "Q está fuera"
                        " de los límites.")
    if "sub3" in case_name:
        # 1 <= N, Q, <= 10^5
        self.assertTrue(2 <= N <= 1e5, "N está fuera"
                        " de los límites.")
        self.assertTrue(2 <= Q <= 1e5, "Q está fuera"
                        " de los límites.")
    if "sub4" in case_name:
        # 1 <= N, Q, <= 3*10^5
        self.assertTrue(2 <= N <= 3e5, "N está fuera"
                        " de los límites.")
        self.assertTrue(2 <= Q <= 3e5, "Q está fuera"
                        " de los límites.")


def checkA(self, A, Q, case_name):
    if "sub1" in case_name:
        # Subtarea 1. 1 <= A <= 2000
        self.assertTrue(Q <= A <= 2000, f"A = {A} está fuera"
                        " de los límites.")
    if "sub2" in case_name:
        # 1 <= A <= 2*10^5
        self.assertTrue(Q <= A <= 2e5, f"A = {A} está fuera"
                        " de los límites.")
    if "sub3" in case_name:
        # 1 <= A <= 2*10^5
        self.assertTrue(Q <= A <= 2e5, f"A = {A} está fuera"
                        " de los límites.")
    if "sub4" in case_name:
        # 1 <= A <= 6*10^5
        self.assertTrue(Q <= A <= 6e5, f"A = {A} está fuera"
                        " de los límites.")


def dfs(self, N, graph):
    vis = [0 for i in range(N + 1)]
    cnt = 0
    stack = [1]
    while len(stack) > 0:
        node = stack.pop()
        cnt += 1
        vis[node] = 1
        for child in graph[node]:
            if vis[child] == 0:
                stack.append(child)
    self.assertTrue(cnt == N, "La lista de adjacencia"
                    " no representa un árbol.")


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
        self.assertTrue(re.match(regex, lines[0]), "Se esperaban dos enteros"
                        "N y Q en la primera línea.")
        # Verifica que N y Q estén dentro de los límites.
        N, Q = map(int, lines[0].split())
        checkNQ(self, N, Q, case_name)
        # Verifica que la segunda línea contenga N caracteres.
        self.assertTrue(re.match("[a-z]+", lines[1]), f"Se esperaban {N}"
                        " caracteres en la segunda línea")
        S = lines[1].split()
        S = str(S)
        self.assertTrue(len(S) == N + 4, f"se esperaban {N} caracteres en la"
                        f" segunda línea, hay {len(S)} {S}")
        # Checar si el árbol está conectado
        graph = [[] for i in range(N + 1)]
        regex = r"^[0-9]+ [0-9]+$"
        for i in range(2, N + 1):
            self.assertTrue(re.match(regex, lines[i]), "Se esperaban dos"
                            f" enteros Ui, Vi, en la línea {i + 1}")
            u, v = map(int, lines[i].split())
            self.assertTrue(1 <= u <= N, "Se esperaba un entero"
                            f" entre 1 y {N}.")
            self.assertTrue(1 <= v <= N, "Se esperaba un entero"
                            f" entre 1 y {N}.")
            if "sub3" in case_name:
                # El árbol debe ser una línea.
                self.assertTrue(u == i - 1 and v == i, "El árbol no"
                                " es una línea.")
            graph[u].append(v)
            graph[v].append(u)
        # Verifica si el grafo está conectado.
        dfs(self, N, graph)
        # Verifica si hay Q líneas después de la lista de adjacencia.
        self.assertEqual(len(lines), N + Q + 1, f"Se esperaban {Q}"
                         f" líneas después de la línea {N + 1}.")
        regex = r"^[0-9]+ [0-9]+ [a-z]+$"
        u = -1
        v = -1
        A = 0
        for i in range(N + 1, N + Q + 1):
            self.assertTrue(re.match(regex, lines[i]), "Se esperaban dos ent"
                            f"eros Ui, Vi, y una cadena en la línea {i + 1}")
            S1, S2, S3 = lines[i].split()
            U = int(S1)
            V = int(S2)
            S = str(S3)
            A += len(S)
            # Verifica que Ui, Vi estén dentro de los límites.
            self.assertTrue(1 <= U <= N and 1 <= V <= N, f"{U} y {V} están"
                            " fuera de los límites.")
            if "sub2" in case_name:
                if u == -1:
                    u = U
                if v == -1:
                    v = V
                # Todas las queries deben ser sobre el mismo camino.
                self.assertTrue(v == V and u == U, "Ui y Vi son distintos.")
        checkA(self, A, Q, case_name)


if __name__ == '__main__':
    validatortest.main()
