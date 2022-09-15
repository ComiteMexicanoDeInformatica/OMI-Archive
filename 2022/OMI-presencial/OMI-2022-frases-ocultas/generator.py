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


def generateS2(caseNumber):
    N = 10
    T = 1000000
    
    casePath = os.path.join("cases", f"sub2.{caseNumber}.in")
    with open(casePath, 'w') as f:
        f.write(f"{T} {N}\n")
        
        for _ in range(T):
            a = random.randint(97, 122)
            c = chr(a)
            f.write(f"{c}")
        f.write("\n")

        for i in range(N):
            if i == 0:
                f.write("3 omi\n")
            else:
                L = (i + 1) * 10000
                f.write(f"{L} ")
                for _ in range(L):
                    a = random.randint(97, 122)
                    c = chr(a)
                    f.write(f"{c}")
                f.write("\n")


def generateS3(caseNumber):
    N = 1000
    T = 1000
    
    casePath = os.path.join("cases", f"sub3.{caseNumber}.in")
    with open(casePath, 'w') as f:
        f.write(f"{T} {N}\n")
        
        for _ in range(T):
            a = random.randint(97, 122)
            c = chr(a)
            f.write(f"{c}")
        f.write("\n")

        for i in range(N):
            if i == 0:
                f.write("3 omi\n")
            else:
                L = random.randint(3,1000)
                f.write(f"{L} ")
                for _ in range(L):
                    a = random.randint(97, 122)
                    c = chr(a)
                    f.write(f"{c}")
                f.write("\n")


def generateS4(caseNumber):
    N = 100000
    T = 1000000
    
    casePath = os.path.join("cases", f"sub4.{caseNumber}.in")
    with open(casePath, 'w') as f:
        f.write(f"{T} {N}\n")
        
        for caso in range(T):
            a = random.randint(97, 122 - caseNumber)
            c = chr(a)
            f.write(f"{c}")
        f.write("\n")

        for i in range(N):
            if i == 0:
                f.write("3 omi\n")
            else:
                L = 10
                f.write(f"{L} ")
                for _ in range(L):
                    a = random.randint(97, 122)
                    c = chr(a)
                    f.write(f"{c}")
                f.write("\n")


if __name__ == '__main__':
    for s in range(1, 6):
        generateS4(s)
