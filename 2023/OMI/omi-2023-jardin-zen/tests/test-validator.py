import re
import sys
import unittest
from omegaup.validator import validatortest


def checkNM(self, N, M, case_name):
    self.assertTrue(1 <= N <= 1000, "N está fuera de los límites.")
    self.assertTrue(1 <= M <= 1000, "M está fuera de los límites.")
    if "sub1" in case_name:
        self.assertTrue(M == 2, "M está fuera de los límites.")
    if "sub3" in case_name:
        self.assertTrue(1 <= N <= 100, "N está fuera de los límites.")
        self.assertTrue(1 <= M <= 100, "M está fuera de los límites.")


def ComponentsCheck(self, N, M, grid):
    # Checar que no haya dos componentes que se solapen.
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    vis = [[0 for j in range(M)] for i in range(N)]
    NewGrid = [[0 for j in range(M)] for i in range(N)]
    cnt = 1
    for i in range(N):
        for j in range(M):
            if vis[i][j] == 1 or grid[i][j] == 0:
                continue
            mx = i
            my = j
            Mx = i
            My = j
            stack = [[i, j]]
            while len(stack) > 0:
                X = stack.pop()
                vis[X[0]][X[1]] = 1
                mx = min(X[0], mx)
                my = min(X[1], my)
                Mx = max(X[0], Mx)
                My = max(X[1], My)
                for k in range(4):
                    Y = [X[0] + dx[k], X[1] + dy[k]]
                    if Y[0] < 0 or Y[0] >= N or Y[1] < 0 or Y[1] >= M:
                        continue
                    if vis[Y[0]][Y[1]] == 1 or grid[Y[0]][Y[1]] == 0:
                        continue
                    stack.append(Y)
            for x in range(mx, Mx + 1):
                for y in range(my, My + 1):
                    self.assertTrue(NewGrid[x][y] == 0, "Hay componentes"
                                    " que se solapan.")
                    NewGrid[x][y] = cnt
            cnt += 1


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
        grid = [[1 for j in range(M)] for i in range(N)]
        # Verifica que los caracteres sean válidos.
        for i in range(1, N + 1):
            S = lines[i].split()
            S = str(S)
            S = S[2:-2]
            self.assertTrue(len(S) == M, f"Hay {len(S)} caracteres"
                            f" en la fila {i} del tablero.")
            for j in range(0, M):
                if S[j] == '#':
                    grid[i - 1][j] = 0
                self.assertTrue(S[j] in ('.', '#'), "Hay un"
                                f" caracter inválido {S[j]}.")
        if "sub2" in case_name:
            ComponentsCheck(self, N, M, grid)


if __name__ == '__main__':
    validatortest.main()
