#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

#!/usr/bin/env python
# -*- coding: latin1 -*-

# Practica 2 - Listas

l1 = []
l2 = [1, 2, 3]
l3 = [1.2, 3.4, 3.3]
l4 = ["hola", "que", "tal"]

print l1; print l2; print l3; print l4

print
for i in range(0,l4.__len__()): print l4[i]
	
l1 = range(1,4)
l2 = range(4,-2)
l3 = range(0,5,2)

print
print l1; print l2; print l3

print
for	i in l1:
	print i, "su cuadrado es:", i**2

print
for i in "caracola":
	print i

print
for i in range(0,5):
	print i, "!=", i+1

l1.extend(l3)
print "\n", l1
l1.append(4)
print l1
l1.insert(0,"primero")
print l1
del l1[0]
print l1
l1.remove(4)
print l1
l2 = l1
print l2

# funcion que devuelve una lista
def fun():
	return range(1,5)

# funcion que elimina los elementos pares de una lista introducida por teclado
def rmpar():
	import string
	cad = raw_input("Dame una lista de numeros (separados por espacio): ")
	l = cad.split()
	aux = list()
	
	for i in range(0,len(l)):
		if int(l[i])%2 != 0:
			aux.append(l[i])
	
	print aux

# elimina las palabras de la primera lista que aparezcan en la segunda lista
l1 = l2 = l3 = []
cad1 = raw_input("\nEscriba una frase: ")
l1 = cad1.split()
cad2 = raw_input("Escriba otra frase: ")
l2 = cad2.split()
for i in range(0,len(l1)):
	for j in range(0,len(l2)):
		if (l1[i] not in l2) & (l1[i] not in l3):
			l3.append(l1[i])
l1 = l3
print l1

# pedir una lista y ordenarla, da igual el tipo
cad = raw_input("\nEscriba una lista (separado por espacios): ")
l = cad.split()
l.sort()
print l

# pedir una frase, convertirla en lista, visualizarla junto a su tamaño y ordenarla
cad = raw_input("\nEscriba una frase: ")
l = cad.split()
print "lista:", l, ; print "long:", len(l)
l.sort()
print "lista ordenada:", l

