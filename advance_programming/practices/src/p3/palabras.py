#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

#!/usr/bin/env python
# -*- coding: latin1 -*-

# Practica 3

import random
import time

def devPalabras(nombre):
	"Recibe una cadena con el nombre de un fichero y devuelve una lista con todas\
 las palabras de dicho fichero"
	
	f = open(nombre, "r")
	lista = f.read()
	f.close()
	
	return lista.split()

def seleccionaElemento(lista):
	"Devuelve un elemento al azar de una lista de elementos que recibe como\
 parametro"
	
	return random.choice(lista)

def introLetra():
	"Pide al usuario por teclado una letra, comprueba si efectivamente es una\
 unica letra y la devuelve. Si el usuario introduce más de una letra, la\
 función volvera a pedir al usuario que introduzca una letra"
	
	letra = raw_input("\nEscriba una letra: ")
	while len(letra) != 1:
		print "\nError, ha introducido mas de una letra"
		letra = raw_input("\nEscriba una letra: ")
	
	return letra

def buscaLetra(letra, cadena):
	"Recibe como parametros dos cadenas. El primero sera una letra y el segundo\
 una cadena. La funcion devolvera una lista con las posiciones dentro de la\
 cadena donde se encuentre la letra"
	
	lista = list()
	
	for i in range(0,len(cadena)):
		if cadena[i] == letra:
			lista.append(i)
	
	return lista

### MAIN ###

tInicio = time.time()

igual = fallos = aciertos = 0

palabras = devPalabras("palabras.txt")

palabra = seleccionaElemento(palabras)

pista = ""
for i in palabra:
	pista += "-"

print "\nPalabra:", pista

while not igual:
	letra = introLetra()

	index = buscaLetra(letra,palabra)
	if (index == []) | (letra in pista):
		fallos += 1
	else:
		aciertos += 1

	for i in index:
		pista = pista[:i]+letra+pista[i+1:]
	
	print "\nPalabra:", pista
	print "\nNumero de fallos: ", fallos
	print "Numero de aciertos: ", aciertos
	
	if pista == palabra:
		igual = 1
		print "\nTiempo jugado: ", round(time.time()-tInicio,2)
	elif fallos == 25:
		igual = 1
		print "\nHas superado el numero de fallos permitido"

