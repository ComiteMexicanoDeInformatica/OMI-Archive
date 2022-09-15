import random
import os


# pylint: disable=too-many-arguments
def makeCase(caseName, width, height, xKarel, yKarel, dirKarel, beepers,
             limitMoves):
    constraints = ""
    if limitMoves:
        constraints = "<comando " + \
                      "nombre=\"AVANZA\" " + \
                      f"maximoNumeroDeEjecuciones=\"{2*width*height}\"/>"

    beepersXML = []
    for (x, y), k in beepers.items():
        beepersXML.append(f"<monton x=\"{x}\" y=\"{y}\" zumbadores=\"{k}\"/>")
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
                  xKarel="{xKarel}" yKarel="{yKarel}"
                  direccionKarel="{dirKarel}"
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
    xKarel = 1
    yKarel = 1
    dirKarel = random.choice(["NORTE", "SUR", "ESTE", "OESTE"])
    maxBeepersPerCell = 10

    if taskNumber == 1:
        # Karel empieza en la (1, 1) y el mundo tiene altura 1.
        height = 1
        limitMoves = False
    elif taskNumber == 2:
        # Karel empieza en la (1, 1), no hay límite de avanza / move y a lo más
        # hay un niño por cada casilla.
        limitMoves = False
        maxBeepersPerCell = 1
    elif taskNumber == 3:
        # Karel empieza en la (1, 1), no hay límite de avanza / move y puede
        # haber cualquier cantidad de niños en una misma casilla.
        limitMoves = False
    elif taskNumber == 4:
        # Karel empieza en la (1, 1), puedes llamar avanza / move a lo más
        # 2 x A veces y a lo más hay un niño por cada casilla.
        limitMoves = True
        maxBeepersPerCell = 1
    elif taskNumber == 5:
        # Karel empieza en la (1, 1), puedes llamar avanza / move a lo más
        # 2 x A veces y puede haber cualquier cantidad de niños en una misma
        # casilla.
        limitMoves = True
    elif taskNumber == 6:
        # Karel inicia en cualquier posición, no hay límite de avanza / move.
        xKarel = random.randint(1, width)
        yKarel = random.randint(1, height)
        limitMoves = False
    elif taskNumber == 7:
        # Karel inicia en cualquier posición, puedes llamar avanza / move a lo
        # más 2 x A veces.
        xKarel = random.randint(1, width)
        yKarel = random.randint(1, height)
        limitMoves = True
    else:
        raise ValueError("Invalid subtask")

    nbeepers = random.randint(0, width*height)
    beepers = {}
    for _ in range(nbeepers):
        beepers[(random.randint(1, width), random.randint(1, height))] = \
            random.randint(1, maxBeepersPerCell)

    makeCase(f"sub{taskNumber}.{caseNumber}.in",
             width, height, xKarel, yKarel, dirKarel, beepers,
             limitMoves)


if __name__ == '__main__':
    random.seed(2022)
    for t in range(1, 8):
        for c in range(1, 6):
            makeSubtask(t, c)
