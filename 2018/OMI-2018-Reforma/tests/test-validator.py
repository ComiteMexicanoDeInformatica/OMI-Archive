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
		
		regex = re.compile(r'(\d*)\n(\d*(?: \d*)*)\n$')
		results = re.match(regex, original_input).groups()
		self.assertEqual(len(results), 2)

		N = int(results[0])
		nums = [int(x) for x in results[1].split()]

		self.assertEqual(N, len(nums))
		self.assertTrue(0 <= min(nums))
		self.assertTrue(max(nums) <= 2**16)
		
		caseName = sys.argv[1]
		if 'casogrande' in caseName:
			self.assertTrue(0 <= N <= 10**5)
		else:
			self.assertTrue(0 <= N <= 1000)

if __name__ == '__main__':
	validatortest.main()