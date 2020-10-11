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

        for i in range(0, len(lines)):
            self.assertTrue(regex.match(lines[i]))
            lines[i] = lines[i].split(' ')
            lines[i][0] = int(lines[i][0])
            lines[i][1] = int(lines[i][1])

        N = lines[0][0]
        Q = lines[0][1]

        self.assertEqual(len(lines), 1 + N + Q)
        caseName = sys.argv[1]
        if '45' in caseName:
            self.assertTrue(0 <= N <= 10**5)
            self.assertTrue(0 <= Q <= 10**5)
        elif '35' in caseName:
            self.assertTrue(0 <= N <= 1000)
            self.assertTrue(0 <= Q <= 1000)
        elif '20' in caseName:
            self.assertTrue(0 <= N <= 100)
            self.assertTrue(0 <= Q <= 100)
            for i in range(1, len(lines)):
                p = lines[i]
                x = p[0]
                y = p[1]
                self.assertTrue(0 <= x <= 100)
                self.assertTrue(0 <= y <= 100)
        else:
            self.fail(f"Invalid case name: {caseName}")

        for i in range(1, len(lines)):
            p = lines[i]
            x = p[0]
            y = p[1]
            self.assertTrue(0 <= x <= 1000)
            self.assertTrue(0 <= y <= 1000)


if __name__ == '__main__':
    validatortest.main()
