#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

#!/usr/bin/env python
# -*- coding: latin1 -*-

# Practica 2 - Parametros

def param(p1, p2, p3, p4, p5, p6):
	p1 = p2 = p3 = p4 = p5 = p6 = 8
	print "\nParametros:", p1, ",", p2, ",", p3, ",", p4, ",", p5, ",", p6

param(24, 2.2, True, "hola", [1,2,3], ("adios", 50, [4,5,6]))

def fun(*args):
	print
	for i in args:
		print i

fun(100, "hola", [1,2,3], ("adios", 50))

def palabras(lista):
	aux = list()
	media = 0.0
	maxi = 0
	mini = 999
	
	for i in range(0,len(lista)):
		l = len(lista[i])
		media += l
		aux.append([lista[i], l])
		if maxi < l:
			maxi = l
		if mini > l:
			mini = l
	
	aux.append(["media", round(media/len(lista),1)])
	aux.append(["max", maxi])
	aux.append(["min", mini])
	
	return aux

print "\n", palabras(["hola", "como", "estas", "tu", "caracola"])

