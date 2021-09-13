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
        if lines[-1] == '':
            lines.pop()

        self.assertTrue(regex.match(lines[0]))

        lines[0] = lines[0].split(' ')
        lines[0][0] = int(lines[0][0])
        lines[0][1] = int(lines[0][1])
        lines[0][2] = int(lines[0][2])

        N = lines[0][0]
        M = lines[0][1]
        R = lines[0][2]

        self.assertEqual(len(lines), M + 1)

        #Verificar que si esté en los limites

        caseName = sys.argv[1]
        limN = 10e5
        limRev = 10e5

        if 'sub1' in caseName:
            limN = 1000
            limRev = 0
        elif 'sub2' in caseName:
            limRev = 0
        elif 'sub3' in caseName:
            limN = 1000
            limRev = 1
        elif 'sub4' in caseName:
            limRev = 1
        elif not 'sub5' in caseName:
            self.fail(f"Invalid case name: {caseName}")


        self.assertTrue(1 <= N <= limN)
        self.assertTrue(1 <= R <= N)

        revCnt = 0

        for line in lines[1:]:
            reg = re.compile(r'^(\d+) (\d+)$')
            self.assertTrue(reg.match(line))

            arr = line.split(' ')
            a = int(arr[0])
            b = int(arr[1])
            self.assertTrue(1 <= a <= N)
            self.assertTrue(1 <= b <= N)
            self.assertTrue(a != b)
            if a > b:
                revCnt += 1

        self.assertTrue(revCnt <= limRev)


if __name__ == '__main__':
    validatortest.main() 
