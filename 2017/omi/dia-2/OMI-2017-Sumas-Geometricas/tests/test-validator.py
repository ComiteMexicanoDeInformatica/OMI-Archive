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

		regex = re.compile(r'^(\d+)\n(\d+(?: \d+)*)\n$')
		results = re.match(regex, original_input).groups()
		
		self.assertEqual(len(results), 2)

		N = int(results[0])
		L = results[1].split(' ')

		self.assertTrue(0 <= N <= 1e5)
		self.assertEqual(len(L), N)
		for x in L:
			self.assertTrue(len(x) < 18)
			if (x[0]!='1'):
				self.assertTrue(len(x) < 17)

if __name__ == '__main__':
	validatortest.main()
