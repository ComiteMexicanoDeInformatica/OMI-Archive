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
		
		caseName = sys.argv[1]
		if 'encode' in caseName:
			regex = re.compile(r'^0\n(\d+)\n$')
			results = re.match(regex, original_input).groups()
			self.assertEqual(len(results), 1)
			number = int(results[0])
			self.assertTrue(1 <= number < 2**63)
		elif 'decode' in caseName:
			regex = re.compile(r'^1\n([A-Z]+)\n$')
			results = re.match(regex, original_input).groups()
			self.assertEqual(len(results), 1)
			limit = "CRPXNLSKVLJFHG"
			self.assertTrue(len(results[0]) >= 1)
			self.assertTrue(len(results[0]) < len(limit) or results[0] <= limit)
		else:
			self.fail(f"Invalid case name: {caseName}")

if __name__ == '__main__':
	validatortest.main()