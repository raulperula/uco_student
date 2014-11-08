#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

# Cadenas

# 1

print "\nEJERCICIO 1\n"

cad1 = "hola"
cad2 = " mundo"
cad = cad1+cad2
print cad

# 2

print "\nEJERCICIO 2\n"

print cad[:2]
print cad[4:]
print cad[2:4]

# 3

#print cad[24]

# 4

#cad[0] = "H"
#print cad

# 5

print "\nEJERCICIO 5\n"

print "hOlA".upper()
print "hOlA".lower()
print "   ho  la   ".strip()
print max("abcdef")
print min("abcdef")
print "a" in "hola"
print "j" not in "hola"

# 6

print "\nEJERCICIO 6\n"

import string

cadena = "hola mundo, que tal todo?"

print string.letters
print string.lowercase
print string.uppercase
print string.digits
print string.punctuation
print string.split(cadena)
print string.find(cadena,",")
print string.replace(cadena,cadena,cadena+cadena)
print string.join(cadena,",")

# 7

#help(string.split)
#help(string.find)
#help(string.replace)
#help(string.join)

# 8

print "\nEJERCICIO 8\n"

cad = raw_input("Dame una cadena: ")
l = cad.split()
print "La cadena tiene ", l.__len__(), " palabras."

