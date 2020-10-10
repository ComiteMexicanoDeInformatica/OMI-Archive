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
        # en la primera línea solo hay un número, N.
        regex = re.compile(r'^(\d+)\n((?:[XO]+\n)+)$', re.MULTILINE)
        original_input = open('data.in', 'r').read()
        results = regex.match(original_input).groups()
        self.assertEqual(len(results), 2)

        N = int(results[0])

        caseName = sys.argv[1]
        if '1.' in caseName:
            self.assertTrue(1 <= N <= 10)
        elif '2.' in caseName:
            self.assertTrue(1 <= N <= 50)
        elif '3.' in caseName:
            self.assertTrue(1 <= N <= 50)
        elif '4.' in caseName:
            self.assertTrue(1 <= N <= 500)
        else:
            self.fail(f"Invalid case name: {caseName}")

        grid = results[1].split('\n')
        grid.pop()

        self.assertEqual(2 * N, len(grid))
        self.assertTrue(all(len(r) == N for r in grid))


if __name__ == '__main__':
    validatortest.main()
