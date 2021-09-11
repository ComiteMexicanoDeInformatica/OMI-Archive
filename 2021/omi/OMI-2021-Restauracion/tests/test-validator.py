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
        regex = re.compile(r'^(\d+) (\d+)$')
        with open('data.in', 'r') as handle:
            original_input = handle.read()

        lines = original_input.split('\n')
        self.assertEqual(lines[-1], '')
        lines.pop()

        self.assertTrue(regex.match(lines[0]))

        lines[0] = lines[0].split(' ')
        lines[0][0] = int(lines[0][0])
        lines[0][1] = int(lines[0][1])

        N = lines[0][0]
        K = lines[0][1]

        if K:
            self.assertEqual(len(lines), 3)
        else:
            self.assertEqual(len(lines), 2)

        # Verificar que si esté en los limites

        caseName = sys.argv[1]

        if 'sub1' in caseName:
            lim = 20
        elif 'sub2' in caseName:
            lim = 1000
        elif 'sub3' in caseName:
            lim = 100000
        elif 'sub4' in caseName:
            lim = 500000

        self.assertTrue(2 <= N <= lim)
        self.assertTrue(0 <= K <= N)

        arr = lines[1].split(' ')
        ints = [int(v) for v in arr]
        self.assertEqual(len(ints), N)
        self.assertTrue(all(
            0 <= v <= 1000000
            for v in ints
        ))

        if K:
            arr = lines[2].split(' ')
            ints = [int(v) for v in arr]
            self.assertEqual(len(ints), K)
            self.assertTrue(all(
                1 <= v <= N
                for v in ints
            ))

            unico = set(ints)
            self.assertEqual(len(unico), K)


if __name__ == '__main__':
    validatortest.main()
