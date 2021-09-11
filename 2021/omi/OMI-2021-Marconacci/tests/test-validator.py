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

        regex = re.compile(r'^(\d+)$')
        self.assertTrue(regex.match(lines[0]))
        P = int(lines[0])

        self.assertTrue(1 <= P <= 1e5)

        caseName = sys.argv[1]
        if 'sub2' in caseName:
            self.assertEqual(P, 1)

        self.assertEqual(len(lines), P + 1)

        genA = 0
        genB = 0

        for line in lines[1:]:
            reg = re.compile(r'^(\d+) (\d+) (\d+)$')
            self.assertTrue(reg.match(line))

            arr = line.split(' ')
            A = int(arr[0])
            B = int(arr[1])
            I = int(arr[2])

            if genA == 0:
                genA = A
                genB = B

            self.assertTrue(0 <= A <= 1e6)
            self.assertTrue(0 <= B <= 1e6)
            self.assertTrue(1 <= I <= 1e6)

            if 'sub3' in caseName:
                self.assertEqual(A, genA)
                self.assertEqual(B, genB)
            elif 'sub1' in caseName:
                self.assertTrue(I <= 30)
            elif 'sub4' in caseName:
                self.assertTrue(P <= 1000)
                self.assertTrue(I <= 1000)


if __name__ == '__main__':
    validatortest.main()
