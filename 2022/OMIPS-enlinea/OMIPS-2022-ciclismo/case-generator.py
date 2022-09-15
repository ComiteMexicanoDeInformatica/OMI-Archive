import random
import os


def makeCase(caseName, E, R, trajectory):
    beepersXML = f"""<monton x="1" y="2" zumbadores="{E}"/>"""
    beepersXML += f"""\n\t\t\t<monton x="2" y="2" zumbadores="{R}"/>"""
    for i, k in enumerate(trajectory):
        beepersXML += f"""\n\t\t\t<monton x="{i+1}" y="1" zumbadores="{k}"/>"""
    baseXML = f"""<ejecucion>
    <condiciones instruccionesMaximasAEjecutar="10000000"
                 longitudStack="65000">
    </condiciones>
    <mundos>
        <mundo nombre="mundo_0" ancho="100" alto="100">
            {beepersXML}
            <posicionDump x="1" y="1"/>
        </mundo>
    </mundos>
    <programas tipoEjecucion="CONTINUA" intruccionesCambioContexto="1"
               milisegundosParaPasoAutomatico="0">
        <programa nombre="p1" ruta="{{$2$}}" mundoDeEjecucion="mundo_0"
                  xKarel="1" yKarel="1" direccionKarel="NORTE"
                  mochilaKarel="INFINITO">
            <despliega tipo="ORIENTACION"/>
            <despliega tipo="MUNDO"/>
        </programa>
    </programas>
</ejecucion>"""
    casePath = os.path.join("cases", caseName)
    with open(casePath, "w") as f:
        f.write(baseXML)


def makeSubtask(taskNumber, caseNumber):
    E = random.randint(1, 200)
    R = random.randint(E, 200)
    nbeepers = random.randint(3, 100)
    trajectory = []

    if taskNumber == 1:
        # La posición actual de Karel tiene la altura máxima de todo el
        # trayecto.
        trajectory.append(random.randint(2, 200))
        for _ in range(nbeepers - 1):
            trajectory.append(random.randint(1, trajectory[0] - 1))
    elif taskNumber == 2:
        # Hay una serie de tramos que suben seguido de una serie de tramos que
        # bajan. Se asegura que Karel puede terminar el trayecto.
        for _ in range(nbeepers):
            trajectory.append(random.randint(1, R + 1))
        changeAt = random.randint(1, nbeepers - 2)
        trajectory[:changeAt] = sorted(trajectory[:changeAt])
        trajectory[changeAt:] = sorted(trajectory[changeAt:], reverse=True)
    elif taskNumber == 3:
        # Hay una serie de tramos que bajan seguido de una serie de tramos que
        # suben. Se asegura que Karel puede terminar el trayecto.
        for _ in range(nbeepers):
            trajectory.append(random.randint(1, R + 1))
        changeAt = random.randint(1, nbeepers - 2)
        trajectory[:changeAt] = sorted(trajectory[:changeAt], reverse=True)
        trajectory[changeAt:] = sorted(trajectory[changeAt:])
    elif taskNumber == 4:
        # La posición actual de Karel tiene altura 1. Se asegura que Karel
        # puede terminar el trayecto.
        trajectory.append(1)
        for _ in range(nbeepers - 1):
            trajectory.append(random.randint(1, R + 1))
    elif taskNumber == 5:
        # La posición actual de Karel tiene altura 1.
        trajectory.append(1)
        for _ in range(nbeepers - 1):
            trajectory.append(random.randint(1, 200))
    elif taskNumber == 6:
        # Sin ninguna restricción.
        for _ in range(nbeepers):
            trajectory.append(random.randint(1, 200))

    makeCase(f"sub{taskNumber}.{caseNumber}.in", E, R, trajectory)


if __name__ == '__main__':
    random.seed(2022)
    for t in range(1, 7):
        for c in range(1, 6):
            makeSubtask(t, c)
