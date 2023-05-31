#!/usr/bin/python3
# -*- coding: utf-8 -*-

from math import sqrt
import logging
import libkarel


def valida(mundo, salida, subtask: str) -> int:

    # Obten el área original
    area = mundo.zumbadores(1, 1)
    area *= 2

    # Obten los dos montones respuesta y deja el menor en alto
    ancho = salida.zumbadores(1, 1)
    alto = salida.zumbadores(2, 1)
    if ancho < alto:
        ancho, alto = alto, ancho

    # Verifica que el alto y ancho de la respuesta den el área correcta
    assert alto * ancho == area, \
           "El triángulo respuesta no tiene el área solicitada"

    # Verifica que la diferencia entre los lados sea la mínima posible
    alto_optimo = 1
    ancho_optimo = area
    for a in range(1, int(sqrt(area)) + 1):
        if area % a == 0:
            alto_optimo = a
            ancho_optimo = area // a

    if subtask != "1":
        assert (alto, ancho) == (alto_optimo, ancho_optimo), \
            "La diferencia entre los lados no es la mínima posible"

    return 100


def _main():
    logging.basicConfig(level=logging.DEBUG)
    score = 0
    try:
        result = libkarel.load_dict()

        mundo = result['case_input']
        contestant = result['contestant_output']
        case_name = result['case_name']
        subtask_number = case_name[3:4]

        if contestant.error:
            score = 0
        else:
            score = valida(mundo, contestant, subtask_number)
    except Exception:
        logging.exception('Karel Runtime Error')
    finally:
        print(score / 100)
        logging.shutdown()


if __name__ == '__main__':
    _main()
