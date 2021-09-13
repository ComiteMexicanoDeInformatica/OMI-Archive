#!/usr/bin/python
# -*- coding: utf-8 -*-
import logging
import unittest
import sys

from omegaup.validator import validatortest

class MyTest(unittest.TestCase):
	def test(self):
		original_input = open("data.in", "r")
		first_line = original_input.readline().split()
		self.assertEqual(len(first_line), 3)

		N = int(first_line[0])
		M = int(first_line[1])
		K = int(first_line[2])

		caseName = sys.argv[1]
		if 'sub1' in caseName:
			self.assertEqual(K, 1)
		elif 'sub2' in caseName:
			self.assertTrue(1 <= N <= 3)
		elif 'sub3' in caseName:
			self.assertTrue(1 <= M <= 10)

		self.assertTrue(1 <= N <= 100000)
		self.assertTrue(1 <= M <= 100000)
		self.assertTrue(1 <= K <= N)

		# Check if infected are not repeated
		infected = original_input.readline().split()
		self.assertEqual(len(infected), K)
		repeated = set()

		for i in range(len(infected)):
			infected[i] = int(infected[i])
			self.assertTrue(1 <= infected[i] <= N)
			self.assertTrue(infected[i] not in repeated)
			repeated.add(infected[i])
		
		if 'sub1' in caseName:
			self.assertTrue(1 in infected)
		
		# Check if number of events and numbers are correct
		number_events = 0
		act_line = original_input.readline()
		while number_events < M and act_line != "":
			event = act_line.split()
			self.assertEqual(len(event), 2)
			event[0] = int(event[0])
			event[1] = int(event[1])
			self.assertTrue(1 <= event[0] <= N)
			self.assertTrue(1 <= event[1] <= N)
			self.assertTrue(event[0] != event[1])  # Not sending to itself
			if 'sub4' in caseName:
				self.assertTrue(event[0] < event[1])
			act_line = original_input.readline()
			number_events = number_events + 1
		
		self.assertEqual(number_events, M)


if __name__ == '__main__':
	validatortest.main()