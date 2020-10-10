#!/usr/bin/python
# -*- coding: utf-8 -*-
import logging
import unittest
import sys
import re

from omegaup.validator import validatortest


class MyTest(unittest.TestCase):
    def test_input(self):
        original_input = open('data.in', 'r').read()

        regex = re.compile(r'^(\d+) (\d+) (\d+)\n$')
        results = re.match(regex, original_input).groups()
        self.assertEqual(len(results), 3)

        N = int(results[0])
        Ka = int(results[1])
        Kb = int(results[2])

        self.assertTrue(0 <= Ka <= N)
        self.assertTrue(0 <= Kb <= N)

        caseName = sys.argv[1]
        if 'veasy' in caseName:
            self.assertTrue(2 <= N <= 5)
        elif 'easy' in caseName:
            self.assertTrue(6 <= N <= 16)
        elif 'med' in caseName:
            self.assertTrue(6 <= N <= 200)
            self.assertTrue(Ka == Kb)
        elif 'vhard' in caseName:
            self.assertTrue(201 <= N <= 5000)
        elif 'hard' in caseName:
            self.assertTrue(33 <= N <= 200)
        else:
            self.fail(f"Invalid case name: {caseName}")


if __name__ == '__main__':
    validatortest.main()
