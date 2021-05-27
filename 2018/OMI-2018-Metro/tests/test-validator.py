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
	
		regex = re.compile(r'(\d+) (\d+) (\d+)\n((?:\d+(?: \d+)+\n)+)$')
		results = re.match(regex, original_input).groups()
		self.assertEqual(len(results), 4)

		P = int(results[0])
		D = int(results[1])
		Q = int(results[2])

		caseName = sys.argv[1]
		if 'ST0' in caseName:
			self.assertTrue(1 <= P <= 100)
			self.assertTrue(1 <= D <= 100)
			self.assertTrue(1 <= Q <= 100)
		elif 'ST1' in caseName:
			self.assertTrue(1 <= P <= 2000)
			self.assertTrue(1 <= D <= 2000)
			self.assertTrue(1 <= Q <= 2000)
		elif 'ST2' in caseName:
			self.assertTrue(1 <= P <= 100000)
			self.assertTrue(1 <= D <= 1000)
			self.assertTrue(1 <= Q <= 1000)
		else:
			self.assertTrue(1 <= P <= 100000)

		lines = results[3].split('\n')
		lines.pop()

		doorsL = lines[:D]
		queriesL = lines[D:]

		self.assertEqual(len(doorsL), D)
		self.assertEqual(len(queriesL), Q)

		doors = [[int(x) for x in y.split()] for y in doorsL]
		disum = 0

		for d in doors:
			xi, di, *dd = d

			disum += di

			self.assertTrue(1 <= xi <= P)
			self.assertTrue(1 <= di <= P)
			self.assertEqual(di, len(dd))

			self.assertTrue(all(1 <= k <= P for k in dd))

			# no repeats
			self.assertEqual(len(dd), len(set(dd)))

		self.assertTrue(disum <= 1000000)

		queries = [[int(x) for x in y.split()] for y in queriesL]
		qisum = 0

		for q in queries:
			qi, *qq = q

			qisum += qi

			self.assertTrue(1 <= qi <= P)
			self.assertEqual(qi, len(qq))

			self.assertTrue(all(1 <= k <= P for k in qq))

			# no repeats
			self.assertEqual(len(qq), len(set(qq)))

		self.assertTrue(qisum <= 1000000)

if __name__ == '__main__':
	validatortest.main()
