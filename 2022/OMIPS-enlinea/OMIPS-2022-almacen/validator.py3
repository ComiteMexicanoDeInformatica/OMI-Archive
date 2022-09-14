#!/usr/bin/python3
# -*- coding: utf-8 -*-

import collections
from typing import Deque, Set
import logging
import libkarel


def reachable(mundo) -> Set[libkarel.Casilla]:

    q: Deque[libkarel.Casilla] = collections.deque(
        ((mundo.x, mundo.y), ))
    visited: Set[libkarel.Casilla] = set()

    while q:
        x, y = q.popleft()
        if (x, y) in visited:
            continue
        visited.add((x, y))
        mask = mundo.paredes(x, y)

        if not mask & libkarel.Direccion.NORTE:
            q.append((x, y + 1))
        if not mask & libkarel.Direccion.SUR:
            q.append((x, y - 1))
        if not mask & libkarel.Direccion.ESTE:
            q.append((x + 1, y))
        if not mask & libkarel.Direccion.OESTE:
            q.append((x - 1, y))

    return visited


def libresCont(mundo, salida, iniX, iniY) -> int:

    q: Deque[libkarel.Casilla] = collections.deque(
        ((iniX, iniY), ))
    visited: Set[libkarel.Casilla] = set()

    cont = 0
    while q:
        x, y = q.popleft()
        if (x, y) in visited or salida.zumbadores(x, y) == 1:
            continue
        visited.add((x, y))
        cont += 1
        mask = mundo.paredes(x, y)

        if not mask & libkarel.Direccion.NORTE:
            q.append((x, y + 1))
        if not mask & libkarel.Direccion.SUR:
            q.append((x, y - 1))
        if not mask & libkarel.Direccion.ESTE:
            q.append((x + 1, y))
        if not mask & libkarel.Direccion.OESTE:
            q.append((x - 1, y))

    return cont


def valida(mundo, salida) -> int:

    # Verifica que todos los montones son de 1 zumbador
    for k, v in salida.lista_zumbadores.items():
        assert v == 1, f"Montón con más de un zumbador: {k}"

    # Verifica que no se hayan cambiado los zumbadores de la entrada
    for (x, y), v in mundo.lista_zumbadores.items():
        if (x != mundo.x or y != mundo.y):
            assert salida.zumbadores(x, y) == 1, f"Se quitó zumbador: {x, y}"

    # Verifica que se hayan dejado K zumbadores
    k = mundo.zumbadores(mundo.x, mundo.y)
    zumbMundo = len(mundo.lista_zumbadores) - 1
    zumbSalida = len(salida.lista_zumbadores)
    assert zumbSalida - zumbMundo == k, "No se dejaron K zumbadores"

    # Verifica que las casillas libres estén todas conectadas
    casillas = reachable(mundo)
    libreX = 0
    libreY = 0
    for (x, y) in casillas:
        if salida.zumbadores(x, y) == 0:
            libreX = x
            libreY = y
    libres = libresCont(mundo, salida, libreX, libreY)

    assert len(casillas) == len(salida.lista_zumbadores) + libres, \
           "Casillas libres no están conectadas"

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
