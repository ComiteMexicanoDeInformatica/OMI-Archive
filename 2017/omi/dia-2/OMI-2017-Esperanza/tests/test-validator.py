#!/usr/bin/python
# -*- coding: utf-8 -*-
import logging
import unittest
import sys
import re

from omegaup.validator import validatortest


class MyTest(unittest.TestCase):
	def test_input(self):
		with open('data.in', 'r') as f:
			original_input = f.read()
		
		regex = re.compile(r'^(\d+)\n([UDLR]+\n)$')
		results = re.match(regex, original_input).groups()
		self.assertEqual(len(results), 2)
		
		N = int(results[0])
		self.assertEqual(len(results[1]), N+1)

		caseName = sys.argv[1]
		if 'easy' in caseName:
			self.assertTrue(1 <= N <= 1000)
		elif 'med' in caseName:
			self.assertTrue(1 <= N <= 20000)
		elif 'hard' in caseName:
			self.assertTrue(1 <= N <= 1000000)
		else:
			self.fail(f"Invalid case name: {caseName}")

if __name__ == '__main__':
	validatortest.main()