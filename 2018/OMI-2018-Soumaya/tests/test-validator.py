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
        
        grid = results[2].split('\n')
        grid.pop()

        adj = [(-1, 0), (0, -1), (1, 0), (0, 1)]
        v = set()

        def dfs(r, c):
            s = [(r, c)]

            while s:
                r,c = s.pop()

                if r < 0 or r >= N or c < 0 or c >= M:
                    continue
                if grid[r][c] != '1':
                    continue
                if (r,c) in v:
                    continue

                v.add((r,c))

                for dr, dc in adj:
                    s.append((r + dr, c + dc))

        K = 0

        for r in range(N):
            for c in range(M):
                if grid[r][c] == '1' and (r,c) not in v:
                    dfs(r,c)
                    K += 1

        self.assertTrue(1 <= K <= 400)

        self.assertEqual(len(grid), N)
        self.assertTrue(all(len(r) == M for r in grid))

        if 'chico' in self.caseName:
            self.assertTrue(1 <= N <= 25)
            self.assertTrue(1 <= M <= 25)
        elif 'mediano' in self.caseName:
            self.assertTrue(1 <= N <= 50)
            self.assertTrue(1 <= M <= 50)
        elif 'grande' in self.caseName:
            self.assertTrue(1 <= N*M <= 10000)
        elif 'enorme' in self.caseName:
            self.assertTrue(1 <= N <= 1500)
            self.assertTrue(1 <= M <= 1500)
            self.assertTrue(1 <= N*M <= 1000000)
        else:
            self.assertTrue(False)

Test().run()
