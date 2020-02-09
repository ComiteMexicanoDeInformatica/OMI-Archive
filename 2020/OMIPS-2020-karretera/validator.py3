#!/usr/bin/python3
# -*- coding: utf-8 -*-

import logging
import math
import sys
from collections import defaultdict

import libkarel

def _main():
    score = 0
    try:
        result = libkarel.load_dict()

        mundo = result['case_input']
        judge = result['case_output']
        contestant = result['contestant_output']

        if contestant.error:
            raise Exception(contestant.error)

        #valida que linea 3 este pintada correctamente
        if all(judge.zumbadores(x, 3) == contestant.zumbadores(x, 3) for x in range(1,mundo.w+1)):
            score += 60

            #no debe tener zumbadores en la mochila
            if (contestant.instrucciones['coge_zumbador'] == contestant.instrucciones['deja_zumbador']):
                score += 12

            # no debe haber zumbadores en otras casilla

            if (contestant.lista_zumbadores == judge.lista_zumbadores):
                score += 8

            # si recojes mas zumbadores de los necesarios para pintar la linea.
            if (contestant.instrucciones['coge_zumbador'] == judge.instrucciones['coge_zumbador']):
                score += 13
            # Tienes una penalización de 13 puntos si avanzas mas de 3n veces.
            if (contestant.instrucciones['avanza'] <= judge.instrucciones['avanza']):
                score += 7
    except:
        logging.exception('Karel Runtime Error')
    finally:
        print(score / 100)


if __name__ == '__main__':
    _main()
