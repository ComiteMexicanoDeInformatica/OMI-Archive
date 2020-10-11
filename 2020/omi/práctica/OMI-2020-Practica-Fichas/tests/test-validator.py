#!/usr/bin/python
# -*- coding: utf-8 -*-
import logging
import unittest
import sys
import re

from omegaup.validator import validatortest


class MyTest(unittest.TestCase):
    def test_input(self):
        with open('data.in', 'r') as handle:
            original_input = handle.read()

        lines = original_input.split('\n')
        self.assertEqual(lines[-1], '')
        lines.pop()

        # En la primera línea hay dos números, n y m
        regex = re.compile(r'^(\d+) (\d+)$')
        self.assertTrue(regex.match(lines[0]))
        N, M = [int(v) for v in lines[0].split(' ')]

        caseName = sys.argv[1]
        if '.20' in caseName:
            # N,M son menores que 10
            self.assertTrue(1 <= N <= 10)
            self.assertTrue(1 <= M <= 10)
        else:
            # N,M son menores que 1000
            self.assertTrue(1 <= N <= 1000)
            self.assertTrue(1 <= M <= 1000)

        lines = lines[1:]
        # Hay N líneas
        self.assertEqual(len(lines), N)
        for line in lines:
            # Ver si es una fila válida con M caracteres
            regex = re.compile(r'^([\.\*]+)$')
            self.assertTrue(regex.match(line))
            self.assertEqual(len(line), M)
        
        


if __name__ == '__main__':
    validatortest.main()
