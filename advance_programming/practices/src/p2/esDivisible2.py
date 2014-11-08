#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

# Practica 2 - E/S por pantalla y argumentos

def esDivisible(a,b):
	if a%b == 0:
		return True
	else:
		return False
		
def esDivisible2(a,b):
	return a%b == 0

def muestraDiv(a,b):
	if esDivisible(a,b):
		print "\nPrimera forma: ", a, " es divisible por ", b
	else:
		print "\nPrimera forma: ", a, " no es divisible por ", b
	
	if esDivisible2(a,b):
		print "Segunda forma: ", a, " es divisible por ", b, "\n"
	else:
		print "Segunda forma: ", a, " no es divisible por ", b, "\n"

## MAIN ##

import sys

if len(sys.argv) == 3:
	a = int(sys.argv[1])
	b = int(sys.argv[2])
else:
	print "\nEscribe dos numeros y te dire si son divisibles\n"
	a = int(raw_input("Dame un numero: "))
	b = int(raw_input("Dame otro numero: "))

muestraDiv(a,b)

