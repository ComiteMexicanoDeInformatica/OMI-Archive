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
        regex = re.compile(r'^(\d+) (\d+)$')
        with open('data.in', 'r') as handle:
            original_input = handle.read()

        lines = original_input.split('\n')
        self.assertEqual(lines[-1], '')
        lines.pop()

        self.assertTrue(regex.match(lines[0]))
        
        lines[0] = lines[0].split(' ')
        lines[0][0] = int(lines[0][0])
        lines[0][1] = int(lines[0][1])

        N = lines[0][0]
        M = lines[0][1]

        self.assertEqual(len(lines), N + 1)

        #Verificar que si esté en los limites

        self.assertTrue(2 <= N <= 50)
        self.assertTrue(2 <= M <= 10000)

        ap = [0] * (N+1)

        for i in range(1, len(lines)):
          arr  = lines[i].split(' ')
          ints = [int(v) for v in arr]
          self.assertEqual(len(ints), M)
          self.assertTrue(all(
            1 <= v <= N 
            for v in ints
          ))
          for v in ints:
            ap[v] += 1

        self.assertEqual(ap.count(M), N)


if __name__ == '__main__':
    validatortest.main()