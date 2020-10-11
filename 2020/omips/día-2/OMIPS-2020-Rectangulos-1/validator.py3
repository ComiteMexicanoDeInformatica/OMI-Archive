#!/usr/bin/python3
# -*- coding: utf-8 -*-

import logging
import math
import sys
from collections import defaultdict

import libkarel


def valida(mundo, salida) -> int:

    validados = defaultdict(int)
    tamaños = defaultdict(int)
    repetidos = 0

    for x in range(1, mundo.w + 1):
        for y in range(1, mundo.h + 1):
            if not (salida.zumbadores(x, y) == 1 and validados[x, y] == 0):
                continue

            # calcula ancho del rectangulo
            ancho = 1
            for i in range(x + 1, mundo.w + 1):
                if salida.zumbadores(i, y) == 1:
                    ancho += 1
                else:
                    break

            # calcula alto del rectangulo
            alto = 1
            for j in range(y + 1, mundo.h + 1):
                if salida.zumbadores(x, j) == 1:
                    alto += 1
                else:
                    break

            # valida que todo el ractangulo tenga montones de 1 zumbador
            for i in range(x, x + ancho):
                for j in range(y, y + alto):
                    validados[i, j] = 1
                    if salida.zumbadores(i, j) != 1:
                        logging.error(
                            "no es un rectangulo valido casila (%s, %s", i, j)
                        return 0

            # y que no tenga zumbadores adyacentes
            s = sum(
                salida.zumbadores(i, j) for i in range(x - 1, x + ancho + 1)
                for j in range(y - 1, y + alto + 1))

            if s != (alto * ancho):
                logging.error(
                    "se detectaron zumbadores adyacentes al rectangulo (%s, %s)",
                    x, y)
                return 0

            tamaños[ancho, alto] += 1
            if tamaños[ancho, alto] > 1:
                repetidos += 1

    z = len(salida.lista_zumbadores)
    t = len(tamaños)

    return max(0, (z - (repetidos // 2)) * t)


def calcula(points, best, world_area) -> int:
    # 1 punto por poner 1 zumbador
    if points <= 1:
        return math.trunc(points)

    points /= world_area

    # 20 puntos por hacer  un solo retangulo del tamano del mundo
    if points <= 1:
        return max(1, math.ceil(points * 20))

    best = (best / world_area) * 0.7

    x = points / (best - 1)

    return min(100, 20 + math.ceil(x * 80))


def _main():
    score = 0
    try:
        result = libkarel.load_dict()

        mundo = result['case_input']
        judge = result['case_output']
        contestant = result['contestant_output']

        if contestant.error:
            raise Exception(contestant.error)

        points = valida(mundo, contestant)
        best = valida(mundo, judge)
        world_area = mundo.w * mundo.h

        score = calcula(points, best, world_area)

        # redondea al par mas cercano
        score = 2 * round(score / 2)

    except:
        logging.exception('Karel Runtime Error')
    finally:
        print(score / 100)


if __name__ == '__main__':
    _main()
