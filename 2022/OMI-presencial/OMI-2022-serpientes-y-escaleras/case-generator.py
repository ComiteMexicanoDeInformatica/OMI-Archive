import os
import random


def makeCase(casePath, N, M, L, R):
    with open(casePath, "w") as f:
        f.write(f"{N} {M}\n")
        for Li, Ri in zip(L, R):
            f.write(f"{Li} {Ri}\n")


def generateCase(taskNumber, caseNumber):
    # Subtarea 1: N, M <= 500
    if taskNumber == 1:
        N = random.randint(1, 500)
        M = random.randint(1, 500)
    # Subtarea 2: N, M <= 10^5
    elif taskNumber == 2:
        N = random.randint(1, 1e5)
        M = random.randint(1, 1e5)
    # Subtarea 3: Sin reestricciones adicionales. 1 <= N, M <= 10^6
    elif taskNumber == 3:
        N = random.randint(1, 1e6)
        M = random.randint(1, 1e6)
    else:
        raise ValueError(f"Número de subtarea inválido: {taskNumber}")

    portals = random.sample(range(2*N + 2), 2*N)
    L = portals[:N]
    R = portals[N:]

    casePath = os.path.join("cases", f"sub{taskNumber}.{caseNumber}.in")
    makeCase(casePath, N, M, L, R)


if __name__ == '__main__':
    for t in range(1, 4):
        for c in range(6):
            generateCase(t, c)
