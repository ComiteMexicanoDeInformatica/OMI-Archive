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
        regex = re.compile(r'^(\d+) (\d+) (\d+)$')
        with open('data.in', 'r') as handle:
            original_input = handle.read()

        lines = original_input.split('\n')
        self.assertEqual(lines[-1], '')
        lines.pop()

        self.assertTrue(regex.match(lines[0]))
        
        lines[0] = lines[0].split(' ')
        lines[0][0] = int(lines[0][0])
        lines[0][1] = int(lines[0][1])
        lines[0][2] = int(lines[0][2])

        N = lines[0][0]
        F = lines[0][1]
        C = lines[0][2]

        self.assertEqual(len(lines), N + 1)

        #Verificar que si esté en los limites

        caseName = sys.argv[1]
        limN = 50000
        lowF = 1
        lowC = 1
        highF = 1e9
        highC = 1e9 

        if 'sub1' in caseName:
            lowF = 3
            highF = 3
            limN = 1
        elif 'sub2' in caseName:
            lowF = 3
            highF = 3
            highC = 1000
        elif 'sub3' in caseName:
            lowF = 3
            highF = 3
        elif 'sub4' in caseName:
            highC = 1
        elif 'sub5' in caseName:
            highF = 500
            highC = 500
            limN = 100
        elif 'sub6' in caseName:
            limN = 2000
        elif not 'sub7' in caseName:
            self.fail(f"Invalid case name: {caseName}")


        self.assertTrue(1 <= N <= limN)
        self.assertTrue(lowF <= F <= highF)
        self.assertTrue(lowC <= C <= highC)

        for line in lines[1:]:
            reg = re.compile(r'^(\d+) (\d+) (\d+) (\d+)$')
            self.assertTrue(reg.match(line))

            arr = line.split(' ')
            f1 = int(arr[0])
            c1 = int(arr[1])
            f2 = int(arr[2])
            c2 = int(arr[3])
            self.assertTrue(1 < f1 <= f2 < F)
            self.assertTrue(1 <= c1 <= c2 <= C)


if __name__ == '__main__':
    validatortest.main()
