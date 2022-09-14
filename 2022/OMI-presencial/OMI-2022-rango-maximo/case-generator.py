from multiprocessing import current_process
import random
import os
from re import sub
import string


def makeFile(Path, N, D, U, E, Cs, EL):
    with open(Path, 'w') as f:
        f.write(f"{N} {D}\n")
        for i in U:
            f.write(f"{i} ")
        f.write("\n")
        f.write(f"{E}\n")
        if(E > 0):
            curr_Pos = 0
            for i in Cs:
                f.write(f"{i}\n")
                for j in range(0, i):
                    f.write(f"{EL[curr_Pos][0]} {EL[curr_Pos][1]}\n")
                    curr_Pos+=1

#subtarea 1 
def makeCase(subTask, caseNum):
    NLimit = 100000
    PLimit = 1000000000
    DLimit = 1000000000
    ELimit = 100000

    if subTask == 0 :
        NLimit = 1000
        PLimit = 1000
        DLimit = 1000
        ELimit = 0
    elif subTask == 1:
        NLimit = 1000
        ELimit = 0
    elif subTask == 2:
        NLimit = 1000
        ELimit = 1000
    elif subTask == 3:
        ELimit = 10
    
    N = random.randint(0, 1000000000) % (NLimit - 1) + 1 
    D = random.randint(0, 1000000000) % (DLimit - 1) + 1
    U = []
    if ELimit > 0 :
        E = random.randint(0, 1000000000) % (ELimit - 1) + 1
    else : 
        E = 0

    for i in range(0, N) :
        U.append(random.randint(0, PLimit))
    
    visitados = [0] * N
    Pares = []
    Cs = []

    for i in range(0, E):
        if(ELimit <= 0):
            break
        C = random.randint(0, ELimit) % (N-1) + 1
        if(C > ELimit):
            C = ELimit
        ELimit -= C
        
        Cs.append(C)
        
        for j in range(0, C):
            Pos = 0
            while(Pos == 0 or visitados[Pos] == 1):
                Pos = random.randint(0, 1000000000) % (N-1) + 1
            Score = random.randint(0, 1000000000) % (PLimit-1) + 1
            Pares.append([Pos, Score])

    
    E = len(Cs)

    print(E)

    U.sort()
    casePath =  os.path.join("cases", f"sub{subTask}.{caseNum}.in")
    makeFile(casePath, N, D, U, E, Cs, Pares)

def specialCase(subtask, caseNumber):
    N = 100000
    E = 100000
    d = 1000

    casePath = os.path.join("cases", f"sub{subtask}.{caseNumber}.in")
    with open(casePath, 'w') as f:
        f.write(f"{N} {d}\n")
        for i in range(1, N + 1):
            f.write(f"{i} ")
        f.write("\n")

        f.write(f"{E}\n")
        for _ in range(E):
            f.write("1\n")

            a = random.randint(1, N)
            b = random.randint(1, N)
            f.write(f"{a} {b}\n")
    

if __name__ == '__main__':
    #for t in range(0, 5):
    #    for c in range(10):
    #        makeCase(t, c)

    specialCase(4, 10)
