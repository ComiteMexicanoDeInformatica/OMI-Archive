#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import os
import re

from ctest import *

class Test(CTest):
    def test(self):
        regex = re.compile(r'^(\d+) (\d+) (\d+)\n((?:[01]+\n)+)$')
        results = re.match(regex, self.input).groups()
        self.assertEqual(len(results), 4)

        N = int(results[0])
        M = int(results[1])
        K = int(results[2])
        
        grid = results[3].split('\n')
        grid.pop()

        self.assertTrue(1 <= N <= 1500)
        self.assertTrue(1 <= M <= 1500)
        self.assertTrue(0 <= K <= 6)

        self.assertEqual(len(grid), N)
        self.assertTrue(all(len(r) == M for r in grid))

        if 'easy' in self.caseName:
            self.assertTrue(1 <= N <= 20)
            self.assertTrue(1 <= M <= 20)

Test().run()
