#!/usr/bin/python3
# -*- coding: utf-8 -*-

import logging
import libkarel


def valida(respuesta, salida) -> int:

    # valida la orientacion de karel
    if respuesta.direccion != salida.direccion:
        return 0

    if respuesta.direccion == "SUR":
        return 100

    # valida la cantidad de pasos
    b_r = list(respuesta.lista_zumbadores.values())
    b_p = list(salida.lista_zumbadores.values())

    if b_r == b_p:
        return 100

    return 50


def _main():
    logging.basicConfig(level=logging.DEBUG)
    score = 0
    try:
        result = libkarel.load_dict()

        mundo = result['case_output']
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
