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

		regex = re.compile(r'^(\d+)$')
		results = re.match(regex, original_input).groups()
		self.assertEqual(len(results), 1)

		N = int(results[0])

		self.assertTrue(20 < N < 500)

if __name__ == '__main__':
	validatortest.main()