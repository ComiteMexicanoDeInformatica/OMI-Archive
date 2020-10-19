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

		regex = re.compile(r'^(\d+) (\d+) (\d+)\n((?:[01]+\n)+)$')
		results = re.match(regex, original_input).groups()
		self.assertEqual(len(results), 4)

		N = int(results[0])
		M = int(results[1])
		K = int(results[2])
		
		grid = results[3].split('\n')
		grid.pop()

		self.assertTrue(1 <= N <= 1500)
		self.assertTrue(1 <= M <= 1500)
		self.assertTrue(0 <= K <= 6)

		self.assertEqual(len(grid), N)
		self.assertTrue(all(len(r) == M for r in grid))

		caseName = sys.argv[1]
		if 'easy' in caseName:
			self.assertTrue(1 <= N <= 20)
			self.assertTrue(1 <= M <= 20)

if __name__ == '__main__':
	validatortest.main()
