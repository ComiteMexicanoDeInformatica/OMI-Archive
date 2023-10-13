import random
import os
from typing import List, Tuple


def makeCase(caseName: str, mazo1: List[Tuple[int, int]],
             mazo2: List[Tuple[int, int]]):
    beepers1 = [f"<monton x=\"{x}\" y=\"1\" zumbadores=\"{z}\"/>"
                for (x, z) in mazo1]
    beepers2 = [f"<monton x=\"{x}\" y=\"2\" zumbadores=\"{z}\"/>"
                for (x, z) in mazo2]
    beepersXML1 = "\n\t\t\t".join(beepers1)
    beepersXML2 = "\n\t\t\t".join(beepers2)

    baseXML = f"""<ejecucion>
    <condiciones instruccionesMaximasAEjecutar="10000000"
                 longitudStack="65000">
    </condiciones>
    <mundos>
        <mundo nombre="mundo_0" ancho="100" alto="100">
            {beepersXML1}
            {beepersXML2}
        </mundo>
    </mundos>
    <programas tipoEjecucion="CONTINUA" intruccionesCambioContexto="1"
               milisegundosParaPasoAutomatico="0">
        <programa nombre="p1" ruta="{{$2$}}" mundoDeEjecucion="mundo_0"
                  xKarel="1" yKarel="1" direccionKarel="NORTE"
                  mochilaKarel="INFINITO">
                  <despliega tipo="ORIENTACION"></despliega>
        </programa>
    </programas>
</ejecucion>"""

    casePath = os.path.join("cases", caseName)
    with open(casePath, "w") as f:
        f.write(baseXML)


def makeSubtask(taskNumber, caseNumber):

    mazo1 = []
    mazo2 = []

    m1 = random.randint(25, 100)
    m2 = random.randint(25, 100)
    for i in range(1, m1 + 1):
        z = random.randint(1, 100)
        mazo1.append((i, z))

    for i in range(1, m2 + 1):
        z = random.randint(1, 100)
        mazo2.append((i, z))

    makeCase(f"sub{taskNumber}.{caseNumber}.in",
             mazo1, mazo2)


def makeSubtask2(taskNumber, caseNumber):

    mazo1 = []
    mazo2 = []

    m1 = random.randint(50, 100)
    m2 = random.randint(50, 100)
    for i in range(1, m1 + 1):
        z = random.randint(1, 5)
        mazo1.append((i, z))

    for i in range(1, m2 + 1):
        z = random.randint(1, 5)
        mazo2.append((i, z))

    makeCase(f"sub{taskNumber}.{caseNumber}.in",
             mazo1, mazo2)


def main():
    random.seed(2023)

    for c in range(5):
        makeSubtask(5, c + 1)

    for c in range(6, 11):
        makeSubtask2(5, c)


if __name__ == '__main__':
    main()
