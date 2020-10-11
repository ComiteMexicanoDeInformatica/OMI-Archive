#!/usr/bin/python
# -*- coding: utf-8 -*-
import logging
import sys
import os
import re
import unittest

from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        # una línea con N y X. N es la cantidad de primos y X el índice del primo perdido.
        # X es -1 para la subtask dificil.
        regex = re.compile(r'^(\d+) (\-?\d+)\n$')
        f = open('data.in', 'r')
        original_input = f.read()
        f.close()
        results = regex.match(original_input).groups()
        self.assertEqual(len(results), 2)

        N = int(results[0])
        X = int(results[1])

        caseName = sys.argv[1]

        if 'easy' in caseName:
            self.assertTrue(2 <= N <= 10**5)
            self.assertTrue(2 <= X < N)
        elif 'hard' in caseName:
            self.assertTrue(2 <= N <= 10**7)
            self.assertEqual(-1, X)
        else:
            self.fail(f"Invalid case name: {caseName}")


if __name__ == '__main__':
    validatortest.main()
