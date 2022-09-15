#!/usr/bin/python3
# -*- coding: utf-8 -*-

import logging
import libkarel


def valida(mundo, salida) -> int:

    ancho = mundo.w + 1
    mitad = ancho // 2
    cambios = 0
    minimo = 0
    total = 0

    # Valida primero que el mundo de salida este correctamente reflejado
    for fil in range(1, mundo.h + 1):
        for col in range(1, mitad):
            if salida.zumbadores(col, fil) != salida.zumbadores(ancho - col, fil):
                return 0
            if salida.zumbadores(mitad, fil) > 0:
                return 0
            
            # Si esta bien, cuenta los cambios
            cambios += abs(salida.zumbadores(col, fil) - mundo.zumbadores(col, fil))
            cambios += abs(salida.zumbadores(ancho - col, fil) - mundo.zumbadores(ancho - col, fil))
            minimo += abs(mundo.zumbadores(col, fil) - mundo.zumbadores(ancho - col, fil))
            total += mundo.zumbadores(col, fil) + mundo.zumbadores(ancho - col, fil)

    logging.debug("%s", cambios)
    logging.debug("%s", minimo)
    logging.debug("%s", total)

    # Si llego hasta aqui hay que calcular el puntaje en base a los cambios
    if cambios <= minimo:
        return 100
    elif cambios >= total:
        return 0
    else:
        return (cambios - minimo) * 100 / (total - minimo)
        

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
