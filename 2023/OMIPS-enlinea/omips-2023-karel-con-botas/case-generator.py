import random
import os
from typing import List


def makeCase(caseName: str, width: int, height: int, beepers: List[int],
             limitMoves: bool):
    constraints = "<comando nombre=\"AVANZA\" " \
        f"maximoNumeroDeEjecuciones=\"{2*width}\"/>" if limitMoves else ""

    beepersXML = [f"<monton x=\"{i + 1}\" y=\"{1}\" zumbadores=\"{k}\"/>"
                  for i, k in enumerate(beepers)]
    beepersXML = "\n\t\t\t".join(beepersXML)

    baseXML = f"""<ejecucion>
    <condiciones instruccionesMaximasAEjecutar="10000000"
                 longitudStack="65000">
        {constraints}
    </condiciones>
    <mundos>
        <mundo nombre="mundo_0" ancho="{width}" alto="{height}">
            {beepersXML}
            <posicionDump x="1" y="1"/>
        </mundo>
    </mundos>
    <programas tipoEjecucion="CONTINUA" intruccionesCambioContexto="1"
               milisegundosParaPasoAutomatico="0">
        <programa nombre="p1" ruta="{{$2$}}" mundoDeEjecucion="mundo_0"
                  xKarel="1" yKarel="1" direccionKarel="NORTE"
                  mochilaKarel="INFINITO">
            <despliega tipo="MUNDO"/>
        </programa>
    </programas>
</ejecucion>"""

    casePath = os.path.join("cases", caseName)
    with open(casePath, "w") as f:
        f.write(baseXML)


def makeSubtask(taskNumber, caseNumber):
    width = random.randint(4, 100)
    height = random.randint(4, 100)
    maxBeepersPerCell = random.randint(1, 200)
    sortBeepers = False
    limitMoves = False

    if taskNumber == 1:
        # Subtarea 1. La energía máxima de Karel es igual a 1.
        maxBeepersPerCell = 1
    elif taskNumber == 2:
        # Subtarea 2. Los años de vida de Karel pasan en orden.
        sortBeepers = True
    elif taskNumber == 3:
        # Subtarea 3. La energía máxima de Karel es igual a 10.
        maxBeepersPerCell = 10
    elif taskNumber == 4:
        # Subtarea 4. El alto del mundo es mayor que la energía máxima de
        # Karel.
        maxBeepersPerCell = random.randint(1, height - 1)
    elif taskNumber == 5:
        # Subtarea 5. El alto del mundo de Karel es 1.
        height = 1
    elif taskNumber == 6:
        # Subtarea 6. Karel puede ejecutar la instrucción ´avanza/move´ un
        # máximo de 2N veces donde N es el ancho del mundo.
        limitMoves = True
    else:
        raise ValueError("Invalid task number")

    nbeepers = random.randint(4, width)
    beepers = []
    while len(beepers) < nbeepers:
        size = min(random.randint(1, maxBeepersPerCell),
                   nbeepers - len(beepers))
        beepers.extend(range(maxBeepersPerCell, maxBeepersPerCell - size, -1))
    if not sortBeepers:
        random.shuffle(beepers)

    makeCase(f"sub{taskNumber}.{caseNumber}.in",
             width, height, beepers, limitMoves)


def main():
    pointsPerSubtask = [10, 16, 14, 20, 22, 18]
    random.seed(2023)

    with open("testplan", "w") as f:
        for t, points in enumerate(pointsPerSubtask):
            for c in range(5):
                makeSubtask(t + 1, c + 1)
                f.write(f"sub{t + 1}.{c + 1} {points}\n")
                points = 0


if __name__ == '__main__':
    main()
