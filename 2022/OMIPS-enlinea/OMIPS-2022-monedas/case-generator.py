import random
import os


# pylint: disable=too-many-arguments
def makeCase(caseName, width, height, beepers):
    beepersXML = []
    listaDump = []

    listaDump.append("<posicionDump x=\"1\" y=\"1\"/>")
    for (x, y), k in beepers.items():
        beepersXML.append(f"<monton x=\"{x}\" y=\"{y}\" zumbadores=\"{k}\"/>")
        listaDump.append(f"<posicionDump x=\"{x}\" y=\"{y}\"/>")
    beepersXML = "\n\t\t\t".join(beepersXML)
    listaDump = "\n\t\t\t".join(listaDump)

    baseXML = f"""<ejecucion>
    <condiciones instruccionesMaximasAEjecutar="10000000"
                 longitudStack="65000">
    </condiciones>
    <mundos>
        <mundo nombre="mundo_0" ancho="{width}" alto="{height}">
            {beepersXML}
            {listaDump}
        </mundo>
    </mundos>
    <programas tipoEjecucion="CONTINUA" intruccionesCambioContexto="1"
               milisegundosParaPasoAutomatico="0">
        <programa nombre="p1" ruta="{{$2$}}" mundoDeEjecucion="mundo_0"
                  xKarel="1" yKarel="1"
                  direccionKarel="NORTE"
                  mochilaKarel="INFINITO">
            <despliega tipo="MUNDO"/>
        </programa>
    </programas>
</ejecucion>"""

    casePath = os.path.join("cases", caseName)
    with open(casePath, "w") as f:
        f.write(baseXML)


def makeSubtask(taskNumber, caseNumber):
    width = 99
    if taskNumber == 1:
        height = 1
    else:
        height = 100

    if caseNumber <= 7:
        nbeepers = random.randint(1, width - 2)
        if (nbeepers % 2) == 1:
            nbeepers -= 1
    else:
        nbeepers = 9

    beepers = {}
    for i in range(nbeepers):
        beepers[i + 2, 1] = random.randint(1, 2)

    makeCase(f"sub{taskNumber}.{caseNumber}.in",
             width, height, beepers)


if __name__ == '__main__':
    random.seed(2022)
    for t in range(1, 3):
        for c in range(1, 11):
            makeSubtask(t, c)
