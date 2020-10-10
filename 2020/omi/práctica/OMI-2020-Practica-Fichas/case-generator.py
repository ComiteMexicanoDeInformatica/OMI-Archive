import random
import os
import itertools as it
from math import *

baseString = """
{N} {M}
{tablero}
""".strip(' \t\n\r')

cases = 8

for i in range(cases):
    caseName = '{}.in'.format(i+1)
    
    n = random.randint(1, 1000)
    m = random.randint(1, 1000)

    density = min(random.random(), random.random())

    tablero = ""
    for i in range(n):
        fila = ['.'] * m
        for j in range(m):
            if random.random() < density:
                fila[j] = '*'
        tablero += "".join(fila) + "\n"

    case = {
        'N': n,
        'M': m,
        'tablero': tablero
    }

    caseString = baseString.format(**case)
    casePath = os.path.join('cases', caseName)
    with open(casePath, 'w') as f:
            f.write(caseString)
