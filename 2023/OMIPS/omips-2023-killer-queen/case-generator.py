import random
import os
from typing import List, Tuple


def makeCase(caseName: str, width: int, mochila: int, iniX: int,
             iniY: int, direc: str, beepers: List[Tuple[int, int]]):
    beepersXML = [f"<monton x=\"{x}\" y=\"{y}\" zumbadores=\"1\"/>"
                  for (x, y) in beepers]
    beepersXML = "\n\t\t\t".join(beepersXML)

    baseXML = f"""<ejecucion>
    <condiciones instruccionesMaximasAEjecutar="10000000"
                 longitudStack="65000">
    </condiciones>
    <mundos>
        <mundo nombre="mundo_0" ancho="{width}" alto="{width}">
            {beepersXML}
            <posicionDump x="{iniX}" y="{iniY}"/>
        </mundo>
    </mundos>
    <programas tipoEjecucion="CONTINUA" intruccionesCambioContexto="1"
               milisegundosParaPasoAutomatico="0">
        <programa nombre="p1" ruta="{{$2$}}" mundoDeEjecucion="mundo_0"
                  xKarel="{iniX}" yKarel="{iniY}" direccionKarel="{direc}"
                  mochilaKarel="{mochila}">
            <despliega tipo="MUNDO"/>
        </programa>
    </programas>
</ejecucion>"""

    casePath = os.path.join("cases", caseName)
    with open(casePath, "w") as f:
        f.write(baseXML)


def makeSubtask(taskNumber, caseNumber):
    width = random.randint(15, 40)
    height = width
    iniX = random.randint(1, width)
    iniY = random.randint(1, width)
    if caseNumber == 1:
        iniX = iniY = 1
    elif caseNumber == 2:
        iniY = height

    mochila = 0
    if taskNumber in (1, 2):
        # Karel lleva 1 zumbador
        mochila = 1
    beepers = []
    beepers.append((iniX, iniY))
    if taskNumber == 1:
        for x in range(1, width + 1):
            if x != iniX and random.randint(1, 11) <= caseNumber:
                beepers.append((x, iniY))
        for y in range(1, height + 1):
            if y != iniY and random.randint(1, 11) <= caseNumber:
                beepers.append((iniX, y))
    elif taskNumber in [2, 4]:
        for x in range(1, width + 1):
            for y in range(1, height + 1):
                if x == iniX and y == iniY:
                    pass
                elif random.randint(1, 11) <= caseNumber:
                    beepers.append((x, y))
    else:
        d = [0, 0, 0, 0, 0, 0, 0, 0]
        for x in range(1, width + 1):
            for y in range(1, height + 1):
                if x == iniX and y == iniY:
                    pass
                elif random.randint(1, 11) <= caseNumber:
                    if x == iniX:
                        if y > iniY and d[0] == 0:
                            beepers.append((x, y))
                            d[0] = 1
                        elif y < iniY and d[4] == 0:
                            beepers.append((x, y))
                            d[4] = 1
                    elif y == iniY:
                        if x > iniX and d[2] == 0:
                            beepers.append((x, y))
                            d[2] = 1
                        elif x < iniX and d[6] == 0:
                            beepers.append((x, y))
                            d[6] = 1
                    elif x + y == iniX + iniY:
                        if x > iniX and d[3] == 0:
                            beepers.append((x, y))
                            d[3] = 1
                        elif x < iniX and d[7] == 0:
                            beepers.append((x, y))
                            d[7] = 1
                    elif y - x == iniY - iniX:
                        if x > iniX and d[1] == 0:
                            beepers.append((x, y))
                            d[1] = 1
                        elif x < iniX and d[5] == 0:
                            beepers.append((x, y))
                            d[5] = 1
                    else:
                        beepers.append((x, y))

    direcciones = ["NORTE", "SUR", "ESTE", "OESTE"]

    makeCase(f"sub{taskNumber}.{caseNumber}.in",
             width, mochila, iniX, iniY,
             direcciones[caseNumber % 4], beepers)


def main():
    pointsPerSubtask = [25, 30, 25, 20]
    random.seed(2023)

    with open("testplan", "w") as f:
        for t, points in enumerate(pointsPerSubtask):
            for c in range(10):
                makeSubtask(t + 1, c + 1)
                f.write(f"sub{t + 1}.{c + 1} {points}\n")
                points = 0


if __name__ == '__main__':
    main()
