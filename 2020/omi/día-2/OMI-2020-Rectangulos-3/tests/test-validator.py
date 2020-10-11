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

        regex = re.compile(r'^(\d+) (\d+)$')
        results = re.match(regex, original_input).groups()
        self.assertEqual(len(results), 2)

        W = int(results[0])
        H = int(results[1])

        self.assertTrue(5 <= W <= 2500)
        self.assertTrue(5 <= H <= 2500)


if __name__ == '__main__':
    validatortest.main()
