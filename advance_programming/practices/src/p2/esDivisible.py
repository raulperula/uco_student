#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

# Practica 2 - Sentencia IF

def esDivisible(a,b):
	if a%b == 0:
		return True
	else:
		return False
		
def esDivisible2(a,b):
	return a%b == 0

def muestraDiv(a,b):
	if esDivisible(a,b):
		print "Primera forma: ", a, " es divisible por ", b, "\n"
	else:
		print "Primera forma: ", a, " no es divisible por ", b, "\n"
	
	if esDivisible2(a,b):
		print "Segunda forma: ", a, " es divisible por ", b, "\n"
	else:
		print "Segunda forma: ", a, " no es divisible por ", b, "\n"

## MAIN ##

muestraDiv(6,3)

