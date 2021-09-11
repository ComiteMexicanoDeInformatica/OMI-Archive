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
            lines = handle.readlines()

        regex = re.compile(r'^(\d+) (\d+) (\d+)$')

        self.assertTrue(regex.match(lines[0]))

        line = lines[0].split()

        N = int(line[0])
        F = int(line[1])
        C = int(line[2])

        self.assertTrue(1 <= N <= int(1e5))
        self.assertTrue(3 <= F <= int(1e9))
        self.assertTrue(3 <= C <= int(1e9))

        repeated = set()
        regex = re.compile(r'^([/\\]) (\d+) (\d+)$')

        for i in range(1, N + 1):
            self.assertTrue(regex.match(lines[i]))

            line = lines[i].split()
            fi = int(line[1])
            ci = int(line[2])

            self.assertTrue(1 <= fi <= F)
            self.assertTrue(1 <= ci <= C)
            self.assertTrue(tuple([fi, ci]) not in repeated)
            repeated.add(tuple([fi, ci]))

        regex = re.compile(r'^(\d+)$')
        self.assertTrue(regex.match(lines[N + 1]))

        line = lines[N + 1].split()
        E = int(line[0])

        self.assertTrue(1 <= E <= int(1e5))

        regex = re.compile(r'^([NESO]) (\d+) (\d+)$')

        for i in range(N + 2, N + E + 2):
            self.assertTrue(regex.match(lines[i]))

            line = lines[i].split()
            fj = int(line[1])
            cj = int(line[2])

            self.assertTrue(1 <= fj <= F)
            self.assertTrue(1 <= cj <= C)

        case_name = sys.argv[1]

        if 'sub1' in case_name:
            self.assertTrue(N <= 500)
            self.assertTrue(F <= 100)
            self.assertTrue(C <= 100)
            self.assertTrue(E <= 1)
        elif 'sub2' in case_name:
            self.assertTrue(N <= 500)
            self.assertTrue(F <= 100)
            self.assertTrue(C <= 100)
        elif 'sub3' in case_name:
            self.assertTrue(N <= 1000)
            self.assertTrue(E <= 1)
        elif 'sub4' in case_name:
            self.assertTrue(N <= 1000)
        elif 'sub5' in case_name:
            self.assertTrue(E <= 1)


if __name__ == '__main__':
    validatortest.main()
