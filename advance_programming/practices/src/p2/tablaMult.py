#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

# Practica 2 - Iteraciones

for i in range(10):
	print "\nTabla de multiplicar del", i+1
	for j in range(10):
		print i+1, "*", j+1, "= ", (i+1)*(j+1)
	print "\n"


print "\nTabla de multiplicar con WHILE\n"

i = 1; j = 1
while i <= 10:
	print i*j, "\t",
	j += 1
	if j == 11:
		j = 1
		i += 1
		print
