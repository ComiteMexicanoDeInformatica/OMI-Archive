import random
import os


def makeCase(caseName: str, width: int, height: int, beepers: int):
    beepersXML = f"\n\t\t\t<monton x=\"1\" y=\"1\" zumbadores=\"{beepers}\"/>"

    baseXML = f"""<ejecucion>
    <condiciones instruccionesMaximasAEjecutar="10000000"
                 longitudStack="65000">
    </condiciones>
    <mundos>
        <mundo nombre="mundo_0" ancho="{width}" alto="{height}">
            {beepersXML}
            <posicionDump x="1" y="1"/>
            <posicionDump x="2" y="1"/>
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

    casePath = os.path.join("./cases", caseName)
    with open(casePath, "w") as f:
        f.write(baseXML)


def makeSubtask(taskNumber, caseNumber):
    width = 100
    height = 100
    beepers = []

    if taskNumber == 1:
        # Subtarea 1. Cualquier triangulo es válido
        beepers = [1, 28, 57, 104, 169, 204, 281, 326, 333, 380]

    elif taskNumber == 2:
        # Subtarea 2. El área del triángulo es un primo
        beepers = [2, 17, 41, 79, 127, 151, 229, 349]

    elif taskNumber == 3:
        # Subtarea 3. El área del triángulo es la mitad de un cuadrado
        beepers = [2, 18, 32, 50, 98, 128, 162, 242, 288, 392]

    elif taskNumber == 4:
        # Subtarea 4. Sin restricciones
        beepers = [22, 27, 72, 90, 118, 193, 262, 261, 342, 377]

    else:
        raise ValueError("Invalid task number")

    makeCase(f"sub{taskNumber}.{caseNumber}.in",
             width, height, beepers[caseNumber - 1])


def main():
    pointsPerSubtask = [25, 25, 25, 25]
    casesPerSubtask = [10, 8, 10, 10]
    random.seed(2023)

    with open("testplan", "w") as f:
        for t, points in enumerate(pointsPerSubtask):
            for c in range(casesPerSubtask[t]):
                makeSubtask(t + 1, c + 1)
                f.write(f"sub{t + 1}.{c + 1} {points}\n")
                points = 0


if __name__ == '__main__':
    main()
