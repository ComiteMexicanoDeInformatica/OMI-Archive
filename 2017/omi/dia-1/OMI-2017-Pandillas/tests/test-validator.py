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
        with open('data.in', 'r') as handle:
            original_input = handle.read()

        lines = original_input.split('\n')
        self.assertEqual(lines[-1], '')
        lines.pop()

        # En la primera línea, dos enteros N, M
        regex = re.compile(r'^(\d+) (\d+)$')
        self.assertTrue(regex.match(lines[0]))

        lines[0] = lines[0].split(' ')
        N = int(lines[0][0])
        M = int(lines[0][1])
        
        caseName = sys.argv[1]
        if 'small' in caseName:
            self.assertTrue(1 <= N <= 200)
            self.assertTrue(1 <= M <= 1000)
        elif 'medium' in caseName:
            self.assertTrue(1 <= N <= 1000)
            self.assertTrue(1 <= M <= 1000)
        else:
            self.assertTrue(1 <= N <= 1000000)
            self.assertTrue(1 <= M <= 200000)

        # En las siguientes M líneas las amistades
        lines = lines[1:]
        self.assertEqual(len(lines), M)
        for line in lines:
            regex = re.compile(r'^(\d+) (\d+)$')
            self.assertTrue(regex.match(line))
            line = line.split(' ')
            a = int(line[0])
            b = int(line[1])
            self.assertTrue(0 <= a < N)
            self.assertTrue(0 <= b < N)
            # No hay personas que sean amigas de sí mismas
            self.assertTrue(a != b)





if __name__ == '__main__':
    validatortest.main()
