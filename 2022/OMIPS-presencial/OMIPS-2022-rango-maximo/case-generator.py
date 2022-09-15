import random
import os


def makeCase(caseName, K, beepers):
    beepersXML = f"""<monton x="1" y="2" zumbadores="{K}"/>"""
    for i, k in enumerate(beepers):
        beepersXML += f"""
            <monton x="{i + 1}" y="1" zumbadores="{k}"/>"""

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
            <despliega tipo="MUNDO"/>
        </programa>
    </programas>
</ejecucion>
"""

    casePath = os.path.join("cases", caseName)
    with open(casePath, "w") as f:
        f.write(baseXML)


def makeSubtask(taskNumber, caseNumber):
    N = random.randint(3, 100)
    K = random.randint(1, 100)

    if taskNumber == 1:
        # Todos los números de la lista son menores o iguales a K.
        beepers = random.choices(range(1, K + 1), k=N)
    elif taskNumber == 2:
        # K = 1
        K = 1
        beepers = random.choices(range(1, 101), k=N)
    elif taskNumber == 3:
        # Todos los números de la lista son distintos.
        beepers = random.sample(range(1, 101), k=N)
    elif taskNumber == 4:
        # Sin restricciones adicionales.
        beepers = random.choices(range(1, 101), k=N)
    else:
        raise ValueError("Invalid subtask")

    makeCase(f"sub{taskNumber}.{caseNumber}.in", K, beepers)


if __name__ == '__main__':
    random.seed(2022)
    for t in range(1, 5):
        for c in range(1, 7):
            makeSubtask(t, c)
