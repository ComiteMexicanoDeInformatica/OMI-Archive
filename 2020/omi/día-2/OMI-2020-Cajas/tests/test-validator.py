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

        lines=original_input.split('\n')
        self.assertEqual(lines[-1],'')
        lines.pop()

        self.assertEqual(len(lines), 2)

        regex = re.compile(r'^(\d+)$')
        self.assertTrue(regex.match(lines[0]))
        N = int(lines[0])

        arr = lines[1].split(' ')
        ints = [int(v) for v in arr]

        self.assertEqual(len(ints), N)

        caseName = sys.argv[1]
        xlim = 100
        if 'easy' in caseName:
            mini = 1
            lim = 10
        elif 'med' in caseName:
            mini = 11
            lim = 100
        elif 'hard' in caseName:
            mini = 101
            lim = 100000
            xlim = 100000
        else:
            self.fail(f"Invalid case name: {caseName}")

        self.assertTrue(mini <= N <= lim)
        self.assertTrue(all(
            0 <= v <= xlim
            for v in ints
        ))


if __name__ == '__main__':
    validatortest.main()
