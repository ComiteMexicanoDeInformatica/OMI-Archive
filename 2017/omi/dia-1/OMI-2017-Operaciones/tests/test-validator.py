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

        self.assertEqual(len(lines), 2)

        # En la primera línea, un entero N
        regex = re.compile(r'^(\d+)$')
        self.assertTrue(regex.match(lines[0]))
        N = int(lines[0])
        self.assertTrue(2 <= N <= 10**6)

        # En la siguiente línea, el número en binario
        regex = re.compile(r'^1([0,1]+)$')
        self.assertTrue(regex.match(lines[1]))
        self.assertEqual(len(lines[1]), N)


if __name__ == '__main__':
    validatortest.main()
