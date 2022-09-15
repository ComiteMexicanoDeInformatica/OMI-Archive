import random
import os


# pylint: disable=too-many-arguments
def makeCase(caseName, xKarel, yKarel, dirKarel, xDarel, yDarel):
    baseXML = f"""<ejecucion>
    <condiciones instruccionesMaximasAEjecutar="10000000"
                 longitudStack="65000">
    </condiciones>
    <mundos>
        <mundo nombre="mundo_0" ancho="100" alto="100">
            <monton x="{xDarel}" y="{yDarel}" zumbadores="1"/>
            <posicionDump x="{xKarel}" y="{yKarel}"/>
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
</ejecucion>
"""
    casePath = os.path.join("cases", caseName)
    with open(casePath, "w") as f:
        f.write(baseXML)


def makeSubtask(taskNumber, caseNumber):
    xKarel = random.randint(1, 100)
    yKarel = random.randint(1, 100)
    dirKarel = random.choice(["NORTE", "SUR", "ESTE", "OESTE"])
    xDarel = random.randint(1, 100)
    yDarel = random.randint(1, 100)

    # Karel empieza en la (1, 1) viendo al norte.
    if taskNumber == 1:
        xKarel = 1
        yKarel = 1
        dirKarel = "NORTE"
    # La casa de Darel está en la misma fila o columna.
    elif taskNumber == 2:
        if taskNumber % 2 == 0:
            yDarel = yKarel
        else:
            xDarel = xKarel
    # Sin restricciones adicionales.
    elif taskNumber == 3:
        pass
    else:
        raise ValueError("Invalid subtask")

    makeCase(f"sub{taskNumber}.{caseNumber}.in",
             xKarel, yKarel, dirKarel, xDarel, yDarel)


if __name__ == '__main__':
    random.seed(2022)
    for t in range(1, 4):
        for c in range(1, 8):
            makeSubtask(t, c)
