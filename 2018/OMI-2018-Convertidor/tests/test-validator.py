#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import os
import re

from ctest import *

class Test(CTest):
    def test(self):
        if 'encode' in self.caseName:
            regex = re.compile(r'0\n(\d+)\n$')
            results = re.match(regex, self.input).groups()
            self.assertEqual(len(results), 1)
            number = int(results[0])
            self.assertTrue(1 <= number < 2**63)
        elif 'decode' in self.caseName:
            regex = re.compile(r'1\n([A-Z]+)\n$')
            results = re.match(regex, self.input).groups()
            self.assertEqual(len(results), 1)
            limit = "CRPXNLSKVLJFHG"
            testStr = results[0]
            self.assertTrue(len(testStr) >= 1)
            self.assertTrue(len(testStr) < len(limit) or testStr <= limit)
        else:
            raise TestFailure('invalid case name')

Test().run()
