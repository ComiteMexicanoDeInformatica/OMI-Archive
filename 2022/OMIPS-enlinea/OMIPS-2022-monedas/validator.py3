#!/usr/bin/python3
# -*- coding: utf-8 -*-

import logging
import libkarel


def valida(mundo, salida) -> int:

    cambios = 0
    puntaje = 10
    minimo = 0

    for x in range(2, mundo.w + 1):
        # Si ya terminaron los zumbadores
        if mundo.zumbadores(x, 1) == 0:
            break

        if salida.zumbadores(x, 1) != mundo.zumbadores(x, 1):
            cambios += 1

        if (x % 2) == 1:
            if salida.zumbadores(x, 1) == salida.zumbadores(x - 1, 1):
                logging.error("Acomodo inválido")
                return 0
            if mundo.zumbadores(x, 1) == mundo.zumbadores(x - 1, 1):
                minimo += 1

    if cambios == minimo:
        puntaje = 50

    if cambios == salida.zumbadores(1, 1):
        puntaje = 100

    logging.debug("%s", cambios)
    logging.debug("%s", minimo)
    logging.debug("%s", salida.zumbadores(1, 1))
    logging.debug("%s", puntaje)

    return puntaje


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
