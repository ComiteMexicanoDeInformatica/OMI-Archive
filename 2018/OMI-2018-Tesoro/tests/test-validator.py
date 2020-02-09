#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import os
import re

from ctest import *

class Test(CTest):
    def test(self):
        regex = re.compile(r'^(\d+) (\d+)\n((?:[01]+\n)+)$')
        results = re.match(regex, self.input).groups()
        self.assertEqual(len(results), 3)

        N = int(results[0])
        M = int(results[1])
        K = sum(1 if x == '1' else 0 for x in results[2])

        grid = results[2].split('\n')
        grid.pop()

        self.assertTrue(1 <= N <= 1000)
        self.assertTrue(1 <= M <= 1000)
        self.assertTrue(1 <= K <= M)

        self.assertEqual(len(grid), N)
        self.assertTrue(all(len(r) == M for r in grid))

        cols = [[grid[i][k] for i in range(N)] for k in range(M)]

        for col in cols:
            count = sum(1 if x == '1' else 0 for x in col)
            self.assertTrue(count <= 1)

Test().run()
