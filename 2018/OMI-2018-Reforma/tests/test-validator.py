#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import os
import re

from ctest import *

class Test(CTest):
    def test(self):
        regex = re.compile(r'(\d*)\n(\d*(?: \d*)*)\n$')
        results = re.match(regex, self.input).groups()
        self.assertEqual(len(results), 2)

        N = int(results[0])
        nums = [int(x) for x in results[1].split()]

        self.assertEqual(N, len(nums))
        self.assertTrue(0 <= min(nums))
        self.assertTrue(max(nums) <= 2**16)
        
        if 'casogrande' in self.caseName:
            self.assertTrue(0 <= N <= 10**5)
        else:
            self.assertTrue(0 <= N <= 1000)

Test().run()
