#!/usr/bin/python3
# -*- coding: utf-8 -*-

import logging
import libkarel


def valida(mundo, salida) -> int:

    beepers = list(mundo.lista_zumbadores.values())
    beepers.sort()

    minimo = 101
    for i in range(1, len(beepers)):
        if (beepers[i] - beepers[i - 1]) < minimo:
            minimo = beepers[i] - beepers[i - 1]

    # Obten los dos montones de respuesta y deja el menor en a
    a = salida.zumbadores(1, 1)
    b = salida.zumbadores(2, 1)
    if a > b:
        a, b = b, a

    # Verifica que esos montones si esten en el conjunto original
    logging.info(msg=f'La pareja respuesta es {a}, {b}')
    logging.info(msg=f'Beepers={beepers}')
    assert a in beepers, "El numero menor no esta en la lista"
    assert b in beepers, "El numero mayor no esta en la lista"

    # Verifica que la diferencia sea la correcta
    assert b - a == minimo, \
           "La pareja entregada no es la de menor diferencia"

    return 100


def _main():
    logging.basicConfig(level=logging.DEBUG)
    score = 0
    try:
        result = libkarel.load_dict()

        mundo = result['case_input']
        contestant = result['contestant_output']

        if contestant.error:
            score = 0
        else:
            score = valida(mundo, contestant)
    except Exception:
        logging.exception('Karel Runtime Error')
    finally:
        print(score / 100)
        logging.shutdown()


if __name__ == '__main__':
    _main()
