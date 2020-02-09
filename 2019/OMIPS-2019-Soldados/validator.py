#!/usr/bin/python
# -*- coding: utf-8 -*-

import libkarel
import sys
import math
import traceback
from collections import defaultdict

score = 0

try:
    result = libkarel.load_dict()

    case_input = result['case_input']
    contestant = result['contestant_output']

    #valida que la ejecución del contestant no tenga errores
    if contestant.error:
        raise Exception('Karel Runtime Error')

    #convierte la lista de beepers a enteros
    #contestant beepers
    cb = defaultdict(int, {
        k: int(v) for (
            k, v) in contestant.lista_zumbadores.iteritems()})

    #input beepers
    ib = defaultdict(int, {
        k: int(v) for (
            k, v) in case_input.lista_zumbadores.iteritems()})

    #valida que la regla se cumpla en todas las casillas
    if all(
        cb[(i,j)] > max(cb[(i-1,j)], cb[(i,j-1)])
        and (ib[(i,j)] == 0 or ib[(i,j)] == cb[(i,j)])
        for i in range(1, case_input.w+1)
        for j in range(1, case_input.h+1)
    ):
        score = 1
    else:
        score = 0

except Exception as e:
    sys.stderr.write(traceback.format_exc())
    sys.stderr.write()
finally:
    print score
