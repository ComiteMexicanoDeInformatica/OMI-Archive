import random
import os


def makeCase(caseName, products, coupons):
    beepersXML = []
    for i, k in enumerate(products):
        beepersXML.append(f"<monton x=\"{i+1}\" y=\"1\" zumbadores=\"{k}\"/>")
    for i, k in enumerate(coupons):
        beepersXML.append(f"<monton x=\"{i+1}\" y=\"2\" zumbadores=\"{k}\"/>")
    beepersXML = "\n\t\t\t".join(beepersXML)

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
</ejecucion>"""

    casePath = os.path.join("cases", caseName)
    with open(casePath, "w") as f:
        f.write(baseXML)


def makeSubtask(taskNumber, caseNumber):
    N = random.randint(1, 100)
    C = random.randint(1, N)

    if taskNumber == 1:
        # Todos los cupones tienen C = 1. Los artículos están ordenados por
        # precio de menor a mayor.
        coupons = [1] * C
        products = sorted(random.randint(1, 100) for _ in range(N))
    elif taskNumber == 2:
        # Solo hay un cupón. Los artículos están ordenados por precio de menor
        # a mayor.
        coupons = [random.randint(1, N)]
        products = sorted(random.randint(1, 100) for _ in range(N))
    elif taskNumber == 3:
        # Todos los cupones tienen la misma C. Los artículos están ordenados
        # por precio de menor a mayor.
        coupons = [random.randint(1, N//C)] * C
        products = sorted(random.randint(1, 100) for _ in range(N))
    elif taskNumber == 4:
        # Todos los artículos cuestan lo mismo.
        coupons = [random.randint(1, N//C) for _ in range(C)]
        products = [random.randint(1, 100)] * N
    elif taskNumber == 5:
        # Sin reestricciones adicionales.
        coupons = [random.randint(1, N//C) for _ in range(C)]
        products = [random.randint(1, 100) for _ in range(N)]
    else:
        raise ValueError("Invalid subtask")

    makeCase(f"sub{taskNumber}.{caseNumber}.in", products, coupons)


if __name__ == '__main__':
    random.seed(2022)
    for t in range(1, 6):
        for c in range(1, 6):
            makeSubtask(t, c)
