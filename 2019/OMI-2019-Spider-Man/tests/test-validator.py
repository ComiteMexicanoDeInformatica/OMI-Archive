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
        regex = re.compile(r'^(\d+) (\d+) (\d+) (\d+) (\d+)$')
        results = re.match(regex, self.input).groups()
        self.assertEqual(len(results), 5)

        N = int(results[0])
        M = int(results[1])
        K = int(results[2])
        X = int(results[3])
        Y = int(results[4])

        if 'small' in self.caseName:
            self.assertTrue(1 <= N < 1000)
            self.assertTrue(1 <= M < 1000)
            self.assertTrue(1 <= K < 1000)
            self.assertTrue(1 <= X < 1000)
            self.assertTrue(1 <= Y < 1000)
        else:
            self.assertTrue(1 <= N < 2**31)
            self.assertTrue(1 <= M < 2**31)
            self.assertTrue(1 <= K < 2**31)
            self.assertTrue(1 <= X < 2**31)
            self.assertTrue(1 <= Y < 2**31)

Test().run()
