import bisect
import os
import random
import string


def generateCase(taskNumber, caseNumber, caseType):
    N = 1000
    T = 1000
    
    casePath = os.path.join("cases", f"sub{taskNumber}.{caseNumber}.in")
    with open(casePath, 'w') as f:
        f.write(f"{N} {T}\n")
        for i in range(1, N + 1):
            a = random.randint(1, 15)
            b = random.randint(1, 15)
            if caseType == 1: b = a
            elif caseType == 2:
                if a > b:
                    t = a
                    a = b
                    b = t
            elif caseType == 3:
                if a < b:
                    t = a
                    a = b
                    b = t

            d = random.randint(1, 5000)
            m = random.randint(1, 200)
            f.write(f"{d} {a} {b} {m}\n")

        for _ in range(T):
            F = random.randint(1, 5000)
            f.write(f"{F} ")


def generateS2(caseNumber, caseType):
    N = 50000
    if caseType == 4: N = 250000
    T = 10000
    
    casePath = os.path.join("cases", f"sub2.{caseNumber}.in")
    with open(casePath, 'w') as f:
        f.write(f"{N} {T}\n")
        a = random.randint(1, 15)
        b = random.randint(1, 15)
        if caseType == 1: b = a
        elif caseType == 2:
            if a > b:
                t = a
                a = b
                b = t
        elif caseType == 3:
            if a < b:
                t = a
                a = b
                b = t

        d = random.randint(1, 5000)
        for _ in range(N):
            m = random.randint(50, 500)
            f.write(f"{d} {a} {b} {m}\n")

        for _ in range(T):
            if a > b: lims = d + (d // 3)
            elif a == b: lims = d + (d // 3)
            else: lims = 3 * d
            F = random.randint(1, lims)
            f.write(f"{F} ")


def generateS3(subtask, caseNumber, caseType):
    N = 250000
    T = 10000
    
    casePath = os.path.join("cases", f"sub{subtask}.{caseNumber}.in")
    with open(casePath, 'w') as f:
        f.write(f"{N} {T}\n")
        a = random.randint(1, 15)
        b = random.randint(1, 15)
        if caseType == 1: b = a
        elif caseType == 2:
            if a > b:
                t = a
                a = b
                b = t
        elif caseType == 3:
            if a < b:
                t = a
                a = b
                b = t

        for _ in range(N):
            a = random.randint(1, 15)
            if caseType == 1: b = a
            else: b = random.randint(1, 15)
            d = random.randint(1, 5000)
            m = random.randint(50, 500)
            f.write(f"{d} {a} {b} {m}\n")

        for _ in range(T):
            if a > b: lims = d + (d // 2)
            elif a == b: lims = d + (d // 3)
            else: lims = 4 * d
            F = random.randint(1, lims)
            f.write(f"{F} ")


if __name__ == '__main__':
    #for s in range(1,3):
    #    generateCase(1, s, 1)
    #for s in range(3,5):
    #    generateCase(1, s, 2)
    #for s in range(5,7):
    #    generateCase(1, s, 3)
    #for s in range(7,11):
    #    generateCase(1, s, 4)

    #for s in range(1, 2):
    #    generateS2(s, 1)
    for s in range(2, 3):
        generateS2(s, 2)
    #for s in range(3, 4):
    #    generateS2(s, 3)
    #for s in range(4, 6):
    #    generateS2(s, 4)

    #for s in range(1, 3):
    #    generateS3(3, s, 1)

    #for s in range(1, 3):
    #    generateS3(4, s, 2)
