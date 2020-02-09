#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import os
import re

from ctest import *

class Test(CTest):
    def test(self):
        gridRegex = r'((?:-?\d+(?: -?\d+)*\n)+)'
        regex = re.compile(r'^(\d+) (\d+) (\d+)\n' + gridRegex + '$')
        results = re.match(regex, self.input).groups()
        self.assertEqual(len(results), 4)

        N = int(results[0])
        M = int(results[1])
        T = int(results[2])

        self.assertTrue(1 <= N <= 100)
        self.assertTrue(1 <= M <= 100)
        self.assertTrue(1 <= T <= 500)

        gridS = results[3].split('\n')
        gridS.pop()

        grid = [[int(x) for x in y.split()] for y in gridS]

        first = grid[:N]
        loop  = grid[N:2*N]
        score = grid[2*N:]

        self.assertEqual(len(first), N)
        self.assertEqual(len(loop), N)
        self.assertEqual(len(score), N)

        for row in first:
            self.assertEqual(len(row), M)
            self.assertTrue(all(1 <= x <= T for x in row))

        for row in loop:
            self.assertEqual(len(row), M)
            self.assertTrue(all(1 <= x <= T for x in row))

        for row in score:
            self.assertEqual(len(row), M)
            self.assertTrue(all(abs(x) <= 10**9 for x in row))

        if 'easy' in self.caseName:
            for i in range(N):
                for j in range(M):
                    self.assertEqual(first[i][j], i+j+1)

            for row in loop:
                self.assertTrue(all(x == T for x in row))

            for row in score:
                self.assertTrue(all(0 <= x <= 10**9 for x in row))

Test().run()
