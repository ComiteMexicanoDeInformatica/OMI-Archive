#!/usr/bin/python3
# -*- coding: utf-8 -*-

import logging
import libkarel


def valida(mundo, salida) -> int:

    posx = mundo.x
    posy = mundo.y
    dire = mundo.direccion
    if dire == 'NORTE':
        posy = posy + 1
    elif dire == 'ESTE':
        posx = posx + 1
    elif dire == 'SUR':
        posy = posy - 1
    else:
        posx = posx - 1

    puntaje = 0
    if salida.x == posx and salida.y == posy:
        puntaje = 100

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
