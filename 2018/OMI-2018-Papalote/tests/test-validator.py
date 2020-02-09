#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import os
import re

from ctest import *

class Test(CTest):
    def test(self):
        regex = re.compile(r'^(\d+) (\d+)\n((?:-?\d+(?: -?\d+)*\n)+)$')
        results = re.match(regex, self.input).groups()
        self.assertEqual(len(results), 3)

        N = int(results[0])
        M = int(results[1])

        self.assertTrue(1 <= N <= 100)
        self.assertTrue(1 <= M <= 100)

        gridS = results[2].split('\n')
        gridS.pop()

        grid = [[int(x) for x in y.split()] for y in gridS]

        self.assertEqual(len(grid), N)

        for row in grid:
            self.assertEqual(len(row), M)
            self.assertTrue(all(abs(x) <= 100 for x in row))

        if 'easy' in self.caseName:
            self.assertTrue(N <= 10)
            self.assertTrue(M <= 10)
        else:
            self.assertTrue(N + M >= 20)

Test().run()
