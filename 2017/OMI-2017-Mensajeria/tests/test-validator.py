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

        regex = re.compile(r'^(\d+) (\d+)$')
        self.assertTrue(regex.match(lines[0]))

        lines[0] = lines[0].split(' ')
        N = int(lines[0][0])
        K = int(lines[0][1])
        self.assertTrue(0 <= N <= 10**6)
        self.assertTrue(0 <= K <= 1000)

        self.assertEqual(len(lines), N + 1)

        regex = re.compile(r'^(\d+)$')
        for i in range(1, len(lines)):
            self.assertTrue(regex.match(lines[i]))
            ai = int(lines[i])
            self.assertTrue(0 <= ai <= 1000)


if __name__ == '__main__':
    validatortest.main()
