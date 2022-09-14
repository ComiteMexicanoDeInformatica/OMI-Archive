#!/usr/bin/python3
# -*- coding: utf-8 -*-

import logging
import libkarel


def valida(judge, contestant) -> int:

    if judge.direccion != contestant.direccion:
        return 0

    if judge.direccion == 'NORTE':
        if judge.zumbadores(1, 1) != contestant.zumbadores(1, 1):
            return 0
    return 100


def _main():
    logging.basicConfig(level=logging.DEBUG)
    score = 0
    try:
        result = libkarel.load_dict()

        judge = result['case_output']
        contestant = result['contestant_output']

        if contestant.error:
            score = 0
        else:
            score = valida(judge, contestant)
    except Exception:
        logging.exception('Karel Runtime Error')
    finally:
        print(score / 100)
        logging.shutdown()


if __name__ == '__main__':
    _main()
