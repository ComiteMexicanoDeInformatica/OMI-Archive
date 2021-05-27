#!/usr/bin/python
# -*- coding: utf-8 -*-
import logging
import unittest
import sys
import re

from omegaup.validator import validatortest

class MyTest(unittest.TestCase):
	def test(self):
		with open('data.in', 'r') as f:
			original_input = f.read()
		
		regex = re.compile(r'^(\d+) (\d+)\n((?:-?\d+(?: -?\d+)*\n)+)$')
		results = re.match(regex, original_input).groups()
		self.assertEqual(len(results), 3)

		N = int(results[0])
		M = int(results[1])

		self.assertTrue(1 <= N <= 100)
		self.assertTrue(1 <= M <= 100)

		gridS = results[2].split('\n')
		gridS.pop()

		grid = [[int(x) for x in y.split()] for y in gridS]

		self.assertEqual(len(grid), N)

		for row in grid:
			self.assertEqual(len(row), M)
			self.assertTrue(all(abs(x) <= 100 for x in row))

		caseName = sys.argv[1]
		if 'easy' in caseName:
			self.assertTrue(N <= 10)
			self.assertTrue(M <= 10)
		else:
			self.assertTrue(N + M >= 20)

if __name__ == '__main__':
	validatortest.main()
