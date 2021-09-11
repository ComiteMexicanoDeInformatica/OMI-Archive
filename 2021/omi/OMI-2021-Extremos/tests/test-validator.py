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
		regex = re.compile(r'^(\d+)$')
		with open('data.in', 'r') as handle:
			original_input = handle.read()

		lines = original_input.split('\n')
		self.assertEqual(lines[-1], '')
		lines.pop()

		self.assertTrue(regex.match(lines[0]))

		N = int(lines[0])
        
       		#Verificar el numero de lineas
        
		self.assertEqual(len(lines), 2)
		#Verificar que si N este en los limites

		self.assertTrue(2 <= N <= 1e5)

        	#Verificar que los elementos esten en los limites
		arr  = lines[1].split(' ')
		ints = [int(v) for v in arr]
		self.assertEqual(len(ints), N)
		self.assertTrue(all(
			1 <= v <= N 
			for v in ints
		))
		#Verificar la unicidad de los elementos.
		self.assertTrue(len(ints) == len(set(ints)))

if __name__ == '__main__':
    validatortest.main()
