#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

#!/usr/bin/env python
# -*- coding: latin1 -*-

# Practica 2 - Tuplas

t1 = "a", "b", "c", "d"
t2 = ("d",)
a, b, c = 1, 2, 3
size = w, h = 10, 10

print t1; print t2; print a, b, c; print size

persona = "Raul", "Perula Martinez", 21, 65, "30554189D"
print "\n", persona

print "\nValores antes:", a, b
a, b = b, a
print "Valores despues:", a, b

def returned():
	return "hola", 23, [1,2,3]

tupla = returned()
print "\n", tupla

lista = list(tupla)
print "\n", lista

tupla = tuple(raw_input("\nEscriba lo que quiera: "))
print "\n", tupla

