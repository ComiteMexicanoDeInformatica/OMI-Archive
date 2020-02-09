#!/usr/bin/python
# -*- coding: utf-8 -*-

import libkarel
import sys
import math
import traceback

score = 0

try:
    result = libkarel.load_dict()

    judge = result['case_output']
    contestant = result['contestant_output']

    if contestant.error:
        raise Exception('Karel Runtime Error')

    judge_beepers = {k: int(v)
                     for (k, v) in judge.lista_zumbadores.iteritems()}
    contestant_beepers = {
        k: int(v) for (
            k, v) in contestant.lista_zumbadores.iteritems()}

    if any(x not in [0, 1] for x in judge_beepers.itervalues()):
        sys.stderr.write('Judge solution is incorrect!\n')
        sys.exit(1)

    if any(v not in [0, 1] or k not in judge_beepers
           for (k, v) in contestant_beepers.iteritems()):
        raise Exception('Additional beepers found')

    judge_count = sum(judge_beepers.itervalues())
    contestant_count = sum(contestant_beepers.itervalues())

    sys.stderr.write('Judge beepers: ' + str(judge_count))
    sys.stderr.write('Contestant beepers: ' + str(contestant_count))

    if contestant_count > judge_count:
        sys.stderr.write('Contestant placed more beepers?!\n')
        sys.exit(1)
    if contestant_count == judge_count:
        score = 1
    elif 100 * contestant_count > 75 * judge_count:
        score = 0.8
    elif 100 * contestant_count >= 50 * judge_count:
        score = 0.5
    else:
        score = 0
except Exception as e:
    sys.stderr.write(traceback.format_exc())
    sys.stderr.write()
finally:
    print score
