#!/usr/bin/python
# -*- coding: utf-8 -*-
import logging
import sys
import os
import re

from ctest import *

logger = logging.getLogger(__name__)

logging.basicConfig(format='%(asctime)s: %(message)s', level=logging.INFO)

# shut up
logging.getLogger('urllib3').setLevel(logging.CRITICAL)

class Test(CTest):
    def test(self):
        regex = re.compile(r'^(\d+) (\d+)$')
        results = re.match(regex, self.input).groups()
        self.assertEqual(len(results), 2)

        X = int(results[0])
        Y = int(results[1])

        if 'samexypow3' in self.caseName:
            self.assertEqual(1162261467 % X, 0)
            self.assertEqual(1162261467 % Y, 0)
        elif 'max1000' in self.caseName:
            self.assertTrue(1 <= X <= 1000)
            self.assertTrue(1 <= Y <= 1000)
        elif 'maxmillon' in self.caseName:
            self.assertTrue(1 <= X <= 1000000)
            self.assertTrue(1 <= Y <= 1000000)
        elif 'big' in self.caseName:
            self.assertTrue(1 <= X <= 15000000)
            self.assertTrue(1 <= Y <= 15000000)
        else:
            raise TestFailure(
                'case name is invalid!'
            )

Test().run()
