#!/usr/bin/python
# -*- coding: utf-8 -*-
import logging
import math
import os
import re
import sys

from ctest import *

logger = logging.getLogger(__name__)

logging.basicConfig(format='%(asctime)s: %(message)s', level=logging.INFO)

# shut up
logging.getLogger('urllib3').setLevel(logging.CRITICAL)


class Test(CTest):
    def test(self):
        regex = re.compile(
            r'^\s*(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+([-+]?\d+)\s+(\d+)\s*$'
        )
        results = re.match(regex, self.input).groups()
        self.assertEqual(len(results), 8)

        (semilla, bits, nbits, casa_origen, casa_destino, limite, direction,
         level) = (int(x) for x in results)

        self.assertIn(level, (0, 1, 2, 3))
        self.assertIn(direction, (-1, 1))
        self.assertTrue(1 < bits < 64)
        self.assertTrue(nbits < bits - 1)
        self.assertTrue(0 <= casa_origen <= 2**nbits)
        self.assertTrue(0 <= casa_destino <= 2**nbits)
        self.assertNotEqual(casa_origen, casa_destino)

        if 'small' in self.caseName:
            self.assertEqual(casa_origen, 0)
            self.assertEqual(level, 0)
            self.assertEqual(limite, 2**nbits)
        elif 'big' in self.caseName:
            self.assertIn(level, (1, 2, 3))
            self.assertTrue(2 <= nbits <= 31)
            self.assertEqual(limite, int(math.sqrt(2**nbits)))
        elif 'huge' in self.caseName:
            self.assertIn(level, (1, 2, 3))
            self.assertTrue(2 <= nbits <= 61)
            self.assertTrue(limite <= 2 * nbits)
        else:
            raise TestFailure('case name is invalid!')


if __name__ == '__main__':
    Test().run()
