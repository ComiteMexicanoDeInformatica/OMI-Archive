#!/usr/bin/python
# -*- coding: utf-8 -*-
import logging
import unittest
import sys
import re

from omegaup.validator import validatortest

#DUMMY
class MyTest(unittest.TestCase):
	def test_input(self):
		self.assertTrue(True)

if __name__ == '__main__':
	validatortest.main()
